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

int inserir(Arvore *arvore, int valor) {
	if (*arvore == NULL) {
		*arvore = criar_vertice(valor);
		return 1;
	}

	if (valor == (*arvore)->valor) {
		return 0;
	}

	if (valor > (*arvore)->valor) {
		return inserir(&(*arvore)->dir, valor);
	} else {
		return inserir(&(*arvore)->esq, valor);
	}
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

void percorrer_em_ordem(Arvore arvore) {
	if (arvore == NULL) {
		return;
	}

	percorrer_em_ordem(arvore->esq);
	printf("%d ", arvore->valor);
	percorrer_em_ordem(arvore->dir);
}

int buscar(Arvore arvore, int valor) {
	if (arvore == NULL) {
		return 0;
	}

	if (valor == arvore->valor) {
		return 1;
	}

	if (valor > arvore->valor) {
		return buscar(arvore->dir, valor);
	} else {
		return buscar(arvore->esq, valor);
	}
}

int remover_iterativo_tipo1(Arvore *arvore, int valor) {

    // Ponteiros para o nó atual e seu pai
    Arvore atual = *arvore;	
    Arvore pai = NULL;

    // Busca iterativa pelo valor
    while (atual != NULL && atual->valor != valor) {
        pai = atual;

        if (valor < atual->valor) {
            atual = atual->esq;
        } else {
            atual = atual->dir;
        }
    }

    // Se não encontrou o valor
    if (atual == NULL) {
        return 0;
    }

    // Nó que substituirá o removido
    Arvore substituto = NULL;

    // Auxiliares para encontrar o predecessor
    Arvore pai_pred, pred;

    // Determinar o substituto
    // CASO 1: sem filho à esquerda
    if (atual->esq == NULL) {
        substituto = atual->dir;
    }

    // CASO 2: sem filho à direita
    else if (atual->dir == NULL) {
        substituto = atual->esq;
    }

    // CASO 3: dois filhos
    else {
        // Predecessor = maior da subárvore esquerda
        pai_pred = atual;
        pred = atual->esq;

        while (pred->dir != NULL) {
            pai_pred = pred;
            pred = pred->dir;
        }

        // Se o predecessor não é filho direto
        if (pai_pred != atual) {
            // Remove o predecessor da posição original
            pai_pred->dir = pred->esq;

            // Predecessor assume a subárvore esquerda
            pred->esq = atual->esq;
        }

        // Predecessor assume a subárvore direita
        pred->dir = atual->dir;
        substituto = pred;
    }

    // Reconectar com o pai
    // Remoção da raiz
    if (pai == NULL) {
        *arvore = substituto;
    } else {
        if (atual == pai->esq) {
            pai->esq = substituto;
		}
        else {
            pai->dir = substituto;
		}
    }

    // Libera o nó removido
    free(atual);

    return 1;
}

Arvore retornar_predecessor_em_ordem(Arvore arvore) {
	Arvore pred = arvore->esq;

	while (pred->dir != NULL) {
		pred = pred->dir;
	}

	return pred;
}

Arvore remover_recursivo_tipo1(Arvore *arvore, int valor) {

	// Caso base: árvore (ou subárvore) vazia
	if (*arvore == NULL) {
		return NULL;
	}

	// Encontrou o nó que deve ser removido
	if (valor == (*arvore)->valor) {

		// CASO 1: nó folha (sem filhos)
		// Basta liberar a memória e retornar NULL para o pai
		if ((*arvore)->esq == NULL && (*arvore)->dir == NULL) {
			free(*arvore);
			return NULL;
		}

		// CASO 2: possui apenas filho à direita
		// O filho direito "sobe" para o lugar do nó removido
		if ((*arvore)->esq == NULL) {
			Arvore filho_dir = (*arvore)->dir;
			free(*arvore);
			return filho_dir;
		}

		// CASO 3: possui apenas filho à esquerda
		// O filho esquerdo "sobe" para o lugar do nó removido
		if ((*arvore)->dir == NULL) {
			Arvore filho_esq = (*arvore)->esq;
			free(*arvore);
			return filho_esq;
		}

		// CASO 4: possui dois filhos
		// Estratégia: substituir pelo predecessor em ordem
		// (maior valor da subárvore esquerda)
		Arvore pred = retornar_predecessor_em_ordem(*arvore);

		// Copia o valor do predecessor para o nó atual
		(*arvore)->valor = pred->valor;

		// Remove o predecessor da subárvore esquerda
		// (ele estará duplicado após a cópia)
		(*arvore)->esq = remover_recursivo_tipo1(&(*arvore)->esq, pred->valor);
	}

	// Se o valor procurado é maior, continua na subárvore direita
	else if (valor > (*arvore)->valor) {
		(*arvore)->dir = remover_recursivo_tipo1(&(*arvore)->dir, valor);
	}

	// Se o valor procurado é menor, continua na subárvore esquerda
	else {
		(*arvore)->esq = remover_recursivo_tipo1(&(*arvore)->esq, valor);
	}

	// Retorna a raiz atual da subárvore (possivelmente atualizada)
	return *arvore;
}

Arvore retornar_sucessor_em_ordem(Arvore arvore) {
	Arvore sucessor = arvore->dir;

	while (sucessor->esq != NULL) {
		sucessor = sucessor->esq;
	}

	return sucessor;
}

Arvore remover_recursivo_tipo2(Arvore *arvore, int valor) {

	// Caso base: árvore (ou subárvore) vazia
	if (*arvore == NULL) {
		return NULL;
	}

	// Encontrou o nó que deve ser removido
	if (valor == (*arvore)->valor) {

		// CASO 1: nó folha (sem filhos)
		// Basta liberar a memória e retornar NULL para o pai
		if ((*arvore)->esq == NULL && (*arvore)->dir == NULL) {
			free(*arvore);
			return NULL;
		}

		// CASO 2: possui apenas filho à direita
		// O filho direito "sobe" para o lugar do nó removido
		if ((*arvore)->esq == NULL) {
			Arvore filho_dir = (*arvore)->dir;
			free(*arvore);
			return filho_dir;
		}

		// CASO 3: possui apenas filho à esquerda
		// O filho esquerdo "sobe" para o lugar do nó removido
		if ((*arvore)->dir == NULL) {
			Arvore filho_esq = (*arvore)->esq;
			free(*arvore);
			return filho_esq;
		}

		// CASO 4: possui dois filhos
		// Estratégia: substituir pelo sucessor em ordem
		// (menor valor da subárvore direita)
		Arvore sucessor = retornar_sucessor_em_ordem(*arvore);

		// Copia o valor do sucessor para o nó atual
		(*arvore)->valor = sucessor->valor;

		// Remove o sucessor da subárvore direita
		// (ele estará duplicado após a cópia)
		(*arvore)->dir = remover_recursivo_tipo2(&(*arvore)->dir, sucessor->valor);
	}

	// Se o valor procurado é maior, continua na subárvore direita
	else if (valor > (*arvore)->valor) {
		(*arvore)->dir = remover_recursivo_tipo2(&(*arvore)->dir, valor);
	}

	// Se o valor procurado é menor, continua na subárvore esquerda
	else {
		(*arvore)->esq = remover_recursivo_tipo2(&(*arvore)->esq, valor);
	}

	// Retorna a raiz atual da subárvore (possivelmente atualizada)
	return *arvore;
}

int remover_recursivo(Arvore *arvore, int valor, int tipo) {
	if (!buscar(*arvore, valor)) {
		return 0;
	}

	if (tipo == 1) {
		*arvore = remover_recursivo_tipo1(arvore, valor);
	} else {
		*arvore = remover_recursivo_tipo2(arvore, valor);
	}

	return 1;
}


int main() {
	Arvore arvore;
	int valor;

	inicializar_arvore(&arvore);

	printf("Leitura da Arvore");

	do {
		printf("\nDigite um valor para inserir na árvore (-1 para parar): ");
		scanf("%d", &valor);

		if (valor != -1) {
			if (inserir(&arvore, valor)) {
				printf("\n\nÁrvore binária criada: \n");
				mostrar_arvore(arvore, 0, "raiz");
			} else {
				printf("Valor já existe na árvore!\n");
			}
		}
	
	} while (valor != -1);


	printf("\n\nPercurso em ordem: \n");
	percorrer_em_ordem(arvore);


	printf("\n\n\nBusca\n");
	printf("Digite um valor para verificar se está na árvore: ");
	scanf("%d", &valor);

	if (buscar(arvore, valor)) {
		printf("O valor %d está na árvore!\n", valor);
	} else {
		printf("O valor %d não está na árvore!\n", valor);
	}

	
	int tipo_remocao;

	printf("\n\nRemocao Iterativa de valores");

	do {
		printf("\nDigite o valor que deseja remover (-1 para parar): ");
		scanf("%d", &valor);

		if (valor != -1) {
			if (!remover_iterativo_tipo1(&arvore, valor)) {
				printf("Valor %d não está na árvore!\n", valor);
			} else {
				printf("Valor %d removido!\n", valor);

				printf("\n\nÁrvore binária criada: \n");
				mostrar_arvore(arvore, 0, "raiz");
			}
		}
	
	} while(valor != -1);
	

	printf("\n\nRemocao Recursiva de valores\n");
	printf("Selecione o tipo de remoção:\n");

	printf("\t1- Predecessor em ordem (maior valor na subárvore esquerda)\n");
	printf("\t2- Sucessor em ordem (menor valor na subárvore direita)\n");

	printf("Opção selecionada: ");
	scanf("%d", &tipo_remocao);

	do {
		printf("\nDigite o valor que deseja remover da árvore (-1 para parar): ");
		scanf("%d", &valor);

		if (valor != -1) {
		
			if (tipo_remocao != 1 && tipo_remocao != 2) {
				printf("Tipo de remoção inválido!\n");
				break;
			}

			if (!remover_recursivo(&arvore, valor, tipo_remocao)) {
				printf("Valor %d não está na árvore!\n", valor);
			} else {
				printf("Valor %d removido!\n", valor);

				printf("\n\nÁrvore binária criada: \n");
				mostrar_arvore(arvore, 0, "raiz");
			}
		
		}
	
	} while (valor != -1);

	return 0;
}