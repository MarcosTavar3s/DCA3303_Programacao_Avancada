// Resposta 01: 1
// Resposta 02: -2
// Resposta 03: 3
// Resposta 04: 10

#include <stdio.h>

int main(void){
    // declaracao de variaveis
    int i=3, j=5;
    int *p, *q;

    p = &i; // o ponteiro p armazena o endereco da memoria de i
    q = &j; // o ponteiro q armazena o endereco da memoria de j

    // printando as expressoes para avaliar o que cada uma faz
    printf("%d\n", p==&i); // comparacao entre o endereco armazenado em p com o de i (resultado e verdadeiro, ou seja, 1 por causa da atribuicao acima)
    printf("%d\n", *p-*q); // o resultado e um int, pois os ponteiros apontam para as variaveis i e j
    printf("%d\n", **&p); // pega o endereco de p, o valor que esta armazenado no endereco de p, como o valor e outro endereco e tem * ele pega o valor do endereco armazenado em p (variavel i)
    printf("%d\n", 3-*p/(*q)+7); // retorna um int porque os ponteiros estao apontando para os valores das variaveis i e j 

    return 0;
}