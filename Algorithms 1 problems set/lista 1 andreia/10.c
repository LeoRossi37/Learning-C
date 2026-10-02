#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main(){
    char a[3], b[3], str[40];
    printf("Escolha uma letra para ser trocada:");
    fgets(a,sizeof(a),stdin);
    printf("Escolha a letra que ira no lugar dessa outra:");
    fgets(b,sizeof(b),stdin);
    printf("digite uma frase para mostrar essa troca:");
    fgets(str,sizeof(str),stdin);
    for(int i=0; i<strlen(str);i++){
        if(toupper(str[i])==toupper(a[0])){
            str[i]=b[0];
        }
    }
    printf("%s", str);
}