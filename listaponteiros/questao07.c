/*
    Resposta:
    1° printf: faz o print do contador (valor armazenado em i)
    2° printf: mostra índice do vetor (posição i) e o valor armazenado nessa posição do vetor com 1 casa decimal
    3° printf: mostra o valor armazenado do endereço armazenado em f (endereço da 1° posição do vetor) + i saltos na memória com 1 casa decimal 
    4° printf: imprime o endereço do vetor na posição i
    5° printf: imprime o endereço armazenado em f + i saltos na memória (é o mesmo que o do vetor) 
*/

#include <stdio.h>

int main(void){
    float vet[5] = {1.1,2.2,3.3,4.4,5.5}; // declaração de um vetor
    float *f; // ponteiro para float
    int i;
    f = vet; // pega o valor do endereço [0] do vetor
    
    printf( "contador/valor/valor/endereco/endereco \n");
    
    for(i = 0 ; i <= 4 ; i++){
     // faz o print do contador
     printf("i = %d",i); 
     // mostra o vetor na posição i e o valor armazenado nele com 1 casa decimal
     printf(" vet[%d] = %.1f",i, vet[i]); 
     // mostra o valor armazenado no endereço de f + i saltos na memória com 1 casa decimal 
     printf(" *(f + %d) = %.1f",i, *(f+i)); 
     // imprimir o endereço do vetor na posição i
     printf(" &vet[%d] = %X",i, &vet[i]);
     // imprimir o endereço de f + i saltos na memória (é o mesmo que o do vetor) 
     printf(" (f + %d) = %X",i, f+i);
     
     printf("\n");
    }
}
