#include<bits/stdc++.h>
using namespace std;

#define GRAU 3
#define MAX 30

typedef struct vertice
{
    char valor;
    int qtd_filhos;
}Vertice;

typedef Vertice Arvore[MAX];

void inicializar(Arvore arvore){
    for(int i=0; i< MAX ; i++){
        arvore[i].valor='-';
        arvore[i].qtd_filhos=0;
    }
}

void buffer(){
    int c;
    while((c=getchar())!= '\n' && c!=EOF);
}

void ler_arvore(Arvore arvore){
    int index_daddy=0;
    cout << "Raiz: ";
    arvore[index_daddy].valor=getchar();
    buffer();
    int index_filho=1;
    while(index_filho<MAX && index_daddy<MAX){
        if(arvore[index_daddy].valor == '-'){
            index_daddy++;
            continue;
        }
        cout << "\n\n Digite o numero de filhos do vertice " << arvore[index_daddy].valor  << " (Limite=" << GRAU << ")";
        cin  >> arvore[index_daddy].qtd_filhos;
        buffer();
        if(arvore[index_daddy].qtd_filhos<=0){
            index_daddy++;
            continue;
        }
        if(arvore[index_daddy].qtd_filhos>GRAU){
            arvore[index_daddy].qtd_filhos=GRAU;
        }

        cout << "\n Leitura dos filhos de : " << arvore[index_daddy].valor << endl;
        for(int i=0; i< arvore[index_daddy].qtd_filhos; i++){
            if(index_filho>=MAX){
                arvore[index_daddy].qtd_filhos=i;
                break;
            }
            printf("Filho = ");
            arvore[index_filho++].valor=getchar();
            buffer();
        }   
        index_daddy++;   

    }
}

void mostrar_vetor(Arvore arvore){
    for(int i=0 ;i<MAX; i++){
        printf("Arvore[%d]= %c (%d)", i, arvore[i].valor, arvore[i].qtd_filhos);
    }
}

void mostrar_arvore(Arvore arvore){
    if(arvore[0].valor=='-'){
        cout << "Árvore vazia!";
        return;
    }
    int index_daddy=0;
    int index_filho=1;
    printf("Raiz \t%c", arvore[index_daddy].valor);
    while(index_daddy<MAX && arvore[index_daddy].valor!='-'){
        printf("\nFilhos de %c: ", arvore[index_daddy].valor);
        if(arvore[index_daddy].qtd_filhos == 0){
            cout << " sem filhos!";
            index_daddy++;
            continue;
        }

        for(int i=0; i<arvore[index_daddy].qtd_filhos; i++){
            printf("\t%c", arvore[index_filho++].valor);

        }
        index_daddy++;

    }
}

void maior_valor(Arvore arvore){
    char maior = arvore[0].valor - '0';
    for( int i=1; i<MAX; i++){
        if(maior != '-' && maior< arvore[i].valor){
            maior=arvore[i].valor;
        }
    }
    cout << "Maior: " << maior;
}

void count_nos(Arvore arvore){
    if(arvore[0].valor=='-'){
    cout <<  "Arvore vaziaa";
    return;
    }
    int count =0;
    int index_daddy=0;
    int index_filho=1;
    while(arvore[index_daddy].valor!='-'){
        if(arvore[index_daddy].qtd_filhos!=0){
            index_daddy++;
            count++;
            continue;
        }
        index_daddy++;
    }
    cout << "\nNúmero de nós: "<< count;

}

void qtd_nos_folha(Arvore arvore){
    if(arvore[0].valor=='-'){
    cout <<  "Arvore vaziaa";
    return;
    }
    int count =0;
    int index_daddy=0;
    int index_filho=1;
    while(arvore[index_daddy].valor!='-'){
        if(arvore[index_daddy].qtd_filhos==0){
            index_daddy++;
            count++;
            continue;
        }
        index_daddy++;
    }
    cout << "\nNúmero de nós: "<< count;
}

int main(){
    Arvore arvore;
    inicializar(arvore);
    cout << "\nLeitura dos vértices da árvore: \n";
    ler_arvore(arvore);
    cout << "\nSua arvore: \n";
    mostrar_arvore(arvore);
    cout << "\nVetor da arvore: \n";
    mostrar_vetor(arvore);
    cout << "\nMaior valor da arvore: \n";
    maior_valor(arvore);
    cout << "\nQtd de nós: \n";
    count_nos(arvore);
    cout << "\nQtd de nós folha: \n";
    qtd_nos_folha(arvore);
}