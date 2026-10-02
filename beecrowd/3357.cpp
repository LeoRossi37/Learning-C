#include <bits/stdc++.h>
using namespace std;


int main(){
    cout << fixed << setprecision(1);
    int n;
    float q, l;
    vector<string> nome;
    cin >> n >> q >> l;
    string x;
    for(int i = 0; i < n; i++){
        cin >> x;
        nome.push_back(x);
    }
    float a = q;
    int passos_totais = 0;
    while(true){
        if(a-l<=0) break;
        a -= l;
        passos_totais++;
    }

    int indice_vencedor;
    if (passos_totais == 0) {
        indice_vencedor = 0;
    } else {
        indice_vencedor = (passos_totais ) % n;
    }
    cout << nome[indice_vencedor] << " " << a << endl;
    return 0;
}