/*
    Resposta: O while vai ter 4 ciclos porque a = 10 e seu decremento ocorre
    com a >> 2 (equivalente a dividir por 2). Analisando cada ciclo do loop:
   
    Antes do while:
    x = 10
    y = 1
    z = 11
    a = 10
    b = 1
    
    1° ciclo:
    x = 10 | 1 = 1010 | 0001 = 1011 (11) - or
    y = 1 ^ 10 = 0001 ^ 1010 = 1011 (11) - xor
    z = 11 & (10+1)  = 1010 & 1011 = 1011 (11) - and
    a = a >> 1 = 1010 >> 1 = 0101 (5)
    b = b << 1 = 0001 << 1 = 0010 (2)
    
    2° ciclo:
    x = 11 | 2 = 1011 | 0010 = 1011 (11) - or
    y = 11 ^ 5 = 1011 ^ 0101 = 1110 (14) - xor
    z = 11 & (5+2) = 1011 & 0111 = 0011 (3) - and
    a = a >> 1 = 0101 >> 1 = 0010 (2)
    b = b << 1 = 0010 << 1 = 0100 (4)
    
    3° ciclo:
    x = 11 | 4 = 1011 | 0100 = 1111 (15) - or
    y = 14 ^ 2 = 1110 & 0010 = 1100 (12) - xor
    z = 3 & (4+6) = 0011 & 1010 = 0010 (2) - and
    a = a >> 1 = 0010 >> 1 = 0001 (1)
    b = b << 1 = 0100 << 1 = 1000 (8)
    
    4° ciclo:
    x = 15 | 8 = 1111 | 1000 = 1111 (15) - or
    y = 12 ^ 1 = 1100 ^ 0001 = 1101 (13) - xor
    z = 2 & (8+1) = 0010 & 1001 = 0000 (0) - and
    a = a >> 1 = 0001 >> 1 = 0000 (0)
    b = b << 1 =  1000 << 1 = 10000 (16)
    
    Fim do while e print das variáveis x,y,z com os valores:
    x = 15
    y = 13
    z = 0 

*/

#include <stdio.h>

int main(){
    int a, b;
    int x, y, z;
    
    scanf( "%d %d", &a, &b);
    
    // x = 10, y = 1, z = 11
    x = a; y = b; z = a + b;
    
    // Enquanto a != 0
    while (a) {
        // or bit-a-bit
        x = x | b;
        printf("x: %.2d\n", x);
        
        // xor bit-a-bit
        y = y ^ a;
        printf("y: %.2d\n", y);
        
        // and bit-a-bit
        z = z & (a+b);
        printf("z: %.2d\n", z);
        
        // a dividido por dois (até chegar a zero vai passar 5 ciclos)
        a = a >> 1;
        printf("a: %.2d\n",a);
        
        // b multiplicado por dois
        b = b << 1;
         printf("b: %.2d\n",b);

    }
    printf("\n");
    printf ("%d %d %d\n", x, y, z);
 
 return 0;
 }
