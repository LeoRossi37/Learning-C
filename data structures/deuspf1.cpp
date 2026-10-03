#include <bits/stdc++.h>
using namespace std;

typedef struct no{
    char placa[7];
    struct no *prox;
}*No;

typedef struct{
    No topo;
    int size;
}Pilha;

void inicia_pilha(Pilha *pilha){
    pilha->topo=NULL;
    return;
}

int empilhar(Pilha *pilha, char *placa){
    if(pilha->topo==NULL){
        printf("Pilha esta cheia!\n");
        return 0;
    }
    No q=(No)malloc(sizeof(struct no));
    strcpy(q->placa,placa);
    q->prox=pilha->topo;
    pilha->topo=q;
    pilha->size++;
    return 1;

}

int desempilhar(Pilha *pilha, char *placa, int &count){
    if(pilha->topo==NULL) return 0;
    Pilha aux;
    inicia_pilha(&aux);
    No temp;
    int flag=0;
    while(pilha->topo!=NULL){
        temp=pilha->topo;
        pilha->topo=temp->prox;
        if(stricmp(temp->placa,placa)==0 && !flag){
            printf("A placa %s foi removida", placa);
            free(temp);
            pilha->size--;
            flag=1;
            count++;
            return 1;
        }else{
            temp->prox=aux.topo;
            aux.topo=temp;
            aux.size++;
            pilha->size--;
            count++;
        }
    }
    while(aux.topo!=NULL){
        temp=aux.topo;
        aux.topo=temp->prox;
        temp->prox=pilha->topo;
        pilha->topo=temp;
        pilha->size++;
        aux.size--;
        count++;
    }

    return flag;
}

void mostrar(Pilha pilha){
    if(pilha.topo==NULL){
        return;
    }

    No temp =pilha.topo;
    int count=0;
    while(temp!=NULL){
        printf("Placa %d: %s\n", count, temp->placa);
        temp=temp->prox;
    }

    printf("\n\n");

}


int main(){
    Pilha p;
    inicia_pilha(&p);
    int op;
    do{
        cout << "\t\t\tMenu\n\n";
        cout<< "Escolha uma opção:\n1-Adicionar placa\n2-Remover placa\n3-Status\n";
        cin >> op;
        cin.ignore();
        if(op==1){
            char placa[7];
            cout << "Digite a placa para ser inserida(7 digitos):";
            fgets(placa,sizeof(placa),stdin);
            placa[strcspn(placa, "\n")] = '\0';
            empilhar(&p, placa);
        }else if(op==2){
            char placa[7];
            int count=0;
            cout<<"Digite a placa a ser removida(7 digitos):";
            fgets(placa,sizeof(placa),stdin);
            placa[strcspn(placa, "\n")] = '\0';
            desempilhar(&p, placa, count);
            cout << "Foram feitos " << count << "movimentos para permitir a saída do carro"; 
        }else if(op==3){
            mostrar(p);
        }
    }while(op!=0);
}