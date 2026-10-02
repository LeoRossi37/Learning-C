#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    while(cin >> n){
    double l,h,c;
    double area, comprimento;
    cin >> h >> c >> l;
    comprimento=sqrt(pow(h,2)+pow(c,2))*n;
    area=comprimento*l/10000;
    printf("%.4lf\n", area);
}
}