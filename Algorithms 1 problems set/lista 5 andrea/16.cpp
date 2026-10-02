#include<bits/stdc++.h>

using namespace std;

int Ackerman(int m, int n){
    if(m==0){
        return n+1;
    }else if(n==0 && m!=0){
        return Ackerman(m-1,1);
    }else if(m!=0 && n!=0){
        return Ackerman(m-1, Ackerman(m,n-1));
    }
    return 0;

    // Se for negativo vai retornar 0 independentemente do numero

}

int AckermanIt(int m, int n){
    int pilha[10000];
    int topo = -1;

    pilha[++topo] = m;

    while(topo >= 0){
        m = pilha[topo--];

        if(m == 0){
            n = n + 1;
        }else if(n == 0){
            n = 1;
            pilha[++topo] = m - 1;
        }else{
            pilha[++topo] = m - 1;
            pilha[++topo] = m;
            n = n - 1;
        }
    }

    return n;
}

int main(){
    int x, y;
    cin >> x >>y;
    cout << endl;
    cout << Ackerman(x,y) << endl;
    cout << AckermanIt(x,y) << endl;


}

