#include <bits/stdc++.h>
using namespace std;

void intercala(int x[], int n){
    if(n <= 1) return;
    int ind = (n % 2 == 0) ? n/2 : n/2 + 1;
    int small[ind], large[n - ind];
    int si = 0, li = 0;
    for(int i=0; i<n-1; i+=2){
        if(x[i] <= x[i+1]){
            small[si++] = x[i];
            large[li++] = x[i+1];
        } else {
            small[si++] = x[i+1];
            large[li++] = x[i];
        }
    }
    if(n % 2 != 0){
        small[si++] = x[n-1];
    }
    intercala(small, si);
    intercala(large, li);
    int i = 0, j = 0, k = 0;
    while(i < si && j < li){
        if(small[i] <= large[j])
            x[k++] = small[i++];
        else
            x[k++] = large[j++];
    }
    while(i < si) x[k++] = small[i++];
    while(j < li) x[k++] = large[j++];
}

int main(){
    int x[9] = {8,3,5,2,9,1,4,7,6};
    int n = 9;
    intercala(x, n);
    for(int i=0; i<n; i++)
        cout << x[i] << " ";
}
