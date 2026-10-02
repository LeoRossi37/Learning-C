#include <bits/stdc++.h>
using namespace std;

int buscabinaria2 (int x, int n, int v[]) {
int e, m, d;
e = -1; d = n;
while (e < d-1) {
m = (e + d)/2;
if (v[m] < x) e = m;
else d = m;
}
return d;
}

int main(){
    int x1,x2,x3,x4,x5, n=15;
    x1=2; x2=5; x3=13; x4=0;x5=9;
    int v[n]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14};
    cout << buscabinaria2(x1,n,v) << endl;
    cout << buscabinaria2(x2,n,v) << endl;
    cout << buscabinaria2(x3,n,v) << endl;
    cout << buscabinaria2(x4,n,v) << endl;
    cout << buscabinaria2(x5,n,v) << endl;
}

// m na primeira iteração pode ser 7 na segunda 3 ou 11, na terceira 1 ou 5 ou 9 ou 13 e na quarta 2,6,10,14