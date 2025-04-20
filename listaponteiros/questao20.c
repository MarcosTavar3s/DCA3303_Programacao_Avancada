#include <stdio.h>  
#include <stdlib.h>

int compare(const void* a, const void* b) {
  /*
  Como quero comparar floats, não é possível usar a abordagem
  direta da subtração, porque a função é int e no retorno fará
  o casting da diferença dos float em um int (MUITO PROBLEMÁTICO).
  
  Nesse sentido, essa função compare explora a implementação do
  qsort que troca o elemento atual com o próximo se o retorno for 1
  e troca o elemento atual com o anterior se o retorno for -1.
  */
  
  if(*(float*)a > *(float*)b){
      return 1;
  }
  
  if(*(float*)a < *(float*)b){
      return -1;
  }
  return 0;
}

int main() {
  int n;
  float *vet;
  
  // Determinação do tamanho da array
  printf("Digite a quantidade de floats que você deseja inserir:\n");
  scanf("%d", &n);
  
  // Alocação da memória para o vetor
  vet = malloc(n*sizeof(float));
  
  // Preenchimento do vetor
  for(int i=0; i<n; i+=1){
    scanf("%f", &vet[i]);
  }
    
  // Uso da função qsort    
  qsort(vet, n, sizeof(float), compare);
  
  for (int i = 0; i < n; i++) {
    printf("%lf ", vet[i]);
  }
  
  return 0;
}
