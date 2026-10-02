#include<bits/stdc++.h>

using namespace std;

bool Palind(char *a, int ini, int fim){
    if(ini >=fim){
        return true;
    }
    if(a[ini]!=a[fim]){
        return false;
    }
    return Palind(a,ini+1,fim-1);
}

int main(){
    char str[]="noom";
    int n=strlen(str);
    if(Palind(str,0,n-1)==true){
        cout << "Eh palindromo\n";
    }else{
        cout << "Nao eh palindromo\n";
    }
}