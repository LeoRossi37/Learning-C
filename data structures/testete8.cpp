#include<bits/stdc++.h>
using namespace std;

typedef struct vertice{
    int valor;
    struct vertice *esq;
    struct vertice *dir;
}*Arvore;

void inicializar_arvore(Arvore *arvore){
    *arvore =NULL;
}

void buffer(){
    int c;
    while((c=getchar())!='\n' && c!=EOF);
}

Arvore criar_vertice(int valor){
    Arvore vertice = (Arvore)malloc(sizeof(struct vertice));
    if(vertice==NULL){
        printf("Erro de alocação\n");
        exit(1);
    }

    vertice->valor=valor;
    vertice->dir=NULL;
    vertice->esq=NULL;

    return vertice;
}

void criar_arvore(Arvore *arvore){
    Arvore pai = *arvore;
    char tem_filho;
    printf("\nO Vertice %d possui filho?(s-sim):", pai->valor);
    scanf(" %c", &tem_filho);
    buffer();
    if(tem_filho!='s'){
        return;
    }
    int valor_filho;
    printf("\nLeitura dos filhos de %d\n", pai->valor);
    printf("Digite o valor do filho da esquerda(-1 para nulo):");
    scanf("%d", &valor_filho);
    if(valor_filho!=-1){
        pai->esq=criar_vertice(valor_filho);
    }
    printf("Digite o valor do filho da direita(-1 para nulo):");
    scanf("%d", &valor_filho);
    if(valor_filho!=-1){
        pai->dir=criar_vertice(valor_filho);
    }
    if(pai->esq!=NULL){
        criar_arvore(&pai->esq);
    }
    
    if(pai->dir!=NULL){
        criar_arvore(&pai->dir);
    }
}

void ler_arvore(Arvore *arvore){
    int value;
    printf("Digite o valor a ser inserido na arvore:");
    scanf("%d", &value);
    *arvore=criar_vertice(value);
    criar_arvore(arvore);
}

void mostrar_arvore(Arvore arvore, int nivel, char *rotulo){
    if(arvore==NULL){
        return;
    }
    printf(" ");
    for(int i=0; i<=nivel; i++){
        printf("--");
    }

    printf("%d (%s)\n", arvore->valor,rotulo );
    nivel++;
    if(arvore->esq!=NULL){
        mostrar_arvore(arvore->esq,nivel,"esq");
    }
    
    if(arvore->dir!=NULL){
        mostrar_arvore(arvore->dir,nivel,"dir");
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

    return buscar(arvore->dir, valor) ||buscar(arvore->esq, valor);

}

int main(){
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

}