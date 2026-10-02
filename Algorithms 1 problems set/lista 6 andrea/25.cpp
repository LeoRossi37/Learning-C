#include <bits/stdc++.h>
using namespace std;

struct aluno {
    char nome[50];
    int numero;
};

char* buscabinaria(int x, aluno v[], int n){
    int e = -1, d = n;
    while(e < d - 1){
        int m = (e + d)/2;
        if(v[m].numero < x) e = m;
        else d = m;
    }
    if(d < n && v[d].numero == x) return v[d].nome;
    return (char *)"";
}

int main(){
    int n, x;
    scanf("%d", &n);
    aluno v[n];
    for(int i=0; i<n; i++)
        scanf("%s %d", v[i].nome, &v[i].numero);
    scanf("%d", &x);
    printf("%s\n", buscabinaria(x, v, n));
}
