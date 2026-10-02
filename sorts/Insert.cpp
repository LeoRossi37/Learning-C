#include <bits/stdc++.h>
using namespace std;

int Insert(int v[],int n){
    int j;
    for(int i=1; i<n; i++){
        int aux=v[i];
        for( j=i-1; (j>=0) && aux<v[j];j--)
            v[j+1]=v[j];
        v[j+1]=aux;
    }
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
    Insert(v,tam);
    cout << "Vetor ordenado:\n";
    for(int i=0; i<tam;i++){
        cout << v[i] << " "; 
    }


}