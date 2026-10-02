#include <bits/stdc++.h>
using namespace std;

int mesa[200005];
int posi[200005];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,q;
    if(!(cin>>n)) return 0;
    cin>>q;

    for(int i=1;i<=n;i++){
        mesa[i]=i;
        posi[i]=i;
    }

    while(q--){
        int t; cin>>t;
        if(t==1){
            int a,b; cin>>a>>b;
            int ta = posi[a];
            int tb = posi[b];
            swap(posi[a], posi[b]);
            swap(mesa[ta], mesa[tb]);
        }else{
            int a; cin>>a;
            int cnt=0;
            int x=a;
            while(mesa[x]!=a){
                x = mesa[x];
                cnt++;
            }
            cout<<cnt<<"\n";
        }
    }
    return 0;
}
