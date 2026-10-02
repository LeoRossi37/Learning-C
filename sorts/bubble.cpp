#include <bits/stdc++.h>
using namespace std;

int bubble(int v[],int n){
    int troca=1;
    for(int i=0; i<n-1 && troca; i++){
        troca=0;
        for(int j=0;j<n-1-i;j++){
            if(v[j]>v[j+1]){
                troca=1;
                int temp= v[j];
                v[j]=v[j+1];
                v[j+1]=temp;
            }
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
    bubble(v,tam);
    cout << "\nVetor ordenado:\n";
    for(int i=0; i<tam;i++){
        cout << v[i] << " "; 
    }


}