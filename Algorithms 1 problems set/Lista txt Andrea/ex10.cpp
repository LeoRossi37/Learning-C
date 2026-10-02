#include <bits/stdc++.h>
using namespace std;

int main(){
    FILE *arq, *copia;
    char nomeCopia[15],nome[15], caracter;
    printf("Digite o nome do arquivo original");
    gets(nome);
    printf("Digite o nome do arquivo para copiar");
    gets(nomeCopia);
    arq=fopen(nome, "r");
    if(!arq){
        cout << "Erro de abertura do arquivo ori!\n";
        exit (1);
    }
    copia=fopen(nomeCopia, "w");
    if(!copia){
        cout << "Erro de abertura do arquivo copia!\n";
        exit (1);
    }
    while(!feof(arq)){
        caracter=getc(arq);
        if(!feof(arq))
        putc(caracter,copia);
    }
    fclose(arq); fclose(copia);
    printf("\n %s copiado com sucesso para %s\n",nome, nomeCopia);


}