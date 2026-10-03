#include<bits/stdc++.h>

using namespace std;

typedef struct no{
    int info;
    struct no *prox;
}*No;

typedef struct pilha{
    No topo;
    int tamanho;
}Pilha;

void iniciar(Pilha *pilha){
    pilha->topo=NULL;
    pilha->tamanho=0;
}

void decimal_bin(Pilha *pilha, int info){
    while(info>0){
    No p= (No)malloc(sizeof(struct no));
    p->info=(info%2);
    p->prox=pilha->topo;
    pilha->topo=p;
    info=info/2;
    }

}

void mostra_lista(Pilha pilha){
    while(pilha.topo!=NULL){
        No q= pilha.topo;
        cout << q->info << " ";
        pilha.topo=q->prox;
        free(q);
    }
    cout << "\n";
}


int main(){
    Pilha pilha;
    iniciar(&pilha);
    int x;
    cin >> x;
    decimal_bin(&pilha, x);
    mostra_lista(pilha);

}