/*
    Resposta: *q = &j e q = *p; causarão erro, pois o *q é uma variável do tipo int e &j retorna um endereço que deve ser armazenado em um ponteiro.
    Além disso, q = *p é errado porque tenta atribuir um valor inteiro a um ponteiro.
    
    Em suma, o principal erro de ambas consistem no erro de atribuição entre os tipos e confusão com a utilização dos operadores de ponteiros.
*/

#include <stdio.h>

int main(void){
    int i, j;
    int *p, *q;

    p = &i;// p = endereço de i
    *q = &j; // atribui ao valor do endereço de q (tipo int) um endereço (ponteiro)
    p = &*&i;  // p = endereço de i
    i = (*&)j;  // simplificando a expressão i = j
    i = *&j; // simplificando a expressão i = j
    i = *&*&j; // simplificando a expressão i = j
    q = *p; // atribui um numero inteiro a um ponteiro (problematica entre tipo) 
    i = (*p)++ + *q; // valor do endereco armazenado em p somado com 1 + valor do endereco armazenado em q

}