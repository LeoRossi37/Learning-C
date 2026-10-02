#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct data{
    int dia, mes, ano;
};

struct TipoReg{
    char nome[50], rg[20];
    double sal;
    int idade;
    char sexo;
    struct data nascimento;
};

struct TipoCadastro{
    struct TipoReg func[100];
    int qtd;
};

void IniciaCadastro(struct TipoCadastro *tp){
    tp->qtd = 0;
}

void LeFuncionarios(struct TipoCadastro *tp){
    if(tp->qtd < 100){
        struct TipoReg *tr = &tp->func[tp->qtd];
        printf("Digite seu nome:\n");
        getchar();
        fgets(tr->nome, sizeof(tr->nome), stdin);
        tr->nome[strcspn(tr->nome,"\n")] = '\0';
        printf("Digite seu RG:\n");
        fgets(tr->rg, sizeof(tr->rg), stdin);
        tr->rg[strcspn(tr->rg, "\n")] = '\0';
        printf("Digite seu salario:\n");
        scanf("%lf",&tr->sal);
        printf("Digite sua idade:\n");
        scanf("%d", &tr->idade);
        printf("Digite seu sexo(M/F/L):\n");
        scanf(" %c", &tr->sexo);
        printf("Digite sua data de nascimento (dd mm aaaa):\n");
        scanf("%d %d %d", &tr->nascimento.dia,&tr->nascimento.mes,&tr->nascimento.ano);
        tp->qtd++;
    }else{
        printf("Cadastro atingiu o limite maximo!\n");
    }
}


void ListaFuncionarios(struct TipoCadastro tp){
    int i;
    for(i=0; i<tp.qtd; i++){
        struct TipoReg tr = tp.func[i];
        printf("\nFuncionario %d:\n", i+1);
        printf("Nome: %s\n", tr.nome);
        printf("RG: %s\n", tr.rg);
        printf("Salario: %.2lf\n", tr.sal);
        printf("Idade: %d\n", tr.idade);
        printf("Sexo: %c\n", tr.sexo);
        printf("Data: %d/%d/%d\n", tr.nascimento.dia, tr.nascimento.mes, tr.nascimento.ano);
    }
}

void OrdenaNome(struct TipoCadastro *tp){
    int i,j;
    for(i=0; i<tp->qtd-1; i++){
        for(j=i+1; j<tp->qtd; j++){
            if(strcasecmp(tp->func[i].nome, tp->func[j].nome) > 0){
                struct TipoReg aux = tp->func[i];
                tp->func[i] = tp->func[j];
                tp->func[j] = aux;
            }
        }
    }
}

void OrdenaSalario(struct TipoCadastro *tp){
    int i,j;
    for(i=0; i<tp->qtd-1; i++){
        for(j=i+1; j<tp->qtd; j++){
            if(tp->func[i].sal > tp->func[j].sal){
                struct TipoReg aux = tp->func[i];
                tp->func[i] = tp->func[j];
                tp->func[j] = aux;
            }
        }
    }
}

void printar(struct TipoCadastro tp){
    int i;
    for(i=0;i<tp.qtd;i++){
        printf("%s -- %.2lf\n", tp.func[i].nome, tp.func[i].sal);
    }
}

void SalarioIntervalo(struct TipoCadastro tp, double v1, double v2){
    int i, qtd=0;
    double soma=0;
    for(i=0;i<tp.qtd;i++){
        if(tp.func[i].sal >= v1 && tp.func[i].sal <= v2){
            printf("%s -- %.2lf\n", tp.func[i].nome, tp.func[i].sal);
            soma += tp.func[i].sal;
            qtd++;
        }
    }
    if(qtd>0){
        printf("Media dos salarios: %.2lf\n", soma/qtd);
    }else{
        printf("Nenhum funcionario nesse intervalo.\n");
    }
}

void ImpostoRenda(struct TipoCadastro tp){
    int i;
    for(i=0;i<tp.qtd;i++){
        double desconto=0;
        if(tp.func[i].sal <= 1000){
            desconto = 0;
        }else if(tp.func[i].sal <= 2000){
            desconto = tp.func[i].sal * 0.10;
        }else if(tp.func[i].sal <= 3500){
            desconto = tp.func[i].sal * 0.15;
        }else{
            desconto = tp.func[i].sal * 0.25;
        }
        printf("%s -- Salario bruto: %.2lf | Desconto: %.2lf | Liquido: %.2lf\n",
               tp.func[i].nome, tp.func[i].sal, desconto, tp.func[i].sal - desconto);
    }
}

struct TipoReg BuscaNome(struct TipoCadastro tp, char nome[]){
    int i;
    for(i=0;i<tp.qtd;i++){
        if(strcmp(tp.func[i].nome, nome)==0){
            return tp.func[i];
        }
    }
    struct TipoReg vazio;
    strcpy(vazio.nome,"");
    return vazio;
}

void AtualizaSalario(struct TipoCadastro *tp, char rg[], double novoSal){
    int i;
    for(i=0;i<tp->qtd;i++){
        if(strcmp(tp->func[i].rg, rg)==0){
            tp->func[i].sal = novoSal;
            printf("Salario atualizado para %.2lf\n", novoSal);
            return;
        }
    }
    printf("RG nao encontrado.\n");
}

struct TipoReg ListaMaraja(struct TipoCadastro tp){
    int i, idx=0;
    for(i=1;i<tp.qtd;i++){
        if(tp.func[i].sal > tp.func[idx].sal){
            idx = i;
        }
    }
    return tp.func[idx];
}

void RemoveFuncionario(struct TipoCadastro *tp, char rg[]){
    int i, j, achou=0;
    for(i=0;i<tp->qtd;i++){
        if(strcmp(tp->func[i].rg, rg)==0){
            achou=1;
            for(j=i;j<tp->qtd-1;j++){
                tp->func[j] = tp->func[j+1];
            }
            tp->qtd--;
            printf("Funcionario removido.\n");
            break;
        }
    }
    if(!achou){
        printf("RG nao encontrado.\n");
    }
}

int main(){
    struct TipoCadastro cadastro;
    IniciaCadastro(&cadastro);
    int n;
    printf("Quantos funcionarios deseja cadastrar (1 a 100): ");
    scanf("%d",&n);
    int i;
    for(i=0;i<n;i++){
        LeFuncionarios(&cadastro);
    }
    int opcao;
    char nome[50], rg[20];
    double sal, v1, v2;
    do{
        printf("\nMenu:\n");
        printf("1 - Listar funcionarios\n");
        printf("2 - Ordenar por nome\n");
        printf("3 - Ordenar por salario\n");
        printf("4 - Buscar por nome\n");
        printf("5 - Atualizar salario\n");
        printf("6 - Mostrar maraja\n");
        printf("7 - Remover funcionario\n");
        printf("8 - Salarios em intervalo\n");
        printf("9 - Imposto de renda\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d",&opcao);
        getchar();
        switch(opcao){
            case 1: ListaFuncionarios(cadastro); break;
            case 2: OrdenaNome(&cadastro); printar(cadastro); break;
            case 3: OrdenaSalario(&cadastro); printar(cadastro); break;
            case 4: printf("Nome para buscar: "); fgets(nome,50,stdin); nome[strcspn(nome,"\n")]=0;
                    {struct TipoReg achado = BuscaNome(cadastro,nome);
                    if(strlen(achado.nome)>0) printf("Achado: %s -- %.2lf\n", achado.nome, achado.sal);
                    else printf("Nao encontrado.\n");}
                    break;
            case 5: printf("RG: "); fgets(rg,20,stdin); rg[strcspn(rg,"\n")]=0;
                    printf("Novo salario: "); scanf("%lf",&sal);
                    AtualizaSalario(&cadastro,rg,sal); break;
            case 6: {struct TipoReg r = ListaMaraja(cadastro);
                      printf("Nome: %s\n", r.nome);
                     printf("RG: %s\n", r.rg);
                      printf("Salario: %.2lf\n", r.sal);
                  printf("Idade: %d\n", r.idade);
                   printf("Sexo: %c\n", r.sexo);
                 printf("Data: %d/%d/%d\n", r.nascimento.dia, r.nascimento.mes, r.nascimento.ano);
            }
                 break;
            case 7: printf("RG para remover: "); fgets(rg,20,stdin); rg[strcspn(rg,"\n")]=0;
                    RemoveFuncionario(&cadastro,rg); break;
            case 8: printf("Intervalo v1 v2: "); scanf("%lf %lf",&v1,&v2);
                    SalarioIntervalo(cadastro,v1,v2); break;
            case 9: ImpostoRenda(cadastro); break;
        }
    }while(opcao!=0);
    return 0;
}
