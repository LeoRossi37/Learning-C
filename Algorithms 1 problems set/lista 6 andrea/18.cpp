#include <bits/stdc++.h>
using namespace std;

int buscabinaria2 (int x, int n, int v[]) {
e = -1; d = n-1;
while (e < d)
{
m = (e + d)/2;
if (v[m] < x) e = m;
else d = m-1;
}
return d+1;
}

// Sim funciona, de modo diferente, mas funciona