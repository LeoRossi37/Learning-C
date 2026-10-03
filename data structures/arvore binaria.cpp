#include<bits/stdc++.h>
using namespace std;
#define MAX 30

typedef int Arvore[MAX];

void inicializar_arvore(Arvore arvore) {
    for (int i = 0; i < MAX; i++) {
        arvore[i] = -1;
    }
}

// Limpa o buffer de entrada do teclado
void limpar_buffer() {
	int c;
	while ((c = getchar()) != '\n' && c != EOF);
}

void ler_arvore(Arvore arvore) {
    printf("Digite o valor da raiz: ");
    scanf("%d", &arvore[0]);

	char tem_filho;


    for (int pai = 0; pai < MAX; pai++) {

        if (arvore[pai] == -1) {
			continue;
		}

		printf("\nO vértice %d possui filho? (s = sim) ", arvore[pai]);
		scanf(" %c", &tem_filho);
		limpar_buffer();
		
		if (tem_filho != 's') {
			continue;
		}

		printf("\nLeitura dos filhos de %d\n", arvore[pai]);

		int filho_esq = 2 * pai + 1;
        int filho_dir = 2 * pai + 2;

        if (filho_esq < MAX) {
            printf("Digite o valor do filho esquerdo (-1 para nulo): ");
            scanf("%d", &arvore[filho_esq]);
        }

        if (filho_dir < MAX) {
            printf("Digite o valor do filho direito (-1 para nulo): ");
            scanf("%d", &arvore[filho_dir]);
        }
    }
}

void mostrar_arvore(Arvore arvore, int pai, int nivel, char *rotulo) {
	if (pai >= MAX || arvore[pai] == -1) {
		return;
	}

	printf(" ");

	// Imprime indentação de acordo com o nível do vértice
	for (int i = 0; i <= nivel * 3; i++) {
		printf("--");
	}

	printf("%d (%s)\n", arvore[pai], rotulo); // Mostra o valor do vértice

	nivel += 1; // Incrementa nível para os filhos

	// Exibe filhos recursivamente
	int filho_esq = 2 * pai + 1;
	int filho_dir = 2 * pai + 2;

	if (filho_esq < MAX && arvore[filho_esq] != -1) {
		mostrar_arvore(arvore, filho_esq, nivel, "esq");
	}

	if (filho_dir < MAX && arvore[filho_dir] != -1) {
		mostrar_arvore(arvore, filho_dir, nivel, "dir");
	}
}

int buscar(Arvore arvore, int pai, int valor) {
	if (pai >= MAX || arvore[pai] == -1) {
		return 0;
	}

	if (arvore[pai] == valor) {
		return 1;
	}

	return buscar(arvore, 2 * pai + 1, valor) || buscar(arvore, 2 * pai + 2, valor);
}

void percorrer_pre_ordem(Arvore arvore, int pai) {
	if (pai >= MAX || arvore[pai] == -1) {
		return;
	}
	
	printf("%d ", arvore[pai]);
	
	percorrer_pre_ordem(arvore, 2 * pai + 1);
	percorrer_pre_ordem(arvore, 2 * pai + 2);
}

void percorrer_em_ordem(Arvore arvore, int pai) {
	if (pai >= MAX || arvore[pai] == -1) {
		return;
	}

	percorrer_em_ordem(arvore, 2 * pai + 1);
	printf("%d ", arvore[pai]);
	percorrer_em_ordem(arvore, 2 * pai + 2);
}

void percorrer_pos_ordem(Arvore arvore, int pai) {
	if (pai >= MAX || arvore[pai] == -1) {
		return;
	}

	percorrer_pos_ordem(arvore, 2 * pai + 1);
	percorrer_pos_ordem(arvore, 2 * pai + 2);
	printf("%d ", arvore[pai]);
}

void mostrar_vetor(Arvore arvore) {
    for (int i = 0; i < MAX; i++) {
        printf("Arvore[%2d] = %d\n", i, arvore[i]);
    }
}

int profundidade(Arvore arvore, int pai){
    if (pai >= MAX || arvore[pai] == -1) {
		return 0;
	}

	int filho_esq = 2 * pai + 1;
	int filho_dir = 2 * pai + 2;

	int prof_esq=profundidade(arvore, filho_esq);
    int prof_dir=profundidade(arvore, filho_dir);

    return 1+(prof_esq>prof_dir ? prof_esq : prof_dir);
}

int qtd_nos_folha(Arvore arvore, int pai){
    if(pai>=MAX || arvore[pai]==-1){
        return 0;
    }

    int filho_esq = 2*pai+1;
    int filho_dir = 2*pai+2;

    if((filho_esq>=MAX || arvore[filho_esq]==-1) && (filho_dir>=MAX || arvore[filho_dir]==-1)){
        return 1;
    }

    return qtd_nos_folha(arvore,filho_dir)+qtd_nos_folha(arvore,filho_esq);

}

int buscar_indice(Arvore arvore, int pai, int valor){
	if(pai>=MAX || arvore[pai]==-1){
		return -1;
	}

	if(arvore[pai]==valor){
		return pai;
	}
	int resultado = buscar_indice(arvore, 2*pai+1, valor);
	if(resultado!=-1){
		return resultado;
	}
	return buscar_indice(arvore, 2*pai+2, valor);
}

void mostrar_relacoes(Arvore arvore, int valor){
    int i = buscar_indice(arvore,0,valor);

    if(i==-1){
        printf("Valor nao encontrado");
    }
    if(i==0){
        cout << "Nao tem pai(raiz)\n\n";
    }else{
        int pai = (i-1)/2;
        cout << "Pai: " << arvore[pai] << endl;
    }

    int esq =2*i+1;
    if(esq<MAX && arvore[esq]!=-1){
        cout << "FIlho esquerdo: " << arvore[esq]<<endl;
    }else{
        cout << "Nao tem filho esquerdo\n";
    }

    int dir = 2*i+2;
    if(dir<MAX && arvore[dir]!=-1){
        cout << "Filho direito: " << arvore[dir] << endl;
    }else{
        cout << "Não tem filho direito\n";
    }

}

int qtd_nos(Arvore arvore, int pai){
	if(pai>=MAX || arvore[pai]==-1){
		return 0;
	}

	return 1 + qtd_nos(arvore, 2*pai+1) + qtd_nos(arvore, 2*pai+2);
}

int qtd_nos_um_filho(Arvore arvore, int pai){
	if(pai>=MAX || arvore[pai]==-1){
		return 0;
	}

	int filho_esq = 2*pai+1;
	int filho_dir = 2*pai+2;

	int qtd = 0;

	if((filho_esq<MAX && arvore[filho_esq]!=-1) && (filho_dir>=MAX || arvore[filho_dir]==-1)){
		qtd = 1;
	}

	if((filho_dir<MAX && arvore[filho_dir]!=-1) && (filho_esq>=MAX || arvore[filho_esq]==-1)){
		qtd = 1;
	}

	return qtd + qtd_nos_um_filho(arvore, filho_esq) + qtd_nos_um_filho(arvore, filho_dir);
}

int qtd_nos_com_filho(Arvore arvore, int pai){
	if(pai>=MAX || arvore[pai]==-1){
		return 0;
	}

	int filho_esq = 2*pai+1;
	int filho_dir = 2*pai+2;

	int qtd = 0;

	if((filho_esq<MAX && arvore[filho_esq]!=-1) || (filho_dir<MAX && arvore[filho_dir]!=-1)){
		qtd = 1;
	}

	return qtd + qtd_nos_com_filho(arvore, filho_esq) + qtd_nos_com_filho(arvore, filho_dir);
}

int qtd_nos_dois_filhos(Arvore arvore, int pai){
	if(pai>=MAX || arvore[pai]==-1){
		return 0;
	}

	int filho_esq = 2*pai+1;
	int filho_dir = 2*pai+2;

	int qtd = 0;

	if(filho_esq<MAX && arvore[filho_esq]!=-1 && filho_dir<MAX && arvore[filho_dir]!=-1){
		qtd = 1;
	}

	return qtd + qtd_nos_dois_filhos(arvore, filho_esq) + qtd_nos_dois_filhos(arvore, filho_dir);
}

void mostrar_pai_irmao(Arvore arvore, int valor){
	int i = buscar_indice(arvore, 0, valor);

	if(i==-1){
		printf("Valor nao encontrado\n");
		return;
	}

	if(i==0){
		printf("O valor %d e a raiz e nao possui pai nem irmao\n", valor);
		return;
}

int pai = (i-1)/2;

	printf("Pai: %d\n", arvore[pai]);

	if(i%2==1){
		int irmao = i+1;

		if(irmao<MAX && arvore[irmao]!=-1){
			printf("Irmao: %d\n", arvore[irmao]);
		}else{
			printf("Nao possui irmao\n");
		}
	}else{
		int irmao = i-1;

		if(irmao>=0 && arvore[irmao]!=-1){
			printf("Irmao: %d\n", arvore[irmao]);
		}else{
			printf("Nao possui irmao\n");
    }
}
}

int main() {
    Arvore arvore;
	int valor_busca;

	inicializar_arvore(arvore);

	printf("Leitura da Arvore\n");
	ler_arvore(arvore);

	printf("\nÁrvore binária criada: \n");
	mostrar_arvore(arvore, 0, 0, "raiz");

	printf("\nVetor que armazena a árvore: \n");
	mostrar_vetor(arvore);

	printf("\n\n");
	printf("Percurso em pré-ordem: ");
	percorrer_pre_ordem(arvore, 0);

	printf("\n\nPercurso em em-ordem: ");
	percorrer_em_ordem(arvore, 0);

	printf("\n\nPercurso em pós-ordem: ");
	percorrer_pos_ordem(arvore, 0);
    
    printf("\nProfundidade: %d\n", profundidade(arvore,0));
    printf("\nQuantidade de nos folha: %d", qtd_nos_folha(arvore,0));
    
	printf("Digite um valor para verificar seu pai e filho(se houver): ");
    int value;
    cin >> value;
    mostrar_relacoes(arvore, value);

	printf("\n\nBusca\n");
	printf("Digite um valor para verificar se está na árvore: ");
	scanf("%d", &valor_busca);

	if (buscar(arvore, 0, valor_busca)) {
		printf("O valor %d está na árvore!\n", valor_busca);
	} else {
		printf("O valor %d não está na árvore!\n", valor_busca);
	}
	printf("\nQuantidade total de nos: %d\n", qtd_nos(arvore,0));

	printf("Profundidade: %d\n", profundidade(arvore,0));

	printf("Quantidade de nos folha: %d\n", qtd_nos_folha(arvore,0));

	printf("Quantidade de nos com exatamente um filho: %d\n", qtd_nos_um_filho(arvore,0));

	printf("Quantidade de nos com pelo menos um filho: %d\n", qtd_nos_com_filho(arvore,0));

	printf("Quantidade de nos com dois filhos: %d\n", qtd_nos_dois_filhos(arvore,0));

}