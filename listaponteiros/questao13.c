/*
    Resposta:
    Considerando que x esteja armazenado no endereço 4092
    Para o tipo char, considerando que ele tem 1 byte:
        x+1 = 4093
        x+2 = 4094
        x+3 = 4095
    Para o tipo int, considerando que ele tem 2 bytes:
        x+1 = 4094
        x+2 = 4096
        x+3 = 4098
    Para o tipo float, considerando que ele tem 4 bytes:
        x+1 = 4096
        x+2 = 4100
        x+3 = 4104
    Para o tipo double, considerando que ele tem 8 bytes:
        x+1 = 4100
        x+2 = 4108
        x+3 = 4116
*/
#include <stdio.h>
 
int main(void){
    char ca = 4, *a = &ca;
    short int ib = 4, *b = &ib;
    float fc = 4, *c = &fc;
    double dd = 4, *d = &dd ;
    
    printf("Char (1 byte): %p %p %p\n", a+1, a+2, a+3);
    printf("Int (2 bytes): %p %p %p\n", b+1, b+2, b+3);
    printf("Float (4 bytes): %p %p %p\n", c+1, c+2, c+3);
    printf("Double (8 bytes): %p %p %p\n", d+1, d+2, d+3);

 }
