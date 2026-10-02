#include<bits/stdc++.h>

using namespace std;

int main(){
	FILE *arq;
	if((arq=fopen("teste.dat","r+b"))==NULL){
		printf("Erro de abertura do arquivo\n");
		exit(1);
	}
	int v[5], i=0; 
	while(fread(&v[i], sizeof(v[i]), 1, arq)==1 && i<5){
 	printf("%d", v[i]); 
 	i++; 
 	cout << endl; }
	fclose(arq);
	
	
	
	
}