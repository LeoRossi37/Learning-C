#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    char s[50];
    fgets(s,sizeof(s),stdin);
    s[strcspn(s,"\n")]=0;
    for(int i=0; i< strlen(s);i++){
        s[i]+=1;
    }
    printf("%s", s);

}