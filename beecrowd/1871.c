#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>



typedef struct {
    int dia, mes, ano;
  } data;     
	 
typedef struct {
    int numero;
    char nome[30];
    float saldo;
    data d;
    int existe;
  } dados;
//------------------------------------
char confirma () {
  char resp;
  printf ("Confirma (S/N)?");
  do {
    resp = toupper(getch());
  } while (resp != 'S' && resp != 'N');
  return resp;
}  
//------------------------------------
void menu (char *opcao) {
  system ("cls");
  printf ("\n    M E N U ");
  printf ("\n 1 - Cadastra");
  printf ("\n 2 - Mostra todos clientes");
  printf ("\n 3 - Consulta cliente pelo numero da conta");
  printf ("\n 4 - Consulta cliente pelo nome");
  printf ("\n 5 - Altera cliente pelo numero da conta");
  printf ("\n 6 - Apaga cliente pelo numero da conta");
  printf ("\n 7 - Sair");
  printf ("\n\n Opcao ---> ");
  do {
    *opcao = getch();
  } while (*opcao < '1' || *opcao > '7'); 
  printf ("%c",*opcao);   
  printf ("\n\n--------------------------------------------------------\n");   
}    
//------------------------------------
void cadastra (char nomearq[]){
  dados cliente;
  char resp, numstr[10];
  FILE *arquivo;
  // Abertura do arquivo
  if ((arquivo = fopen(nomearq, "r+b")) == NULL) {
    if ((arquivo = fopen(nomearq, "wb")) == NULL) {
      printf ("\nErro da abertura do arquivo.\n\n");
      return;
    }    
  }
  else fseek (arquivo, 0, SEEK_END);  // Arquivo existe e posiciono o pomteiro no final do arquivo
  // Leitura dos registros e gravacao
  do {
    fflush (stdin); // "Limpa" o buffer de entrada - teclado
    cliente.existe = 1;
    printf("\n\nNome do cliente: ");
    gets(cliente.nome);
    printf("Numero da conta: ");
    gets(numstr);
    cliente.numero = atoi(numstr);
    printf("Saldo: ");
    gets(numstr);
    cliente.saldo = atof(numstr);
    printf ("Data: ");
    scanf ("%d %d %d",&cliente.d.dia,&cliente.d.mes,&cliente.d.ano);
    fwrite(&cliente,sizeof(dados),1,arquivo);
    printf("\n Adicionar outro cliente (s/n)?: ");
    do {
      resp = toupper(getch());
    } while (resp != 'S' && resp != 'N');
  } while (resp == 'S');
  fclose (arquivo);     
}     
//------------------------------------
void mostra (char nomearq[]){
  FILE *arquivo;
  dados cliente;
  // Abertura do arquivo
  if ((arquivo = fopen(nomearq, "rb")) == NULL) {
    printf ("\n Erro de abertura de arquivo.\n\n");
    getch();
    return;
  }
  // Leitura dos registros  
  printf ("\nNumero da conta     Nome do cliente       Saldo             Data");
  while (fread (&cliente, sizeof(dados), 1, arquivo) == 1) 
    if (cliente.existe) 
      printf ("\n %14d %19s %11.2f       %2d/%2d/%4d",cliente.numero,cliente.nome,cliente.saldo,cliente.d.dia,cliente.d.mes,cliente.d.ano);
  fclose (arquivo);
  getch();
}
//------------------------------------
void consultaNumero (char nomearq[]){
  FILE *arquivo;
  dados cliente;
  int numero, achou = 0;
  // Abertura do arquivo
  if ((arquivo = fopen(nomearq, "rb")) == NULL) {
    printf ("\n Erro de abertura de arquivo.\n\n");
    getch();
    return;
  }
  printf ("\nQual o numero da conta do cliente que deseja consultar? ");
  scanf ("%d",&numero);
  // Leitura dos registros  
  while (fread (&cliente, sizeof(dados), 1, arquivo) == 1 && !achou)
    if (cliente.existe && cliente.numero == numero) {
      printf ("\n\n Cliente: %s \n Saldo R$ %.2f em %d/%d/%d.\n\n",cliente.nome,cliente.saldo,cliente.d.dia,cliente.d.mes,cliente.d.ano);
      achou = 1;
    }
  if (!achou)
    printf ("Nao ha cliente cadastrado com numero de conta %d.\n\n",numero);
  fclose (arquivo);
  getch();
}
//------------------------------------
void consultaNome (char nomearq[]){
  FILE *arquivo;
  dados cliente;
  int achou = 0;
  char nome[30];
  // Abertura do arquivo
  if ((arquivo = fopen(nomearq, "rb")) == NULL) {
    printf ("\n Erro de abertura de arquivo.\n\n");
    getch();
    return;
  }
  printf ("\nQual o nome do cliente que deseja consultar? ");
  fflush (stdin);
  gets (nome);
  // Leitura dos registros  
  while (fread (&cliente, sizeof(dados), 1, arquivo) == 1 && !achou)
    if (cliente.existe && strcmp(cliente.nome,nome)==0) {
      printf ("\n\n Cliente: %s -----> Numero da conta: %d\n Saldo R$ %.2f em %d/%d/%d.\n\n",cliente.nome,cliente.numero,cliente.saldo,cliente.d.dia,cliente.d.mes,cliente.d.ano);
      achou = 1;
    }
  if (!achou)
    printf ("O cliente %s nao esta cadastrado.\n\n",nome);
  fclose (arquivo);
  getch();
}
//------------------------------------
void alteraNumero (char nomearq[]){
  FILE *arquivo;
  dados cliente;
  int numero, achou = 0;
  char numstr[30];
  // Abertura do arquivo
  if ((arquivo = fopen(nomearq, "r+b")) == NULL) {
    printf ("\n Erro de abertura de arquivo.\n\n");
    getch();
    return;
  }
  printf ("\nQual o numero da conta do cliente que deseja alterar? ");
  scanf ("%d",&numero);
  // Leitura dos registros  
  while (fread (&cliente, sizeof(dados), 1, arquivo) == 1 && !achou)
    if (cliente.existe && cliente.numero == numero) {
      printf ("\n\n Cliente: %s \n Saldo R$ %.2f em %d/%d/%d.\n\n",cliente.nome,cliente.saldo,cliente.d.dia,cliente.d.mes,cliente.d.ano);
      fflush (stdin); // "Limpa" o buffer de entrada - teclado
      printf("Saldo: ");
      gets(numstr);
      cliente.saldo = atof(numstr);
      // Volta o ponteiro
      fseek (arquivo,-sizeof(dados),SEEK_CUR);
      // Grava os dados lidos - alterados
      fwrite(&cliente,sizeof(dados),1,arquivo);
      fflush (arquivo);
      achou = 1;
    }
  if (!achou)
    printf ("Nao ha cliente cadastrado com numero de conta %d.\n\n",numero);
  fclose (arquivo);
  getch();
}
//------------------------------------
void apagaRegNumero(char nomearq[]){
  FILE *arquivo;
  dados cliente;
  int numero, achou = 0;
  char numstr[30];
  // Abertura do arquivo
  if ((arquivo = fopen(nomearq, "r+b")) == NULL) {
    printf ("\n Erro de abertura de arquivo.\n\n");
    getch();
    return;
  }
  printf ("\nQual o numero da conta do cliente que deseja apagar? ");
  scanf ("%d",&numero);
  // Leitura dos registros  
  while (fread (&cliente, sizeof(dados), 1, arquivo) == 1 && !achou)
    if (cliente.existe && cliente.numero == numero) {
      printf ("\n\n Cliente: %s \n Saldo R$ %.2f em %d/%d/%d.\n\n",cliente.nome,cliente.saldo,cliente.d.dia,cliente.d.mes,cliente.d.ano);
      fflush (stdin); // "Limpa" o buffer de entrada - teclado
      if (confirma() == 'S') {
        cliente.existe = 0; 
        // Volta o ponteiro
        fseek (arquivo,-sizeof(dados),SEEK_CUR);
        // Grava os dados lidos - alterados
        fwrite(&cliente,sizeof(dados),1,arquivo);
        fflush (arquivo);
        printf ("\n\nCliente %s removido.\n\n",cliente.nome);  
      }
      else
        printf ("\n\nCliente %s nao removido.\n\n",cliente.nome);  
      achou = 1;
    }
  if (!achou)
    printf ("Nao ha cliente cadastrado com numero de conta %d.\n\n",numero);
  fclose (arquivo);
  getch();
}  
//------------------------------------
void remocaoFisica (char nomearq[]){
  FILE *arquivo, *arqaux;
  dados cliente;
  // Abertura do arquivo
  if ((arquivo = fopen(nomearq, "rb")) == NULL) {
    printf ("\n Erro na realizacao da remocao fisica.\n\n");
    getch();
    return;
  }
  arqaux = fopen("NOME.BAK", "wb");
  while (fread (&cliente, sizeof(dados), 1, arquivo) == 1)
    if (cliente.existe)
      fwrite (&cliente, sizeof(dados), 1, arqaux);
  fclose (arquivo);
  fclose (arqaux);
  remove(nomearq);
  rename ("NOME.BAK",nomearq);
  printf ("\n\nRemocao fisica realizada.");
  getch();
}  
//------------------------------------
int main() {
  char opcao, nome_arquivo[20];
  printf ("Nome do arquivo a ser manipulado: ");
  gets (nome_arquivo);
  do{
    menu(&opcao);
    switch (opcao) {
      case '1': cadastra(nome_arquivo);
                break;
      case '2': mostra (nome_arquivo);
                break;
      case '3': consultaNumero(nome_arquivo);
                break;
      case '4': consultaNome(nome_arquivo);
                break;
      case '5': alteraNumero(nome_arquivo);
                break;
      case '6': apagaRegNumero(nome_arquivo);
                break;              
      case '7': break;
      default: printf ("\nOpcao errada.\n");
    }
  } while (opcao != '7');
  remocaoFisica(nome_arquivo);
}    
//------------------------------------