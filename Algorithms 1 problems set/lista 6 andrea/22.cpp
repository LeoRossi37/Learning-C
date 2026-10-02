int buscaBinRec(int *v,int esq, int dir, int num){
    int meio=(esq+dir)/2;
    if(esq>dir){
        return -1;
    }
    if(v[meio]==num){
        return meio;
    }
    if(v[meio]>num){
         return buscaBinRec(v,esq,meio-1,num);
    }else{
         return buscaBinRec(v,meio+1,dir,num);
    }
}