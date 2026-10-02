#include<bits/stdc++.h>

using namespace std;

int Soma(int a){
    int soma=0;
    for(int i=a; i>0; i--){
        soma+=i;
    }
    return soma;
}

int main(){
    int x;
    cin >> x;
    cout << Soma(x);
}