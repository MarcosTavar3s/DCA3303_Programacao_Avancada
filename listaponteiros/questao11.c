 /*
    Resposta: O programa dá erro por dois motivos:
    1° motivo: existe atribuição de valores dentro da struct, na maioria dos compiladores C isso é inadequado e gera erro já que a struct deve ser apenas o molde para a estrutura de dados.
    2° motivo: o ponteiro para struct *s não aponta para nenhum endereço, então seria como se ele tivesse tentando acessar um espaço da memória onde o próprio molde (struct) está definido,
    isso não funciona e, se caso venha a funcionar, não irá retornar o esperado pelo programador.
    O código corrigido encontra-se abaixo.
 */
 
 #include <stdio.h>
 #include <string.h>
 
 struct teste{
    int x;
    char nome[50];
 };
 
 int main(void){
    struct teste *s, jose;
    
    s = &jose; // s armazena o endereço de memoria de jose
    
    s->x = 3; // altera o atributo x de jose via ponteiro
    strcpy(s->nome, "jose"); // altera o atributo nome de jose via ponteiro (copia da string jose para a struct)
    
    printf("%d\n", s->x);
    printf("%s\n", s->nome);
}
