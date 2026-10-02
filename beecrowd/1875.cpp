#include <bits/stdc++.h>
using namespace std;

int main(){
    int c;
    cin >> c;
    for(int i=0; i<c; i++){
        int g, gr=0,gb=0,gg=0;
        cin >> g;
        char m,s;
        for(int j=0; j<g; j++){
           cin >> m >> s;
           if(m=='G'){
            if(s=='B') gg+=2;
            if(s=='R') gg++;
           }
           if(m=='R'){
            if(s=='G') gr+=2;
            if(s=='B') gr++;
           }
           if(m=='B'){
            if(s=='R') gb+=2;
            if(s=='G') gb++;
           }
        }
        int flag=0;
        if(gb > gg && gb > gr ){
        cout << "blue\n";
        flag=1;
    }
    if(gr > gg && gb < gr ){
        cout << "red\n";
        flag=1;
    }
    if(gr < gg && gb < gg ){
        cout << "green\n";
        flag=1;
    }
        if(gb==gg && gb==gr && gg==gr && flag==0){
        cout << "trempate\n";
    }else if((gb==gg || gb==gr || gg==gr) && flag==0){
        cout << "empate\n";
    }
    
    }
    
}