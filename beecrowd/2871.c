#include<stdio.h>
#include<string.h>
#include<time.h>

int main(){


    int x, y, soma=0, sacas=0, resto=0;
    while(scanf("%d %d", &x, &y)!=EOF){
    int m[x][y];
    for(int i=0; i<x; i++){
        for(int j=0; j<y; j++){
            scanf("%d", &m[i][j]);
        }
    }
    for(int i=0; i<x; i++){
        for(int j=0; j<y; j++){
            soma+=m[i][j];
        }
    }
    sacas=soma/60;
    resto=soma%60;
    printf("%d saca(s) e %d litro(s)\n", sacas, resto);
    soma=0;
    }
}