/*
    Resposta:
    aloha[2] = value funciona e atribui o valor 2.2 a terceira posição do vetor aloha
    scanf("%f", &aloha) não funciona, pois tenta atribui um valor float à posição do vetor aloha (endereço)
    aloha = "value" dá errado porque há atribuição de uma string (conjunto de char) a uma varíavel do tipo float
    printf("%f", aloha) não dá erro de quebrar o código, mas não mostra o valor de aloha, pois não foi especificado nenhuma posição do vetor, irá mostrar lixo de memória
    coisas[4][4] = aloha[3] funciona e atribui o valor do índice 3 de aloha à matriz de coisas na posição [4][4]
    coisas[5] = aloha não funciona pois tenta acessar atribuir um vetor a uma array
    pf = value não funciona, pois tenta atribuir um float a um ponteiro e não um endereço de memoria.
    pf = aloha funciona por causa do isomorfismo entre os vetores/arrays e os ponteiros.
*/

#include <stdio.h>
 
 int main(void) {
    float aloha[10], coisas[10][5], *pf, value = 2.2;
    int i=3;
    
    aloha[2] = value;
    scanf("%f", &aloha);  // apresenta warnings mas funciona por sorte
    // aloha = "value";
    printf("%f", aloha);  // apresenta warnings mas não quebra o código
    coisas[4][4] = aloha[3];
    // coisas[5] = aloha;
    // pf = value;
    pf = aloha;
    
    return 0;
 }
