#include <bits/stdc++.h>
using namespace std;

int sumNat(int a){
    if(a==0){
        return 0;
    }
    return a+sumNat(a-1);
}

int main(){
    int x;
    cin >> x;
    cout << sumNat(x);
}