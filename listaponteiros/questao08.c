/*
    Resposta: a opção correta é *(pulo + 2), o que acontece é que o programa pula dois unidades de tamanho
    em relação ao endereço de memória 0 do vetor (como é int, é 8 bytes = 2 int* 4 byte/int) e depois extrai
    seu valor.
*/
#include <stdio.h>

int main() {
    int pulo[4] = {0,1,2,3};
    printf("%d", *(pulo+2));

    return 0;
}
