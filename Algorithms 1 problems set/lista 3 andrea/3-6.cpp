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
	if((arq=fopen("pessoas.bin", "rb"))==NULL){
		printf("Erro de abertura no arquivo\n");
		exit(1);
	}
	int i=0;
	while(fread(&Pessoa,sizeof(Pessoa),1,arq)==1 && i<4){
	printf("Nome: %s", Pessoa[i].nome);
	printf("Idade: %d\n", Pessoa[i].idade);
	printf("Altura: %.2f\n", Pessoa[i].alt);
	i++;
	}

	
	fclose(arq);
}