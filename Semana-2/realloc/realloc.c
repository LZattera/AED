#include<stdio.h>
#include<stdlib.h>

int main(){
  int *ptr, i;

  ptr= (int *)malloc(2 * sizeof(ptr));
  
  if (!ptr){printf("ERRO, sem espaço de memoria!\n"); exit(1);}

  printf("Digite tres numeros: \n"); 
  for(i=0; i<3; i++)
  {
      scanf("%d", ptr+i);
  } 

//Aumentando um espaço no vetor
  ptr = (int *) realloc(ptr, sizeof(int));

if(!ptr){printf("--ERRO sem espaço na memoria---"); exit(1);}

printf("Digite mais um numero:\n");
scanf("%d", (ptr+3));

//Imprimindo o vetor
printf("Os numeros guardados no vetor sao:\n");
for ( i = 0; i < 4; i++)
{
    printf("%d\n", *ptr);
    ptr++;
}
 
//Liberando a memoria alocada
free(ptr);
}