#include<bits/stdc++.h>

using namespace std;

int busca(int v[], int ini, int fim, int x){
    if(ini > fim){
        return -1;
    }
    int meio=(ini+fim)/2;
    if(v[meio]==x){
        return meio;
    }else if(v[meio]> x){
        return busca(v,ini, meio-1,x);
    }else{
        return busca(v,meio+1,fim,x);
    }

}


int main(){
    int v[10]={1,2,3,4,5,6,7,8,9,10};
    int x;
    cout << "Digite o numero que quer saber a posição";
    cin >> x;
    int r= busca(v,0,9,x);
    if(r==-1){
        cout << "Numero nao encontrado\n";
    }else{
        cout << "Encontrado na posicao: "<< r << endl;
    }

}