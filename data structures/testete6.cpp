#include<bits/stdc++.h>
using namespace std;

typedef struct vertice
{
    char valor;
    struct vertice *filho_esq;
    struct vertice *irmao_dir;
}*Vertice;

typedef struct arvore{
    Vertice raiz;
    int grau;
    int profundidade;
}Arvore;

void inicializa(Arvore *arvore){
    arvore->raiz=NULL;
    arvore->grau=0;
    arvore->profundidade=-1;
}

void buffer(){
    int c;
    while ((c=getchar()) != '\n' && c!=EOF);
    
}

Vertice criar_vertice(char valor){
    Vertice vertice = (Vertice)malloc(sizeof(struct vertice));

    vertice->valor=valor;
    vertice->filho_esq=NULL;
    vertice->irmao_dir=NULL;

    return vertice;

}

void criar_filhos(Vertice pai, int qtd_filhos){
    printf("\nLeitura dos filhos de : %c\n", pai->valor);
    printf("Filho = ");
    char valor = getchar();
    buffer();
    pai->filho_esq = criar_vertice(valor);
    Vertice filho_atual = pai->filho_esq;

    for(int i=2; i<=qtd_filhos; i++){
        printf("Filho = ");
        valor = getchar();
        buffer();
        Vertice novo_filho = criar_vertice(valor);
        filho_atual->irmao_dir=novo_filho;
        filho_atual = filho_atual->irmao_dir;
    }

}

void criar_arvore(Arvore *arvore, Vertice pai){
    int qtd_filhos;
    printf("\n\nDigire o numero de filhos do vertice %c: ", pai->valor);
    scanf("%d", qtd_filhos);
    buffer();
    if(qtd_filhos<=0){
        return;
    }

    if(qtd_filhos > arvore->grau){
        arvore->grau=qtd_filhos;
    }

    arvore->profundidade++;
    criar_filhos(pai, qtd_filhos);
    Vertice filho = pai->filho_esq;
    while(filho!=NULL){
        criar_arvore(arvore,filho);
        filho = filho->irmao_dir;
    }
}

void ler_arvore(Arvore *arvore){
    printf("Raiz: ");
    char valor = getchar();
    buffer();
    Vertice raiz = criar_vertice(valor);
    arvore->raiz=raiz;
    criar_arvore(arvore, arvore->raiz);
}

void mostrar_arvore(Vertice raiz, int nivel){
    if(raiz=NULL){
        return;
    }

    printf(" ");

    for(int i=0; i<=nivel*2; i++){
        printf("--");
    }
    printf("%c\n", raiz->valor);
    Vertice filho = raiz-> filho_esq;
    nivel++;

    while(filho != NULL){
        mostrar_arvore(filho,nivel);
        filho=filho->irmao_dir;
    }

}

void percorrer_preordem(Vertice raiz){
    if(raiz=NULL){
        return;
    }
    printf("%c", raiz->valor);

    percorrer_preordem(raiz->filho_esq);
    percorrer_preordem(raiz->irmao_dir);

}

void percorrer_posordem(Vertice raiz){
    if(raiz==NULL){
        return;
    }
    percorrer_posordem(raiz->filho_esq);
    printf("%c", raiz->valor);
    percorrer_preordem(raiz->irmao_dir);

}

int pot(int base, int exp){
    int res=1;
    for(int i=0; i<exp; i++){
        res*=base;
    }
    return res;
}

void percorrer_nivel(Arvore arvore, Vertice raiz){
    if(raiz==NULL){
        return;
    }

    Vertice vertice_atual=raiz;
    int tam_fila=(pot(arvore.grau,arvore.profundidade+1)-1)/(arvore.grau-1);
    Vertice *fila_filhos=(Vertice*)malloc(sizeof(Vertice)*tam_fila);
    int final_fila=-1;
    while(vertice_atual!=NULL){
        printf("%c ", vertice_atual->valor);
        if(vertice_atual->filho_esq!=NULL){
            fila_filhos[++final_fila]=vertice_atual->filho_esq;
        }
        vertice_atual = vertice_atual->irmao_dir;

    }

    for(int i=0 ;i< final_fila;i++){
        percorrer_nivel(arvore,fila_filhos[i]);
    }

    free(fila_filhos);

}


int main (){
    Arvore arvore;

    printf("Leitura dos vertices da arvore:\n");
    ler_arvore(&arvore);

    printf("\n\nArvore criada:\n");
    mostrar_arvore(arvore.raiz, 0);

    printf("\nGrau: %d",arvore.grau);
    printf("\nProfundidade: %d", arvore.profundidade);

    printf("\nPercurso em pre-ordem: ");
    percorrer_preordem(arvore.raiz);
    printf("\nPercurso em pos-ordem: ");
    percorrer_posordem(arvore.raiz);
    printf("\nPercurso por nivel: ");
    percorrer_nivel(arvore, arvore.raiz);
    
    return 0;

}