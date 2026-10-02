#include <bits/stdc++.h>
using namespace std;

int main(){
    int v[6]={20,12,28,05,10,18};
    for(int i=0; i<6; i++){
        int menor=i;
        for(int j=i+1;j<6;j++){
            if(v[j]<v[menor]){
                menor=j;
            }
        }
        if(menor!=i){
                int aux=v[i];
                v[i]=v[menor];
                v[menor]=aux;
            }
        printf("Iteracao %d: ", i+1);
        for(int k=0; k<6; k++){
            printf("%d ", v[k]);
        }
        printf("\n");
    }
}