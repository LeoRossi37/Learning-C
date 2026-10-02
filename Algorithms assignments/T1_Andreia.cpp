#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#ifdef _WIN32
#include <windows.h>
#endif

int inteiro(const char *msg){
    char buffer[100];
    int valido, num;
    do{
        valido = 1;
        printf("%s", msg);
        if(fgets(buffer, sizeof(buffer), stdin) == NULL){
            valido = 0;
        }
        buffer[strcspn(buffer, "\n")] = 0;
        if(buffer[0] == '\0') valido = 0;
        for(int i=0; buffer[i] && valido; i++){
            if(!isdigit((unsigned char)buffer[i])){
                valido = 0;
                break;
            }
        }
        if(valido){
            num = (int)strtol(buffer, NULL, 10);
        } else {
            printf("Entrada inválida! Digite apenas números.\n");
        }
    }while(!valido);
    return num;
}

double doble(const char *msg){
    char buffer[100];
    int valido;
    double num;
    do{
        valido = 1;
        printf("%s", msg);
        if(fgets(buffer, sizeof(buffer), stdin) == NULL){
            valido = 0;
        }
        buffer[strcspn(buffer, "\n")] = 0;
        if(buffer[0] == '\0') valido = 0;
        int ponto = 0;
        for(int i=0; buffer[i] && valido; i++){
            if(!isdigit((unsigned char)buffer[i])){
                if((buffer[i] == '.' || buffer[i] == ',') && !ponto){
                    ponto = 1;
                    if(buffer[i] == ',') buffer[i] = '.';
                }else{
                    valido = 0;
                    break;
                }
            }
        }
        if(valido){
            num = strtod(buffer, NULL);
        } else {
            system("cls");
            printf("Entrada inválida! Digite apenas números (use '.' ou ',' para decimais).\n");
        }
    }while(!valido);
    return num;
}

void extensoGrupo(int n,
                  char *unidades[],
                  char *dez_a_dezenove[],
                  char *dezenas[],
                  char *centenas[]){
    if(n == 0) return;
    if(n == 100){
        printf("cem ");
        return;
    }
    int temCentena = n / 100;
    int resto = n % 100;
    if(temCentena > 0){
        if(temCentena == 1 && resto != 0){
            printf("cento ");
        } else {
            printf("%s ", centenas[temCentena]);
        }
        if(resto > 0) printf("e ");
    }
    if(resto >= 10 && resto < 20){
        printf("%s ", dez_a_dezenove[resto - 10]);
        return;
    } else if(resto >= 20){
        printf("%s ", dezenas[resto / 10]);
        if(resto % 10 > 0) printf("e ");
        resto %= 10;
    }
    if(resto > 0){
        printf("%s ", unidades[resto]);
    }
}

void opc1(){
    long long int bit100=0, bit50=0, bit20=0, bit10=0, bit5=0, bit2=0;
    long long int cent100=0, cent50=0, cent10=0, cent5=0, cent1=0;
    double bitsin, bitsout, bitsorigin;
    long long int valor;
    bitsorigin = doble("Digite a quantidade de bit(s) a ser sacada: ");
    bitsin = bitsorigin;
    valor = (long long int)(bitsin * 100 + 0.5);
    while(valor > 0){
        if(valor >= 10000){
            bitsout = valor/10000;
            valor = valor%10000;
            bit100 += (int)bitsout;
         }else if(valor >= 5000){
            bitsout = valor/5000;
            valor = valor%5000;
            bit50 += (int)bitsout;
        }else if(valor >= 2000){
            bitsout = valor/2000;
            valor = valor%2000;
            bit20 += (int)bitsout;
        }else if(valor >= 1000){
            bitsout = valor/1000;
            valor = valor%1000;
            bit10 += (int)bitsout;
         }else if(valor >= 500){
            bitsout = valor/500;
            valor = valor%500;
            bit5 += (int)bitsout;
        }else if(valor >= 200){
            bitsout = valor/200;
            valor = valor%200;
            bit2 += (int)bitsout;
          }else if(valor >= 100){
            bitsout = valor/100;
            valor = valor%100;
            cent100 += (int)bitsout;
        }else if(valor >= 50){
            bitsout = valor/50;
            valor = valor%50;
            cent50 += (int)bitsout;
        }else if(valor >= 10){
            bitsout = valor/10;
            valor = valor%10;
            cent10 += (int)bitsout;
         }else if(valor >= 5){
            bitsout = valor/5;
            valor = valor%5;
            cent5 += (int)bitsout;
        }else{
            cent1 += valor;
            valor = 0;
        }
    }
    printf("Para a quantia B$ %.2lf, foram entregues:\n", bitsorigin);
    if(bit100!=0) printf("%lld nota(s) de 100\n", bit100);
    if(bit50!=0) printf("%lld nota(s) de 50\n", bit50);
    if(bit20!=0) printf("%lld nota(s) de 20\n", bit20);
    if(bit10!=0) printf("%lld nota(s) de 10\n", bit10);
    if(bit5!=0) printf("%lld nota(s) de 5\n", bit5);
    if(bit2!=0) printf("%lld nota(s) de 2\n", bit2);
    if(cent100!=0) printf("%lld moeda(s) de 1 Bit\n", cent100);
    if(cent50!=0) printf("%lld moeda(s) de 50 Centbits\n", cent50);
    if(cent10!=0) printf("%lld moeda(s) de 10 Centbits\n", cent10);
    if(cent5!=0) printf("%lld moeda(s) de 5 Centbits\n", cent5);
    if(cent1!=0) printf("%lld moeda(s) de 1 Centbits\n", cent1);
}

void opc2(){
    char *unidades[] = {"", "um", "dois", "três", "quatro", "cinco", "seis", "sete", "oito", "nove"};
    char *dezenas[] = {"", "dez", "vinte", "trinta", "quarenta", "cinquenta", "sessenta", "setenta", "oitenta", "noventa"};
    char *centenas[] = {"", "cem", "duzentos", "trezentos", "quatrocentos", "quinhentos", "seiscentos", "setecentos", "oitocentos", "novecentos"};
    char *dez_a_dezenove[] = {"dez", "onze", "doze", "treze", "quatorze", "quinze", "dezesseis", "dezessete", "dezoito", "dezenove"};
    double valor = doble("Digite o valor do cheque (ex: 2103.42): ");
    long long int inteiro = (long long int)valor;
    int centavos = (int)((valor - inteiro) * 100 + 0.5);
    printf("Valor por extenso: ");
    if(inteiro == 0){
        printf("zero bit");
    } else {
        int bilhoes = (int)(inteiro / 1000000000LL);
        int milhoes = (int)((inteiro / 1000000LL) % 1000);
        int milhares = (int)((inteiro / 1000LL) % 1000);
        int unidades_ = (int)(inteiro % 1000);
        int printed = 0;
        if(bilhoes > 0){
    extensoGrupo(bilhoes, unidades, dez_a_dezenove, dezenas, centenas);
    printf("%s", bilhoes > 1 ? "bilhões" : "bilhão");
    if(milhoes > 0 || milhares > 0 || unidades_ > 0) printf(", ");
}

if(milhoes > 0){
    extensoGrupo(milhoes, unidades, dez_a_dezenove, dezenas, centenas);
    printf("%s", milhoes > 1 ? "milhões" : "milhão");
    if(milhares > 0 || unidades_ > 0) printf(", ");
}

if(milhares > 0){
    extensoGrupo(milhares, unidades, dez_a_dezenove, dezenas, centenas);
    printf("mil");
    if(unidades_ > 0) printf(", ");
}

if(unidades_ > 0){
    if(bilhoes > 0 || milhoes > 0 || milhares > 0) printf("e ");
    extensoGrupo(unidades_, unidades, dez_a_dezenove, dezenas, centenas);
}

        printf("bits");
    }
    if(centavos > 0){
        printf(" e ");
        if(centavos >= 10 && centavos < 20){
            printf("%s ", dez_a_dezenove[centavos-10]);
        } else {
            if(centavos/10 > 0){
                printf("%s ", dezenas[centavos/10]);
                if(centavos%10 > 0) printf("e ");
            }
            if(centavos%10 > 0){
                printf("%s ", unidades[centavos%10]);
            }
        }
        printf("centbits");
    }
    printf("\n");
}

int main(){
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif
    int rep;
    int op, senha;
    do{
        do{
            do{
                senha = inteiro("\n\t\tDigite sua senha para acessar o caixa:\n");
                system("cls");
                if(senha!=15973){
                    printf("Senha errada!\n\n");
                }
            }while(senha!=15973);
            printf("\t\t\tMENU\n\n\t\tDigite uma opção:\n");
            printf("1-Retirada de Bit\n");
            printf("2-Preenchimento automático de cheque\n");
            printf("3-Sair!\n");
            op = inteiro("");
            if(op!=1 && op!=2 && op!=3){
                printf("Valor inválido\nDigite um valor presente no menu!\n");
            }
        }while(op!=1 && op!=2 && op!=3);
        system("cls");
        if(op==1) opc1();
        if(op==2) opc2();
        if(op==3) { printf("Saindo...\n"); return 0; }
        do{
            rep = inteiro("Quer acessar o menu novamente(1-sim/2-nao):");
            if(rep!=1 && rep!=2){
                printf("Valor inválido, digite novamente:\n");
            }
        }while(rep!=1 && rep!=2);
    }while(rep==1);
    return 0;
}
