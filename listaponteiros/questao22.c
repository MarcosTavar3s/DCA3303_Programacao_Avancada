/*
  Resposta: Para vetores pequenos, a diferença entre a minha função e o qsort é relativamente pequena, porém a diferença de eficiência
  realmente começa a ocorrer para "n" grandes. Para comprovar tal afirmação, testei com 10 elementos (com o mesmo resultado em ambas
  funções) e com 1000 (o que demonstrou que a minha função corresponde a execução de 3 qsort para 1 ordenamento). Vale ressaltar ainda
  que esse comportamento acontece em virtude da implementação mais otimizada de ordenação do quick sort.
  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Função de ordenação tipo qsort, mas para int
void ordenacao(int *vet, int num, int (*compare)(const void *, const void *)) {
   
   /* O aninhamento dos fors irá rodar (num-1)*(num-1) vezes, isso vai garantir que
   o vetor seja mapeado completamente.
   */
   for (int i = 0; i < num - 1; i++) {
        for (int j = i + 1; j < num; j++) {
            // identifica que o vetor é maior que o outro e troca :)
            if (compare(&vet[i], &vet[j])>0) {
                int temp = vet[i];
                vet[i] = vet[j];
                vet[j] = temp;
            }
        }
    }
}

// recebe os endereços dos ponteiros
int comparacao(const void *a, const void *b) {
      return (*(int*)a - *(int*)b);
}


int main() {
    clock_t t; // fazer o benchmarking
    int n = 1000;
    int *vet = malloc(n*sizeof(int));
    int *copia = malloc(n*sizeof(int));
    
    for (int i = 0; i < n; ++i) {
        vet[i] = rand() % 100;
    }
    
    // fazendo copia para comparar com o qsort
    memcpy(copia, vet, n*sizeof(int));
    
    printf("Calculando o tempo (benchmarking).....\n");
    
    t = clock();
    ordenacao(vet, n, comparacao);
    t = clock() - t;
    printf("Clicks da minha funcao: %d\n", (int)t);

   
    t = clock();
    qsort(copia, n, sizeof(int), comparacao);
    t = clock() - t;
    printf("Clicks do qsort: %d\n", (int)t);

    free(vet);
    free(copia);

    return 0;
}
