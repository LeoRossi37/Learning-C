#include<bits/stdc++.h>
using namespace std;
#define MAX 30

typedef int Arvore[MAX];

void incia_arvore(Arvore arvore){
    for(int i=0;i<MAX; i++){
        arvore[i]=-1;
    }
}

void limpar_buffer() {
	int c;
	while ((c = getchar()) != '\n' && c != EOF);
}

void ler_arvore(Arvore arvore){
    cout << "Digire o valor da raiz :";
    cin >> arvore[0];
    char flag;
    for( int i =0; i<MAX; i++){
        if(arvore[i]==-1){
            continue;
        }
        printf( " \n O vertice %d, possui filho?(s-sim/n-nao)", arvore[i]);
        cin >> flag;
        limpar_buffer();
        if(flag!='s'){
            continue;
        }

        printf("Leitura dos filhos de %d\n", arvore[i]);
        int filho_esq=2*i+1;
        int filho_dir=2*i+2;
        if(filho_esq<MAX){
            printf("Digite o valor para o filho esquerdo(-1 para vazio)");
            cin >> arvore[filho_esq];
        }
        if(filho_dir<MAX){
            printf("DIgite o valor para o filho direito(-1 para vazio)");
            cin >> arvore[filho_dir];
        }

    }
}
void mostrar_arvore(Arvore arvore, int pai, int grau, char *rotulo){
    if(pai>=MAX || arvore[pai]==-1){
        return;
    }

    printf("\n----\n");
    for(int i =0 ; i<=grau; i++){
        printf("--");
    }

    printf("%d (%s)\n", arvore[pai], rotulo);
    grau++;
    int filho_esq=2*pai+1;
    int filho_dir=2*pai+2;
    if(filho_esq<MAX && arvore[filho_esq]!=-1){
        mostrar_arvore(arvore, filho_esq, grau, "esq");
    }
    if(filho_dir<MAX && arvore[filho_dir]!=-1){
        mostrar_arvore(arvore, filho_dir, grau, "dir");
    }

}

int busca(Arvore arvore, int pai, int valor){
    if (pai>=MAX || arvore[pai]==-1){
        return 0;
    }
    if(arvore[pai]==valor){
        return 1;
    }
    return busca(arvore, 2*pai+1, valor) || busca(arvore, 2*pai+2, valor);
}


void percorrer_pre_ordem(Arvore arvore, int pai){
    if(pai>=MAX || arvore[pai]==-1){
        return;
    }

    printf("%d", arvore[pai]);
    percorrer_pre_ordem(arvore,2*pai+1);
    percorrer_pre_ordem(arvore,2*pai+2);

}

void percorrer_em_ordem(Arvore arvore, int pai){
    if(pai>=MAX || arvore[pai]==-1){
        return;
    }
    percorrer_em_ordem(arvore, 2*pai+1);
    printf("%d", arvore[pai]);
    percorrer_em_ordem(arvore, 2*pai+2);
}

void percorrer_pos_ordem(Arvore arvore, int pai){
    if(pai>=MAX || arvore[pai]==-1){
        return;
    }
    percorrer_pos_ordem(arvore, 2*pai+1);
    percorrer_pos_ordem(arvore, 2*pai+2);
    printf("%d", arvore[pai]);
}

void mostrar_vetor(Arvore arvore){
    for(int i=0; i<MAX; i++){
        printf("Arvore[%2d]= %d\n", i, arvore[i]);
    }
}

int profundidade(Arvore arvore, int pai){
    if(pai >=MAX || arvore[pai]==-1){
        return 0;
    }
    int filho_esq=2*pai+1;
    int filho_dir=2*pai+2;
    int prof_esq=profundidade(arvore, filho_esq);
    int prof_dir=profundidade(arvore, filho_dir);

    return 1+(prof_esq>prof_dir ? prof_esq : prof_dir);

}

int qtd_nos_folha(Arvore arvore, int pai){
    if(pai>=MAX || arvore[pai]==-1){
        return 0;
    }
    int filho_esq=2*pai+1;
    int filho_dir=2*pai+2;
    if((filho_esq>=MAX || arvore[filho_esq]==-1) && (arvore[filho_dir]==-1 || filho_dir>=MAX)){
        return 1;
    }

    return qtd_nos_folha(arvore, filho_dir)+qtd_nos_folha(arvore,filho_esq);

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

void mostrar_relacoes(Arvore arvore, int value){
    int i = buscar_indice(arvore,0,value);
    if(i==-1){
        printf("Valor nao encontrado\n");
        return;
    }
    if(i==0){
        printf("Nao tem pai(raiz)\n");
    }else{
        int pai =(i-1)/2;
        printf("Pai %c\n", arvore[pai]);
    }
    int esq=2*i+1;
    if(esq<MAX && arvore[esq]!=-1){
        printf("Filho esquerdo %c\n", arvore[esq]);
    }
    else{
        cout << "Nao tem filho esquerdo\n";
    }

    int dir=2*i+2;
    if(dir<MAX && arvore[dir]!=-1){
        printf("Filho direito %c", arvore[dir]);

    }else {
        printf("Nao tem filho direito");
    }

}

int main(){
    Arvore arvore;
    int valor_busca;
    incia_arvore(arvore);
    printf("Leitura da arvore:");
    ler_arvore(arvore);
    cout << "\nArvore binaria criada: \n";
    mostrar_arvore(arvore,0,0,"raiz");
    cout << "Digite um valor para buscar na arvore:";
    cin >> valor_busca;
    if(busca(arvore, 0, valor_busca)){
        cout << "O valor " << valor_busca << " esta na arvore!";
    }else{
        printf("O valor %d nao esta na arvore", valor_busca);
    }
    
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
}