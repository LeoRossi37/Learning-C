#include<bits/stdc++.h>
#include<conio.h>
using namespace std;

typedef struct reg *no;
struct reg{
    int info;
    struct reg *prox;
};

typedef struct{
    no prim, ult;
    int qte;
}Descritor;

void cria_LLSECD(Descritor *lista){
    (*lista).prim=(*lista).ult=NULL;
    (*lista).qte = 0;
}

void insere_incio_LLSECD(Descritor *lista, int info){
    no p;
    p = (no) malloc(sizeof(struct reg));
    p->info = info;
    p->prox = (*lista).prim;
    (*lista).prim=p;
    (*lista).qte++;
    if((*lista).qte==1)
    (*lista).ult=p;
}

void insere_fim_LLSECD(Descritor *lista, int info){
    no p;
    p = (no) malloc(sizeof(struct reg));
    p->info = info;
    p->prox = NULL;
    if((*lista).qte==0)
    (*lista).prim=p;
    else
    (*lista).ult->prox=p;
    (*lista).ult=p;
    (*lista).qte++;
}

int verif_LLSECD(Descritor lista, int info){
    if(lista.qte==0){
        return 0;
    }
    no p= lista.prim;
    do{
        if(p->info==info)
        return 1;
        p=p->prox;
    }while(p!=NULL);
    return 0;
}

void mostra_LLSECD(Descritor lista){
    if(lista.qte == 0){
        cout << "\nLista Vazia\n";
        return;
    }
    no p=lista.prim;
    cout << "\nElementos da  lista: ";
    do{
        cout << p->info << " ";
        p=p->prox;
    }while(p!=NULL);

}

int remove_inicio(Descritor *lista){
    if((*lista).qte==0){
        return 0;
    }else{
        no p = (*lista).prim;
        (*lista).prim=p->prox;
        if((*lista).qte==1)
        (*lista).ult==NULL;
        (*lista).qte--;
        free(p);
        return 1;
    }
}
int remove_fim(Descritor *lista){
    if((*lista).qte==0){
        return 0;
    }
    no p, q;
    p=(*lista).prim;
    while(p->prox){
        q=p;
        p=p->prox;
    }
    (*lista).qte--;
    if((*lista).qte==0){
        (*lista).ult==NULL;
        (*lista).prim==NULL;
    }else{
        (*lista).ult=q;
        q->prox =NULL;
    }
    free(p);
    return 1;
}

int main(){
    int info;
    Descritor lista;
    char resp;
    cria_LLSECD(&lista);
    cout << "Inserir:\n";
    do{
        cout << "\nDigite um numero inteiro: ";
        cin >> info;
       // insere_incio_LLSECD(&lista,info);
        insere_fim_LLSECD(&lista,info);
        mostra_LLSECD(lista);
        cout << "\nContinua?(S/N)";
        do{
            resp=toupper(getch());
        }while(resp!='N' && resp!='S');
    }while(resp=='S');
    cout << "\nVerificacao numero:";
    cin >> info;
    if(verif_LLSECD(lista,info)){
        cout << "O numero " << info << " esta na lista!";
    }else{
        cout << "O numero " << info << " nao esta na lista!";
    }
    int remov;
    do{
        do{
        cout << "\nRemocao de primeiro ou ultimo elem(1-primeiro/2-ultimo):";
        cin >> remov;
        }while(remov!= 1 && remov!=2);
    if(remov==1){
        remove_inicio(&lista);
        cout << "\nRemocao do 1o elem. realizada com sucesso!\n";
        mostra_LLSECD(lista);
    }else{
        remove_fim(&lista);
        cout << "\nRemocao do ultimo elem. realizada com sucesso!\n";
        mostra_LLSECD(lista);
    }
     cout << "\nContinua remocao?(S/N)";
        do{
            resp=toupper(getch());
        }while(resp!='N' && resp!='S');
    }while(resp=='S');
    
}