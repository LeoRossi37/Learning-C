#include <bits/stdc++.h>
using namespace std;

int buscabinaria2 (int x, int n, int v[]) {
int e, m, d;
e = -1; d = n;
while (e < d-1) {
m = (e + d)/2;
if (v[m] < x) e = m;
else d = m;
}
return d;
}

// Sim m sempre esta nesse intervalo  quando o if é executado, pois apesar
// do e comecar em -1 d começa em n e nao em n-1, portanto corrige esse erro.