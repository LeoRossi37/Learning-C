#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    while(getline(cin,s)){
        if(s.size()==0) continue;
        s.erase(remove(s.begin(), s.end(), ' '), s.end());
        int p = s.find('+');
        int q = s.find('=');
        string a = s.substr(0,p);
        string b = s.substr(p+1, q-p-1);
        string c = s.substr(q+1);
        long long A,B,C;
        if(isalpha(a[0])){
            B = stoll(b);
            C = stoll(c);
            A = C - B;
            cout << A << '\n';
        } else if(isalpha(b[0])){
            A = stoll(a);
            C = stoll(c);
            B = C - A;
            cout << B << '\n';
        } else {
            A = stoll(a);
            B = stoll(b);
            C = A + B;
            cout << C << '\n';
        }
    }
    return 0;
}
