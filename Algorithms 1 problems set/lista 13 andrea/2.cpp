int primeiro(lista *l){
    if(l->inicio==NULL) return -1;
    return l->inicio->info;
}
