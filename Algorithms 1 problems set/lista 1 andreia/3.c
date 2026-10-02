#include<stdio.h>
#include<string.h>

int strcmp(const char *s1, const char *s2){
    int i=0;
    while(s1[i]!='\0' && s2[i]!='\0'){
        if(s1[i]!=s2[i]){
            return(s1[i]-s2[i]);
        }
        i++;
    }
    return(s1[i]-s2[i]);
}
int main(){
    char a[100], b[100];
    scanf("%s %s", &a, &b);
    int r = strcmp(a,b);
    if(r==0){
        printf("Strings iguais\n");
    }else if(r>0){
        printf("|%s| vem depois da string |%s|\n", a, b);
    }else{
         printf("|%s| vem primeiro que a string |%s|\n", a, b);
    }
    return 0;
}