#include<bits/stdc++.h>
#include<conio.h>
using namespace std;

typedef struct reg *node;
struct reg{
    int info;
    struct reg *prox;
};

void cria_lista(node *lista){
    *lista=NULL;
}

void insere_inicio(node *lista, int info){
    node p = (node)malloc(sizeof(struct reg));
    p->info=info;
    p->prox=*lista;
    *lista=p;
}

void mostra_lista(node lista){
    node p=lista;
    if(!lista){
        printf("Lista vazia");
    }else{
while(p){
        printf("%d ",p->info);
        p=p->prox;
    }
    }
    
}
void conta_lista(node lista, int info){
    node p=lista;
    int count=0;
    if(!lista){
        printf("Lista vazia");
    }else{
        while(p!=NULL){
            if(p->info==info){
            count++;
            }
        p=p->prox;
        }
    }
   printf("%d numeros na lista\n", count);
}

void insere_fim(node *lista, int info){
    node p;
    p=(node)malloc(sizeof(struct reg));
    p->info=info;
    p->prox=NULL;
    if(*lista==NULL)
    *lista=p;
    else{
        node q=*lista;
        while(q->prox)
        q=q->prox;
        q->prox=p;
    }
}

void insere_ordem(node *lista, int info){
    node p;
    p=(node)malloc(sizeof(struct reg));
    p->info=info;
    if(*lista==NULL || info <=(*lista)->info){
        p->prox=*lista;
        *lista=p;
    }else{
        node q = *lista, r;
        while(q!=NULL && q->info<info){
            r=q;
            q=q->prox;
        }
        p->prox=q;
        r->prox=p;
    }
}

void remove_prim(node *lista){
    node p=*lista;
    if(!lista){
        return;
    }
    *lista=p->prox;
    free(p);
    printf("\nPrimeiro elem. removido\n");

}

void remove_num(node *lista, int info){
    node p=*lista;
    if(!*lista){
        return;
    }
    if(p->info==info){
        *lista=p->prox;
        free(p);
        return;
    }
    node q=p;
    p=p->prox;
    while(p->info!=info && p){
        q=p;
        p=p->prox;
    }
    if(p){
    q->prox=p->prox;
    free(p);
    printf("\n elem %d removido\n", info);
    }
    
    
}

int main(){
    node lista;
    int op;
    cria_lista(&lista);
    do{
        int info;
        cout << "\nDigite qual opcao quer usar:\n";
    printf("1-inserir no inicio\n2-mostrar lista\n3-contar elementos\n4-inserir fim\n5-remove primeiro elemento\n6-remove elemento escolhido\n");
    cin >> op;
    if(op==1){
        printf("Digite um valor pra inserir na lista:");
        cin >> info;
        insere_inicio(&lista, info);
    }else if(op==2){
        mostra_lista(lista);
    }else if(op==3){
        cout << "\nDigite um numero pra ver qntas vezes ele aparece:\n";
        cin >> info;
        conta_lista(lista, info);
    }else if(op==4){
        printf("Digite um valor pra inserir na lista:");
        cin >> info;
        insere_fim(&lista, info);
    }else if(op==5){
        remove_prim(&lista);
    }else if(op==6){
        printf("Digite um valor pra remover na lista:");
        cin >> info;
        remove_num(&lista, info);
    }

    }while(op!=0);
}