 /*
  Resposta: O programa não tem a resposta esperada porque a função implementada faz que haja a
  navegação entre espaços da memória, isso significa que a implementação de str++ faz que ocorra
  um salto de 8 bytes (tamanho do ponteiro) na memória. Em razão disso, o conteúdo string não é alterada.
 */
 
 #include <string.h>
 #include <stdio.h>
 #include <stdlib.h>
 
 // ponteiro que aponta para outro ponteiro que aponta para um char
 void funcao(char** str){
    printf("%p\n", str);
    str++; // pula um byte na memória
    printf("%p\n", str++);
}
 
 int main(){
    char *str = (void *)malloc(50*sizeof(char)); // aloca na memória uma string de 50 caracteres
    strcpy(str, "Agostinho"); // copia o nome Agostinho para a string
    funcao(&str); // passa o endereço do ponteiro
    puts(str); // mostrar a string
    free(str); // liberar o espaço alocado
    return 0;
 }
