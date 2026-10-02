#include <bits/stdc++.h>
using namespace std;


int main (){
    double n, res=1;
    cin >> n;
    for(int i=0;i<n;i++){
        double x;
        char a;
        cin >> x >> a;
        if(a=='*') res*=x;
        else res/=x;
    }
    cout << fixed << setprecision(0) << res << endl;

}