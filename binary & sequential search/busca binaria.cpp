#include <bits/stdc++.h>
using namespace std;

int buscaBinIt(int *v,int esq, int dir, int num){
    int meio;
    while(esq<=dir){
        meio=(esq+dir)/2;
        if(v[meio]==num){
            return meio;
        }
        if(num>v[meio]){
            esq=meio+1;
        }else{
            dir=meio-1;
        }
    }
    return -1;
}


int buscaBinRec(int *v,int esq, int dir, int num){
    int meio=(esq+dir)/2;
    if(esq>dir){
        return -1;
    }
    if(v[meio]==num){
        return meio;
    }
    if(v[meio]>num){
         return buscaBinRec(v,esq,meio-1,num);
    }else{
         return buscaBinRec(v,meio+1,dir,num);
    }
}


int main(){
    int v[10]={1,2,3,4,5,6,7,8,9,10};
    int tam=10, n=7;
    cout <<  "O numero esta na posicao: "<< buscaBinIt(v,0,tam-1,n) << endl;
    cout <<  "O numero esta na posicao: "<< buscaBinRec(v,0,tam-1,n) << endl;

}