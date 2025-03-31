/*
    Primeiro %p: mostra o endereco de i que foi armazenado em p
    Segundo %p: mostra o endereco de i mais um salto do tamanho short int (2 bytes ou 16 bits a mais no endereco)
    
    Primeiro %d: mostra o valor de i + 2 (p aponta pra i e pega seu valor) - res: 7
    Segundo %d: mostra o valor de i (pega o endereço presente em p e pega o valor do endereco dele) - res: 5
    Terceiro %d: por ordem de precedencia, o resultado e 3 vezes o valor do endereco que p aponta (3 vezes i) - res: 15
    Quarto %d: mostra o valor de i (pega o endereço presente em p e pega o valor do endereco dele) e soma com 4 - res: 9
*/

#include <stdio.h>

int main(void){
    short int i = 5, *p; // inteiro de 16 bits (2 bytes)
    p = &i;
    printf("%p %p %d %d %d %d\n", p, p+1, *p+2, **&p, 3**p, **&p+4);


    return 0;
}