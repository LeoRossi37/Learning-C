#include<stdio.h>

int main(){
    int x;
    scanf("%d", &x);
    int v[x], i;
    for( i=0; i<x; i++){
        scanf("%d", &v[i]);
    }
    int menor=v[0], posicao=0;
    for( i=1; i<x; i++){
        if(menor>v[i]){
            menor=v[i];
        }
    }
    i=0;
    while(menor!=v[i]){
        i++;
        posicao++;
    }
        
          printf("Menor valor: %d\nPosicao: %d", menor, posicao);

}