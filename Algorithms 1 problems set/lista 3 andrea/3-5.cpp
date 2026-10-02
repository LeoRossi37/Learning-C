#include<bits/stdc++.h>

using namespace std;

struct pessoas{
	char nome[30];
	int idade;
	float alt;
	
}Pessoa;

int main(){
	FILE *arq;
	pessoas Pessoa[4];
	if((arq=fopen("pessoas.bin", "wb"))==NULL){
		printf("Erro de abertura no arquivo\n");
		exit(1);
	}
	for(int i=0; i<4; i++){
	printf("Digite seu nome:");
	fgets(Pessoa[i].nome,sizeof(Pessoa[i].nome),stdin);
	getchar();
	printf("Digite sua idade:");
	scanf(" %d", &Pessoa[i].idade);
	printf("Digite sua altura:");
	scanf(" %f", &Pessoa[i].alt);
	fwrite(&Pessoa,sizeof(Pessoa), 1, arq);
	}
	
	
	fclose(arq);
}