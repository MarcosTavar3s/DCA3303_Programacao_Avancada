/*
    Resposta: o programa retorna 22, pois a função f faz o seguinte:
    **ppc += 1: incrementa o valor armazenado dentro do ponteiro para ponteiro para int em uma unidade, o valor que antes era 5, agora é 6.
    *pb += 2: incrementa o valor armazenado dentro do ponteiro para int em duas unidades, o valor então passa de é 6 para 8.
    a += 3: pega o valor copiado de c e soma com 3, resultando em 8.
    Ao somarmos todos esses números (como foi feito no return da função f), temos o retorno do número 22 que é mostrado na saída.
*/

#include <stdio.h>
 
 int f(int a, int *pb, int **ppc) {
    int b, c;
    **ppc += 1; // pega o valor armazenado no ponteiro para ponteiro ppc e incrementa em uma unidade
    c = **ppc; // c = 6
     
    *pb += 2; // aponta para o endereço armazenado em pb, pega o seu valor e incrementa em duas unidades (o valor era 5 mas já sofreu um incremento de uma unidade em **ppc+=1, então *pb=8)
    b = *pb; // b = 8
    
    a += 3; // a = 5+3 = 8
    
    return a + b + c; // 6+8+8 = 22
}
 void main() {
    int c, *b, **a;
    c = 5;
    b = &c; // b aponta para c
    a = &b; // a aponta para b
    printf("%d\n", f(c, b, a));
    getchar();
 }
