#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    while(cin >> n){
        vector<int> dig(9,0);
        for(int i=8; i>=0; i--){
            dig[i] = n % 10;
            n /= 10;
        }

        for(int i=0; i<9; i++) cout << (dig[i] >= 5 ? '0' : '1');
        cout << endl;
        for(int i=0; i<9; i++) cout << (dig[i] >= 5 ? '1' : '0');
        cout << endl;
        cout << "---------" << endl;
        cout << endl;

        for(int linha=0; linha<5; linha++){
            for(int i=0; i<9; i++){
                int val = dig[i] % 5;
                // agora as pedras sobem de baixo pra cima
                if(linha >= 5 - val) cout << '0';
                else cout << '1';
            }
            cout << endl;
        }
        cout << endl;
    }
}
