void copiar(lista *orig, lista *dest){
    iniciar(dest);
    no *p = orig->inicio;
    while(p!=NULL){
        no *q = malloc(sizeof(no));
        q->info = p->info;
        q->prox = NULL;
        q->ant = dest->fim;
        if(dest->inicio==NULL) dest->inicio = q;
        else dest->fim->prox = q;
        dest->fim = q;
        p = p->prox;
    }
}
