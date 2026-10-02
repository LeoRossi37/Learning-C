#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;  
    getchar();
    for(int i=0; i<n; i++){
        string s;
        int x;
        getline(cin,s);
        cin >> x;
        for(int j=0; j<s.size(); j++){
            s[j]-=x;
        }
        cout << s << endl;
    }

}