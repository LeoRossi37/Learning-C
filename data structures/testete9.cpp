#include<bits/stdc++.h>
using namespace std;

typedef struct vertice{
    int valor;
    struct vertice *esq;
    struct vertice *dir;
}*Arvore;

void inicializar_arvore(Arvore arvore){
    *arvore=NULL;
}

void buffer(){
    char c;
    while((c=getchar())!='\n' && c!=EOF);
}

Arvore criar_vertice(int valor){
    Arvore vertice= (Arvore)malloc(sizeof(struct vertice));
    if(vertice==NULL){
        printf("Erro de alocação!\n");
        exit(1);
    }
    vertice->valor=valor;
    vertice->dir=NULL;
    vertice->esq=NULL;
    return vertice;
}

int inserir(Arvore *arvore, int valor){
    if(*arvore==NULL){
        *arvore=criar_vertice(valor);
        return 1;
    }
    if(valor==(*arvore)->valor){
        return 0;
    }
    if(valor > (*arvore)->valor){
        return inserir(&(*arvore)->dir,valor);
    }else{
        return inserir(&(*arvore)->esq, valor);
    }
}

void mostrar_arvore(Arvore arvore, int nivel, char *rotulo){
    if(arvore==NULL){
        return;
    }
    printf("%d (%s)", arvore->valor, rotulo);
    nivel++;
    if(arvore->esq!=NULL){
        mostrar_arvore(arvore->esq, nivel , "esq");

    }
    if(arvore->dir!=NULL){
        mostrar_arvore(arvore->dir, nivel, "dir");
    }
}

void percorrer_em_ordem(Arvore arvore){
    if(arvore==NULL){
        return;
    }
    percorrer_em_ordem(arvore->esq);
    printf("%d", arvore->valor);
    percorrer_em_ordem(arvore->dir);
}
void percorrer_pre_ordem(Arvore arvore){
    if(arvore==NULL){
        return;
    }
    printf("%d", arvore->valor);
    percorrer_pre_ordem(arvore->esq);
    percorrer_pre_ordem(arvore->dir);
}
void percorrer_pos_ordem(Arvore arvore){
    if(arvore==NULL){
        return;
    }
    percorrer_pos_ordem(arvore->esq);
    percorrer_pos_ordem(arvore->dir);
    printf("%d", arvore->valor);
}

int buscar(Arvore arvore, int valor){
    if(arvore==NULL){
        return 0;
    }
    if(arvore->valor==valor){
        return 1;
    }
    if(arvore->valor>valor){
        return buscar(arvore->esq, valor);
    }else{
        return buscar(arvore->dir, valor);
    }
    
}

int remover_iterativo1(Arvore *arvore, int valor){
    Arvore atual= *arvore;
    Arvore pai = NULL;
    while(atual!=NULL && atual->valor !=valor){
        pai=atual;
        if(atual->valor>valor){
            atual=atual->esq;
        }else{
            atual=atual->dir;
        }
    }
    if(atual==NULL){
        return 0;
    }

    Arvore sub =NULL;
    Arvore pai_pred, pred;
    if(atual->esq==NULL){
        sub=atual->dir;
    }
    else if(atual->dir==NULL){
        sub=atual->esq;
    }
    else{
        pai_pred=atual;
        pred=atual->esq;
        while(pred->dir!=NULL){
            pai_pred=pred;
            pred=pred->dir;
        }
        if(pai_pred!=atual){
            pai_pred->dir=pred->esq;
            pred->esq=atual->esq;
        }
        pred->dir=atual->dir;
        sub=pred;
    }
    if(pai==NULL){
        *arvore=sub;
    }else{
        if(atual==pai->esq){
            pai->esq=sub;
        }else{
            pai->dir=sub;
        }
    }
    free(atual);
    return 1;

}

Arvore retornar_pred_em_ordem(Arvore arvore){
    Arvore pred=arvore->esq;
    while(pred->dir!=NULL){
        pred=pred->dir;
    }
    return pred;
}

Arvore remover_recursivo1(Arvore *arvore, int valor){
    if(*arvore==NULL){
        return NULL;
    }
    if(valor==(*arvore)->valor){
        //nó folha
        if((*arvore)->esq==NULL && (*arvore)->dir==NULL){
            free(arvore);
            return NULL;
        }
        //filho a direita
        if((*arvore)->esq==NULL){
            Arvore filho_dir=(*arvore)->dir;
            free(*arvore);
            return filho_dir;
        }
        //filho a esquerda
        if((*arvore)->dir==NULL){
            Arvore filho_esq=(*arvore)->esq;
            free(*arvore);
            return filho_esq;
        }
        //2 filhos --> substitui pelo predecessor em ordem(maior da subarvore esq)
         Arvore pred=retornar_pred_em_ordem(*arvore);
         (*arvore)->valor=pred->valor;
         (*arvore)->esq=remover_recursivo1 (&(*arvore), valor);
         
    }else if(valor> (*arvore)->valor){
        (*arvore)->dir=remover_recursivo1(&(*arvore)->dir, valor);
    }else{
        (*arvore)->esq=remover_recursivo1(&(*arvore)-esq, valor);
    }
    return *arvore;
}

Arvore sucessor_em_ordem(Arvore arvore){
    Arvore sucessor=arvore->dir;
    while(sucessor->esq!=NULL){
        sucessor=sucessor->esq;
    }
    return sucessor;
}

Arvore remove_recursivo2(Arvore *arvore, int valor){
    if(*arvore == NULL){
        return NULL;
    }
    if(valor==(*arvore)->valor){
        //no folha
        if((*arvore)->dir==NULL && (*arvore)->esq==NULL){
            free(*arvore);
            return NULL;
        }
        //filho a direita
        if((*arvore)->esq==NULL){
            Arvore filho_dir=(*arvore)->dir;
            free(*arvore);
            return filho_dir;
        }
        //filho a esquerda
        if((*arvore)->dir==NULL){
            Arvore filho_esq=(*arvore)->esq;
            free(*arvore);
            return filho_esq;
        }
        Arvore sucessor=sucessor_em_ordem((*arvore));
        (*arvore)->valor=sucessor->valor;
        (*arvore)->dir=remove_recursivo2(&(*arvore)->dir, valor);
    }else if(valor>(*arvore)->valor){
        (*arvore)->dir=remove_recursivo2(&(*arvore)->dir,valor);
    }else{
        (*arvore)->esq=remove_recursivo2(&(*arvore)->esq, valor);
    }
    return *arvore;
}

int remover_recursivo(Arvore *arvore, int valor, int tipo){
    if(!buscar(*arvore, valor)){
        return 0;
    }
    if(tipo==1){
        remover_recursivo1(arvore, valor);
    }else{
        remove_recursivo2(arvore,valor);
    }
    return 1;
}

int main(){
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