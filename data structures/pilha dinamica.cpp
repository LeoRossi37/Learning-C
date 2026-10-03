#include <bits/stdc++.h>
using namespace std;

typedef struct no{
    int item;
    struct no *prox;
}*No;

typedef struct{
    No topo;
    int size;
}Pilha;

void inicializar(Pilha *p){
    p->topo = NULL;
    p->size = 0;
}

bool vazia(Pilha p){
    return (p.topo == NULL);
}

int empilha(Pilha *p, int item){
    No novo = (No) malloc(sizeof(struct no));
    if(novo == NULL) return 0;

    novo->item = item;
    novo->prox = p->topo;
    p->topo = novo;
    p->size++;

    return 1;
}

int desempilha(Pilha *p, int *item){
    if(vazia(*p)) return 0;

    No temp = p->topo;
    *item = temp->item;

    p->topo = temp->prox;
    free(temp);
    p->size--;

    return 1;
}

int topo(Pilha p, int *item){
    if(vazia(p)) return 0;

    *item = p.topo->item;
    return 1;
}


void imprimir(Pilha p){
    No aux = p.topo;
    while(aux != NULL){
        cout << aux->item << " ";
        aux = aux->prox;
    }
    cout << endl;
}

int main(){
    Pilha p;
    inicializar(&p);

    empilha(&p, 10);
    empilha(&p, 20);
    empilha(&p, 30);

    cout << "Pilha: ";
    imprimir(p);

    int x;
    desempilha(&p, &x);
    cout << "Desempilhou: " << x << endl;

    cout << "Pilha agora: ";
    imprimir(p);

    return 0;
}