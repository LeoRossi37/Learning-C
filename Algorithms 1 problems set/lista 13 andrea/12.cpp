void remover_n(lista *l, int n){
    if(n<1) return;
    no *p = l->inicio;
    int k = 1;
    while(k<n && p!=NULL){
        p = p->prox;
        k++;
    }
    if(p==NULL) return;
    if(p->ant!=NULL) p->ant->prox = p->prox;
    else l->inicio = p->prox;
    if(p->prox!=NULL) p->prox->ant = p->ant;
    else l->fim = p->ant;
    free(p);
}
