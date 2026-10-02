#include<stdio.h>
#include<ctype.h>
#include<string.h>



int main(){
    int x;
    scanf("%d", &x);
    f1(x);
    return 0;
}


void f1(int x){
    int fact=1;
    for(int i=1; i<x; i++){
        fact*=i;
    }
    printf("O fatorial de %d, eh: %d", x, fact);

}