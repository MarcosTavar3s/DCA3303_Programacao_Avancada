#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    int n = 10;
    int *vet = malloc(n * sizeof(int));
    
    printf("Vetor: ");
    for (int i = 0; i < n; ++i) {
        vet[i] = rand() % 100;
        printf("%d ", vet[i]);
    }

    ordenacao(vet, n, comparacao);
    printf("\n");
    printf("Vetor ordenado: ");
    for (int i = 0; i < n; ++i) {
        printf("%d ", vet[i]);
    }

    free(vet);

    return 0;
}
