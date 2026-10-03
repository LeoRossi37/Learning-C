#include<bits/stdc++.h>

using namespace std;

#define MAX 30

typedef struct pilhazinha{
    char pilha[MAX];
    int topo;
}Pilha;

void start_list(Pilha *pilha){
    pilha->topo=-1;
}

int esta_cheia(Pilha pilha){
if(pilha->topo==MAX-1){
    return 1;

}
return 0;
}

int esta_vazia(Pilha pilha){
if(pilha->topo==-1){
    return 1;

}
return 0;
}



int push(Pilha *pilha, char info){
    if(esta_cheia(*pilha)){
        return 0;
    }
    pilha->topo++;
    pilha->pilha[pilha->topo]=info;
    return 1;

}

int pop (Pilha *pilha, char *info){
    if(esta_vazia(*pilha)){
        return 0;
    }
    *info=pilha->pilha[pilha->topo];
    pilha->topo--;
}

int main(){
    Pilha pilha;
    char info[MAX];
    start_list(&pilha);
    cin >> info;
    for(int i=0; info[i] != '\0'; i++){
        push(&pilha,info[i]);
    }

    char x;

    while(!esta_vazia(pilha)){
        pop(&pilha,&x);
        cout << x << "\n";
    }


}