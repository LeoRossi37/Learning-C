void limpar(lista *l){
    no *p = l->inicio;
    while(p!=NULL){
        no *aux = p;
        p = p->prox;
        free(aux);
    }
    l->inicio = NULL;
    l->fim = NULL;
}
