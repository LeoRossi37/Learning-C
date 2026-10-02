#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
int main() {
    FILE *original,*copia;
    char caracter, nome[13], nome_novo[13];
    int count=0, c2=0, c3=0, c4=0;
    printf("\nDigite o nome do arquivo: ");
    gets (nome);
    printf("\nDigite o nome do arquivo copia: ");
    gets (nome_novo);
    if ((original = fopen(nome,"r")) == NULL) {
    printf("\nErro ao abrir o arquivo original.\n\n");
    exit(1);
}
    if ((copia = fopen(nome_novo,"w")) == NULL) {
        printf("\nErro ao abrir o arquivo cópia.\n\n");
        exit(1);
}
    while(!feof(original)) {
    caracter = getc (original);
    if (!feof(original))
    if(toupper(caracter)=='A' ||toupper(caracter)=='I' ||  toupper(caracter)=='E' || toupper(caracter)=='O' || toupper(caracter)=='U'){
        count++;
    }
    if(caracter==' '){
        c2++;
    }
    if(isalpha(caracter) && (toupper(caracter)!='A' && toupper(caracter)!='I' &&  toupper(caracter)!='E' && toupper(caracter)!='O' && toupper(caracter)!='U')){
        c3++;
    }
    if(isdigit(caracter)){
        c4++;
    }
        putc (caracter,copia);
}
    fclose(original);
    fclose(copia);
        printf("\n%s copiado com sucesso com o nome de %s.\n\n",nome,nome_novo);
        printf("%d vogais\n %d espacos\n %d consoantes\n %d numeros\n", count, c2, c3, c4);
    return 0;
}