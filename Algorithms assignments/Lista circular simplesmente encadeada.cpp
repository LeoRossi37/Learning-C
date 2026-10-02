#include<bits/stdc++.h>
#include<conio.h>
using namespace std;

typedef struct reg *no;
struct reg {
int info;
struct reg *prox;
};
no lista;

void cria_lista (no *lista) {
*lista = NULL;
}

void inclui_inicio_lista(no *lista, int info){
    no p = (no) malloc(sizeof(struct reg));
    p->info = info;
    if(!*lista){
        p->prox=p;
        *lista=p;
    }else{
        no q=*lista;
        while(q->prox != *lista){
            q=q->prox;
        }
        q->prox=p;
        p->prox=*lista;
        *lista=p;
    }
}

void inclui_final_lista(no *lista, int info) {
  no p = (no) malloc(sizeof(struct reg));
  p->info = info;
  if (!*lista) {
    p->prox = p;
    *lista = p;
  }
  else {
    no q = *lista;
    while (q->prox != *lista)
      q = q->prox;
    q->prox = p;
    p->prox = *lista;
  }
}

void inclui_ordenada_lista(no *lista, int info){
  // criacao do no
  no p = (no) malloc(sizeof(struct reg));
  p->info = info;
  if (*lista == NULL) { 
    p->prox = p;
    *lista = p;
  }     
  else 
    if (info <= (*lista)->info){
      no q = *lista;
      while (q->prox != *lista)
        q = q->prox;
      q->prox = p;
      p->prox = *lista;
      *lista = p;
    }
    else {
      no q = *lista, r;
      do {
        r = q;
        q = q->prox;
      } while (q != *lista && q->info < info); 
      p->prox = q; 
      r->prox = p;                
    } 
}

void mostra_lista (no lista) {
  if (lista == NULL) {
    printf ("\nLista vazia");
    return;
  }
  no p = lista;
  printf ("\nElementos da lista: ");
  do {
    printf ("%d ",p->info);
    p = p->prox;
  } while (p != lista);
}

int remove_inicio_lista(no *lista) {
  if (!*lista)
    return 0;
  if ((*lista)->prox == *lista) {
    free (*lista);
    *lista = NULL;
  }
  else {
    no q = *lista;
    while (q->prox != *lista)
      q = q->prox;
    no p = *lista;
    *lista = p->prox;
    q->prox = *lista;
    free (p);
  }
  return 1;
}


int remove_elem_lista(no *lista, int elem) {
  if (!*lista)
    return 0;
  if (elem == (*lista)->info) {
    no q = *lista;
    if (*lista == (*lista)->prox) 
      *lista = NULL;
    else {
      no q = *lista;
      while (q->prox != *lista)
        q = q->prox;
      q->prox = (*lista)->prox;    
      *lista = (*lista)->prox;
    }  
    free (q);
    return 1;
  }
  no q = *lista, r;
  do {
    r = q;        
    q = q->prox;
  } while (q->info != elem && q != *lista);
  if (q->info != elem)
    return 0;
  r->prox = q->prox;
  free (q);
  return 1;
}

int main(){
int info;
  no lista;    
  char resp;
  cria_lista (&lista);
printf ("I N S E R C A O\n");
  do {
    printf ("\nDigite um numero inteiro: ");
    scanf ("%d",&info);
   //inclui_inicio_lista (&lista,info);
    inclui_final_lista (&lista,info);
   //inclui_ordenada_lista(&lista,info);
    mostra_lista (lista);
    printf ("\n\nContinua (S/N)? ");   
    do {
      resp = toupper(getch());
    } while (resp!='N' && resp!='S');
  } while (resp!='N');
printf ("\n\nR E M O C A O\n");
  do {
    printf ("\nDigite um numero inteiro: ");
    scanf ("%d",&info);
    if (remove_elem_lista (&lista,info))
    //if (remove_inicio_LCSE (&lista))
      printf ("-> %d removido.\n",info);
    else  
      printf ("-> elemento %d nao pertence a lista.\n",info);
    mostra_lista(lista);
    printf ("\nContinua (S/N)? ");   
    do {
      resp = toupper(getch());
    } while (resp!='N' && resp!='S');
  } while (resp!='N');

}