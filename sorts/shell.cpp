#include <bits/stdc++.h>
using namespace std;

int shell(int vet[],int n){
    int i, j, gap, aux;
    for(gap=n/2; gap>0; gap/=2){
        for(i=gap; i< n; i++){
            aux=vet[i];
            for(j=i-gap; j>=0 && aux<vet[j]; j-=gap){
                vet[j+gap]=vet[j];
            }
            vet[j+gap]=aux;
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
    shell(v,tam);
    cout << "\nVetor ordenado:\n";
    for(int i=0; i<tam;i++){
        cout << v[i] << " "; 
    }


}