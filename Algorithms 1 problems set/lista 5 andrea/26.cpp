#include<bits/stdc++.h>

using namespace std;

int T(int t){
    if(t==1){
        return 1;
    }
    return T(t-1)+3;
}

int main(){
    int x;
    cin >> x;
    cout << T(x);
}