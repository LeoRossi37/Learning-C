void inserir_inicio(lista *l, int x){
    no *p = malloc(sizeof(no));
    p->info = x;
    p->ant = NULL;
    p->prox = l->inicio;
    if(l->inicio!=NULL) l->inicio->ant = p;
    else l->fim = p;
    l->inicio = p;
}
