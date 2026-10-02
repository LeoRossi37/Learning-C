#include<bits/stdc++.h>
#include<conio.h>
using namespace std;

typedef struct reg *node;
struct reg {
int info;
struct reg *prox;
};

void cria_lista(node *lista){
  *lista=NULL;
}

void insere_inicio(node *lista, int info){
  node p = (node)malloc(sizeof(struct reg));
  p->info=info;
  if(!*lista){
    p->prox=p;
    *lista=p;
  }else{
    node q=*lista;
    while(q->prox!=*lista){
      q=q->prox;
    }
    q->prox=p;
    p->prox=*lista;
    *lista=p;
  }
}

void insere_fim(node *lista, int info){
  node p = (node)malloc(sizeof(struct reg));
  p->info=info;
  if(!*lista){
    p->prox=p;
    *lista=p;
  }else{
    node q=*lista;
    while(q->prox!=*lista){
      q=q->prox;
    }
    q->prox=p;
    p->prox=*lista;
  }
}

void contar_elementos(node lista){
  node p=lista;
  int count=0;
  if(!lista){
    printf("\nLista sem elementos!\n");
  }
  do{
    count++;
    p=p->prox;
  }while(p!=lista);
  printf("%d elementos na lista!\n", count);
  system("pause");
}

void mostra_lista(node lista){
  node p=lista;
  if(!lista){
    printf("\nLista vazia\n");
    return;
  }
  do{
    printf("%d ", p->info);
    p=p->prox;
  }while(p!=lista);
}

int main(){
    node lista;
    int op;
    cria_lista(&lista);
    do{
      int info;
      cout << "\nDigite qual opcao quer usar:\n";
    printf("1-inserir no inicio\n2-mostrar lista\n3-contar elementos\n4-inserir fim\n5-remove primeiro elemento\n");
    cin >> op;
    if(op==1){
      printf("Digite um valor pra inserir na lista:");
      cin >> info;
      insere_inicio(&lista, info);
    }else if(op==2){
      mostra_lista(lista);
    }else if(op==3){
      contar_elementos(lista);
    }else if(op==4){
      printf("Digite um valor pra inserir na lista:");
      cin >> info;
      insere_fim(&lista,info);
    }

    }while(op!=0);
}