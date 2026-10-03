#include<bits/stdc++.h>
using namespace std;

#define tam 10

typedef struct Fila{
    int itens[tam];
    int fim, inicio;
    int size;
}Fila;

int iniciaLista(Fila *fila){
    fila->fim=-1;
    fila->inicio=-1;
    fila->size=0;
    return 1;
}

int vazia(Fila fila){
    return fila.size==0;
}

int cheia(Fila fila){
    return fila.size==tam;
}

int tam_fila(Fila fila){
    return fila.size;
}

int enfilera(Fila *fila, int x){
    if(cheia(*fila)){
        return 0;
    }
    if(fila->inicio == -1){
        fila->inicio=0;
    }
    
    fila->fim=(fila->fim +1) %tam;

    fila->itens[fila->fim]=x;
    fila->size++;

    return 1;

}

int desenfileirar(Fila *fila, int *x){
    if(vazia(*fila)){
        return 0;
    }

    *x=fila->itens[fila->inicio];
    fila->size--;

    if(fila->inicio == fila->fim){
        iniciaLista(fila);
    }else{
        fila->inicio=(fila->inicio + 1) % tam;
    }

    return 1;

}

int espiar(Fila fila, int *item_inicio){
    if(vazia(fila)){
        return 0;
    }

    *item_inicio = fila.itens[fila.inicio];

    return 1;

}

void mostra_fila(Fila fila){
    if(vazia(fila)){
        cout << "Fila Vazia\n";
        return;
    }

    cout << "Itens da fila: ";
    int i=fila.inicio;

    while(i!=fila.fim){
        cout << fila.itens[i] << " ";
        i=(i+1)%tam;
    }

    cout << fila.itens[fila.fim] << "\n";

}

void invert_fila(Fila *fila){
    if(vazia(*fila)){
        cout << "Fila vazia, nao há como inverter!\n";
    }
    int aux[fila->size];
    int count =fila->size;
    for(int i=0; i< count; i++){
        desenfileirar(fila, &aux[i]);
    }
    for(int i=count-1; i >=0; i--){
        enfilera(fila, aux[i]);
    }
    cout << "Fila invertida\n";
}

int main(){
    Fila fila;
    iniciaLista(&fila);
    int op, a;
    do{
        cout<< "1-insere 2-desenfilera 3-mostra 4-Inverte: ";
        cin >> op;
        if(op==1){
            cout << "Digite um numero para inserir na lista: ";
            cin >> a;
            if(!enfilera(&fila, a)) cout << "Erro: Fila cheia!";
        }
        if(op==2){
            if(desenfileirar(&fila, &a)){
                cout << "Removido: " << a << "\n";
            }
        }
        if(op==3){
            mostra_fila(fila);
        }
        if(op==4){
            invert_fila(&fila);
        }
    }while(op!=0);

   

}