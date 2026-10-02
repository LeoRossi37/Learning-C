#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, g;
    cin >> n >> g;
    char v[n];
    int x[n];
    for(int i=0; i<n; i++){
        cin >> v[i] >> x[i];
    }
    int esc;
    cin >> esc;
    char vet[esc];
    for(int i=0; i<esc; i++){
        cin >> vet[i];
    }
    int soma=0;
     for(int i=0; i<n; i++){
        for(int j=0; j<esc;j++){
            if(vet[j]==v[i]){
                soma+=x[i];
            }
        }
    }
    cout << soma << endl;
    if(soma>=g){
        cout << "You shall pass!\n";
    }else{
        cout << "My precioooous\n";
    }
}