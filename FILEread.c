#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

struct BANCO{
    int regs;
    int num;
    char nome[20];
}banco;

int main(){
    FILE *arq;
    arq = fopen("banco.txt", "r");
    if(!arq){
        printf("Erro na abertura do arquivo!\n");
        exit(1);
    }
    
        while(fread(&banco,sizeof(banco),1,arq)!=NULL){
            printf("Nome: %s\n", banco.nome);
            printf("Registro: %d\n", banco.regs);
            printf("Numero da agencia: %d\n", banco.num);
        };


       
    }