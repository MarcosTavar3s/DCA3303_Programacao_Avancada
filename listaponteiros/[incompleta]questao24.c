#include <stdio.h>
#include <stdlib.h>

void preenchimento_matriz(int **matriz, int nl, int nc){
    for(int i=0; i<nl; i++){
        for(int j=0; j<nc;j++){
            matriz[i][j] = rand()%10;
        }
    }
}

int **multiplica_matrizes(int **a, int **b, int **c, int nl_final, int inter , int nc_final){
    
}

int main()
{
    // Declarando as matrizes
    int **a, **b, **c;
    // Declarando numero de linhas e colunas
    int nca, nla, ncb, nlb, ncc, nlc;
    
    // A = 2x3 = 6
    nla = 2;
    nca = 3;
    // B  = 3x4 = 12
    nlb = 3;
    ncb = 4;
    // C = 2x4 = 8 
    nlc = nla;
    ncc = ncb;
    
    // Alocando a memória das matrizes
    a = malloc(nla*sizeof(int*));
    b = malloc(nlb*sizeof(int*));
    c = malloc(nlc*sizeof(int*));
    
    a[0] = malloc(nla*nca*sizeof(int));
    b[0] = malloc(nlb*ncb*sizeof(int));
    c[0] = malloc(nlc*ncc*sizeof(int));
    
    // fixação dos ponteiros
    // A
    for(int i = 1; i < nla; i++){
        a[i] = a[i-1] + nca;
    }
    // B
    for(int i = 1; i < nlb; i++){
        b[i] = b[i-1] + ncb;
    }
    // C
    for(int i = 1; i < nlc; i++){
        c[i] = c[i-1] + ncc;
    }
    
    // preenchimento das matrizes A e B
    preenchimento_matriz(a,nla,nca);
    preenchimento_matriz(b,nlb,ncb);

     for(int i=0; i<nla; i++){
        for(int j=0; j<nca;j++){
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    
    for(int i=0; i<nlb; i++){
        for(int j=0; j<ncb;j++){
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }
    
    
    // multiplicacao das matrizes
    multiplica_matrizes(a,b,c,2,3,4);
    
    return 0;
}
