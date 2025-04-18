#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    int n;
    float *vet;
    
    printf("Digite a quantidade de floats que você deseja inserir:\n");
    scanf("%d", &n);
    
    // Alocação da memória
    vet = malloc(n*sizeof(float));
    
    for(int i=0; i<n; i+=1){
        scanf("%f", &vet[i]);
    }
    
    
    for(int i=0; i<n; i+=1){
        printf("%f ", vet[i]);
    }
    
    return 0;
}
