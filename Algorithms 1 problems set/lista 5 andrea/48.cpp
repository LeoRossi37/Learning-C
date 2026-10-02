#include<bits/stdc++.h>

using namespace std;

double soma(double n){
    if(n<=0){
        return 0;
    }
    return (((n*n)+1)/n)+soma(n-1);
}


int main(){
double x;
cin >> x;
cout << soma(x) << endl;

}