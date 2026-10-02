#include <bits/stdc++.h>
using namespace std;

void ordenaContagem(int x[], int n){
    int count[n], y[n];
    for(int i=0; i<n; i++){
        count[i]=0;
        for(int j=0; j<n; j++){
            if(x[j]<x[i])
                count[i]++;
        }
    }
    for(int i=0; i<n; i++){
        y[count[i]]=x[i];
    }
    
    for(int i=0; i<n; i++){
        x[i]=y[i];
    }
}

int main(){
    int x[6]={5,3,2,5,1,4};
    int n=6;
    ordenaContagem(x,n);
    for(int i=0; i<n; i++){
        cout << x[i] << " ";
    }
}
