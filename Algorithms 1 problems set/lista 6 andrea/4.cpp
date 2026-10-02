#include <bits/stdc++.h>
using namespace std;

// A função abaixo recebe um vetor crescente v[0..n-1]
// com n >= 1 e um número x.
// Ela devolve um índice j em 0..n tal que v[j-1] < x <= v[j].
int buscabinaria (int x, int n, int v[]) {
int e, m, d;
if (v[n-1] < x) return n;
if (x <= v[0]) return 0; // agora v[0] < x <= v[n-1]
e = 0; d = n-1;
while (e < d-1) {
m = (e + d)/2;
if (v[m] < x) e = m;
else d = m;
}
return d;
}

// a) Ele vai acessar a posição n do vetor, sendo que o vetor só vai até a posição n-1
// fazendo com que ele acesse algo de fora do vetor, talvez achando um lixo que quebre a busca.

// b) Pode ser que cause um loop infito no while ou, mesmo se terminar, escolher o valor
// incorreto  pois nao garante que v[d-1]<x<=v[d]

// c) Nos casos de m+1, pode ser que ele ignore um numero e não contabilize ele ou ate mesmo pegue
//  um numero que nao esta no vetor, assim como no m-1 mas agora invertido.