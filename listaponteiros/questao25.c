/*
  Resposta: O vazamento de memória ocorre no item C, pois caso o size da string recebida for maior que 50, não ocorrerá o free de s, de forma
  a impossibilitar que o endereço de s seja acessado. 
*/

//(C)
 int f(char *data){
   void *s;
   s = malloc(50);
   int size = strlen(data);
   if (size > 50)
     return(-1);
   free(s);
   return 0;
 }
