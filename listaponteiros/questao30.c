#include <stdio.h>
#include <stdlib.h>

void imprimir(int ***matriz, int np, int nl, int nc, int plano){
    // decremento porque o usuario nao começa a contar do 0
    --plano;
    
    printf("Plano %d:\n", plano+1);
    if(nc >= plano){
        for (int j = 0; j < nl; ++j) {
            for (int k = 0; k < nc; ++k) {
                printf("%d ", matriz[plano][j][k]);
            }
                printf("\n");
        }
        return;
    }
    
     for(int i = 0; i < np; ++i) {
        printf("\nPlano %d:\n", i+1);
        for (int j = 0; j < nl; ++j) {
            for (int k = 0; k < nc; ++k) {
                printf("%d ", matriz[i][j][k]);
            }
            printf("\n");
        }
    } 
}

int main() {
    int ***matriz;
    int np, nl, nc;
    int impressao, modificar_arr;

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

    printf("Deseja imprimir a matriz preenchida randomicamente?\nDigite 1 para sim e 0 para nao\n");
    scanf("%d", &impressao);
    
    if(impressao==1){
        int plano;
        printf("Qual plano voce deseja imprimir(comecando de 1)?\n Se quiser todos, digite uma dimensao maior que o numero de planos disponiveis\n");
        scanf("%d", &plano);
        // impressão
        imprimir(matriz, np, nl, nc, plano);
    }
    
    printf("Deseja mudar algum valor?\nDigite 1 para sim e 0 para nao\n");
    scanf("%d", &modificar_arr);
    
    if(modificar_arr==1){
        // dimensão da array que vai ser alterada
        int nnp, nnl, nnc;
        printf("Digite o plano, linha e coluna (comecando de 1):\n");
        scanf("%d %d %d", &nnp, &nnl, &nnc);
        
        if(nnp > np+1 || nnl > nl+1 || nnc > nc+1){
            printf("Dimensoes fora do alcance! Xau!");
            exit(0);
        }
        
        printf("Digite o numero:\n");
        // -1 pois o usuario não dá input com o plano começando com 0
        scanf("%d", &matriz[nnp-1][nnl-1][nnc-1]);
        
        imprimir(matriz, np, nl, nc, nnp); // imprime o plano depois de alterado

    }
    
    // liberação da memoria
    free(matriz[0][0]);
    free(matriz[0]);
    free(matriz);

    return 0;
}
