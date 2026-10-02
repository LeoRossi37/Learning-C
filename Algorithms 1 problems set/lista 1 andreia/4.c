#include<stdio.h>
#include<string.h>

int cont1(const char *s1){
    int i=0, count =0;
    while(s1[i]!= '\0'){
        if(s1[i]=='1'){
            count ++;
        }
        i++;
    }
    return(count);
} 

int main(){
    char str[20];
    scanf("%s", &str);
    int a = cont1(str);
    printf("O numero 1 aparece %d vez(es)\n", a);

}