#include <bits/stdc++.h>
using namespace std;

int buscabinaria2 (int x, int n, int v[]) {
int e = -1, d = n;
while (e < d-1) {
m = (e + d)/2;
if (v[m] < x) e = m;
else d = m;
}
return d;
}

