/*
(a) 20
(b) 29.0
(c) P
(d) e
(e) P
(f) e
(g) t
(h) 31
(i) 45
(j) 27
(l) 31
(m) 45
(n) 27
*/

#include <stdio.h>

int main(void) {
    int valor;
    int *p1;
    float temp;
    float *p2;
    char aux;
    char *nome = "Ponteiros";
    char *p3;
    int idade;
    int vetor[3];
    int *p4;
    int *p5;

    /* (a) */
    valor = 10; // atribui 10 a valor
    p1 = &valor; // p1 registra o endereço de valor
    *p1 = 20; // equivale a valor = 20
    printf("(a)%d \n", valor); // retornará 20

    /* (b) */
    temp = 26.5;
    p2 = &temp; // p2 pega o endereço de temp
    *p2 = 29.0; // equivale a temp = 29.0
    printf("(b)%.1f \n", temp); // mostra 29.0 (pois %.1f limita a quantidade de casas decimais no print)

    /* (c) */
    p3 = &nome[0]; // p3 pega o endereço do primeiro caractere do *nome
    aux = *p3; // equivale a aux =  P
    printf("(c)%c \n", aux); // mostra o caractere "P"

    /* (d) */
    p3 = &nome[4]; // p3 pega o endereço do quinto caractere do *nome
    aux = *p3; // equivale a aux = "e"
    printf("(d)%c \n", aux); // mostra o caractere "e"

    /* (e) */
    p3 = nome; // ponteiro de p3 recebe nome
    printf("(e)%c \n", *p3); // o valor da primeira posição do valor de nome, assim *p3 é igual a P

    /* (f) */
    p3 = p3 + 4; // pula 4 bytes na memória, é 4 bytes porque o tipo de p3 é char e cada char tem 1 byte
    printf("(f)%c \n", *p3); // *p3 por natureza é o índice 0 do ponteiro, então p3+4 = "e", ou o mesmo que p3[4]

    /* (g) */
    p3--; // volta 1 byte, porque o tipo de p3 é char e cada char tem 1 byte
    printf("(g)%c \n", *p3); // *p3 é o índice anteriro a p3[4] que é o p3[3], ou o caractere "t"

    /* (h) */
    vetor[0] = 31; // atribuição a posição 0 do vetor
    vetor[1] = 45; // atribuição a posição 1 do vetor
    vetor[2] = 27; // atribuição a posição 2 do vetor
    p4 = vetor; // p4 = vetor
    idade = *p4; // valor de *p4 retorna por natureza o índice 0 do vetor, isso se deve ao "isomorfismo" entre os ponteiros e vetores
    printf("(h)%d \n", idade); // retorna a posição 0 do vetor, ou seja 31

    /* (i) */
    p5 = p4 + 1; // pula 4 bytes na memória, é 4 bytes porque o tipo de p5 é int e cada int tem 4 bytes
    idade = *p5; // isso equivale a vetor[1], isso se deve ao "isomorfismo" entre os ponteiros e vetores
    printf("(i)%d \n", idade); // 45

    /* (j) */
    p4 = p5 + 1; // pula 4 bytes na memória, é 4 bytes porque o tipo de p4 é int e cada int tem 4 bytes
    idade = *p4; // isso equivale a vetor[2], isso se deve ao "isomorfismo" entre os ponteiros e vetores
    printf("(j)%d \n", idade); // 27

    /* (l) */
    p4 = p4 - 2; // volta 4 bytes na memória, porque o tipo do ponteiro é inteiro
    idade = *p4; // *p4 equivale ao primeiro elemento do vetor, isto é, vetor[0]
    printf("(l)%d \n", idade); // 31

    /* (m) */
    p5 = &vetor[2] - 1; // pega o endereço de vetor[2] e volta 4 bytes na memória por causa do tipo int, ou seja, o endereço de vetor[1]
    printf("(m)%d \n", *p5); // 45

    /* (n) */
    p5++; // pula 4 bytes na memória, é 4 bytes porque o tipo de p4 é int e cada int tem 4 bytes, indo para o vetor[2]
    printf("(n)%d \n", *p5); // 27

    return(0);
}