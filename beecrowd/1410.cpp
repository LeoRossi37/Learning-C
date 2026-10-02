#include<iostream>

using namespace std;

int main(){
    int a, d;
    do{
        cin >> a >> d;
        int v[a], b[d];
    for (int i=0; i<a; i++){
        cin >>v[i];
    }
    for (int i=0; i<d; i++){
        cin >>b[i];
    }
    for (int i=0; i<a-1; i++){
       for (int j=i+1; j<a; j++){
            if(v[i]>v[j]){
                int temp = v[i];
                v[i] = v[j];
                v[j] = temp;
            }
        }
    }
    for (int i=0; i<d-1; i++){
       for (int j=i+1; j<d; j++){
            if(b[i]>b[j]){
                int temp = b[i];
                b[i] = b[j];
                b[j] = temp;
            }
        }
    }
    if(v[0]<b[1]){
        printf("Y\n");
    }else if(a!=0){
        printf("N\n");
    }
    }while(a!=0 && d!=0);
    



}