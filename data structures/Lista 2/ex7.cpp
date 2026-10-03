#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TIPO_REDE     1
#define TIPO_SOFTWARE 2
#define TIPO_HARDWARE 3

typedef struct {
    char setor[128];
    char ramal[32];
} ChamadoRede;

typedef struct {
    char usuario[128];
    char programa[128];
} ChamadoSoftware;

typedef struct {
    char patrimonio[64];
    char defeito[256];
} ChamadoHardware;

typedef union {
    ChamadoRede     rede;
    ChamadoSoftware software;
    ChamadoHardware hardware;
} DadosChamado;


typedef struct no {
    int tipo;
    DadosChamado dados;
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

int enfileirar(Fila *f, int tipo, DadosChamado dados) {
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

int desenfileirar(Fila *f, int *tipo, DadosChamado *dados) {
    if (esta_vazia(*f)) return 0;

    No p    = f->inicio;
    *tipo   = p->tipo;
    *dados  = p->dados;
    f->inicio = p->prox;
    free(p);

    if (f->inicio == NULL) f->final = NULL;

    f->tamanho--;
    return 1;
}


void exibir_chamado(int tipo, DadosChamado dados) {
    switch (tipo) {
        case TIPO_REDE:
            printf("REDE: setor=%s, ramal=%s",
                   dados.rede.setor, dados.rede.ramal);
            break;
        case TIPO_SOFTWARE:
            printf("SOFTWARE: usuario=%s, programa=%s",
                   dados.software.usuario, dados.software.programa);
            break;
        case TIPO_HARDWARE:
            printf("HARDWARE: patrimonio=%s, defeito=%s",
                   dados.hardware.patrimonio, dados.hardware.defeito);
            break;
        default:
            printf("(tipo desconhecido)");
    }
}


void cmd_add_rede(Fila *f, const char *setor, const char *ramal) {
    DadosChamado d;
    strncpy(d.rede.setor, setor, 127); d.rede.setor[127] = '\0';
    strncpy(d.rede.ramal, ramal,  31); d.rede.ramal[31]  = '\0';

    if (enfileirar(f, TIPO_REDE, d)) {
        printf("Chamado de REDE adicionado (setor=%s, ramal=%s).\n", setor, ramal);
    } else {
        printf("Erro: memoria insuficiente.\n");
    }
}

void cmd_add_software(Fila *f, const char *usuario, const char *programa) {
    DadosChamado d;
    strncpy(d.software.usuario,  usuario,  127); d.software.usuario[127]  = '\0';
    strncpy(d.software.programa, programa, 127); d.software.programa[127] = '\0';

    if (enfileirar(f, TIPO_SOFTWARE, d)) {
        printf("Chamado de SOFTWARE adicionado (usuario=%s, programa=%s).\n",
               usuario, programa);
    } else {
        printf("Erro: memoria insuficiente.\n");
    }
}

void cmd_add_hardware(Fila *f, const char *patrimonio, const char *defeito) {
    DadosChamado d;
    strncpy(d.hardware.patrimonio, patrimonio, 63);  d.hardware.patrimonio[63]  = '\0';
    strncpy(d.hardware.defeito,    defeito,    255); d.hardware.defeito[255]    = '\0';

    if (enfileirar(f, TIPO_HARDWARE, d)) {
        printf("Chamado de HARDWARE adicionado (patrimonio=%s, defeito=%s).\n",
               patrimonio, defeito);
    } else {
        printf("Erro: memoria insuficiente.\n");
    }
}

void cmd_atender(Fila *f) {
    if (esta_vazia(*f)) {
        printf("Nenhum chamado na fila.\n");
        return;
    }

    int tipo;
    DadosChamado dados;
    desenfileirar(f, &tipo, &dados);

    printf("Atendendo chamado de ");
    exibir_chamado(tipo, dados);
    printf("\n");
}

void cmd_status(Fila f) {
    if (esta_vazia(f)) {
        printf("Fila vazia.\n");
        return;
    }

    printf("Fila atual (%d chamado(s)):\n", f.tamanho);
    No aux = f.inicio;
    int i = 1;
    while (aux != NULL) {
        printf("  %d. ", i);
        exibir_chamado(aux->tipo, aux->dados);
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
    int n_tokens;

    printf("=== Central de Atendimento Tecnico ===\n");
    printf("Comandos:\n");
    printf("  add rede <setor> <ramal>\n");
    printf("  add software <usuario> <programa>\n");
    printf("  add hardware <patrimonio> <defeito>\n");
    printf("  atender | status | sair\n\n");

    while (1) {
        printf("> ");
        if (fgets(linha, sizeof(linha), stdin) == NULL) break;

        size_t len = strlen(linha);
        if (len > 0 && linha[len - 1] == '\n') linha[len - 1] = '\0';

        /* Tokeniza */
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
            if (n_tokens < 2) {
                printf("Uso: add <rede|software|hardware> ...\n");
                continue;
            }
            if (strcmp(tokens[1], "rede") == 0) {
                if (n_tokens < 4) { printf("Uso: add rede <setor> <ramal>\n"); continue; }
                cmd_add_rede(&fila, tokens[2], tokens[3]);
            } else if (strcmp(tokens[1], "software") == 0) {
                if (n_tokens < 4) { printf("Uso: add software <usuario> <programa>\n"); continue; }
                cmd_add_software(&fila, tokens[2], tokens[3]);
            } else if (strcmp(tokens[1], "hardware") == 0) {
                if (n_tokens < 4) { printf("Uso: add hardware <patrimonio> <defeito>\n"); continue; }
                cmd_add_hardware(&fila, tokens[2], tokens[3]);
            } else {
                printf("Tipo desconhecido: %s\n", tokens[1]);
            }
        } else if (strcmp(tokens[0], "atender") == 0) {
            cmd_atender(&fila);
        } else if (strcmp(tokens[0], "status") == 0) {
            cmd_status(fila);
        } else {
            printf("Comando desconhecido: %s\n", tokens[0]);
        }
    }

    return 0;
}
