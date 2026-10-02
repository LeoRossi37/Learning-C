#include <bits/stdc++.h>
using namespace std;

int main(){
    char frase [10000], par1[3],par2[3];
    fgets(frase,sizeof(frase),stdin);
    frase[strcspn(frase,"\n")]='\0';
    int n=strlen(frase);
    for(int i=2; i<n-1;i++){
        par1[0]=frase[i];
        par2[0]=frase[i-2];
        par2[1]=frase[i-1];
        par2[2]='\0';
        if(i+1<n){
            par1[1]=frase[i+1];
        }else{
            par1[1]='\0';
        }
        par1[2]='\0';
       if(strcmp(par1, par2) == 0){
            for(int j=i; j<n-1; j++){
                frase[j] = frase[j+2];
            }
            n -= 2;
            frase[n] = '\0';
            i -= 2;
            if(i<2) i=2;
        }
    }

    cout << frase << endl;

}