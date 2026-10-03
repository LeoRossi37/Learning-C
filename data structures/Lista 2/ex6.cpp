#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct tarefa {
    char nome[256];
    int tempo_restante;
    int prioridade; 
} Tarefa;

typedef struct no {
    Tarefa item;
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

int enfileirar(Fila *f, Tarefa item) {
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

int desenfileirar(Fila *f, Tarefa *item) {
    if (esta_vazia(*f)) return 0;

    No p = f->inicio;
    *item = p->item;
    f->inicio = p->prox;
    free(p);

    if (f->inicio == NULL) f->final = NULL;

    f->tamanho--;
    return 1;
}

int espiar(Fila f, Tarefa *item) {
    if (esta_vazia(f)) return 0;
    *item = f.inicio->item;
    return 1;
}

typedef struct {
    Fila alta;   /* prioridade 3 */
    Fila media;  /* prioridade 2 */
    Fila baixa;  /* prioridade 1 */
} FilaPrioridade;

void inicializar_fp(FilaPrioridade *fp) {
    inicializar_fila(&fp->alta);
    inicializar_fila(&fp->media);
    inicializar_fila(&fp->baixa);
}

int fp_esta_vazia(FilaPrioridade fp) {
    return esta_vazia(fp.alta) && esta_vazia(fp.media) && esta_vazia(fp.baixa);
}

int fp_tamanho(FilaPrioridade fp) {
    return fp.alta.tamanho + fp.media.tamanho + fp.baixa.tamanho;
}
int fp_enfileirar(FilaPrioridade *fp, Tarefa t) {
    switch (t.prioridade) {
        case 3: return enfileirar(&fp->alta,  t);
        case 2: return enfileirar(&fp->media, t);
        case 1: return enfileirar(&fp->baixa, t);
        default:
            printf("Prioridade invalida: %d\n", t.prioridade);
            return 0;
    }
}

int fp_desenfileirar(FilaPrioridade *fp, Tarefa *t) {
    if (!esta_vazia(fp->alta))  return desenfileirar(&fp->alta,  t);
    if (!esta_vazia(fp->media)) return desenfileirar(&fp->media, t);
    if (!esta_vazia(fp->baixa)) return desenfileirar(&fp->baixa, t);
    return 0;
}

int fp_espiar(FilaPrioridade fp, Tarefa *t) {
    if (!esta_vazia(fp.alta))  return espiar(fp.alta,  t);
    if (!esta_vazia(fp.media)) return espiar(fp.media, t);
    if (!esta_vazia(fp.baixa)) return espiar(fp.baixa, t);
    return 0;
}


const char *nome_prioridade(int p) {
    switch (p) {
        case 3: return "alta";
        case 2: return "media";
        case 1: return "baixa";
        default: return "?";
    }
}

void cmd_add(FilaPrioridade *fp, const char *nome, int tempo, int prio) {
    if (prio < 1 || prio > 3) {
        printf("Prioridade invalida. Use 1 (baixa), 2 (media) ou 3 (alta).\n");
        return;
    }
    if (tempo <= 0) {
        printf("Tempo deve ser positivo.\n");
        return;
    }

    Tarefa t;
    strncpy(t.nome, nome, 255);
    t.nome[255] = '\0';
    t.tempo_restante = tempo;
    t.prioridade = prio;

    if (fp_enfileirar(fp, t)) {
        printf("Tarefa '%s' adicionada (tempo=%ds, prioridade=%s).\n",
               nome, tempo, nome_prioridade(prio));
    } else {
        printf("Erro: memoria insuficiente.\n");
    }
}

#define QUANTUM 2

void cmd_processar(FilaPrioridade *fp) {
    if (fp_esta_vazia(*fp)) {
        printf("Nenhuma tarefa na fila.\n");
        return;
    }
    Tarefa t;
    fp_desenfileirar(fp, &t);

    int executado = (t.tempo_restante >= QUANTUM) ? QUANTUM : t.tempo_restante;
    t.tempo_restante -= executado;

    if (t.tempo_restante == 0) {
        printf("Executando '%s' por %ds (concluida).\n", t.nome, executado);
    } else {
        printf("Executando '%s' por %ds (restam %ds).\n",
               t.nome, executado, t.tempo_restante);
        fp_enfileirar(fp, t);
    }
}

void imprimir_fila_label(Fila f, const char *label) {
    if (esta_vazia(f)) return;
    No aux = f.inicio;
    while (aux != NULL) {
        printf("  [%s] %s - %ds restantes\n",
               label, aux->item.nome, aux->item.tempo_restante);
        aux = aux->prox;
    }
}

void cmd_status(FilaPrioridade fp) {
    if (fp_esta_vazia(fp)) {
        printf("Nenhuma tarefa na fila.\n");
        return;
    }
    printf("Tarefas aguardando (%d total):\n", fp_tamanho(fp));
    imprimir_fila_label(fp.alta,  "ALTA ");
    imprimir_fila_label(fp.media, "MEDIA");
    imprimir_fila_label(fp.baixa, "BAIXA");
}

int main() {
    FilaPrioridade fp;
    inicializar_fp(&fp);
    char linha[512];
    char cmd[64], nome[256];
    int tempo, prio;

    printf("=== Processamento de Tarefas com Prioridade ===\n");
    printf("Comandos:\n");
    printf("  add <nome> <tempo> <prioridade(1-3)>\n");
    printf("  processar | status | sair\n\n");

    while (1) {
        printf("> ");
        if (fgets(linha, sizeof(linha), stdin) == NULL) break;

        size_t len = strlen(linha);
        if (len > 0 && linha[len - 1] == '\n') linha[len - 1] = '\0';

        if (sscanf(linha, "%63s", cmd) != 1) continue;

        if (strcmp(cmd, "sair") == 0) {
            break;
        } else if (strcmp(cmd, "add") == 0) {
            if (sscanf(linha, "%*s %255s %d %d", nome, &tempo, &prio) == 3) {
                cmd_add(&fp, nome, tempo, prio);
            } else {
                printf("Uso: add <nome> <tempo> <prioridade>\n");
            }
        } else if (strcmp(cmd, "processar") == 0) {
            cmd_processar(&fp);
        } else if (strcmp(cmd, "status") == 0) {
            cmd_status(fp);
        } else {
            printf("Comando desconhecido: %s\n", cmd);
        }
    }

    return 0;
}
