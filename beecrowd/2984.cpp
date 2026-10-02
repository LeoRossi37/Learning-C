#include<bits/stdc++.h>

using namespace std;

int main(){
    string a;
    cin >> a;
    int count=0;
    int x=a.size();
    for(int i=0; i<x; i++){
        if(a[i]=='(') count++;
        if(a[i]==')' && count!=0) count--;
    }
    if(count==0){
        cout << "Partiu RU!\n";
    }else{
        cout << "Ainda temos " << count << " assunto(s) pendente(s)!\n";
    }
}