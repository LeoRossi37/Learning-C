#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, x, cm=0, cj=0;
    do{

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> x;
        if(x==1){
            cj++;
        }else if(x==0){
            cm++;
        }
    }
    if(n!=0){
        cout << "Mary won " << cm << " and John won " << cj << endl;
    }
    
    cj=0;
    cm=0;
    }while(n!=0);

}