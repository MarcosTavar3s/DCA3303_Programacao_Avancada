#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void compara(float *vet, int n){
    float aux;
    
    for(int i=0; i<n; i+=1){
        
        if(i>0 && vet[i]<vet[i-1]){
            for(int j=i-1; j>=0; j-=1){
                if(vet[i] < vet[j]){
                    aux = vet[i];
                    vet[i] = vet[j];
                    vet[j] = aux;
                }
                else{
                    break;
                }
            } 
        }
    }
    
}

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
