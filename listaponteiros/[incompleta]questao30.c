#include <stdio.h>
#include <stdlib.h>

int main() {
    // declaracao de variaveis
    int ***matriz, np, nl, nc;
    
    printf("Coloque o numero de planos, linhas e colunas (profundidade, altura e comprimento):\n");
    scanf("%d %d %d", &np, &nl, &nc);
    
    // aloca número de planos
    matriz = malloc(np * sizeof(int**));
    
    // aloca espaço para todas as linhas
    matriz[0] = malloc(np * nl * sizeof(int*));
    
    // aloca espaço para todos os elementos
    matriz[0][0] = malloc(np * nl * nc * sizeof(int));
    
    
    // liberação do espaço alocado
    free(matriz[0][0]);
    free(matriz[0]);
    free(matriz);
    
    return 0;
}
