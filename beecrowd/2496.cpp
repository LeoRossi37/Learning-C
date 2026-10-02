#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int letras;
        cin >> letras;
        string frase;
        cin >> frase;

        string ordenada = frase;
        sort(ordenada.begin(), ordenada.end());

        // Contar quantas posições diferem
        vector<int> dif;
        for(int j = 0; j < letras; j++){
            if(frase[j] != ordenada[j])
                dif.push_back(j);
        }

        bool chance = false;
        if(dif.size() == 2){
            swap(frase[dif[0]], frase[dif[1]]);
            if(frase == ordenada)
                chance = true;
        }
        if(chance)
            cout << "There are the chance.\n";
        else
            cout << "There aren't the chance.\n";
    }
}
