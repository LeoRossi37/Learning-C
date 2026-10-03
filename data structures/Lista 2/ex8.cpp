#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TIPO_BACKUP   1
#define TIPO_EMAIL    2
#define TIPO_RELATORIO 3

typedef struct {
    char pasta[256];
    int  tamanho_gb;
} TarefaBackup;

typedef struct {
    char destinatario[256];
    char assunto[256];
} TarefaEmail;

typedef struct {
    char nome[256];
    int  paginas;
} TarefaRelatorio;


typedef struct no {
    int   tipo;
    void *dados;     
    struct no *prox;
} *No;

typedef struct {
    No inicio, final;
    int tamanho;
} Fila;

void inicializar_fila(Fila *f) {
    f->inicio = f->final = NULL;
    f->tamanho = 0;
}

int esta_vazia(Fila f) {
    return (f.inicio == NULL);
}

int enfileirar(Fila *f, int tipo, void *dados) {
    No novo = (No) malloc(sizeof(struct no));
    if (novo == NULL) return 0;

    novo->tipo  = tipo;
    novo->dados = dados;
    novo->prox  = NULL;

    if (f->inicio == NULL) {
        f->inicio = novo;
    } else {
        f->final->prox = novo;
    }

    f->final = novo;
    f->tamanho++;
    return 1;
}

int desenfileirar(Fila *f, int *tipo, void **dados) {
    if (esta_vazia(*f)) return 0;

    No p      = f->inicio;
    *tipo     = p->tipo;
    *dados    = p->dados;
    f->inicio = p->prox;
    free(p);              

    if (f->inicio == NULL) f->final = NULL;

    f->tamanho--;
    return 1;
}
void liberar_dados(int tipo, void *dados) {
    (void) tipo;  
    free(dados);
}


void exibir_tarefa(int tipo, void *dados) {
    switch (tipo) {
        case TIPO_BACKUP: {
            TarefaBackup *t = (TarefaBackup *) dados;
            printf("BACKUP: pasta=%s, tamanho=%d GB", t->pasta, t->tamanho_gb);
            break;
        }
        case TIPO_EMAIL: {
            TarefaEmail *t = (TarefaEmail *) dados;
            printf("EMAIL: destinatario=%s, assunto=%s", t->destinatario, t->assunto);
            break;
        }
        case TIPO_RELATORIO: {
            TarefaRelatorio *t = (TarefaRelatorio *) dados;
            printf("RELATORIO: nome=%s, paginas=%d", t->nome, t->paginas);
            break;
        }
        default:
            printf("(tipo desconhecido)");
    }
}


void cmd_add_backup(Fila *f, const char *pasta, int tamanho) {
    TarefaBackup *t = (TarefaBackup *) malloc(sizeof(TarefaBackup));
    if (t == NULL) { printf("Erro: memoria insuficiente.\n"); return; }

    strncpy(t->pasta, pasta, 255); t->pasta[255] = '\0';
    t->tamanho_gb = tamanho;

    if (enfileirar(f, TIPO_BACKUP, t)) {
        printf("Tarefa BACKUP adicionada (pasta=%s, tamanho=%d GB).\n",
               pasta, tamanho);
    } else {
        free(t);
        printf("Erro: memoria insuficiente.\n");
    }
}

void cmd_add_email(Fila *f, const char *destinatario, const char *assunto) {
    TarefaEmail *t = (TarefaEmail *) malloc(sizeof(TarefaEmail));
    if (t == NULL) { printf("Erro: memoria insuficiente.\n"); return; }

    strncpy(t->destinatario, destinatario, 255); t->destinatario[255] = '\0';
    strncpy(t->assunto,      assunto,      255); t->assunto[255]      = '\0';

    if (enfileirar(f, TIPO_EMAIL, t)) {
        printf("Tarefa EMAIL adicionada (destinatario=%s, assunto=%s).\n",
               destinatario, assunto);
    } else {
        free(t);
        printf("Erro: memoria insuficiente.\n");
    }
}

void cmd_add_relatorio(Fila *f, const char *nome, int paginas) {
    TarefaRelatorio *t = (TarefaRelatorio *) malloc(sizeof(TarefaRelatorio));
    if (t == NULL) { printf("Erro: memoria insuficiente.\n"); return; }

    strncpy(t->nome, nome, 255); t->nome[255] = '\0';
    t->paginas = paginas;

    if (enfileirar(f, TIPO_RELATORIO, t)) {
        printf("Tarefa RELATORIO adicionada (nome=%s, paginas=%d).\n",
               nome, paginas);
    } else {
        free(t);
        printf("Erro: memoria insuficiente.\n");
    }
}

void cmd_executar(Fila *f) {
    if (esta_vazia(*f)) {
        printf("Nenhuma tarefa na fila.\n");
        return;
    }

    int tipo;
    void *dados;
    desenfileirar(f, &tipo, &dados);

    printf("Executando ");
    exibir_tarefa(tipo, dados);
    printf("\n");

    liberar_dados(tipo, dados);  

void cmd_status(Fila f) {
    if (esta_vazia(f)) {
        printf("Fila vazia.\n");
        return;
    }

    printf("Fila atual (%d tarefa(s)):\n", f.tamanho);
    No aux = f.inicio;
    int i = 1;
    while (aux != NULL) {
        printf("  %d. ", i);
        exibir_tarefa(aux->tipo, aux->dados);
        printf("\n");
        aux = aux->prox;
        i++;
    }
}


int main() {
    Fila fila;
    inicializar_fila(&fila);

    char linha[1024];
    char tokens[8][256];
    int  n_tokens;

    printf("=== Agendador de Processos ===\n");
    printf("Comandos:\n");
    printf("  add backup <pasta> <tamanho_gb>\n");
    printf("  add email <destinatario> <assunto>\n");
    printf("  add relatorio <nome> <paginas>\n");
    printf("  executar | status | sair\n\n");

    while (1) {
        printf("> ");
        if (fgets(linha, sizeof(linha), stdin) == NULL) break;

        size_t len = strlen(linha);
        if (len > 0 && linha[len - 1] == '\n') linha[len - 1] = '\0';

        n_tokens = 0;
        char *tok = strtok(linha, " ");
        while (tok != NULL && n_tokens < 8) {
            strncpy(tokens[n_tokens], tok, 255);
            tokens[n_tokens][255] = '\0';
            n_tokens++;
            tok = strtok(NULL, " ");
        }

        if (n_tokens == 0) continue;

        if (strcmp(tokens[0], "sair") == 0) {
            break;
        } else if (strcmp(tokens[0], "add") == 0) {
            if (n_tokens < 2) { printf("Uso: add <backup|email|relatorio> ...\n"); continue; }

            if (strcmp(tokens[1], "backup") == 0) {
                if (n_tokens < 4) { printf("Uso: add backup <pasta> <tamanho_gb>\n"); continue; }
                int tam = atoi(tokens[3]);
                if (tam <= 0) { printf("Tamanho deve ser positivo.\n"); continue; }
                cmd_add_backup(&fila, tokens[2], tam);

            } else if (strcmp(tokens[1], "email") == 0) {
                if (n_tokens < 4) { printf("Uso: add email <destinatario> <assunto>\n"); continue; }
                cmd_add_email(&fila, tokens[2], tokens[3]);

            } else if (strcmp(tokens[1], "relatorio") == 0) {
                if (n_tokens < 4) { printf("Uso: add relatorio <nome> <paginas>\n"); continue; }
                int pag = atoi(tokens[3]);
                if (pag <= 0) { printf("Paginas deve ser positivo.\n"); continue; }
                cmd_add_relatorio(&fila, tokens[2], pag);

            } else {
                printf("Tipo desconhecido: %s\n", tokens[1]);
            }
        } else if (strcmp(tokens[0], "executar") == 0) {
            cmd_executar(&fila);
        } else if (strcmp(tokens[0], "status") == 0) {
            cmd_status(fila);
        } else {
            printf("Comando desconhecido: %s\n", tokens[0]);
        }
    }

    while (!esta_vazia(fila)) {
        int tipo; void *dados;
        desenfileirar(&fila, &tipo, &dados);
        liberar_dados(tipo, dados);
    }

    return 0;
}
