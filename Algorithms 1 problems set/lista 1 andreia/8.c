#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<conio.h>

int main(){
    char a[30];
    fgets(a, sizeof(a),stdin);
    int count =0;
    for(int i=0; i<strlen(a);i++){
        if(toupper(a[i])=='A' || toupper(a[i])=='E' || toupper(a[i])=='I' || toupper(a[i])=='O' || toupper(a[i])=='U'){
            count++;
        }
    }
    printf("%d", count);
}