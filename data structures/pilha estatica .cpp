#include<bits/stdc++.h>
using namespace std;

#define TAM 5

typedef struct {
    int pilha[TAM];
    int topo;
}Pilha;

void inicializar(Pilha *pilha){
    pilha->topo=-1;
}
bool vazia(Pilha pilha){
    if( pilha.topo== -1){
        return true;
    }else{
        return false;
    }
}
bool cheia(Pilha pilha){
if( pilha.topo== (TAM -1)){
        return true;
    }else{
        return false;
    }
}

int empilhar (Pilha *p, int info){
    if(cheia(*p)){
        return 0;
    }
    p->pilha[++p->topo]=info;
    return 1;
}

int desempilhar(Pilha *p, int *info){
    if(vazia(*p)) return 0;

    *info=p->pilha[p->topo--];

    return 1;

}

int peek(Pilha p, int *info){
    if(vazia(p)) return 0;

    *info= p.pilha[p.topo];
    return 1;

}

void mostrar_pilha(Pilha p){
    if(vazia(p)) return ;

    cout << " Pilha:\n";

    int info;

    while(!vazia(p)){
        desempilhar(&p, &info);
        cout << info << "\n";
    }

}

int main(){
    Pilha pilha;
    int x;
    inicializar(&pilha);
    for(int i=0; i<TAM; i++){
        int a;
        cin >> a;
        empilhar(&pilha,a);
    }
    mostrar_pilha(pilha);
    cout << endl;
    peek(pilha, &x);
    cout << x << "\n";

}