#include <bits/stdc++.h>
using namespace std;

int comb(int n, int k){
    if(k==0 || k==n){
        return 1;
    }
    if(k>n){
        return 0;
    }

    return comb(n-1,k-1) + comb(n-1,k);

}

int main (){
    int po;
    do{
    int a, b;
    cin >> a >> b;
    cout << comb(a,b);
        do{
        cout << "\nDigite 1 para fazer novamente e 2 para sair\n";
        cin >> po;
        }while(po!=1 && po!=2);
    }while (po==1);

}