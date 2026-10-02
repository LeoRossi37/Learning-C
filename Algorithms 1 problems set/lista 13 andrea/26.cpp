typedef struct nd{
    char linha[251];
    struct nd *ant;
    struct nd *prox;
}nd;

typedef struct{
    nd *inicio;
    nd *fim;
    nd *atual;
}texto;

void iniciar_texto(texto *t){
    t->inicio = NULL;
    t->fim = NULL;
    t->atual = NULL;
}

void inserir_linha(texto *t, char *s){
    nd *p = malloc(sizeof(nd));
    strcpy(p->linha, s);
    p->prox = NULL;
    p->ant = t->fim;
    if(t->inicio==NULL) t->inicio = p;
    else t->fim->prox = p;
    t->fim = p;
    if(t->atual==NULL) t->atual = p;
}

void ler_arquivo(texto *t, char *nome){
    FILE *arq = fopen(nome, "r");
    if(arq==NULL) return;
    char s[251];
    while(fgets(s,250,arq)!=NULL){
        s[strcspn(s, "\n")] = 0;
        inserir_linha(t, s);
    }
    fclose(arq);
}

void subir(texto *t){
    if(t->atual!=NULL && t->atual->ant!=NULL) t->atual = t->atual->ant;
}

void descer(texto *t){
    if(t->atual!=NULL && t->atual->prox!=NULL) t->atual = t->atual->prox;
}
