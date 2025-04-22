// A resposta da questão é o próprio código :)
#include <stdio.h>
#include <stdlib.h>

int *soma_vetores(int *vet1, int *vet2, int *resultado, int n){
    resultado = malloc(n*sizeof(int));
    
    for(int i=0; i < n; i++){
        resultado[i] = vet1[i] + vet2[i];
    }
    
    free(vet1);
    free(vet2);
    
    return resultado;
}

int main()
{   
    int n = 4, *vet1, *vet2, *soma;
    vet1 = malloc(n*sizeof(int));
    vet2 = malloc(n*sizeof(int));
    
    for(int i=0; i < n; i++){
        vet1[i] = rand()%100;
        vet2[i] = rand()%100;
    }    
    
    for(int i=0; i < n; i++){
        printf("Vet1[%d] = %d\n", i,vet1[i]);
        printf("Vet2[%d] = %d\n", i,vet2[i]);
    }
    
    soma = soma_vetores(vet1, vet2, soma, n);
    
    printf("Resultado da soma:\n");
    for(int i=0; i < n; i++){
        printf("%d ", soma[i]);
    }
    
    free(soma);
    
    return 0;
}
