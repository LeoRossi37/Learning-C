#include<bits/stdc++.h>
using namespace std;

#define MAX 5

typedef struct{
    int pilha[MAX];
    int top;
}Pilha;

void inicia_pilha(Pilha *pilha){
    pilha->top=-1;
}

bool esta_vazia(Pilha pilha){
    if(pilha.top==-1){
        return true;
    }
    return false;
}

bool esta_cheia(Pilha pilha){
    if(pilha.top==(MAX-1)){
        return true;
    }
    return false;
}

int empilha(Pilha *pilha, int info){
    if(esta_cheia(*pilha)){
        cout << "Pilha está cheia!\n";
        return 0;
    }
    pilha->pilha[++pilha->top]=info;

    return 1;
}

int desempilha(Pilha *pilha, int *info){
    if(esta_vazia(*pilha)){
        return 0;
    }

    *info=pilha->pilha[pilha->top--];

    return 1;
}

int espiar_topo(Pilha pilha, int *info){
    if(esta_vazia(pilha)){
        "Pilha está vazia!\n";
        return 0;
    }

    *info=pilha.pilha[pilha.top];

    return 1;
}

void mostrar_pilha(Pilha pilha){
    if(esta_vazia(pilha)) return;

    cout << "Pilha: ";
    int x;
    while(!esta_vazia(pilha)){
        desempilha(&pilha, &x);
        cout << x << endl;
    }

    cout << "\n\n";

}


int main(){
    Pilha pilha;
    int x;
    inicia_pilha(&pilha);
    for(int i=0; i < MAX; i++){
        int a;
        cin >> a;
        empilha(&pilha, a);
    }
    espiar_topo(pilha, &x);
    cout  << "Topo da pilha : "<< x << endl;
    mostrar_pilha(pilha);
}