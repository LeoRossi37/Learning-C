#include<bits/stdc++.h>
using namespace std;

int main(){

    int hora, minuto;
    while(cin >> hora >> minuto){
        int h=hora/30;
        int min=minuto/6;
        cout << setfill('0') << setw(2) << h << ":" << setfill('0') << setw(2) << min << endl;
    }
}

