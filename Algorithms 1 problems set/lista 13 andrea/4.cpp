int pertence(lista *l, int x){
    no *p = l->inicio;
    while(p!=NULL){
        if(p->info==x) return 1;
        p = p->prox;
    }
    return 0;
}
