#include <bits/stdc++.h>
using namespace std;

int main(){
    FILE *entrada, *saida;
    int lin, col, nzeros;
    
    entrada = fopen("matriz.txt", "w");
    
    if(!entrada){
        printf("Erro ao abrir arquivo!\n");
        exit(1);
    }
    printf("Digite o quantas linhas e colunas tem e quantos 0 quer colocar:");
    scanf("%d %d %d", &lin, &col, &nzeros);
    fprintf(entrada,"%d %d %d\n", lin, col, nzeros);
    for(int i=0; i<nzeros; i++){
    int x,y;
    printf("Digite a posicao dos 0's que quer colocar:");
    scanf("%d %d", &x, &y);
    fprintf(entrada, "%d %d\n", x, y);
    }
    fclose(entrada);
    entrada = fopen("matriz.txt", "r");
    saida = fopen("matriz_saida.txt", "w");
    if(!entrada || !saida){
        printf("Erro ao abrir arquivo!\n");
        exit(1);
    }
    int matriz[lin][col];
    for(int i=0; i<lin; i++){
        for(int j=0; j<col; j++){
            matriz[i][j] = 1;
        }
    }
    for(int k=0; k<nzeros; k++){
        int x, y;
        fscanf(entrada, "%d %d", &x, &y);
        matriz[x-1][y-1] = 0; 
    }
    for(int i=0; i<lin; i++){
        for(int j=0; j<col; j++){
            fprintf(saida, "%d ", matriz[i][j]);
        }
        fprintf(saida, "\n");
    }

    fclose(entrada);
    fclose(saida);

    printf("Arquivo 'matriz_saida.txt' gerado com sucesso!\n");
    return 0;
}
