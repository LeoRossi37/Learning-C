#include <bits/stdc++.h>
using namespace std;

int main(){
    int r,l;
    double vol,pi=3.1415;
    cin >> r >> l;
    vol=(4.0/3.0)*pi*pow(r,3);
    int qtd=(int)(l/vol);
    cout << qtd << endl;
}