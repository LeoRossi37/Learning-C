#include <bits/stdc++.h>
using namespace std;

int F(int i){
    int a=0, b=1, aux;
    if(i==0){
        return 0;
    }
    if(i==1){
        return 1;
    }
    for(int j=2; j<=i; j++){
        aux=a+b;
        a=b;
        b=aux;
    }

    return b;

}

int main(){
    int a;
    cin >> a;
    cout << F(a);
}