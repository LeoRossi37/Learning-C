typedef struct ns{
    int info;
    struct ns *prox;
}ns;

ns* remover_simples(ns *ini, int x){
    ns *p = ini, *ant = NULL;
    while(p!=NULL && p->info < x){
        ant = p;
        p = p->prox;
    }
    if(p==NULL || p->info!=x) return ini;
    if(ant==NULL) ini = p->prox;
    else ant->prox = p->prox;
    free(p);
    return ini;
}
