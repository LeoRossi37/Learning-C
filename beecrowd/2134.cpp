#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    int count=0;
    while(cin >> n){
    vector<int> notas(n);
    vector<string> names(n);
    for(int i=0; i<n; i++){
        string nome;
        cin >> nome;
        if(nome.size()>20){
            nome=nome.substr(0,20);
        }
        names[i]=nome;
        cin >> notas[i];
    }
    vector<pair<int,string>> v;
    for(int i=0; i<n; i++){
        v.push_back({notas[i],names[i]});
    }
    sort(v.begin(),v.end(),[](pair<int,string> a,pair<int,string> b){
        if(a.first!=b.first) return a.first<b.first;
        return a.second>b.second;
    });
    count++;
    printf("Instancia %d\n",count);
    cout << v[0].second << endl << endl;
    if(cin.eof()) break;

 }
}