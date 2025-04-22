#include <stdio.h>
#include <stdlib.h>

void preenchimento_matriz(int **matriz, int nl, int nc){
    for(int i=0; i<nl; i++){
        for(int j=0; j<nc;j++){
            matriz[i][j] = rand()%20;
        }
    }
}

void multiplica_matrizes(int **a, int **b, int **c, int nl_final, int inter, int nc_final){
    
    // preenchimento de c deve ser dois for (1° com nl_final, 2° com nc_final)
    for(int i = 0; i < nl_final; i++){
        for(int j = 0; j < nc_final; j++){
            c[i][j] = 0; // inicia o vetor com 0 porque faz um somatório acumulativo
            for(int k = 0; k < inter; k++){
                // linha de a com coluna de b
                c[i][j] += a[i][k]*b[k][j];
            }
        }
    }  

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
    
    for(int i=0; i<nlc; i++){
        for(int j=0; j<ncc;j++){
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
    
    free(a[0]);
    free(b[0]);
    free(c[0]);
    free(a);
    free(b);
    free(c);
    
    return 0;
}
