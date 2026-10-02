#include<bits/stdc++.h>

using namespace std;


int main(){
	FILE *arq;
	if((arq=fopen("teste.dat","wb"))==NULL){
		printf("Erro de abertura do arquivo\n");
		exit(1);
	}
	int v[5];
	printf("Digite 5 numeros inteiros para serem gravados no arquivo:");
	for(int i=0; i<5; i++){
		scanf("%d", &v[i]);
		fwrite(&v[i], sizeof(v[i]), 1, arq);
	}
	
	fclose(arq);
	
	
}