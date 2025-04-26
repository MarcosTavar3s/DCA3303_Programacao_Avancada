#include <stdio.h>

// função de decodificação para ver se o programa operou corretamente
void decode(unsigned long estado){
    unsigned char bit;
    
    /*
    63 (64-1) é usado porque o tamanho é 64 bits
    se começar descolocando 64, obviamente que o
    resultado é 0.
    
    >=0 pois se deslocar 0 bits e fazer o & com 1
    o resultado será o bit menos significativo.
    */
    printf("Valor em binario: ");
    for(int i=63; i>=0; --i){
        printf("%ld", (estado >> i) & 1);
    }
    printf("\n");
   
}

int main() {
    unsigned char m[8][8] ={
        {0,1,0,1,0,1,0,1},
        {1,0,1,0,1,0,1,0},
        {0,1,0,1,0,1,0,1},
        {1,0,1,0,1,0,1,0},
        {0,1,0,1,0,1,0,1},
        {1,0,1,0,1,0,1,0},
        {1,0,1,0,1,0,1,0},
        {1,0,1,0,1,0,1,0}
    };
    
    // definicao da variavel de 64 bits
    unsigned long valor=0;
    
    // aninhamento de fors para percorrer toda a matriz
    for(int i=0; i<8; ++i){
        for(int j=0; j<8; ++j){
            /*
                desloca para esquerda e faz OR com o
                char atual convertido para inteiro.
            */
            valor = (valor << 1) | ((int)m[i][j]);
        }
    }
    
    printf("Valor em long: %ld\n",valor);

    //send(unsigned long estado);
    decode(valor); // implementada para ver se a minha resposta está certa
    
    return 0;
}
