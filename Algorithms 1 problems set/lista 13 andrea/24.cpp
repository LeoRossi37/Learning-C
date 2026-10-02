int existe(lista *l, int x){
    no *p = l->inicio;
    while(p!=NULL){
        if(p->info==x) return 1;
        p = p->prox;
    }
    return 0;
}

void copiar_sem_repetir(lista *orig, lista *dest){
    iniciar(dest);
    no *p = orig->inicio;
    while(p!=NULL){
        if(!existe(dest, p->info)){
            no *q = malloc(sizeof(no));
            q->info = p->info;
            q->prox = NULL;
            q->ant = dest->fim;
            if(dest->inicio==NULL) dest->inicio = q;
            else dest->fim->prox = q;
            dest->fim = q;
        }
        p = p->prox;
    }
}
