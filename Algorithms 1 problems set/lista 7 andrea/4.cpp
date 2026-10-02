#include <bits/stdc++.h>
using namespace std;

int Insercao (int n, float *vet) {
float aux;
int i, j;
for (i = 1; i < n; i++) {
aux = vet[i];
j = i - 1;
while (j >= 0 && aux > vet[j] ) { // troquei o menor por maior em "aux<vet[j]" 
vet[j+1] = vet[j];
j = j - 1;
}
vet[j+1] = aux;
}
}

int main(){
    float v[6]={2,1,4,5,78,10};
    int n=6;
    Insercao(n,v);
    for(int i=0; i< 6; i++){
        cout << v[i] << " ";
    }
}