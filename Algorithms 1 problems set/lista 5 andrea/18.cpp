#include<bits/stdc++.h>

using namespace std;

int Sum(int a[], int n){
    if(n==0){
        return 0;
    }
    return a[n-1]+Sum(a, n-1);
}

int main(){
    int op;
    do{
        int v[5], n;
        n=5;
        cout << "Digite 5 numeros para serem somados:";
        for(int i=0; i<5; i++){
            cin >> v[i];
        }
        cout << "A soma dos 5 numeros eh de: " << Sum(v,n) << endl;
        do{
            printf("Digite 1 se quer fazer de novo e 2 se nao:");
        cin >> op;
        }while(op!=2 && op!=1);
    }while(op==1);
}