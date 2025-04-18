 /*
    Resposta: A saída mostrará o mesmo endereço de memória 3 vezes. Esse comportamento ocorre devido a forma de alocação de matrizes
    na memória que acontece em blocos de memória isomorfos a vetores com uma fixação de ponteiros. Vale ressaltar que as expressões se
    comportam de maneira a extrair o endereço do índice x[3][0].
    Detalhamento e justificativas:
    x+3: pula 3 unidades de memória em x, mas como x é uma matriz, ou seja, **x, ela armazena o endereço do começo da última linha da matriz
    *(x+3): extrai o valor de x+3, porém x[][], como dito acima, é isomorfo a **x, assim, o retorno também é o endereço de memória de x[3][0]
    *(x+2)+3: extrai o valor do endereço da memória do elemento x[2][0] e pula 3 casas na memória, o que resulta na próxima linha, pois a matriz tem 3 colunas.
 */
#include <stdio.h>
int main(){
    unsigned int x[4][3] = {{1, 2, 3}, {4, 5, 6},
    {7, 8, 9}, {10, 11, 12}};
    
    printf("%u, %u, %u", x+3, *(x+3), *(x+2)+3);
}
