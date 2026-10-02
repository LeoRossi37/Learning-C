#include <bits/stdc++.h>
using namespace std;


int main(){
    FILE *arq, *vogais;
    char *palavra, texto[121];
    int count=0;
    arq=fopen("abc.txt", "r");
    vogais=fopen("vogais.txt", "w");
    if(!arq){
        printf("Erro ao abrir o arquivo 1!");
    }
    if(!vogais){
        printf("Erro ao abrir o arquivo das palvaras com vogais!");
    }
    while(fgets(texto,120,arq)!=NULL){
        printf("\t%s\n\n", texto);
        palavra=strtok(texto, " ");
        while (palavra!=NULL){
            if(toupper(palavra[0])=='A' || toupper(palavra[0])=='I' || toupper(palavra[0])=='O' || toupper(palavra[0])=='U' || toupper(palavra[0])=='E' ){
                count++;
                fprintf(vogais,"%s\n",palavra);
            }
            palavra=strtok(NULL, " ");
        }
    }
    fclose(arq); fclose(vogais);
    cout << "Foram gravadas " << count << " palavras inciadas com vogais no arquivo!" << endl;
}