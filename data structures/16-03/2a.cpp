#include<bits/stdc++.h>

using namespace std;

typedef struct no{
    char item;
    struct no *prox;
}*No;

typedef struct fila{
    int inicio, fim;
    int size;
}Fila;

void initialize_queue(Fila *fila){
    fila->inicio=fila->final=NULL;
    fila->size=0;
}

int is_empty(Fila fila){
    return fila->inicio == NULL;
}

int insert(Fila *fila, char x){
    No no = (No) malloc(sizeof(struct no));
    if(no == NULL){
        return 0;
    }

    no->item=x;
    no->prox= NULL;

    if(fila->inicio==NULL){
        fila->inicio=no;
    }else{
        fila->fim->prox=no;
    }

    fila->fim = no;
    fila->size++;

    return 1;

}





int main(){

}