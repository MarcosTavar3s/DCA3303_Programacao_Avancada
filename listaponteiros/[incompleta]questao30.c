#include <stdio.h>
#include <stdlib.h>

int main() {
    int ***matriz;
    int np, nl, nc;

    printf("Coloque o numero de planos, linhas e colunas (profundidade, altura e comprimento):\n");
    scanf("%d %d %d", &np, &nl, &nc);
    
    // alocação da matriz
    matriz = malloc(np * sizeof(int**));
    matriz[0] = malloc(np * nl * sizeof(int*));
    matriz[0][0] = malloc(np * nl * nc * sizeof(int));
    
    /*
        planos -> int ***n -> plano1    plano2      plano3
        linhas -> int **n ->  linha1    linha2      linha3
        colunas -> int *n -> coluna1    coluna2    coluna3
    */
    
    // fixação dos planos
    for(int i = 1; i < np; ++i) {
        matriz[i] = matriz[i-1] + nl;
    }
    
    // fixação das linhas em relação ao plano
    for (int i = 1; i < np; ++i) {
        matriz[i][0] = matriz[i-1][0] + (nl * nc);
    }
    
    // fixação das colunas
    for (int i = 0; i < np; ++i) {
        for (int j = 1; j < nl; ++j) {
            matriz[i][j] = matriz[i][j-1] + nc;
        }
    }

    // preenchimento
    for(int i = 0; i < np; ++i) {
        for (int j = 0; j < nl; ++j) {
            for (int k = 0; k < nc; ++k) {
                matriz[i][j][k] = rand() % 10;
            }
        }
    }

    
    // impressão
    for(int i = 0; i < np; ++i) {
        printf("\nPlano %d:\n", i);
        for (int j = 0; j < nl; ++j) {
            for (int k = 0; k < nc; ++k) {
                printf("%d ", matriz[i][j][k]);
            }
            printf("\n");
        }
    }
    
    
    // liberação da memoria
    free(matriz[0][0]);
    free(matriz[0]);
    free(matriz);

    return 0;
}
