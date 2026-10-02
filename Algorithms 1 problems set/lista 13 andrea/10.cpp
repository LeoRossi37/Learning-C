void remover_inicio(lista *l){
    if(l->inicio==NULL) return;
    no *p = l->inicio;
    l->inicio = p->prox;
    if(l->inicio!=NULL) l->inicio->ant = NULL;
    else l->fim = NULL;
    free(p);
}
