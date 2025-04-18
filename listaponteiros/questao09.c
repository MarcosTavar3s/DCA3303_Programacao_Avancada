/*
    Resposta:
    p = mat+1 é uma expressão válida, por causa do isomorfismo entre vetores e ponteiros. Vale ressaltar que o que acontece internamente é a extração do endereço do primeiro índice do vetor (0) e incrementa um salto de 1 unidade de tamanho int(4 bytes) na memória
    p = mat++ não funciona, pois o operador ++ funciona como um incrementador de +1 em números inteiros, mas p armazena somente endereços de memória (tipo de dado ponteiro)
    p = ++mat não funciona, vide explicação de p = mat++
    x = (*mat) é uma expressão válida. Ela vai no endereço de memória do vetor e extrai seu valor, armazenando na variável inteira (não há incompatibilidade de tipos)
    
*/
#include <stdio.h>

int main() {
    int mat[4], *p, x;
    p = mat+1;
    p = mat++;
    p = ++mat;
    x = (*mat);

    return 0;
}
