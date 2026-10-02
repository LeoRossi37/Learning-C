

#include <stdio.h>
#include <string.h>

struct Endereco {
    char rua[50], numero[10], complemento[30], bairro[30], cep[15], cidade[30], estado[5], pais[30];
};

struct Telefone {
    char ddd[5], numero[20];
};

struct Data {
    int dia, mes, ano;
};

struct Pessoa {
    char nome[50], email[50];
    struct Endereco end;
    struct Telefone tel;
    struct Data nasc;
};

struct Pessoa agenda[100];
int qtd = 0;

void imprime(struct Pessoa p){
    printf("Nome: %s\n", p.nome);
    printf("Email: %s\n", p.email);
    printf("Endereco: %s, %s, %s, %s, %s, %s, %s, %s\n",
           p.end.rua, p.end.numero, p.end.complemento, p.end.bairro,
           p.end.cep, p.end.cidade, p.end.estado, p.end.pais);
    printf("Telefone: (%s) %s\n", p.tel.ddd, p.tel.numero);
    printf("Nascimento: %d/%d/%d\n", p.nasc.dia, p.nasc.mes, p.nasc.ano);
    printf("\n");
}

void busca_por_primeiro_nome(){
    char nome[50];
    scanf(" %[^\n]", nome);
    for(int i=0;i<qtd;i++){
        if(strcmp(agenda[i].nome, nome)==0){
            imprime(agenda[i]);
        }
    }
}

void busca_por_mes_de_aniversario(){
    int m;
    scanf("%d", &m);
    for(int i=0;i<qtd;i++){
        if(agenda[i].nasc.mes == m){
            imprime(agenda[i]);
        }
    }
}

void busca_por_dia_e_mes_de_aniversario(){
    int d, m;
    scanf("%d %d", &d, &m);
    for(int i=0;i<qtd;i++){
        if(agenda[i].nasc.dia == d && agenda[i].nasc.mes == m){
            imprime(agenda[i]);
        }
    }
}

void insere_pessoa(){
    struct Pessoa p;
    scanf(" %[^\n]", p.nome);
    scanf(" %[^\n]", p.email);

    scanf(" %[^\n]", p.end.rua);
    scanf(" %[^\n]", p.end.numero);
    scanf(" %[^\n]", p.end.complemento);
    scanf(" %[^\n]", p.end.bairro);
    scanf(" %[^\n]", p.end.cep);
    scanf(" %[^\n]", p.end.cidade);
    scanf(" %[^\n]", p.end.estado);
    scanf(" %[^\n]", p.end.pais);

    scanf(" %[^\n]", p.tel.ddd);
    scanf(" %[^\n]", p.tel.numero);

    scanf("%d %d %d", &p.nasc.dia, &p.nasc.mes, &p.nasc.ano);

    int pos = 0;
    while(pos < qtd && strcmp(agenda[pos].nome, p.nome) < 0){
        pos++;
    }

    for(int i=qtd;i>pos;i--){
        agenda[i] = agenda[i-1];
    }

    agenda[pos] = p;
    qtd++;
}

void retira_pessoa(){
    char nome[50];
    scanf(" %[^\n]", nome);

    for(int i=0;i<qtd;i++){
        if(strcmp(agenda[i].nome, nome)==0){
            for(int j=i;j<qtd-1;j++){
                agenda[j] = agenda[j+1];
            }
            qtd--;
            i--;
        }
    }
}

void imprime_agenda(){
    int op;
    scanf("%d", &op);

    if(op==1){
        for(int i=0;i<qtd;i++){
            printf("%s - (%s) %s - %s\n", agenda[i].nome, agenda[i].tel.ddd, agenda[i].tel.numero, agenda[i].email);
        }
    } else {
        for(int i=0;i<qtd;i++){
            imprime(agenda[i]);
        }
    }
}

int main(){
    int op;

    while(1){
        scanf("%d", &op);

        if(op==1) busca_por_primeiro_nome();
        else if(op==2) busca_por_mes_de_aniversario();
        else if(op==3) busca_por_dia_e_mes_de_aniversario();
        else if(op==4) insere_pessoa();
        else if(op==5) retira_pessoa();
        else if(op==6) imprime_agenda();
        else if(op==0) break;
    }
}
