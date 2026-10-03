#include<bits/stdc++.h>
using namespace std;

typedef struct no{
    char num;
    struct no *prox;
}*No;

typedef struct{
    No topo;
    int size;
}Pilha;

void inicia(Pilha *p){
    p->topo=NULL;
    p->size=0;
}

bool vazia(Pilha p){
    return (p.topo==NULL);
}

int empilhar(Pilha *p, char num){
    No q = (No) malloc(sizeof(struct no));
    if(q==NULL)return 0;
    q->num=num;
    q->prox=p->topo;
    p->topo=q;
    p->size++;

    return 1;
}

char desempilhar(Pilha *p){
    if(p->topo == NULL) return '\0';
    No temp = p->topo;
    char val = temp->num;
    p->topo = temp->prox;
    free(temp);
    p->size--;
    return val;
}

char topo(Pilha p){
    if(vazia(p)) return '\0';
    return p.topo->num;
}

int precedencia(char num){
    if(num == '+' || num == '-') return 1;
    if(num == '*' || num == '/') return 2;
    return 0;
}

int prefixaPosfixa(char *exp, char *saida){
    Pilha p;
    inicia(&p);
    int i=0, j=0;
    while(exp[i]!='\0'){
        if(exp[i]==' '){
            i++;
            continue;
        }
        if(isdigit(exp[i])){
            while(isdigit(exp[i])){
                saida[j++]=exp[i++];
            }
            saida[j++]=' ';
            continue;
        }
        if(exp[i]== '('){
            empilhar(&p, exp[i]);
        }
        else if(exp[i] == ')'){
            while(!vazia(p) && topo(p)!='('){
                saida[j++]=desempilhar(&p);
                saida[j++]=' ';
            }
            desempilhar(&p);
        }
        else{
            while(!vazia(p) && precedencia(topo(p)) >= precedencia(exp[i])){
                saida[j++]=desempilhar(&p);
                saida[j++]=' ';
            }
            empilhar(&p, exp[i]);
        }
        i++;
    }
    while(!vazia(p)){
        saida[j++]=desempilhar(&p);
        saida[j++]=' ';
    }
    saida[j]='\0';
    return 1;
}

int avaliar(char *exp){
    int pilha[100], topo = -1;
    int i = 0;
    while(exp[i] != '\0'){
        if(exp[i]==' '){
            i++;
            continue;
        }
        if(isdigit(exp[i])){
            int num = 0;
            while(isdigit(exp[i])){
                num = num*10 + (exp[i]-'0');
                i++;
            }
            pilha[++topo] = num;
            continue;
        }
        int b = pilha[topo--];
        int a = pilha[topo--];
        if(exp[i] == '+') pilha[++topo] = a + b;
        if(exp[i] == '-') pilha[++topo] = a - b;
        if(exp[i] == '*') pilha[++topo] = a * b;
        if(exp[i] == '/') pilha[++topo] = a / b;
        i++;
    }

    return pilha[topo];
}

int balanceado(char *exp){
    Pilha p;
    inicia(&p);
    int i=0;
    while(exp[i]!='\0'){
        if(exp[i]=='('){
            empilhar(&p, '(');
        }
        else if(exp[i]==')'){
            if(vazia(p)) return 0;
            desempilhar(&p);
        }
        i++;
    }

    return vazia(p);
}

int main(){
    char exp[100];
    char pos[100];
    cout << "Digite a expressao: ";
    fgets(exp, sizeof(exp), stdin);
    exp[strcspn(exp, "\n")] = '\0';
    if(!balanceado(exp)){
        cout << "Erro: delimitadores incorretos\n";
        return 0;
    }
    prefixaPosfixa(exp, pos);
    cout << "Posfixa: " <<pos << endl;
    cout << "Resultado: " << avaliar(pos) << endl;




}