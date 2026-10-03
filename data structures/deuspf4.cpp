#include <bits/stdc++.h>
using namespace std;

typedef struct vertice{
    int item;
    struct vertice *filho_esq;
    struct vertice *irmao_dir;
}*Vertice;

typedef struct arvore{
    Vertice raiz;
    int grau;
    int profundidade;
}Arvore