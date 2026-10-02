#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char str[200], repete[50];
    printf("Digite uma frase: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0;

    printf("Sua frase é: %s\n", str);

    printf("Digite a palavra que você quer ver quantas vezes se repete: ");
    fgets(repete, sizeof(repete), stdin);
    repete[strcspn(repete, "\n")] = 0;

    int count = 0;
    char *p = str;

    while ((p = strstr(p, repete)) != NULL) {
        count++;
        p++;
    }

    printf("A palavra \"%s\" se repete %d vezes na frase.\n", repete, count);
    return 0;
}
