#include<iostream>
#include<string>
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int caso=1; caso<=t; caso++){
        string metodo;
        int r, g, b;
        cin >> metodo >> r >> g >> b;
        int p=0;

        if(metodo=="min"){
            p=min(r,min(g,b));
        }else if(metodo=="max"){
            p=max(r,max(g,b));
        }else if(metodo=="mean"){
            p=(r+g+b)/3;
        }else if(metodo=="eye"){
            p=(0.3*r)+(0.59*g)+(0.11*b);
        }

        cout << "Caso# " << caso << ": " << p << endl; 
    }

}