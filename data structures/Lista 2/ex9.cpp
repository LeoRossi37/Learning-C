#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


typedef struct tarefa {
    char nome[256];
    int  tempo;
} Tarefa;

typedef struct no {
    Tarefa item;
    struct no *ant;
    struct no *prox;
} *No;

typedef struct {
    No inicio, final;
    int tamanho;
} Deque;

void inicializar_deque(Deque *d) {
    d->inicio = d->final = NULL;
    d->tamanho = 0;
}

int deque_vazio(Deque d) {
    return (d.inicio == NULL);
}

int inserir_final(Deque *d, Tarefa item) {
    No novo = (No) malloc(sizeof(struct no));
    if (novo == NULL) return 0;

    novo->item = item;
    novo->prox = NULL;
    novo->ant  = d->final;

    if (d->final != NULL) {
        d->final->prox = novo;
    } else {
        d->inicio = novo;
    }

    d->final = novo;
    d->tamanho++;
    return 1;
}

int remover_inicio(Deque *d, Tarefa *item) {
    if (deque_vazio(*d)) return 0;

    No p  = d->inicio;
    *item = p->item;
    d->inicio = p->prox;

    if (d->inicio != NULL) {
        d->inicio->ant = NULL;
    } else {
        d->final = NULL;
    }

    free(p);
    d->tamanho--;
    return 1;
}

int inserir_inicio(Deque *d, Tarefa item) {
    No novo = (No) malloc(sizeof(struct no));
    if (novo == NULL) return 0;

    novo->item = item;
    novo->ant  = NULL;
    novo->prox = d->inicio;

    if (d->inicio != NULL) {
        d->inicio->ant = novo;
    } else {
        d->final = novo;
    }

    d->inicio = novo;
    d->tamanho++;
    return 1;
}

int remover_final(Deque *d, Tarefa *item) {
    if (deque_vazio(*d)) return 0;

    No p  = d->final;
    *item = p->item;
    d->final = p->ant;

    if (d->final != NULL) {
        d->final->prox = NULL;
    } else {
        d->inicio = NULL;
    }

    free(p);
    d->tamanho--;
    return 1;
}

int topo_pilha(Deque d, Tarefa *item) {
    if (deque_vazio(d)) return 0;
    *item = d.final->item;
    return 1;
}

int fila_enqueue(Deque *fila, Tarefa t)           { return inserir_final(fila, t); }
int fila_dequeue(Deque *fila, Tarefa *t)          { return remover_inicio(fila, t); }
int fila_enqueue_frente(Deque *fila, Tarefa t)    { return inserir_inicio(fila, t); }

/* --- Pilha de historico --- */
int pilha_push(Deque *hist, Tarefa t)             { return inserir_final(hist, t); }
int pilha_pop(Deque *hist, Tarefa *t)             { return remover_final(hist, t); }

void cmd_add(Deque *fila, const char *nome, int tempo) {
    if (tempo <= 0) { printf("Tempo deve ser positivo.\n"); return; }

    Tarefa t;
    strncpy(t.nome, nome, 255); t.nome[255] = '\0';
    t.tempo = tempo;

    if (fila_enqueue(fila, t)) {
        printf("Tarefa '%s' (%ds) adicionada a fila.\n", nome, tempo);
    } else {
        printf("Erro: memoria insuficiente.\n");
    }
}

void cmd_run(Deque *fila, Deque *hist) {
    if (deque_vazio(*fila)) {
        printf("Nenhuma tarefa na fila.\n");
        return;
    }

    Tarefa t;
    fila_dequeue(fila, &t);

    printf("Executando: %s (%ds)\n", t.nome, t.tempo);
    sleep(t.tempo);
    printf("(concluida)\n");

    pilha_push(hist, t);
}

void cmd_undo(Deque *fila, Deque *hist) {
    if (deque_vazio(*hist)) {
        printf("Historico vazio. Nada para desfazer.\n");
        return;
    }

    Tarefa t;
    pilha_pop(hist, &t);
    fila_enqueue_frente(fila, t);    /* volta ao INICIO da fila */
    printf("Tarefa \"%s\" retornou para a fila.\n", t.nome);
}

void cmd_status(Deque fila, Deque hist) {
    printf("--- Fila de tarefas (%d) ---\n", fila.tamanho);
    if (deque_vazio(fila)) {
        printf("  (vazia)\n");
    } else {
        No aux = fila.inicio;
        int i = 1;
        while (aux != NULL) {
            printf("  %d. %s (%ds)\n", i, aux->item.nome, aux->item.tempo);
            aux = aux->prox;
            i++;
        }
    }

    printf("--- Historico (%d) ---\n", hist.tamanho);
    if (deque_vazio(hist)) {
        printf("  (vazio)\n");
    } else {
        No aux = hist.final;
        int i = 1;
        while (aux != NULL) {
            printf("  %d. %s (%ds) [concluida]\n", i, aux->item.nome, aux->item.tempo);
            aux = aux->ant;
            i++;
        }
    }
}

int main() {
    Deque fila, hist;
    inicializar_deque(&fila);
    inicializar_deque(&hist);

    char linha[512];
    char cmd[64], nome[256];
    int tempo;

    printf("=== Simulador de Tarefas com Historico ===\n");
    printf("Comandos: add <nome> <tempo> | run | undo | status | sair\n\n");

    while (1) {
        printf("> ");
        if (fgets(linha, sizeof(linha), stdin) == NULL) break;

        size_t len = strlen(linha);
        if (len > 0 && linha[len - 1] == '\n') linha[len - 1] = '\0';

        if (sscanf(linha, "%63s", cmd) != 1) continue;

        if (strcmp(cmd, "sair") == 0) {
            break;
        } else if (strcmp(cmd, "add") == 0) {
            if (sscanf(linha, "%*s %255s %d", nome, &tempo) == 2) {
                cmd_add(&fila, nome, tempo);
            } else {
                printf("Uso: add <nome> <tempo>\n");
            }
        } else if (strcmp(cmd, "run") == 0) {
            cmd_run(&fila, &hist);
        } else if (strcmp(cmd, "undo") == 0) {
            cmd_undo(&fila, &hist);
        } else if (strcmp(cmd, "status") == 0) {
            cmd_status(fila, hist);
        } else {
            printf("Comando desconhecido: %s\n", cmd);
        }
    }

    

}
