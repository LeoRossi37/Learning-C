#include<bits/stdc++.h>
using namespace std;

typedef struct reg *no;

struct reg{
    string nome;
    struct reg *prox;
};

typedef struct{
    no prim, ult;
    int qte;
}Descritor;

void cria_fila(Descritor *fila){
    (*fila).prim = (*fila).ult = NULL;
    (*fila).qte = 0;
}

void entra_fila(Descritor *fila, string nome){
    no p;
    p = (no) malloc(sizeof(struct reg));

    p->nome = nome;
    p->prox = NULL;

    if((*fila).qte == 0)
        (*fila).prim = p;
    else
        (*fila).ult->prox = p;

    (*fila).ult = p;
    (*fila).qte++;
}

void ver_primeiro(Descritor fila){
    if(fila.qte == 0){
        cout << "\nFila vazia\n";
        return;
    }

    cout << "\nPrimeira pessoa da fila: " << fila.prim->nome << "\n";
}

void atender(Descritor *fila){
    if((*fila).qte == 0){
        cout << "\nFila vazia\n";
        return;
    }

    no p = (*fila).prim;

    cout << "\nPessoa atendida: " << p->nome << "\n";

    (*fila).prim = p->prox;

    if((*fila).qte == 1)
        (*fila).ult = NULL;

    (*fila).qte--;

    free(p);
}

void quantidade(Descritor fila){
    cout << "\nQuantidade de pessoas na fila: " << fila.qte << "\n";
}

void fila_vazia(Descritor fila){
    if(fila.qte == 0)
        cout << "\nA fila esta vazia\n";
    else
        cout << "\nA fila nao esta vazia\n";
}

void mostra_fila(Descritor fila){

    if(fila.qte == 0){
        cout << "\nFila vazia\n";
        return;
    }

    no p = fila.prim;

    cout << "\nFila: ";

    while(p != NULL){
        cout << p->nome << " ";
        p = p->prox;
    }

    cout << "\n";
}

int main(){

    Descritor fila;

    cria_fila(&fila);

    int op;
    string nome;

    do{

        cout << "\n----- SISTEMA DE ATENDIMENTO -----\n";
        cout << "1 - Adicionar pessoa na fila\n";
        cout << "2 - Ver primeira pessoa\n";
        cout << "3 - Atender pessoa\n";
        cout << "4 - Quantidade de pessoas\n";
        cout << "5 - Verificar se fila esta vazia\n";
        cout << "6 - Mostrar fila\n";
        cout << "0 - Sair\n";
        cout << "Opcao: ";

        cin >> op;

        if(op == 1){
            cout << "Nome da pessoa: ";
            cin >> nome;
            entra_fila(&fila,nome);
        }

        else if(op == 2){
            ver_primeiro(fila);
        }

        else if(op == 3){
            atender(&fila);
        }

        else if(op == 4){
            quantidade(fila);
        }

        else if(op == 5){
            fila_vazia(fila);
        }

        else if(op == 6){
            mostra_fila(fila);
        }

    }while(op != 0);

}