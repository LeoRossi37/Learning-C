#include <bits/stdc++.h>
using namespace std;

#define TIPO_INT 1
#define TIPO_CHAR 2
#define TIPO_FLOAT 3

typedef union {
	int item_int;
	char item_char;
	float item_float;
} Item;

typedef struct node {
	int tipo_item;
	Item item;
	struct node *prox;
} *No;

typedef struct queue {
	No inicio, final;
	int tamanho;
} Fila;


void inicializar_fila(Fila *fila) {
	fila->inicio = fila->final = NULL;
	fila->tamanho = 0;
}

int esta_vazia(Fila fila) {
	return fila.inicio == NULL;
}

int enfileirar(Fila *fila, int tipo_item, Item item) {
	No no = (No) malloc(sizeof(struct node));

	if (no == NULL) {
		return 0;
	}

	no->tipo_item = tipo_item;
	no->item = item;
	no->prox = NULL;

	if (fila->inicio == NULL) {
		fila->inicio = no;
	} else {
		fila->final->prox = no;
	}

	fila->final = no;
	fila->tamanho++;

	return 1;
}

int desenfileirar(Fila *fila, int *tipo_item, Item *item) {
	if (esta_vazia(*fila)) {
		return 0;
	}

	*tipo_item = fila->inicio->tipo_item;
	*item = fila->inicio->item;

	No p = fila->inicio;
	fila->inicio = p->prox;
	free(p);

	if (fila->inicio == NULL) {
		fila->final = NULL;
	}

	fila->tamanho--;

	return 1;
}

int espiar(Fila fila, int *tipo_item, Item *item_inicio) {
	if (esta_vazia(fila)) {
		return 0;
	}

	*tipo_item = fila.inicio->tipo_item;
	*item_inicio = fila.inicio->item;

	return 1;
}

void mostrar_item(int tipo_item, Item item) {
	switch (tipo_item) {
		case TIPO_INT:
			printf("%d ", item.item_int);
			break;
		case TIPO_CHAR:
			printf("%c ", item.item_char);
			break;
		case TIPO_FLOAT:
			printf("%.2f ", item.item_float);
			break;
		default:
			printf("Tipo inválido!\n");
	}
}

void mostrar_fila(Fila fila) {
	if (esta_vazia(fila)) {
		printf("A fila está vazia\n");
		return;
	}

	printf("A fila tem %d itens: ", fila.tamanho);

	No p = fila.inicio;

	while(p != NULL) {
		mostrar_item(p->tipo_item, p->item);
		p = p->prox;
	}

	printf("\n");
}

void limpar_buffer_entrada() {
	int temp;
	while((temp = getchar()) != '\n' && temp != EOF);
}


int main() {
	Fila fila;
	int tipo_item;
	Item item;

	inicializar_fila(&fila);

	char parar = 'n';

	do {
		printf("Digite o tipo do item (1 para int, 2 para char, 3 para float): ");
		scanf("%d", &tipo_item);
		limpar_buffer_entrada();

		printf("Digite o item: ");

		switch (tipo_item) {
			case TIPO_INT:
				scanf("%d", &item.item_int);
				break;
			case TIPO_CHAR:
				item.item_char = getchar();
				break;
			case TIPO_FLOAT:
				scanf("%f", &item.item_float);
				break;
			default:
				printf("Tipo inválido!\n");
		}
		
		limpar_buffer_entrada();

		int enfileirado = enfileirar(&fila, tipo_item, item);

		if (!enfileirado) {
			printf("Memória insuficiente!\n");
		}

		printf("Item enfileirado: ");
		mostrar_item(tipo_item, item);
		printf("\n");

		mostrar_fila(fila);

		printf("Deseja parar? (n para não, qualquer outra tecla para sim)? ");
		parar = getchar();
	} while(parar == 'n');

	espiar(fila, &tipo_item, &item);
	printf("O primeiro item da fila é: ");
	mostrar_item(tipo_item, item);
	printf("\n");

	while (!esta_vazia(fila)) {
		desenfileirar(&fila, &tipo_item, &item);
		printf("Item desenfileirado: ");
		mostrar_item(tipo_item, item);
		printf("\n");

		mostrar_fila(fila);
	}

	printf("Todos os itens foram desenfileirados!\n");
	
	return 0;
}