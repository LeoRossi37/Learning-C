#include<bits/stdc++.h>
using namespace std;

#define MAX 10

typedef struct no{
    int item;
    struct no *prox;
}*No;

typedef struct {
    No topo;
    int size;
}Pilha;

int inicia_pilha(Pilha *pilha){
    pilha->topo=NULL;
    pilha->size=0;
    return 1;
}

bool esta_cheia(Pilha pilha){
    if(pilha.size==(MAX)){
        return true;
    }
    return false;
}

bool esta_vazia(Pilha pilha){
    if(pilha.topo==NULL){
        return true;
    }
    return false;
}

int empilhar(Pilha *pilha, int item){
    if(esta_cheia(*pilha)){
        cout << "Pilha cheia!\n";
        return 0;
    }
    No novo = (No)malloc(sizeof(struct no));
    if(novo==NULL) return 0;

    novo->item=item;
    novo->prox=pilha->topo;
    pilha->topo=novo;
    pilha->size++;

    return 1;
}

int desempilhar(Pilha *pilha, int *item){
    if(esta_vazia(*pilha)){
        cout << "Pilha já está vazia!\n";
        return 0;
    }

    No temp = pilha->topo;
    *item=temp->item;
    pilha->topo=temp->prox;
    free(temp);
    pilha->size--;
    return 1;
}

int espia_topo(Pilha pilha, int *item){
    if(esta_vazia(pilha)){
        cout << "Pilha está vazia";
        return 0;
    }
    *item=pilha.topo->item;
    return 1;
}

void imprimir(Pilha *pilha){
    if(esta_vazia(*pilha)){
        cout << "Pilha está vazia\n";
        return;
    }

    Pilha aux;
    inicia_pilha(&aux);

    int x;

    while(!esta_vazia(*pilha)){
        desempilhar(pilha, &x);
        cout << x << " ";
        empilhar(&aux, x);
    }

    while(!esta_vazia(aux)){
        desempilhar(&aux, &x);
        empilhar(pilha, x);
    }

    cout << endl;
}
int main(){
    Pilha p;
    int x;
    inicia_pilha(&p);
    for(int i=0; i < MAX; i++){
        cin >> x;
        empilhar(&p, x);
    }
    espia_topo(p, &x);
    cout << "Topo da pilha: " << x << endl;
    imprimir(&p);
    if(esta_vazia(p)){
        cout << "\nPilha vazia!!!\n";
    }
}