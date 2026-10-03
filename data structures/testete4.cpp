#include<bits/stdc++.h>
using namespace std;


typedef struct no{
    int itens;
    struct no *prox;
}*No;

typedef struct fila
{
    No inicio, final;
    int size;
}Fila;

int iniciar(Fila *fila){
    fila->inicio=fila->final=NULL;
    fila->size=0;
}

bool vazia(Fila fila){
    return fila.inicio==NULL;
}

int inserir(Fila *fila, int item){
    No p = (No)malloc(sizeof(struct no));
    if(p==NULL){
        return 0;
    }

    p->itens=item;
    p->prox=NULL;
    if(vazia(*fila)){
        fila->inicio=p;
        fila->final=p;
    }else{
        fila->final->prox=p;
        fila->final=p;
    }
    fila->size++;

    return 1;

}

int desenfileirar(Fila *fila, int *item){
    if(vazia(*fila)) return 0;
    No aux = fila->inicio;
    *item=aux->itens;
    fila->inicio=aux->prox;
    if(fila->inicio == NULL){
        fila->final = NULL;
    }
    free(aux);
    fila->size--;
    return 1;
}

int peek_inicio(Fila fila, int *item){
    if(vazia(fila)) return 0;

    *item=fila.inicio->itens;

    return 1;
}

void mostrar(Fila fila){
    if(vazia(fila)){
        return;
    }

    No aux = fila.inicio;

    while(aux!=NULL){
        cout << aux->itens << " ";
        aux=aux->prox;
    }
    cout << "\n";
}

int main(){
    Fila fila;
    int x;
    iniciar(&fila);
    for(int i=0; i< 10; i++){
        cin >> x;
        inserir(&fila,x);
    }
    peek_inicio(fila, &x);
    cout << endl;
    mostrar(fila);
}