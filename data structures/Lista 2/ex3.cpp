#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no {
    char item[256];
    struct no *prox;
} *No;

typedef struct {
    No topo;
    int size;
} Pilha;

void inicializar(Pilha *p) {
    p->topo = NULL;
    p->size = 0;
}

int vazia(Pilha p) {
    return (p.topo == NULL);
}

int empilha(Pilha *p, const char *item) {
    No novo = (No) malloc(sizeof(struct no));
    if (novo == NULL) return 0;

    strncpy(novo->item, item, 255);
    novo->item[255] = '\0';
    novo->prox = p->topo;
    p->topo = novo;
    p->size++;

    return 1;
}

int desempilha(Pilha *p, char *item) {
    if (vazia(*p)) return 0;

    No temp = p->topo;
    strncpy(item, temp->item, 255);
    item[255] = '\0';

    p->topo = temp->prox;
    free(temp);
    p->size--;

    return 1;
}

int topo_pilha(Pilha p, char *item) {
    if (vazia(p)) return 0;
    strncpy(item, p.topo->item, 255);
    item[255] = '\0';
    return 1;
}
void inverter_pilha(Pilha *p) {
    Pilha aux;
    inicializar(&aux);
    char buf[256];

    while (!vazia(*p)) {
        desempilha(p, buf);
        empilha(&aux, buf);
    }
    while (!vazia(aux)) {
        desempilha(&aux, buf);
        empilha(p, buf);
    }
}

void simplificar_caminho(const char *caminho) {
    Pilha p;
    inicializar(&p);

    char copia[4096];
    strncpy(copia, caminho, 4095);
    copia[4095] = '\0';

    int absoluto = (copia[0] == '/');
    int erro = 0;

    char *token = strtok(copia, "/");
    while (token != NULL) {
        if (strcmp(token, ".") == 0) {
        } else if (strcmp(token, "..") == 0) {
            if (vazia(p)) {
                printf("Erro: caminho invalido (.. alem da raiz)\n");
                erro = 1;
                break;
            }
            char descartado[256];
            desempilha(&p, descartado);
        } else if (strlen(token) > 0) {
            empilha(&p, token);
        }
        token = strtok(NULL, "/");
    }

    if (erro) return;
    inverter_pilha(&p);
    if (absoluto) printf("/");

    int primeiro = 1;
    char buf[256];
    while (!vazia(p)) {
        desempilha(&p, buf);
        if (!primeiro) printf("/");
        printf("%s", buf);
        primeiro = 0;
    }
    printf("\n");
}

int main() {
    char caminho[4096];

    printf("=== Simplificador de Caminhos UNIX ===\n");
    printf("Digite o caminho (ou 'sair' para encerrar):\n");

    while (1) {
        printf("> ");
        if (fgets(caminho, sizeof(caminho), stdin) == NULL) break;

        /* Remove newline */
        size_t len = strlen(caminho);
        if (len > 0 && caminho[len - 1] == '\n') caminho[len - 1] = '\0';

        if (strcmp(caminho, "sair") == 0) break;
        if (strlen(caminho) == 0) continue;

        printf("Caminho simplificado: ");
        simplificar_caminho(caminho);
    }

    return 0;
}
