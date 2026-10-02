#include<stdio.h>
#include<stdlib.h>

int main(){
    FILE *arq;
    int count=0;
    char ch;
    if((arq=fopen("arqBinario.c","r"))==NULL){
        printf("\nErro de abertura");
        exit(1);
    }
    while((ch=getc(arq))!=EOF){
        count++;
    }
    fclose(arq);
    printf("\nO arquivo contem %d caracteres\n", count);



}