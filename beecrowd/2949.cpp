#include<bits/stdc++.h>

using namespace std;

int main(){
    int a=0, e=0, h=0, m=0, x=0;
    int n;
    cin >> n;
    for(int i=0; i< n; i++){
        char tipo;
        char nome[15];
        cin >> nome >> tipo;
        if(toupper(tipo)=='X'){
            x++;
        }
        if(toupper(tipo)=='E'){
            e++;
        }
        if(toupper(tipo)=='H'){
            h++;
        }
        if(toupper(tipo)=='M'){
            m++;
        }
        if(toupper(tipo)=='A'){
            a++;
        }
    }
    cout << x << " Hobbit(s)\n";
    cout << h << " Humano(s)\n";
    cout << e << " Elfo(s)\n";
    cout << a << " Anao(oes)\n";
    cout << m << " Mago(s)\n";

}