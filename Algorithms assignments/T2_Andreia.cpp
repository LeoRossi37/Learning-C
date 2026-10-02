#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#ifdef _WIN32
#include <windows.h>
#include <conio.h>
#endif

void clear() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

typedef struct{
    int mes, ano, dia;
}data;

typedef struct{
    int numero;
    char nome[30];
    long long int gol, ass;
    data d;
}dados;

void cript(char *s){
    for(int i=0;s[i];i++) s[i]+=3;
}
void decript(char *s){
    for(int i=0;s[i];i++) s[i]-=3;
}

char leCharSN(char msg[]){
    char c;
    do{
        printf("%s",msg);
        c=toupper(getchar());
        clear();
    }while(c!='S'&&c!='N');
    return c;
}

int leInteiro(char msg[], int min, int max){
    int n;
    while(1){
        printf("%s",msg);
        if(scanf("%d",&n)==1&&n>=min&&n<=max){
            clear();
            return n;
        }
        else{
            clear();
            printf("Entrada invalida, tente novamente.\n");
        }
    }
}

long long int leLong(char msg[]){
    long long int n;
    while(1){
        printf("%s",msg);
        if(scanf("%lld",&n)==1){
            clear();
            return n;
        }
        else{
            clear();
            printf("Entrada invalida, tente novamente.\n");
        }
    }
}

void ajuda(){
    system("cls");
    printf("\t\t\tAJUDA\n\n");
    printf("1-Voce deve colocar nome, numero do jogador, quantidade de gols e assistencias feitas e sua data de aposentadoria\n");
    printf("2-Apenas demonstra os jogadores cadastrados, se houver\n");
    printf("3-Procura as informações pelo nome do jogador, se ele constar na base de dados!\n");
    printf("4-Procura as informações pelo numero do jogador, se ele constar na base de dados!\n");
    printf("5-Altera o numero da camisa do jogador pelo nome\n");
    printf("6-Apaga o jogador da base de dados, se houver nela, pelo numero da camisa\n");
    printf("7-Sair do programa\n\n");
    printf("Pressione ENTER para voltar...");
    getchar();
}

void interf(char *op){
    system("cls");
    printf("\t\t\t   MENU\n");
    printf("\t\t  Escolha uma opcao\n");
    printf("\t1-Cadastro de jogadores\n");
    printf("\t2-Mostrar os jogadores\n");
    printf("\t3-Consultar jogador pelo nome\n");
    printf("\t4-Consulta jogador pelo numero da camisa\n");
    printf("\t5-Altera jogador pelo nome\n");
    printf("\t6-Apaga jogador pelo numero da camisa\n");
    printf("\t7-Sair!\n\n");
    printf("\tF1-AJUDA\n\n");
    printf("Opcao: ");
#ifdef _WIN32
    while(1){
        int ch=_getch();
        if(ch==0 || ch==224){
            int ch2=_getch();
            if(ch2==59){
                ajuda();
                system("cls");
                printf("\t\t\t   MENU\n");
                printf("\t\t  Escolha uma opcao\n");
                printf("\t1-Cadastro de jogadores\n");
                printf("\t2-Mostrar os jogadores\n");
                printf("\t3-Consultar jogador pelo nome\n");
                printf("\t4-Consulta jogador pelo numero da camisa\n");
                printf("\t5-Altera jogador pelo nome\n");
                printf("\t6-Apaga jogador pelo numero da camisa\n");
                printf("\t7-Sair!\n\n");
                printf("\tF1-AJUDA\n\n");
                printf("Opcao: ");
                continue;
            } else continue;
        }
        if(ch>='1' && ch<='7'){
            *op=(char)ch;
            printf("%c\n", *op);
            return;
        }
    }
#else
    do {
        *op=getchar();
    } while(*op<'1'||*op>'7');
    clear();
    printf("Opcao: %c\n",*op);
#endif
}

void cadastro(char name[]){
    FILE *arq=fopen(name,"a");
    if(!arq){printf("\nErro ao abrir o arquivo\n");return;}
    char rep;
    dados dado;
    do{
        printf("\nNome do jogador:");
        fgets(dado.nome,sizeof(dado.nome),stdin);
        dado.nome[strcspn(dado.nome,"\n")]=0;
        cript(dado.nome);
        dado.numero=leInteiro("\nNumero da camisa do jogador(1-99):",1,99);
        dado.gol=leLong("\nNumero de gols:");
        dado.ass=leLong("\nNumero de assistencias:");
        dado.d.dia=leInteiro("\nDia da aposentadoria:",1,31);
        dado.d.mes=leInteiro("Mes da aposentadoria:",1,12);
        dado.d.ano=leInteiro("Ano da aposentadoria:",1900,2100);
        fprintf(arq,"%s;%d;%lld;%lld;%d;%d;%d\n",dado.nome,dado.numero,dado.gol,dado.ass,dado.d.dia,dado.d.mes,dado.d.ano);
        rep=leCharSN("\nDeseja adicionar outro jogador (S/N)? ");
    }while(rep=='S');
    fclose(arq);
}

void exib(char name[]){
    FILE *arq=fopen(name,"r");
    if(!arq){printf("Erro ao abrir o arquivo!\n");getchar();return;}
    char linha[256];
    dados dado;
    system("cls");
    while(fgets(linha,sizeof(linha),arq)){
        int r = sscanf(linha,"%29[^;];%d;%lld;%lld;%d;%d;%d",dado.nome,&dado.numero,&dado.gol,&dado.ass,&dado.d.dia,&dado.d.mes,&dado.d.ano);
        if(r==7){
            decript(dado.nome);
            if(dado.numero!=0){
                printf("\nNome: %s\n",dado.nome);
                printf("Numero do jogador: %d\n",dado.numero);
                printf("Gol(s): %lld\n",dado.gol);
                printf("Assistencia(s): %lld\n",dado.ass);
                printf("Aposentado desde: %d/%d/%d\n",dado.d.dia,dado.d.mes,dado.d.ano);
            }
        }
    }
    fclose(arq);
    printf("\nPressione ENTER para voltar ao menu...");
    getchar();
}

void consNome(char name[]){
    FILE *arq=fopen(name,"r");
    if(!arq){printf("Erro ao abrir o arquivo!\n");getchar();return;}
    char nome[30],linha[256];
    dados t;
    int flag=0;
    printf("Digite o nome do jogador desejado: ");
    fgets(nome,sizeof(nome),stdin);
    nome[strcspn(nome,"\n")]=0;
    while(fgets(linha,sizeof(linha),arq)){
        int r = sscanf(linha,"%29[^;];%d;%lld;%lld;%d;%d;%d",t.nome,&t.numero,&t.gol,&t.ass,&t.d.dia,&t.d.mes,&t.d.ano);
        if(r==7){
            decript(t.nome);
            if(_stricmp(t.nome,nome)==0){
                printf("\nDados do jogador %s:\n",t.nome);
                printf("Camisa: %d\n",t.numero);
                printf("Gol(s): %lld\n",t.gol);
                printf("Assistencia(s): %lld\n",t.ass);
                printf("Data de aposentadoria: %d/%d/%d\n",t.d.dia,t.d.mes,t.d.ano);
                flag=1;
                break;
            }
        }
    }
    if(!flag) printf("\nO jogador %s nao consta na nossa base de dados!\n",nome);
    fclose(arq);
    printf("\nPressione ENTER para voltar ao menu...");
    getchar();
}

void consNum(char name[]){
    FILE *arq=fopen(name,"r");
    if(!arq){printf("Erro ao abrir o arquivo!\n");getchar();return;}
    int num,flag=0; char linha[256]; dados t;
    num=leInteiro("Digite o numero do jogador desejado:",1,99);
    while(fgets(linha,sizeof(linha),arq)){
        int r = sscanf(linha,"%29[^;];%d;%lld;%lld;%d;%d;%d",t.nome,&t.numero,&t.gol,&t.ass,&t.d.dia,&t.d.mes,&t.d.ano);
        if(r==7){
            decript(t.nome);
            if(t.numero==num){
                printf("\nDados do jogador do numero %d:\n",t.numero);
                printf("Nome: %s\n",t.nome);
                printf("Gol(s): %lld\n",t.gol);
                printf("Assistencia(s): %lld\n",t.ass);
                printf("Data de aposentadoria: %d/%d/%d\n",t.d.dia,t.d.mes,t.d.ano);
                flag=1;
                break;
            }
        }
    }
    if(!flag) printf("\nO jogador de camisa %d nao consta na nossa base de dados!\n",num);
    fclose(arq);
    printf("\nPressione ENTER para voltar ao menu...");
    getchar();
}

void altNome(char name[]){
    FILE *arq=fopen(name,"r");
    if(!arq){printf("Erro ao abrir o arquivo!\n");getchar();return;}
    char nome[30],linha[256]; dados t; int flag=0;
    FILE *tmp=fopen("temp.txt","w");
    if(!tmp){ fclose(arq); printf("Erro ao criar arquivo temporario\n"); getchar(); return; }
    printf("Digite o nome do jogador que deseja alterar: ");
    fgets(nome,sizeof(nome),stdin);
    nome[strcspn(nome,"\n")]=0;
    while(fgets(linha,sizeof(linha),arq)){
        int r = sscanf(linha,"%29[^;];%d;%lld;%lld;%d;%d;%d",t.nome,&t.numero,&t.gol,&t.ass,&t.d.dia,&t.d.mes,&t.d.ano);
        if(r==7){
            decript(t.nome);
            if(_stricmp(t.nome,nome)==0 && !flag){
                int numero=leInteiro("\nDigite o novo numero da camisa do jogador:",1,99);
                while(numero==t.numero){
                    printf("Mesmo numero que o anterior, por favor mude!\n");
                    numero=leInteiro("Novo numero da camisa:",1,99);
                }
                t.numero=numero;
                cript(t.nome);
                fprintf(tmp,"%s;%d;%lld;%lld;%d;%d;%d\n",t.nome,t.numero,t.gol,t.ass,t.d.dia,t.d.mes,t.d.ano);
                flag=1;
            } else {
                fprintf(tmp,"%s",linha);
            }
        } else {
            fprintf(tmp,"%s",linha);
        }
    }
    fclose(arq); fclose(tmp);
    remove(name); rename("temp.txt",name);
    if(!flag) printf("\nO jogador %s nao consta na nossa base de dados!\n",nome);
    printf("\nPressione ENTER para voltar ao menu...");
    getchar();
}

void apagaNum(char name[]){
    FILE *arq=fopen(name,"r");
    if(!arq){printf("Erro ao abrir o arquivo!\n");getchar();return;}
    char linha[256]; dados t; int numero,achou=0; char confirma;
    FILE *tmp=fopen("temp.txt","w");
    if(!tmp){ fclose(arq); printf("Erro ao criar arquivo temporario\n"); getchar(); return; }
    numero=leInteiro("\nDigite o numero da camisa que deseja apagar:",1,99);
    while(fgets(linha,sizeof(linha),arq)){
        int r = sscanf(linha,"%29[^;];%d;%lld;%lld;%d;%d;%d",t.nome,&t.numero,&t.gol,&t.ass,&t.d.dia,&t.d.mes,&t.d.ano);
        if(r==7){
            decript(t.nome);
            if(t.numero==numero && !achou){
                printf("\nDados do jogador %s:\nCamisa: %d\nGol(s): %lld\nAssistencia(s): %lld\nData de aposentadoria: %d/%d/%d\n",t.nome,t.numero,t.gol,t.ass,t.d.dia,t.d.mes,t.d.ano);
                confirma=leCharSN("Deseja remover esse jogador (S/N)? ");
                if(confirma=='S'){ achou=1; continue; }
            }
        }
        fprintf(tmp,"%s",linha);
    }
    fclose(arq); fclose(tmp);
    remove(name); rename("temp.txt",name);
    if(!achou) printf("\nNenhum jogador de numero %d encontrado.\n",numero);
    else printf("\nRemocao fisica realizada.\n");
    printf("\nPressione ENTER para voltar ao menu...");
    getchar();
}

int main(){
    #ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    #endif
    char op,name[30];
    printf("Digite o nome do arquivo(.txt) a ser modificado:");
    fgets(name,sizeof(name),stdin);
    name[strcspn(name,"\n")]=0;
    if(strlen(name)==0) strcpy(name,"jogadores.txt");
    do{
        interf(&op);
        switch(op){
            case '1': cadastro(name); break;
            case '2': exib(name); break;
            case '3': consNome(name); break;
            case '4': consNum(name); break;
            case '5': altNome(name); break;
            case '6': apagaNum(name); break;
            case '7': system("cls"); printf("\n\t\t\tObrigado por usar nosso programa!\n\n\n\n"); exit(1);
            default: break;
        }
    }while(op!='7');
    return 0;
}
