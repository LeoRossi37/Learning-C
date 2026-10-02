#include <bits/stdc++.h>
using namespace std;

void transposicaoParImpar(int x[], int n){
    int troca=1;
    while(troca){
        troca=0;
        for(int i=1; i<n-1; i+=2){
            if(x[i]>x[i+1]){
                int temp=x[i];
                x[i]=x[i+1];
                x[i+1]=temp;
                troca=1;
            }
        }
        for(int i=0; i<n-1; i+=2){
            if(x[i]>x[i+1]){
                int temp=x[i];
                x[i]=x[i+1];
                x[i+1]=temp;
                troca=1;
            }
        }
    }
}

int main(){
    int x[6]={5,3,2,8,1,4};
    int n=6;
    transposicaoParImpar(x,n);
    for(int i=0; i<n; i++){
        cout << x[i] << " ";
    }
}


// a) Termina quando não há trocas feitas em uma passagem completa pelo vetor

// c) É O(n^2), pois há dois for na função!