#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <windows.h>
#include <string.h>
#include <conio.h>

//Função para Centralizar---------------------------------------------------------------------------------------------------------------------------
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

typedef struct tipoData {
    int dia, mes, ano;
} tipoData;

typedef struct tipoHorario {
    int hora, minuto;
} tipoHorario;

// ---------- CORREÇÃO IMPORTANTE: precisa declarar tipoData/tipoHorario ANTES de comparar() ----------
int comparar(tipoData d1, tipoHorario h1, tipoData d2, tipoHorario h2) {
    if(d1.ano != d2.ano)
        return d1.ano < d2.ano;
    if(d1.mes != d2.mes)
        return d1.mes < d2.mes;
    if(d1.dia != d2.dia)
        return d1.dia < d2.dia;

    if(h1.hora != h2.hora)
        return h1.hora < h2.hora;

    return h1.minuto < h2.minuto;
}

typedef struct compromisso *node;

struct compromisso {
    tipoData data;
    tipoHorario horario;

    char texto[100];

    struct compromisso *prox;
};

// ---------- INSERÇÃO ORDENADA CORRIGIDA ----------
void inclui_ordenado(node *lista, tipoData data, tipoHorario horario, const char *texto){
    node novo = malloc(sizeof(struct compromisso));

    novo->data = data;
    novo->horario = horario;
    strcpy(novo->texto, texto);
    novo->prox = NULL;

    // insere no início
    if (*lista == NULL || comparar(data, horario, (*lista)->data, (*lista)->horario)) {
        novo->prox = *lista;
        *lista = novo;
        return;
    }

    node atual = *lista;

    while (atual->prox != NULL &&
           !comparar(data, horario, atual->prox->data, atual->prox->horario)) {
        atual = atual->prox;
    }

    novo->prox = atual->prox;
    atual->prox = novo;
}

void criar_listaCompromissos(node *listaCompromissos) {
    *listaCompromissos = NULL;
}

void inserir_compromisso(node *listaCompromissos){
    tipoData adicionar;
    tipoHorario horario;
    char texto[100];

    system("cls");
    gotoxy(45, 4);
    printf("Inserir compromisso selecionado\n");

    do {
        printf("Dia (1-31): ");
        scanf("%d", &adicionar.dia);
        if (adicionar.dia < 1 || adicionar.dia > 31)
            printf("Dia invalido! Tente novamente.\n");
    } while (adicionar.dia < 1 || adicionar.dia > 31);

    do {
        printf("Mes (1-12): ");
        scanf("%d", &adicionar.mes);
        if (adicionar.mes < 1 || adicionar.mes > 12)
            printf("Mes invalido! Tente novamente.\n");
    } while (adicionar.mes < 1 || adicionar.mes > 12);

    printf("Ano: ");
    scanf("%d", &adicionar.ano);

    do {
        printf("Hora (0-23): ");
        scanf("%d", &horario.hora);
    } while (horario.hora < 0 || horario.hora > 23);

    do {
        printf("Minuto (0-59): ");
        scanf("%d", &horario.minuto);
    } while (horario.minuto < 0 || horario.minuto > 59);

    printf("Descrição do compromisso: ");
    while(getchar() != '\n');
    fgets(texto, 100, stdin);
    texto[strcspn(texto, "\n")] = 0;

    inclui_ordenado(listaCompromissos, adicionar, horario, texto);
    printf("Compromisso inserido com sucesso!\n");
    system("pause");
}

void buscar_por_palavra(node listaCompromissos){
    if(listaCompromissos == NULL){
        printf("A agenda está vazia!\n");
        system("pause");
        return;
    }

    char palavra[100];
    printf("Digite a palavra para buscar: ");

      if (fgets(palavra, sizeof(palavra), stdin) == NULL) {
        printf("Erro de leitura!\n");
        system("pause");
        return;
    }

        if (palavra[0] == '\n') {
       
        if (fgets(palavra, sizeof(palavra), stdin) == NULL) {
            printf("Erro de leitura!\n");
            system("pause");
            return;
        }
    }

        palavra[strcspn(palavra, "\n")] = 0;


    int encontrados = 0;
    node atual = listaCompromissos;

    system("cls");
    printf("Resultados da busca por \"%s\":\n\n", palavra);

    while(atual != NULL){
        if(strstr(atual ->texto, palavra) != NULL){
            printf("Data: %02d/%02d/%04d\n", atual->data.dia, atual->data.mes, atual->data.ano);

            printf("Horário: %02d:%02d\n", atual->horario.hora, atual->horario.minuto);

            printf("Descrição: %s\n\n", atual->texto);
            encontrados++;

        }
        atual = atual->prox;
    }
    if(encontrados == 0)
    printf("Nenhum compromisso encontrado contendo essa palavra!\n");

    system("pause");

}

void remover_compromisso_data(node *listaCompromissos) {
    if (*listaCompromissos == NULL) {
        printf("A agenda esta vazia!\n");
        system("pause");
        return;
    }

    tipoData dataRemover;

    printf("Dia (1-31): ");
    scanf("%d", &dataRemover.dia);

    printf("Mes (1-12): ");
    scanf("%d", &dataRemover.mes);

    printf("Ano: ");
    scanf("%d", &dataRemover.ano);

    node atual = *listaCompromissos;
    node anterior = NULL;

    int removidos = 0;

    while (atual != NULL) {
        if (atual->data.dia == dataRemover.dia &&
            atual->data.mes == dataRemover.mes &&
            atual->data.ano == dataRemover.ano) {

            node temp = atual;
            if (anterior == NULL) {
                *listaCompromissos = atual->prox;
                atual = *listaCompromissos;
            } else {
                anterior->prox = atual->prox;
                atual = anterior->prox;
            }
            free(temp);
            removidos++;
        }
        else {
            anterior = atual;
            atual = atual->prox;
        }
    }

    // --------- ERRO CORRIGIDO: você usou "=" ao inves de "==" ---------
    if (removidos == 0){
        printf("Nenhum compromisso registrado nessa data!\n");
        system("pause");
    
    } else {
        printf("Compromisso(s) apagado(s) com sucesso!\n");
        system("pause");
    }
}

void remover_compromisso_nome(node *listaCompromissos){
    if (*listaCompromissos == NULL) {
        printf("A agenda esta vazia!\n");
        return;
    }
    char textoRemove[100];
    printf("\t\t\nDigite a descrição do compromisso que deseja remover:");
    fgets(textoRemove,sizeof(textoRemove),stdin);
    textoRemove[strcspn(textoRemove,"\n")]='\0';
    node atual=*listaCompromissos;
    node anterior=NULL;
    int remov=0;
    while(atual){
        if(stricmp(atual->texto,textoRemove)==0){
            node aux=atual;
            if(anterior==NULL){
            *listaCompromissos=atual->prox;
            atual=*listaCompromissos;
            }else{
                anterior->prox=atual->prox;
                atual=anterior->prox;
            }
            free(aux);
            remov++;
        }else{
            anterior=atual;
            atual=atual->prox;
        }
    }
    if(remov==0){
        printf("\nNão há compromissos com essa descrição!\n");
        system("pause");
    }else{
        printf("\nForam removidos %d compromissos com a descrição: '%s'\n", remov, textoRemove);
        system("pause");
    }

}

void altera_data_pelo_nome(node *listaCompromissos){
    if (*listaCompromissos == NULL) {
        printf("A agenda esta vazia!\n");
        system("pause");
        return;
    }
    tipoData dataAlterar;
    tipoHorario horas;
    char textoRemove[100];
    printf("\t\t\nDigite a descrição do compromisso que deseja alterar a data:");
    fgets(textoRemove,sizeof(textoRemove),stdin);
    textoRemove[strcspn(textoRemove,"\n")]='\0';
    node atual=*listaCompromissos;
    int alt=0;
    while(atual){
        if(stricmp(atual->texto,textoRemove)==0){
            char r;
            do{
            printf("\nAchamos um compromisso com a descrição:\n %s--> Data: %d/%d/%d  Hora: %d:%d, é esse que deseja alterar?(S-sim/N-nao)\n"
            ,atual->texto,atual->data.dia,atual->data.mes,atual->data.ano, atual->horario.hora, atual->horario.minuto);
            scanf(" %c", &r); 
            r = toupper(r);
            }while(r!='S' && r!='N');
            if(r=='S'){
                printf("Digite a data para altera-lá:(dia/mes/ano)  ");
                do{
                    printf("Dia (1-31): ");
                    scanf("%d", &dataAlterar.dia);
                    if(dataAlterar.dia <1 || dataAlterar.dia>31) printf("Dia invalido! Tente novamente.\n");
                }while(dataAlterar.dia <1 || dataAlterar.dia>31);
                do{
                    printf("Mes (1-12): ");
                    scanf("%d", &dataAlterar.mes);
                    if(dataAlterar.dia <1 || dataAlterar.dia>12) printf("Mês invalido! Tente novamente.\n");
                }while(dataAlterar.mes <1 || dataAlterar.mes>12);
                do{
                    printf("Ano: ");
                    scanf("%d", &dataAlterar.ano);
                }while(dataAlterar.ano <0 || dataAlterar.dia>10000000);
                atual->data = dataAlterar;
                alt++;
                printf("\nCompromisso atualizado com sucesso!\n");
                while (getchar() != '\n');
            }
        }
            atual=atual->prox;
    }
    if(alt==0){
        printf("\nNão há compromissos com essa descrição!\n");
        system("pause");
    }else{
        printf("\n %d compromisso(s) mudado(s) de data com sucesso!", alt);
        system("pause");
    }

}

void salvar_compromissos(node listaCompromissos){

    if(listaCompromissos == NULL){
        printf("A agenda esta vazia!\n");
        system("pause");
        return;
    }

    FILE *arquivo = fopen("agenda.txt", "w");

    if(arquivo == NULL){
        perror("Erro na abertura do arquivo!\n");
        system("pause");
        return;
    }

    node atual = listaCompromissos;

    while(atual != NULL){
        
        fprintf(arquivo, "%d %d %d %d %d %s\n", atual->data.dia, atual->data.mes, atual->data.ano, atual->horario.hora, atual->horario.minuto, atual->texto);
        atual = atual->prox;
    }

    fclose(arquivo);

    printf("Compromissos salvos com sucesso! Local salvo: agenda.txt\n");
    system("pause");

}

void procurar_compromisso_palavra(node listaCompromissos){
    
    if(listaCompromissos == NULL){
        printf("Nao ha compromissos na agenda!\n");
        system("pause");
        return;
    }
    
    char palavra[50];

    printf("Digite a palavra para buscar: ");
    scanf("%s", &palavra);
    
    node atual = listaCompromissos;
    int encontrados = 0;

    system("cls");
    printf("Resultados da busca: ");

    while(atual != NULL){
        if(strstr(atual->texto, palavra) != NULL){
            
            printf("Data: %02d/%02d/%04d\n", atual->data.dia, atual->data.mes, atual->data.ano);

            printf("Horário: %02d:%02d\n", atual->horario.hora, atual->horario.minuto);

            printf("Descrição: %s\n\n", atual->texto);

            encontrados++;
        }
        atual = atual->prox;
    }

    if(encontrados == 0){
        printf("Nenhum compromisso foi encontrado contendo esta palavra!\n");
    }

    system("pause");
}

void ler_disco_arq(node *listaCompromissos){
    FILE *arq = fopen("agenda.txt","r");
    if(arq==NULL){
        printf("\nErro na abertura do arquivo!\n");
        system("pause");
        return;
    }
    node comp;
    node temp;
    int comp_lidos=0;
    while (*listaCompromissos != NULL) {
        temp = *listaCompromissos;
        *listaCompromissos = (*listaCompromissos)->prox;
        free(temp);
    }
    while(1){
        comp=(node)malloc(sizeof(struct compromisso));
        if (comp == NULL) {
            printf("Erro de alocacao de memoria ao ler o arquivo.\n");
            break;
        }
        if (fscanf(arq, "%d %d %d %d %d %s\n", 
                   &comp->data.dia, 
                   &comp->data.mes, 
                   &comp->data.ano,
                   &comp->horario.hora, 
                   &comp->horario.minuto,
                   comp->texto) != 6) {
                    free(comp);
                    break;
    }
    comp->prox=*listaCompromissos;
    *listaCompromissos=comp;
    comp_lidos++;
    }
    fclose(arq);
    if(comp_lidos>0){
        printf("\n%d compromisso(s) carregado(s) com sucesso do disco\n", comp_lidos);
        system("pause");
    }else{
        printf("\nNenhum compromisso encontrado!\n");
        system("pause");
    }
}

int main() {
   
    node listaCompromissos;
    criar_listaCompromissos(&listaCompromissos);

    system("chcp 65001 > NUL"); 
    system("cls");

    char intro[] = {"Bem vindo ao sistema ABC(Agenda Braba dos Crias)."};
    gotoxy(45, 4);
    for (int i = 0; i < strlen(intro); i++) {
        printf("%c", intro[i]);
        usleep(30000);
    }
    printf("\n");
    gotoxy(52, 5);
    printf("Aperte qualquer tecla para iniciar!\n");


    char resp;

   
 
        
    do{
    
  

    system("cls");
     

    gotoxy(45, 4);
    printf("Escolha uma utilidade.\n");
    gotoxy(45, 6);
    printf("1 - Inserir um compromisso na agenda\n");
    gotoxy(45, 7);
    printf("2 - Remover compromisso por data\n");
    gotoxy(45, 8); 
    printf("3 - Remover compromisso por palavra");
    gotoxy(45, 9);
    printf("4 - Consulta os compromissos da agenda"); 
    gotoxy(45, 10); 
    printf("5 - Procurar compromissos com busca em palavra"); 
    gotoxy(45, 11); 
    printf("6 - Alterar compromisso com busca em palavra"); 
    gotoxy(45, 12); 
    printf("7 - Altera compromisso da agenda com busca em data e horário"); 
    gotoxy(45, 13); 
    printf("8 - Salva em disco os compromissos da agenda"); 
    gotoxy(45, 14); 
    printf("9 - Lê do disco os compromissos previamente salvos em disco"); 
    gotoxy(45, 15); 
    printf("0 - Terminar Execução\n");
    resp = getch();

   

 

    if(resp == '1'){
        inserir_compromisso(&listaCompromissos);
    }
    else if(resp == '2'){
       
        remover_compromisso_data(&listaCompromissos);

        
    }
    else if(resp == '3'){
        
        remover_compromisso_nome(&listaCompromissos);
    }

    else if(resp == '4'){
        buscar_por_palavra(listaCompromissos);
    }

    else if(resp == '5'){
        procurar_compromisso_palavra(listaCompromissos);
    }

    else if(resp == '6'){
        altera_data_pelo_nome(&listaCompromissos);
    }

    else if(resp == '7'){
        system("cls");
        FILE *arq = fopen("agenda.txt", "w");

        if(arq == NULL){
            printf("Erro ao abrir arquivo!\n");
            system("pause");
        }
        else{
            node atual = listaCompromissos;

            while(atual != NULL){
                fprintf(arq, "%02d/%02d/%04d %02d:%02d | %s\n",
                atual->data.dia,
                atual->data.mes,
                atual->data.ano,
                atual->horario.hora,
                atual->horario.minuto,
                atual->texto
            );
            atual = atual->prox;
            }
            fclose(arq);
            printf("Compromissos salvos no arquivo com sucesso!\n");
            system("pause");
        }
    }

    else if(resp == '8'){
        salvar_compromissos(listaCompromissos);
    }else if(resp=='9'){
        ler_disco_arq(&listaCompromissos);
    }


}while(resp != '0');

}