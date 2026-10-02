#include <bits/stdc++.h>
using namespace std;

int shell(int vet[], int n){
    int i, j, aux;
    for(int gap = n/2; gap > 0; gap /= 2){
        for(i = gap; i < n; i++){
            aux = vet[i];
            for(j = i; j >= gap && vet[j - gap] > aux; j -= gap){
                vet[j] = vet[j - gap];
            }
            vet[j] = aux;
        }
    }
    return 0;
}


int main(){
    int x;
    cin >> x;
    for(int i=0;i<x;i++){
        int tent;
        cin >> tent;
        int v[tent];
        for(int j=0; j< tent; j++){
            cin >> v[j];
        }
        shell(v,tent);
        vector<int> impares;
        for(int j=0; j< tent; j++){
            if((v[j])%2!=0){
                impares.push_back(v[j]);
            }   
        }
        int esq=0, dir=impares.size()-1;
        while(esq<=dir){
            if(dir>=esq){
                cout << impares[dir];
                dir--;
                if(esq<=dir)
                cout << " ";
            }
            if(esq<=dir){
                cout << impares[esq];
                esq++;
            if(esq<=dir) cout << " ";
            }
        }
        cout << endl;
    }
}