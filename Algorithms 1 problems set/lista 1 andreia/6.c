#include<stdio.h>
#include<string.h>

char* strev1(const char *s1, char *s2){
    int i, j;
    for( i=0, j=strlen(s1)-1; i<strlen(s1) && j>=0;i++, j--){
       if (s1[j] != '\n') { 
            s2[i] = s1[j];
        }
        }
        s2[i]='\0';
        return s2;
    }


int main(){
    char str[20];
    char invertida[20];
    fgets(str, sizeof(str),stdin);
    strev1(str,invertida);
    printf("%s", invertida);
}