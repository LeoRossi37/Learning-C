#include<iostream>

using namespace std;

int main(){
     int n;
     while(cin >> n && n!=0){
        int v[n];
        for(int i=0; i<n; i++){
            cin >> v[i];
        }   
        int count =0;
        for(int i=0; i<n; i++){
            int ant, prox;
            ant=v[(i-1+n)%n];
            prox=v[(i+1)%n];
            if((ant<v[i] && prox<v[i]) || (prox>v[i] && ant>v[i])){
                count ++;   
            }
            
        } 
        printf("%d\n\n\n", count);
     }

}