#include <bits/stdc++.h>
using namespace std;

int F(int i){
    int sum=1;
    while(i>1){
        sum+=i;
        i--;
    }
    return sum;
}
int main(){
    int a;
    cin >> a;
    cout << F(a);

}