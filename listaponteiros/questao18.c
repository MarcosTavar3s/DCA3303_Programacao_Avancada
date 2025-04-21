/*
  Resposta: Ponteiro para função é uma técnica em C/C++ para atribuir a um ponteiro o endereço do código executável de uma função,
  permitindo que a variável ponteiro ao ser invocada possa executar o que ocorre na função. Vale ressaltar ainda, que não é possível
  realizar aritmética de ponteiros (isto é, sair pulando na memória) em ponteiros para função.

  Fonte: https://www.ibm.com/docs/pt-br/i/7.5.0?topic=functions-pointers
*/
#include <stdio.h>
#include <stdlib.h>

// Função que multiplica uma entrada por 2
int multiplica_por_dois(int num){
    return num << 1; // uso do operador de bits para fazer de forma mais rápida a multiplicação
};

int main(void){
    // Definição das variáveis
    int (*pf)(int) = &multiplica_por_dois; // ponteiro para uma função do tipo int e que tem parâmetro int
    int a = 5; // variavel que será usado para demonstrar o ponteiro para função

    // Mostra os dados
    printf("a = %d\n", a); // mostra o valor de a = 5
    printf("2*a = %d", pf(a)); // mostra o valor de a após passar pela função apontada pelo ponteiro, ou seja, 2*a = 10

    return 0;
}
