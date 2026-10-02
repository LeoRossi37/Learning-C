#include <stdio.h>
#include <string.h>
#include <ctype.h>

void palavra(char *f){
    char *c;
    c=strtok(f," ,.-");
    printf("Dividindo as palavras da frase:\n");
    while(c!=NULL){
        printf("\t\t %s\n", c);
        c=strtok(NULL," ,.-");
    }
}


int main(){
    char str[100];
    printf("Digite uma frase:");
    fgets(str,sizeof(str),stdin);
    str[strcspn(str, "\n")] = 0;
    palavra(str);
}