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



int main(){
    int v[10]={1,2,3,4,5,6,7,8,9,10};
    int tam=10, n=7;
    cout <<  "O numero esta na posicao: "<< buscaBinIt(v,1,tam,n) << endl;

}