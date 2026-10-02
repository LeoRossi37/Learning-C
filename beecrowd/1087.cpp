#include <bits/stdc++.h>
using namespace std;

int F (int i){
if (i == 0)
return 0;
if (i == 1)
return 1;
return F(i-1) + F(i-2);
}

int main() {
    int j=15;
    cout << F(15);

    return 0;
}
