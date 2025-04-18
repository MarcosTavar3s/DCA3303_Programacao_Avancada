/*
    Resposta: A saída é um erro, pois há a tentativa de atribuição de um inteiro a um ponteiro, variável que armazena endereços de memória.
*/

 #include <stdio.h>
 
 void main(){
    int const *x= 3;
    printf("%d", ++(*x));
 }
