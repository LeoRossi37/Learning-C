no* ultimo_no(lista *l, int *valor){
    if(l->fim==NULL){
        *valor = -1;
        return NULL;
    }
    *valor = l->fim->info;
    return l->fim;
}
