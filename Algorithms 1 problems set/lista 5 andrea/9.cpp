#include <bits/stdc++.h>
using namespace std;

int elev(int a, int b){
    if(b==0){
        return 1;
    }
    return a*elev(a,b-1);
}


int main(){
    int n,x, op;
    do{
    cout << "Escreva o primeiro numero pra ser elevado ao segundo numero:";
    cin >> n >> x;
    cout << elev(n,x) << endl;
    do{
        cout << "Deseja fazer novamente?(1-sim/2-nao)" << endl;
        cin >> op;
        }while(op!=2 && op!=1);
    }while(op==1);
    
}