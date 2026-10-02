int buscabin(char *x, char v[][50], int n){
    int e = -1, d = n;
    while(e < d - 1){
        int m = (e + d)/2;
        if(strcmp(v[m], x) < 0) e = m;
        else d = m;
    }
    if(d < n && strcmp(v[d], x) == 0) return d;
    return -1;
}