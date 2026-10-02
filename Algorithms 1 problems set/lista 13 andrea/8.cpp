void inserir_depois_n(lista *l, int n, int x){
    if(n<1) return;
    no *p = l->inicio;
    int k = 1;
    while(k<n && p!=NULL){
        p = p->prox;
        k++;
    }
    if(p==NULL) return;
    no *q = malloc(sizeof(no));
    q->info = x;
    q->prox = p->prox;
    q->ant = p;
    if(p->prox!=NULL) p->prox->ant = q;
    else l->fim = q;
    p->prox = q;
}
