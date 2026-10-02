#include<bits/stdc++.h>

using namespace std;

int main(){
	FILE *arq;
	if((arq=fopen("teste.dat","r+b"))==NULL){
		printf("Erro de abertura do arquivo\n");
		exit(1);
	}
	int v[5], novo;
	fseek(arq, 2*sizeof(int), SEEK_SET);
	scanf("%d", &novo);
	fwrite(&novo, sizeof(novo), 1, arq);
	
	fclose(arq);
	
	
	
	
}