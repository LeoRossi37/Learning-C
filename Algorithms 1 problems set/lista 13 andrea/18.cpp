void inverter(lista *l){
    no *p = l->inicio;
    while(p!=NULL){
        no *aux = p->prox;
        p->prox = p->ant;
        p->ant = aux;
        p = aux;
    }
    no *aux = l->inicio;
    l->inicio = l->fim;
    l->fim = aux;
}
