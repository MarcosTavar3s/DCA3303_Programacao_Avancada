/*
    Resposta: A saída do programa será a string "gh", pois a operação (p += sizeof(int))[-1]
    corresponde a um salto no endereço de p em 3 bytes (4 bytes por causa do sizeof(int) e -1 do
    ponteiro t que é do tipo char, feito no [-1]). 
*/

#include <stdio.h>

 void funcao(char **p){ // recebe um ponteiro para ponteiro para char (matriz) - endereço do ponteiro
    char *t; // cria um ponteiro para char (tamanho = 1 byte)
    t = (p += sizeof(int)); //  pega o endereço de p salta 4 espaços na memória e volta um espaço (pula 3 espaços)
    // t = endereço de p + 4 bytes - 1 byte = endereço de p + 3 bytes
    printf("%s\n", t); // imprime string armazenada no ponteiro
 }
 
 int main(){
     
    char *a[] = { "ab", "cd", "ef", "gh", "ij", "kl"}; // ponteiro para vetor de char (matriz)
    funcao(a);
    
    return 0;
 }
