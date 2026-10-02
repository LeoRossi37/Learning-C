#include<iostream>
#include<time.h>
#include<stdlib.h>
using namespace std;

int main(){
    cout << "Digite a quantia a apostar:" << endl;
    int qnt, roleta, num;
    cin >> qnt;
    srand(time(NULL));
    num= rand() % 101;
    int count=0;
    do{
        cout << "Digite um numero de 1 a 100:";
        cin >> roleta;
        if(num>roleta){
            cout << "Mais alto" << endl;
            count++;
            qnt-=10;
        }
        if(num<roleta){
            cout << "Mais baixo" << endl;
            count++;
            qnt-=10;
        }
        if(num==roleta){
            count++;
            cout << "Parabens voce acertou em " << count  << " tentativas, o numero era:" << num << endl;
            cout << "Voce ganhou " << qnt << " reais";
        }
    }while(roleta!=num);
    
    
}