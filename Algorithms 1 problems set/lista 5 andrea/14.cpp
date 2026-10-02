#include <bits/stdc++.h>
using namespace std;

int F (int n){
if (n == 0)
return 1;
if (n == 1)
return 2;
return 2*F(n-2)*F(n-1);
}

int main(){
    int op;
    do{
    int x;
    cin >> x;
    cout << F(x) << endl << endl; 
    cin >> op;
    }while (op ==1);
}


// Sequencia numeria eh de: 1,2,4,16,128,4096....
// Porque funciona como F(3)=2x2x4=16;
// F(4)=2x4x16=128 e assim em diante puxando o resultado pra multiplicação
// Mantendo o primeiro 2 e trocando os outros dois termos