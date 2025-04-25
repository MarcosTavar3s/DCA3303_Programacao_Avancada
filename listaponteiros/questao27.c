/*
    Resposta:
    I - Correta, o resultado da impressão é 7 - 7, isso ocorre porque as
    funções mapeiam para achar o índice do valor que é 15, ou seja, 7 e 7.
    
    II - Falso, a implementação da função 2 é feita de forma que vai 
    indo em metade do vetor e comparando para ver os valores, fazendo que
    seja percorrido de metade a metade (de forma mais rápida). No pior dos
    casos, a função 2 percorrerá aproximadamente metade do vetor. Já no pior
    dos casos, a funcao1 irá percorrer todos os valores da array.
    
    III - Falso, a funcao2 não utiliza iteratividade e sim recursividade.
    
    Portanto, letra A é a correta (I apenas).
*/

#include <stdio.h>
#define TAM 10
int funcao1(int vetor[], int v){
    int i;
    for (i = 0; i < TAM; i++){
    if (vetor[i] == v)
        return i;
    }
    return -1;
 }
int funcao2(int vetor[], int v, int i, int f){
    int m = (i + f) / 2;
    if (v == vetor[m])
      return m;
    if (i >= f)
      return -1;
    if (v > vetor[m])
      return funcao2(vetor, v, m+1, f);
    else
      return funcao2(vetor, v, i, m-1);
 }
 int main(){
    int vetor[TAM] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    printf("%d - %d", funcao1(vetor, 15), funcao2(vetor, 15, 0, TAM-1));
    return 0;
}
