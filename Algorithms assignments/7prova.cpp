#include <bits/stdc++.h>
using namespace std;

struct produtos{
    int cod;
    char desc[20];
    int qtd;
};

int buscaBinRec(int *v, int ini, int fim, int num){
    int meio=(ini+fim)/2;
    if(ini >=fim) return -1;
    if(num=v[meio]){
        return num;
    }
    if(num>v[meio]){
        return buscaBinRec(v,meio+1,fim,num);
    }else if(num<v[meio]){
        return buscaBinRec(v, ini, meio-1, num);
    }else{
        return -2;
    }
}

int bubble(int v[], int n){
    int troca=1;
    for(int i=0; i<n && troca; i++){
        troca=0;
        for(int j=0; j<n-1-i; j++){
            if(v[j]>v[j+1]){
                troca=1;
                int temp=v[j];
                v[j]=v[j+1];
                v[j+1]=temp;
            }
        }
    }
}

int main(){
    
    printf("Quantos produtos deseja cadastrar?: ");
    int x;
    cin >> x;
    produtos prod[x];
    int v[x];
    for(int i=0; i<x;i++){
        cout << "\nDigite o id, descricao e quantidade em estoque do produto:";
        cin >> prod[i].cod;
        cin.ignore();
        cin.getline(prod[i].desc,50);
        cin>>prod[i].qtd;
        v[i]=prod[i].cod;
    }
    bubble(v,x);
    int codigo;
    cout << "Digite o codigo do produto que quer ver:";
    cin >> codigo;
    int ajuda;
    ajuda=buscaBinRec(v,0,x-1,codigo);
    if(ajuda==-2){
        printf("Numero nao encontrado");
    }else{
        printf("Seu produto eh: %s e tem %d em estoque", prod[ajuda].desc, prod[ajuda].qtd);
    }
    
}