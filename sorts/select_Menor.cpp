#include <bits/stdc++.h>
using namespace std;

int select(int v[],int n){
    for(int i=0; i<n; i++){
        int menor=i;
        for(int j=i+1;j<n;j++){
            if(v[j]<v[menor]){
                menor=j;
            }
        }
        if(menor!=i){
                int aux=v[i];
                v[i]=v[menor];
                v[menor]=aux;
            }
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
    select(v,tam);
    cout << "Vetor ordenado:\n";
    for(int i=0; i<tam;i++){
        cout << v[i] << " "; 
    }


}