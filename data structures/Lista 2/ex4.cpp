#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


typedef struct trabalho {
    char nome[256];
    int paginas;
} Trabalho;

typedef struct no {
    Trabalho item;
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

int enfileirar(Fila *f, Trabalho item) {
    No novo = (No) malloc(sizeof(struct no));
    if (novo == NULL) return 0;

    novo->item = item;
    novo->prox = NULL;

    if (f->inicio == NULL) {
        f->inicio = novo;
    } else {
        f->final->prox = novo;
    }

    f->final = novo;
    f->tamanho++;
    return 1;
}

int desenfileirar(Fila *f, Trabalho *item) {
    if (esta_vazia(*f)) return 0;

    No p = f->inicio;
    *item = p->item;
    f->inicio = p->prox;
    free(p);

    if (f->inicio == NULL) f->final = NULL;

    f->tamanho--;
    return 1;
}

int espiar(Fila f, Trabalho *item) {
    if (esta_vazia(f)) return 0;
    *item = f.inicio->item;
    return 1;
}

void cmd_add(Fila *f, const char *nome, int paginas) {
    Trabalho t;
    strncpy(t.nome, nome, 255);
    t.nome[255] = '\0';
    t.paginas = paginas;

    if (enfileirar(f, t)) {
        printf("Trabalho '%s' (%d paginas) adicionado a fila.\n", nome, paginas);
    } else {
        printf("Erro: memoria insuficiente.\n");
    }
}

void cmd_print(Fila *f) {
    if (esta_vazia(*f)) {
        printf("Fila vazia. Nenhum trabalho para imprimir.\n");
        return;
    }

    Trabalho t;
    desenfileirar(f, &t);
    printf("Imprimindo '%s' (%d paginas)...\n", t.nome, t.paginas);

    int i;
    for (i = 1; i <= t.paginas; i++) {
        printf("  Pagina %d/%d\n", i, t.paginas);
        sleep(1);
    }
    printf("Impressao de '%s' concluida.\n", t.nome);
}

void cmd_cancel(Fila *f, const char *nome) {
    if (esta_vazia(*f)) {
        printf("Fila vazia. Nenhum trabalho para cancelar.\n");
        return;
    }

    Fila aux;
    inicializar_fila(&aux);

    int encontrado = 0;
    Trabalho t;

    while (!esta_vazia(*f)) {
        desenfileirar(f, &t);
        if (!encontrado && strcmp(t.nome, nome) == 0) {
            encontrado = 1;
        } else {
            enfileirar(&aux, t);
        }
    }

    while (!esta_vazia(aux)) {
        desenfileirar(&aux, &t);
        enfileirar(f, t);
    }

    if (encontrado) {
        printf("Trabalho '%s' cancelado.\n", nome);
    } else {
        printf("Trabalho '%s' nao encontrado na fila.\n", nome);
    }
}

void cmd_status(Fila f) {
    if (esta_vazia(f)) {
        printf("Fila vazia.\n");
        return;
    }

    printf("Fila de impressao (%d trabalho(s)):\n", f.tamanho);
    No aux = f.inicio;
    int i = 1;
    while (aux != NULL) {
        printf("  %d. %s (%d paginas)\n", i, aux->item.nome, aux->item.paginas);
        aux = aux->prox;
        i++;
    }
}

int main() {
    Fila fila;
    inicializar_fila(&fila);

    char linha[512];
    char cmd[64], nome[256];
    int paginas;

    printf("=== Simulador de Impressora ===\n");
    printf("Comandos: add <nome> <paginas> | print | cancel <nome> | status | sair\n\n");

    while (1) {
        printf("> ");
        if (fgets(linha, sizeof(linha), stdin) == NULL) break;

        size_t len = strlen(linha);
        if (len > 0 && linha[len - 1] == '\n') linha[len - 1] = '\0';

        if (sscanf(linha, "%63s", cmd) != 1) continue;

        if (strcmp(cmd, "sair") == 0) {
            break;
        } else if (strcmp(cmd, "add") == 0) {
            if (sscanf(linha, "%*s %255s %d", nome, &paginas) == 2) {
                cmd_add(&fila, nome, paginas);
            } else {
                printf("Uso: add <nome> <paginas>\n");
            }
        } else if (strcmp(cmd, "print") == 0) {
            cmd_print(&fila);
        } else if (strcmp(cmd, "cancel") == 0) {
            if (sscanf(linha, "%*s %255s", nome) == 1) {
                cmd_cancel(&fila, nome);
            } else {
                printf("Uso: cancel <nome>\n");
            }
        } else if (strcmp(cmd, "status") == 0) {
            cmd_status(fila);
        } else {
            printf("Comando desconhecido: %s\n", cmd);
        }
    }

    return 0;
}
