#include<bits/stdc++.h>
#include<time.h>

using namespace std;

typedef struct no{
    char placa[7];
    struct no *prox;
}*No;

typedef struct{
    No topo;
    int size;
}Pilha;

void inicia(Pilha *p){
    p->topo=NULL;
    p->size=0;
}

bool vazia(Pilha p){
    return (p.topo==NULL);
}

int empilhar(Pilha *p, char *placa){
    No q = (No) malloc(sizeof(struct no));
    if(placa==NULL)return 0;
    strcpy(q->placa,placa);

    q->prox=p->topo;
    p->topo=q;
    p->size++;

    return 1;

}

int desemplihar(Pilha *p, char *placa, int &count){
    if(vazia(*p))return 0;

    Pilha aux;
    inicia(&aux);
    No temp;
    int achou=0;

    while(!vazia(*p)){
        temp=p->topo;
        p->topo=temp->prox;
        if(strcmp(temp->placa,placa)==0 && !achou){
            cout << "O carro com a placa:" << placa << " foi removido!\n";
            free(temp);
            p->size--;
            achou=1;
            count++;
        }else{
            temp->prox=aux.topo;
            aux.topo=temp;
            aux.size++;
            p->size--;
            count++;
        }

    }

    while(!vazia(aux)){
        temp=aux.topo;
        aux.topo=temp->prox;
        temp->prox=p->topo;
        p->topo=temp;
        p->size++;
        aux.size--;
    }

    return achou;

}

void mostrar(Pilha p){
    if(vazia(p)){
        cout << "Pilha vazia\n";
        return;
    }
    No temp = p.topo;
    cout << "Placas:\n";
    while(temp!=NULL){
        cout << temp->placa << " ";
        temp=temp->prox;
    }
    cout << "\n\n";
}



int main(){
    Pilha p;
    inicia(&p);
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
            desemplihar(&p, placa, count);
            cout << "Foram feitos " << count << "movimentos para permitir a saída do carro"; 
        }else if(op==3){
            mostrar(p);
        }
    }while(op!=0);
}