#include <bits/stdc++.h>
using namespace std;

int busca (int x, int n, int v[]) {
int j = 0;
while (v[j] < x && j < n) ++j;
return j;
}
// esse código tem problemas, pois se j=n ele ainda acessa v[j] e pode ser que retorne algo indesejado
// podendo acessar algo fora do vetor.