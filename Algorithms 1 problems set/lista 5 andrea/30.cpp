#include<bits/stdc++.h>

using namespace std;

void Permuta(char *a, int ini, int fim){
    if(ini==fim){
        cout << a << endl;
    }else{
        for(int i = ini; i<=fim; i++){
            char temp;
            temp =a[ini];
            a[ini]=a[i];
            a[i]=temp;
            Permuta(a,ini+1,fim);
            temp = (a[ini]);
            a[ini]=a[i];
            a[i]=temp;
        }
    }


}

int main(){
    char str[] = "ABC";
    int n=strlen(str);

    cout << "Permutacoes de '%s': " << str << "\n";
    Permuta(str,0,n-1);
}   
