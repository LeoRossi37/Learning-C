#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no {
    char placa[32];
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

int enfileirar(Fila *f, const char *placa) {
    No novo = (No) malloc(sizeof(struct no));
    if (novo == NULL) return 0;

    strncpy(novo->placa, placa, 31);
    novo->placa[31] = '\0';
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

int desenfileirar(Fila *f, char *placa) {
    if (esta_vazia(*f)) return 0;

    No p = f->inicio;
    strncpy(placa, p->placa, 31);
    placa[31] = '\0';

    f->inicio = p->prox;
    free(p);

    if (f->inicio == NULL) f->final = NULL;

    f->tamanho--;
    return 1;
}

void cmd_chega(Fila *f, const char *dir, const char *placa) {
    if (enfileirar(f, placa)) {
        printf("Carro %s chegou na fila %s.\n", placa, dir);
    } else {
        printf("Erro: memoria insuficiente.\n");
    }
}

void cmd_abrir(Fila *f, const char *dir, int n) {
    if (esta_vazia(*f)) {
        printf("Fila %s esta vazia. Nenhum carro para passar.\n", dir);
        return;
    }

    printf("Abrindo sinal para %s: ", dir);
    char placa[32];
    int passaram = 0;

    while (passaram < n && !esta_vazia(*f)) {
        desenfileirar(f, placa);
        printf("%s ", placa);
        passaram++;
    }
    printf("\n");
    printf("%d carro(s) passaram pelo cruzamento %s.\n", passaram, dir);
}

void cmd_status(Fila ns, Fila lo) {
    printf("--- Status do cruzamento ---\n");

    printf("Norte-Sul (%d carro(s)): ", ns.tamanho);
    if (esta_vazia(ns)) {
        printf("vazia\n");
    } else {
        No aux = ns.inicio;
        while (aux != NULL) {
            printf("%s ", aux->placa);
            aux = aux->prox;
        }
        printf("\n");
    }

    printf("Leste-Oeste (%d carro(s)): ", lo.tamanho);
    if (esta_vazia(lo)) {
        printf("vazia\n");
    } else {
        No aux = lo.inicio;
        while (aux != NULL) {
            printf("%s ", aux->placa);
            aux = aux->prox;
        }
        printf("\n");
    }
}

int main() {
    Fila fila_ns, fila_lo;
    inicializar_fila(&fila_ns);
    inicializar_fila(&fila_lo);

    char linha[512];
    char cmd[64], dir[8], placa[32];
    int n;

    printf("=== Simulacao de Cruzamento ===\n");
    printf("Comandos:\n");
    printf("  chega NS <placa>  | chega LO <placa>\n");
    printf("  abrir NS <n>      | abrir LO <n>\n");
    printf("  status | sair\n\n");

    while (1) {
        printf("> ");
        if (fgets(linha, sizeof(linha), stdin) == NULL) break;

        size_t len = strlen(linha);
        if (len > 0 && linha[len - 1] == '\n') linha[len - 1] = '\0';

        if (sscanf(linha, "%63s", cmd) != 1) continue;

        if (strcmp(cmd, "sair") == 0) {
            break;
        } else if (strcmp(cmd, "chega") == 0) {
            if (sscanf(linha, "%*s %7s %31s", dir, placa) == 2) {
                if (strcmp(dir, "NS") == 0) {
                    cmd_chega(&fila_ns, "NS", placa);
                } else if (strcmp(dir, "LO") == 0) {
                    cmd_chega(&fila_lo, "LO", placa);
                } else {
                    printf("Direcao invalida. Use NS ou LO.\n");
                }
            } else {
                printf("Uso: chega <NS|LO> <placa>\n");
            }
        } else if (strcmp(cmd, "abrir") == 0) {
            if (sscanf(linha, "%*s %7s %d", dir, &n) == 2) {
                if (n <= 0) {
                    printf("Numero de carros deve ser positivo.\n");
                } else if (strcmp(dir, "NS") == 0) {
                    cmd_abrir(&fila_ns, "NS", n);
                } else if (strcmp(dir, "LO") == 0) {
                    cmd_abrir(&fila_lo, "LO", n);
                } else {
                    printf("Direcao invalida. Use NS ou LO.\n");
                }
            } else {
                printf("Uso: abrir <NS|LO> <n>\n");
            }
        } else if (strcmp(cmd, "status") == 0) {
            cmd_status(fila_ns, fila_lo);
        } else {
            printf("Comando desconhecido: %s\n", cmd);
        }
    }

    return 0;
}
