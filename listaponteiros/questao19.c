#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void compara(float *vet, int n){
    float aux;
    
    for(int i=0; i<n; i++){
        // compara com o proximo, se for maior, proximo fica com o valor do atual
        if(vet[i]>vet[i+1] && i<n-1){
            aux = vet[i];
            vet[i] = vet[i+1];
            vet[i+1] = aux;
        }
        
        // compara com os anteriores, se for menor, anterior fica com o valor do atual
        if(i!=0 && vet[i]<vet[i-1]){
            for(int j=i; j>0; j--){
                if(vet[j]<vet[j-1]){
                    aux = vet[j];
                    vet[j] = vet[j-1];
                    vet[j-1] = aux;
                }
                else break;
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
    
    compara(vet, n);

    for(int i=0; i<n; i+=1){
        printf("%f ", vet[i]);
    }
    
    free(vet);
    
    return 0;
}
