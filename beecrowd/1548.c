#include<stdio.h>

int main(){
    int n, x, count =0;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &x);
        int v[x], m[x];
        for(int j=0; j<x; j++){
            scanf("%d", &v[j]);
            m[j]=v[j];
        }
        for(int k=0; k<x-1;k++){
           for(int l=k+1; l<x; l++){
            if(m[k]<m[l]){
                int temp= m[k];
                m[k]=m[l];
                m[l]=temp;
            }
           }
        }
        count=0;
        for(int j=0; j<x; j++){
            if(m[j]==v[j]){
                count++;
            }
        }
    printf("%d\n", count);
    }

}