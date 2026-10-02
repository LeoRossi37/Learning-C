#include<bits/stdc++.h>

using namespace std;

int busca(int *v, int n, int num){
    for(int i=0; i<n;i++){
        if(v[i]==num){
            return i;
        }
    }
    return -1;
}

int buscaOrd(int *v, int n, int num){
    for(int i=0;i< n && v[i]<=num; i++){
        if(v[i]==num){
            return i;
        }
    }
    return -1;
}

int buscaRec(int *v, int n, int num){
    if(n==0){
        return 0;
    }
    if(v[n-1]==num){
        return n-1;
    }
    return buscaRec(v,n-1,num);
}

int buscaRecOrd(int *v, int n, int num){
    if(n==0 || num>v[n-1]){
        return -1;
    }
    if(v[n-1]==num){
        return n-1;
    }
    return buscaRecOrd(v,n-1,num);
}

int main(){
    int v[10]={1,2,3,4,5,6,7,8,9,10};
    int x[10]={4,2,1,5,3,10,6,8,9,7};
    int tam=10, n=7;
    cout <<  "O numero esta na posicao: "<< busca(x,tam,n) << endl;
    cout <<  "O numero esta na posicao: "<< buscaOrd(v,tam,n) << endl;
    cout <<  "O numero esta na posicao: "<< buscaRec(x,tam,n) << endl;
    cout <<  "O numero esta na posicao: "<< buscaRecOrd(v,tam,n) << endl;
}