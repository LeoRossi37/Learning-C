#include<iostream>
#include<string>
using namespace std;

int main(){
    int n;
    cin >> n;
    for(int i=0; i<n;i++){
            int x, d, pj=0, pm=0;
            for(int k=0; k<3; k++){
            cin >> x >> d;
            pj+= x*d;
            }
            for(int k=0; k<3; k++){
            cin >> x >> d;
            pm+= x*d;
            }
           if(pj>pm){
                cout << "JOAO" << endl;
           }else{
            cout << "MARIA" << endl;
           }
        } 
    
    
}