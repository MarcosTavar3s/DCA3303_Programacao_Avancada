/*
    Respostas: Estão comentadas ao longo do código :)
*/

#include <stdio.h>

char *a[] = {"AGOSTINHO", "MEDEIROS", "BRITO", "JUNIOR"};
/*
    Descrevendo ** b[]
    Primeiro elemento: endereço de "JUNIOR"
    Segundo elemento: endereço de "BRITO"
    Terceiro elemento: endereço de "MEDEIROS"
    Quarto elemento: endereço de "AGOSTINHO"
*/
char **b[] = {a + 3, a + 2, a + 1, a}; 

char ***c = b; // Armazena o endereço do ponteiro para ponteiro de b[0] = a+3

int main() {
  /*
  {
  *c == endereço de B
  **c == *(*b) == valor armazenado no local 0 de b = (a+3)
  **++c == c[1] == b[1] == a + 2 == BRITO
  c passa a apontar para b[1] == a+2
  }
  
  {
  *--*++c == c[1][-1] == (b[1+1])-1 == (a+1)-1 == a == AGOSTINHO
  *--*++c + 3 == a[0] + 3 == começar strings depois do indice 3 == STINHO
  c passa a apontar para b[2]
  }
  
  {
  *c == valor do endereço de b[2] 
  *c[-2] == *b[2-2] == *b[0] == *(a+3) == JUNIOR
  *c[-2] + 3 == *(a+3) + 3 = começar string depois do indice 3 == IOR
  }
  
  {
  c == valor do endereço de b[2]
  c[-1][-1] == *((b[2-1])-1) == *((a+2)-1) == *(a+1) == MEDEIROS
  c[-1][-1] + 1 == *((a+2)-1) + 1 == começar string depois do indice 1 == EDEIROS
  }
 

  */
  printf("%s ", **++c);
  printf("%s ", *--*++c + 3);
  printf("%s ", *c[-2] + 3);
  printf("%s ", c[-1][-1] + 1);
  
  return 0;
 }
