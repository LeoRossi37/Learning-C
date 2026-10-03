#include <bits/stdc++.h>
using namespace std;

#define grau 3
#define max 30

typedef struct vertice{
    char valor;
    int qtd_filhos;
}Vertice;

typedef Vertice Arvore[max];

void inicializar(Arvore arvore){
    for(int i=0; i<max; i++){
        arvore[i].valor='-';
        arvore[i].qtd_filhos=0;
    }
}

void buffer(){
    int c;
    while((c=getchar())!= '\n' && c!=EOF);
}

void ler_arvore(Arvore arvore){
    int index_pai = 0;
    cout << "Raiz : ";
    arvore[index_pai].valor=getchar();
    buffer();
    int index_filho =1;
    while(index_filho<max && index_pai<max){
        if(arvore[index_pai].valor == '-'){
            index_pai++;
            continue;
        }
        printf("\n\n Digite o numero de filhos do vértice %c (Limite=%d): ", arvore[index_pai].valor, grau);
        scanf("%d", &arvore[index_pai].qtd_filhos);
        buffer();

        if(arvore[index_pai].qtd_filhos<=0){
            index_pai++;
            continue;
        }

        if(arvore[index_pai].qtd_filhos>grau){
            arvore[index_pai].qtd_filhos=grau;
        }
        printf("\nLeitura dos filhos de: %c\n", arvore[index_pai].valor);

        for(int i=0; i<arvore[index_pai].qtd_filhos; i++){
            if(index_filho>=max){
                arvore[index_pai].qtd_filhos=i;
                break;
            }
            printf("Filho = ");
            arvore[index_filho++].valor= getchar();
            buffer();

        }

        index_pai++;
        
    }
}

void mostrar_arvore(Arvore arvore){
    if(arvore[0].valor=='-'){
        printf("\n\n Arvore vazia");
        return;
    }
    

    int index_pai=0;
    int index_filho=1;

    printf("Raiz \t\t%c", arvore[index_pai].valor);
    while(index_pai < max && arvore[index_pai].valor != '-'){
        printf("\nFilhos de %c: ", arvore[index_pai].valor);
        if(arvore[index_pai].qtd_filhos == 0){
            printf(" sem filhos");
            index_pai++;
            continue;
        }

        for(int i=0; i<arvore[index_pai].qtd_filhos; i++){
            printf("\t%c", arvore[index_filho++].valor);
        }
        index_pai++;
    }
}

void mostrar_vetor(Arvore arvore){
    for(int i =0; i< max; i++){
        printf("Arvore[%2d]=%c (%d)\n", i, arvore[i].valor, arvore[i].qtd_filhos);
    }
}

void maior_valor(Arvore arvore){
    char maior = arvore[0].valor - '0';
    for(int i=1; i<max;i++){
        if(maior != '-' && maior<arvore[i].valor){
            maior=arvore[i].valor;
        }
    }
    printf("Maior : %c", maior);
}

void count_nos(Arvore arvore){
    if(arvore[0].valor=='-'){
        printf("\n\n Arvore vazia");
        return;
    }
    int count=0;
    int index_pai=0;
    int index_filho=1;
    while( arvore[index_pai].valor != '-'){
        if(arvore[index_pai].qtd_filhos != 0){
            index_pai++;
            count++;
            continue;
        }
            index_pai++;
        }
        cout << "\nNúmero de nós: " << count;
}

void qtd_nos_folha(Arvore arvore){
        if(arvore[0].valor=='-'){
        printf("\n\n Arvore vazia");
        return;
    }
    int count=0;
    int index_pai=0;
    int index_filho=1;
    while( arvore[index_pai].valor != '-'){
        if(arvore[index_pai].qtd_filhos == 0){
            index_pai++;
            count++;
            continue;
        }
            index_pai++;
        }
        cout << "\nNúmero de nós: " << count;
}
int main(){
    Arvore arvore;
    inicializar(arvore);

    printf("Leitura dos vertices da arvore: \n");
    ler_arvore(arvore);

    printf("\n\nArvore criada: \n");
    mostrar_arvore(arvore);

    printf("\n\nVetor que armazena a arvore: \n");
    mostrar_vetor(arvore);
    cout << "\n\n";
    maior_valor(arvore);
    count_nos(arvore);
    qtd_nos_folha(arvore);
}