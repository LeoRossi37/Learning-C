#include<iostream>

using namespace std;

int main(){
    long int n;
    
        while(cin >> n && n!=0 ){

        bool first = true;
        for(int i=1; i*i<=n; i++){
            if(!first){
                cout << " ";
            }
            cout << i*i;
            first = false;
        }
        cout << endl;
    }
}