#include<bits/stdc++.h>

using namespace std;

typedef struct no{
    int info;
    struct no *prox;
}no;

void insert_ord(no *&head, int value){

    no *novo = (no*) malloc(sizeof(no));
    novo->info = value;
    novo->prox = NULL;

    if(head == NULL || value < head->info){
        novo->prox = head;
        head = novo;
        return;
    }

    no *aux = head;

    while(aux->prox != NULL && aux->prox->info < value){
        aux = aux->prox;
    }

    novo->prox = aux->prox;
    aux->prox = novo;
}

void remove_minor_k(no *&head, int k){

    while(head != NULL && head->info < k){
        no *temp = head;
        head = head->prox;
        free(temp);
    }

    no *aux = head;

    while(aux != NULL && aux->prox != NULL){

        if(aux->prox->info < k){
            no *temp = aux->prox;
            aux->prox = temp->prox;
            free(temp);
        }else{
            aux = aux->prox;
        }

    }
}

void show_list(no *head){

    no *aux = head;

    while(aux != NULL){
        cout << aux->info << " ";
        aux = aux->prox;
    }

    cout << "\n";
}

int main(){

    no *head = NULL;

    int op,value,k;

    do{
        cout << "\n1-Inserir valor\n";
        cout << "2-Ver lista\n";
        cout << "3-Remover menores que k\n";
        cout << "0-Sair\nOpcao: ";

        cin >> op;

        if(op == 1){
            cout << "Valor: ";
            cin >> value;
            insert_ord(head,value);
        }

        else if(op == 2){
            show_list(head);
        }

        else if(op == 3){
            cout << "Digite k: ";
            cin >> k;
            remove_minor_k(head,k);
        }

    }while(op != 0);

}