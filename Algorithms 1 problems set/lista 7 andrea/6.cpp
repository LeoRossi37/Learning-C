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
    int x;
    cin >> x;
    int v[x];
    for(int i=0; i<x; i++){
        cin >> v[i];
    }
    shell(v,x);
    int count[x], maior=0;
    for(int i=0; i<x;i++){
        count[i]=0;
            if(v[i]==v[i+1]){
                count[i]++;
                if(count[i]>maior){
                    maior=v[i];
                }
            }
    }
    printf("%d\n", maior);
}