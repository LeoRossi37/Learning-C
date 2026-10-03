#include<bits/stdc++.h>
using namespace std;

typedef struct vertice {
	int valor;
	struct vertice *esq;
	struct vertice *dir;
} *Arvore;


// Inicializa a árvore como vazia
void inicializar_arvore(Arvore *arvore) {
	*arvore = NULL;
}

// Limpa o buffer de entrada do teclado
void limpar_buffer() {
	int c;
	while ((c = getchar()) != '\n' && c != EOF);
}

// Cria um vértice com valor informado e ponteiros nulos
Arvore criar_vertice(int valor) {
	Arvore vertice = (Arvore) malloc(sizeof(struct vertice));

	if (vertice == NULL) {
		printf("Erro de alocação!\n");
    	exit(1);
	}

	vertice->valor = valor;        // Atribui o valor ao vértice

	vertice->esq = NULL;      // Inicializa ponteiros como NULL
	vertice->dir = NULL;

	return vertice;                // Retorna o vértice criado
}

void criar_arvore(Arvore *arvore) {
	Arvore pai = *arvore;

	char tem_filho;
	
	printf("\n\nO vértice %d possui filho? (s = sim): ", pai->valor);
	scanf(" %c", &tem_filho);
	limpar_buffer(); // Limpa buffer após scanf

	if (tem_filho != 's') {
		return;
	}
	
	
	int valor_filho;

	printf("\nLeitura dos filhos de %d\n", pai->valor);
	
	printf("Entre com o filho da esquerda (-1 para nulo): ");
	scanf("%d", &valor_filho);

	if (valor_filho != -1) {
		pai->esq = criar_vertice(valor_filho);
	}


	printf("Entre com o filho da direita (-1 para nulo): ");
	scanf("%d", &valor_filho);

	if (valor_filho != -1) {
		pai->dir = criar_vertice(valor_filho);
	}


	if (pai->esq != NULL) {
		criar_arvore(&pai->esq);
	}

	if (pai->dir != NULL) {
		criar_arvore(&pai->dir);
	}
}

void ler_arvore(Arvore *arvore) {
	int valor;

	printf("\nDigite o valor da raiz = ");
	scanf("%d", &valor);
	
	// Cria o vértice da raiz e guarda na árvore
	*arvore = criar_vertice(valor);

	// Cria o restante da árvore
	criar_arvore(arvore);
}

void mostrar_arvore(Arvore arvore, int nivel, char *rotulo) {
	if (arvore == NULL) { // Se o vértice não existir, retorna
		return;
	}

	printf(" ");

	// Imprime indentação de acordo com o nível do vértice
	for (int i = 0; i <= nivel * 3; i++) {
		printf("--");
	}

	printf("%d (%s)\n", arvore->valor, rotulo); // Mostra o valor do vértice

	nivel += 1; // Incrementa nível para os filhos

	// Exibe filhos recursivamente
	if (arvore->esq != NULL) {
		mostrar_arvore(arvore->esq, nivel, "esq");
	}

	if (arvore->dir != NULL) {
		mostrar_arvore(arvore->dir, nivel, "dir");
	}
}

void percorrer_pre_ordem(Arvore arvore) {
	if (arvore == NULL) {
		return;
	}
	
	printf("%d ", arvore->valor);
	percorrer_pre_ordem(arvore->esq);
	percorrer_pre_ordem(arvore->dir);
}

void percorrer_em_ordem(Arvore arvore) {
	if (arvore == NULL) {
		return;
	}

	percorrer_em_ordem(arvore->esq);
	printf("%d ", arvore->valor);
	percorrer_em_ordem(arvore->dir);
}

void percorrer_pos_ordem(Arvore arvore) {
	if (arvore == NULL) {
		return;
	}

	percorrer_pos_ordem(arvore->esq);
	percorrer_pos_ordem(arvore->dir);
	printf("%d ", arvore->valor);
}

int buscar(Arvore arvore, int valor) {
	if (arvore == NULL) {
		return 0;
	}

	if (arvore->valor == valor) {
		return 1;
	}

	return buscar(arvore->esq, valor) || buscar(arvore->dir, valor);
}


int main() {
	Arvore arvore;
	int valor_busca;

	inicializar_arvore(&arvore);
	
	printf("Leitura da Arvore");
	ler_arvore(&arvore);

	printf("\nÁrvore binária criada: \n");
	mostrar_arvore(arvore, 0, "raiz");

	printf("\n\n");
	printf("Percurso em pré-ordem: ");
	percorrer_pre_ordem(arvore);

	printf("\n\nPercurso em em-ordem: ");
	percorrer_em_ordem(arvore);

	printf("\n\nPercurso em pós-ordem: ");
	percorrer_pos_ordem(arvore);

	printf("\n\nBusca\n");
	printf("Digite um valor para verificar se está na árvore: ");
	scanf("%d", &valor_busca);

	if (buscar(arvore, valor_busca)) {
		printf("O valor %d está na árvore!\n", valor_busca);
	} else {
		printf("O valor %d não está na árvore!\n", valor_busca);
	}

	return 0;
}