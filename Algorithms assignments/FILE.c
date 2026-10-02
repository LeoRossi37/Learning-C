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
    char rep;
    arq = fopen("banco.txt", "at");
    if(!arq){
        printf("Erro na abertura do arquivo!\n");
        exit(1);
    }
    do{
        printf("Digite o numero do seu registro:");
        scanf("%d", &banco.regs);
        printf("Digite o numero da agencia:");
        scanf("%d", &banco.num);
        printf("Digite seu nome:");
        scanf("%s", &banco.nome);
        fwrite(&banco,sizeof(banco),1,arq);
        do{
            printf("Deseja registrar novamente?(S-sim/N-nao):\n");
            scanf("%s", &rep);
        }while(toupper(rep)!='S' && toupper(rep)!='N');
    }while(toupper(rep)=='S');

    



}