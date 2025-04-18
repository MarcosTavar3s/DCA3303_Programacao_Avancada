 /*
    Resposta: memory leak, ou vazamento de memória, é um erro que ocorre quando, após alocar uma variável dinamicamente,
    não há a liberação correta do espaço alocado de modo a gerar um espaço na memória que não pode ser mais acessado.
    Em termos simples, o programador compromete memória que poderia estar sendo usada, não podendo mais acessar tal espaço.
    A função de exemplo que será utilizada aumenta e preenche um vetor. Na implementação da função foi pressuposto que ela sempre
    receberá um vetor menor para transformar em um maior (não foi tratada as exceções, pois o objetivo é somente demonstrar o erro
    de vazamento de memória).
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* o_size == tamanho antigo
   n_size == tamanho novo
   *x == ponteiro que deseja aumentar o tamanho 
*/
int* exemplo(int *x, int n_size, int o_size){
    int *r = malloc(n_size*sizeof(int));
    
    memcpy(r, x, o_size * sizeof(int));
    
    // preenchendo o vetor com números pseudoaleatórios de 0 a 9
    for(int i=o_size; i<n_size; i++){
        r[i] = rand()%10;
    }
    
    // caso a linha abaixo seja comentada, haverá um erro de memory leak, pois o endereço previamente armazenado em x será perdido e ficará inacessável
    free(x);
    return r;
}

int main(){
    int *x, n;
    n = 10;
    x =  malloc(10*sizeof(int));
    
    // preenchendo o vetor com números pseudoaleatórios de 0 a 9
    for(int i=0; i<n; i++){
        x[i] = rand()%10;
    }
    
    // mostrando o x
    for(int i=0; i<n; i++){
        printf("%.2d ",x[i]);
    }

    // função para aumentar tamanho e preencher o espaço
    x = exemplo(x, 50, 10);
    
    printf("\n");
    // mostrando o x após o aumento da memória
    for(int i=0; i<50; i++){
        printf("%.2d ", x[i]);
    }
    
    free(x);
    
    return 0;
}
