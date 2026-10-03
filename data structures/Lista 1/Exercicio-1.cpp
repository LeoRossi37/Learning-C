#include<bits/stdc++.h>
#include<time.h>

using namespace std;
#define MAX 100

typedef struct lista_estatica{
    int info[MAX];
    int size;
}Lista;

bool exist(Lista *lista, int value){
    for(int i=0;i<lista->size; i++){
        if(lista->info[i]==value){
            return true;
        }
    }
    return false;
}

void start_list(Lista *lista){
    lista->size=0;
}

void insert_random_ord(Lista *lista){
    if(lista->size==MAX){
        cout << "Lista cheia!\n";
        return;
    }
    int senha=rand()%100000;
    if(exist(lista,senha)){
        cout << "Senha repetida:" << senha << "\n";
        return;
    }
    int pos=0;

    while(pos<lista->size && lista->info[pos]<senha){
        pos++;
    }

    for(int i=lista->size; i>pos; i--){
        lista->info[i]=lista->info[i-1];
    }

    lista->info[pos]=senha;
    lista->size++;

    cout << "Senha inserida:" << senha << "\n";


}

void remove_minor(Lista *lista){
    if(lista->size == 0){
        cout << "Lista vazia\n";
        return;
    }

    int minor = lista->info[0];

    for(int i = 0; i < lista->size - 1; i++){
        lista->info[i] = lista->info[i+1];
    }

    lista->size--;

    cout << "Menor senha removida: " << minor << endl;
}

void show_lista(Lista *lista){
    if(lista->size==0){
        cout << "Lista vazia!\n";
    }else{
        for(int i=0; i<lista->size; i++){
            cout << lista->info[i] << " ";
        }
        cout << "\n";
    }
}

int main(){
    Lista lista;
    int info;
    start_list(&lista);
    int op;
    srand(time(NULL));
    do{
        cout << "\t\tMENU\n";
        cout << "1-Inserir senha aleatoria\n";
        cout << "2-Ver lista\n";
        cout << "3-Remover menor elemento(ordem)\n";
        cout << "0-Sair!\nDigite a opcao: ";
        cin >> op;
        if(op==1){
            insert_random_ord(&lista);
        }else if(op==2){
            show_lista(&lista);
        }else if (op==3){
            remove_minor(&lista);
        }
    }while(op!=0);
}