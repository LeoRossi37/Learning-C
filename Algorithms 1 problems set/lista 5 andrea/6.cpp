#include <bits/stdc++.h>
using namespace std;

// Na função iterativa roda muito mais rápido
// Na função recursiva quando passa do 33o numero de fibonacci ele começa a demorar pra rodar!

int fibo(int a){
    if(a==0){
        return 0;
    }
    if(a==1){
        return 1;
    }
    int f1,f2,f3;
    f1=f2=1;
    for(int i=2; i<a; i++){
    f3=f1+f2;
    f1=f2;
    f2=f3;
    }
    return f2;

}

int fiboRecurs(int a){
    if(a==0){
        return 0;
    }
    if(a==1){
        return 1;
    }
    return fiboRecurs(a-1)+fiboRecurs(a-2);
}


int main(){
    int x;
    cin >> x;
    cout << fibo(x) << endl;
    cout << fiboRecurs(x);
}