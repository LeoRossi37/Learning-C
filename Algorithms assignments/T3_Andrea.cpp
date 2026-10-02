#include <bits/stdc++.h>
using namespace std;

// Gnome Sort!

int main(){
    int n;
    cin >> n;
    int v[n];
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    int pos=1;
    while(pos<n){
        if(v[pos]>=v[pos-1]){
            pos++;
        }else{
            int aux=v[pos];
            v[pos]=v[pos-1];
            v[pos-1]=aux;
            if(pos>1) pos--;
            else pos=1;
        }
    }
    for(int i=0;i<n;i++){
        cout << v[i] << " ";
    }
}
