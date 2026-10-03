#include<bits/stdc++.h>

using namespace std;

#define MAX 30

typedef struct pilhazinha{
    int pilha[MAX];
}Pilha;

int push(Pilha *pilha, int info){
    for(int i=0; i<MAX; i++){
        if(pilha->pilha[i] == -1){
            pilha->pilha[i] = info;
            return 1;
        }
    }
    return 0;
}

void mostrar(Pilha pilha){
    int i=0;
    while(i<MAX && pilha.pilha[i]!=-1){
        cout << pilha.pilha[i] << "\n";
        i++;
    }
}

int main(){
    Pilha pilha;

    for(int i=0;i<MAX;i++){
        pilha.pilha[i] = -1;
    }

    int x;

    while(cin >> x){
        push(&pilha, x);
    }

    mostrar(pilha);
}