/*
    Resposta:
    1° programa: O primeiro programa mostrará os valores armazenados dentro do vetor vet em ordem dos índices crescente, o retorno então será, respectivamente: 4 9 13.
    2° programa: O segundo programa irá mostrar os endereços de memória associados ao vetor, começando da memória mais baixa (da posição 0) até a mais alta (posição 2 que corresponde a posição da memória 0 + 8 bytes em virtude do dado ser inteiro).
*/
#include <stdio.h>

int main(){
    int vet[] = {4, 9, 13};
    int i;
    
    for(i=0;i<3;i++){
        printf("%d ", *(vet+i));
    }
    
    for(i=0;i<3;i++){
        printf( "%X ",vet+i);
    }
}
