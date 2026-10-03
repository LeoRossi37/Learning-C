#include<bits/stdc++.h>
using namespace std;

#define MAX 10

typedef struct estrutura_fila{
    int itens[MAX];
    int inicio, fim;
    int size;
}Fila;

void iniciar_fila(Fila *fila){
    fila->fim=-1;
    fila->inicio=0;
    fila->size=0;
}

bool esta_vazia(Fila fila){
    return fila.size==0;
}

bool esta_cheia(Fila fila){
    return fila.size==MAX;
}

int tamanho(Fila fila){
    return fila.size;
}

int enfileirar(Fila *fila, int item){
    if(esta_cheia(*fila)){
        return 0;
    }
    if(fila->inicio==-1){
        fila->inicio=0;
    }
    fila->fim=(fila->fim+1) %MAX;
    fila->itens[fila->fim]=item;
    fila->size++;
    return 1;
}

int desenfileierar(Fila *fila, int *item){
    if(esta_vazia(*fila)){
        return 0;
    }

    *item=fila->itens[fila->inicio];
    fila->size--;
    if(fila->inicio==fila->fim){
        iniciar_fila(fila);
    }else{
        fila->inicio=((fila->inicio+1)%MAX);
    }

    return 1;
}

int peek_front(Fila fila, int *item){
    if(esta_vazia(fila)){
        return 0;
    }

    *item=fila.itens[fila.inicio];
    return 1;

}

void mostra_fila(Fila fila){
    if(esta_vazia(fila)){
        return;
    }
    int i=fila.inicio;
    while(i!=fila.fim){
        cout << fila.itens[i] << " ";
        i=(i+1)%MAX;
    }

    cout << fila.itens[fila.fim] << "\n";

}

int main (){
    Fila fila;
    int x;
    int op;
    iniciar_fila(&fila);
    do{
        cout << "1-enfileira\n2-desenfileira\n3-mostra\n4-peek no comeco\n0-sair!\n";
        cin >> op;
        switch (op)
        {
            case 1:
            for(int i=0; i<MAX; i++){
                cin >> x;
                enfileirar(&fila, x);
            }
            break;
            case 2:
            if(desenfileierar(&fila, &x)){
                cout << x << " foi removido!\n";
            }
            else cout << "Fila vazia!\n";
            break;
            case 3:
            mostra_fila(fila);
            break;
            case 4:
            if(peek_front(fila, &x)){
            cout << "Primeiro CANALHA na fila: " << x << "\n";
            }else{
                cout << "FIla vazia!\n";
            }
            break;
            case 0: return 0;
        }
    }while(op!=0);
}