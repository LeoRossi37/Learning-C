#include <bits/stdc++.h>
using namespace std;

void quickSort(int v[],int ini, int fim){
    int pivo;
    if(ini>=fim) return;
    pivo=ini;
    for(int j=ini; j<fim; j++){
        if(v[j]<=v[fim]){
            int temp=v[pivo];
            v[pivo]=v[j];
            v[j]=temp;
            pivo++;
        }
    }
    int temp=v[pivo];
    v[pivo]=v[fim];
    v[fim]=temp;
    quickSort(v,ini,fim-1);
    quickSort(v,ini+1,fim);
}


int main(){
    int tam;
    printf("Digite o tamanho do vetor:");
    cin >> tam;
    int v[tam];
    cout << "Digite os valores para o vetor:";
    for(int i=0; i<tam;i++){
        cin >> v[i];
    }
    cout << "Vetor nao ordenado:\n";
    for(int i=0; i<tam;i++){
        cout << v[i] << " "; 
    }
    quickSort(v,0,tam);
    cout << "Vetor ordenado:\n";
    for(int i=0; i<tam;i++){
        cout << v[i] << " "; 
    }


}