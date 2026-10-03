#include<bits/stdc++.h>

using namespace std;

#define MAX 30

typedef struct pilhazinha{
    char pilha[MAX];
}Pilha;

int push(Pilha *pilha, char info){
    for(int i=0; i<MAX; i++){
        if(pilha->pilha[i] == '\0'){
            pilha->pilha[i] = info;
            pilha->pilha[i+1] = '\0';
            return 1;
        }
    }
    return 0;
}

void mostrar(Pilha pilha){
    for(int i=0; pilha.pilha[i] != '\0'; i++){
        cout << pilha.pilha[i];
    }
    cout << endl;
}

void repet(Pilha *pilha){
    int j = 0;

    for(int i = 1; pilha->pilha[i] != '\0'; i++){
        if(pilha->pilha[i] != pilha->pilha[j]){
            j++;
            pilha->pilha[j] = pilha->pilha[i];
        }
    }

    pilha->pilha[j+1] = '\0';
}

int main(){
    Pilha pilha;

    for(int i=0;i<MAX;i++){
        pilha.pilha[i] = '\0';
    }

    char x[MAX];

    cin >> x;

    for(int i=0; x[i] != '\0'; i++){
        push(&pilha, x[i]);
    }

    repet(&pilha);

    mostrar(pilha);
}