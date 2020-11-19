#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "agenda.h"

int main()
{
    void *pBuffer;
    pBuffer = malloc((sizeof(int)*5) + (sizeof(char)*10));
    //Os espaços alocados correspondem a:
    //1º(0) num de elementos, 2º(1) controle repetição 1, 3º(2) controle repetição 2
    //4º(3) escolha, 5º(4) numero temporário, 6º(5) nome temporário
    
    *(int *)pBuffer = 0;

    do
    {
        printf("----Agenda----\n");
        printf("1.Inserir\n");
        printf("2.Buscar\n");
        printf("3.Listar\n");
        printf("4.Apagar\n");
        printf("5.sair\n Escolha: ");
        scanf("%d", (int *)(pBuffer + (3*sizeof(int))));

        switch (*(int *)(pBuffer + (3*sizeof(int))))
        {
        case 1:
            pBuffer = inserir(pBuffer);
            break;
        case 2:
            buscar(pBuffer);
            break;
        case 3:
            listar(pBuffer);
            break;
        case 4:
           pBuffer = apagar(pBuffer);
           break;
        default:
            break;
        }
        
    } while (*(int*)(pBuffer + (3 * sizeof(int)))!=5);

    free(pBuffer);
    
    return 0;
}

void *inserir(void *pBuffer)
{
  pBuffer = realloc(pBuffer, (5 * sizeof(int)) + (10 * (sizeof(char))) + (((10 * sizeof(char)) + sizeof(int)) * ((*(int *)pBuffer) + 1)));
  
  printf("Informe o nome: ");
  scanf("%s", (char *)(pBuffer + ((5 * sizeof(int)) + (10 * (sizeof(char))) + ((*(int *)pBuffer) * (10 * sizeof(char) + sizeof(int))))));
  
  *(int *)pBuffer = *(int *)pBuffer + 1;

    return pBuffer;
}

void buscar(void *pBuffer)
{
    printf("Nome: ");
    scanf("%s", (char *)(pBuffer+(4*sizeof(int))));

    for(*(int *)(pBuffer + (sizeof(int))) = 0; *(int *)(pBuffer + (sizeof(int))) < *(int *)pBuffer; *(int *)(pBuffer + (sizeof(int))) = *(int *)(pBuffer + (sizeof(int))) + 1)
    {
        if (strcmp((pBuffer + ((5 * sizeof(int)) + (10 * (sizeof(char))) + (((10 * sizeof(char)) + (sizeof(int))) * *(int *)(pBuffer + (sizeof(int)))))), (char *)(pBuffer + (4 * sizeof(int)))) == 0)
        {
             printf("Nome: %s\n", (char *)(pBuffer + ((5 * sizeof(int)) + (10 * (sizeof(char))) + (((10 * sizeof(char)) + (sizeof(int))) * *(int *)(pBuffer + (sizeof(int)))))));
        }
    }
}

void listar(void *pBuffer)
{

  for (*(int *)(pBuffer + (sizeof(int))) = 0; *(int *)(pBuffer + (sizeof(int))) < *(int *)pBuffer; *(int *)(pBuffer + (sizeof(int))) = *(int *)(pBuffer + (sizeof(int))) + 1)
  {
    printf("Nome: %s\n", (char *)(pBuffer + ((5 * sizeof(int)) + (10 * (sizeof(char))) + (((10 * sizeof(char)) + (sizeof(int))) * *(int *)(pBuffer + (sizeof(int)))))));
  }

}

void *apagar(void  *pBuffer)
{
  printf("Informe o nome que deseja apagar: ");
  scanf("%s", (char *)(pBuffer + (4 * sizeof(int))));

  for (*(int *)(pBuffer + (sizeof(int))) = 0; strcmp((pBuffer + ((5 * sizeof(int)) + (10 * (sizeof(char))) + (((10 * sizeof(char)) + (sizeof(int))) * *(int *)(pBuffer + (sizeof(int)))))), (char *)(pBuffer + (4 * sizeof(int)))) != 0; *(int *)(pBuffer + (sizeof(int))) = *(int *)(pBuffer + (sizeof(int))) + 1)
  {  }

  for (*(int *)(pBuffer + (sizeof(int))) = *(int *)(pBuffer + (sizeof(int))); *(int *)(pBuffer + (sizeof(int))) < *(int *)pBuffer; *(int *)(pBuffer + (sizeof(int))) = *(int *)(pBuffer + (sizeof(int))) + 1)
  {
    strcpy((char *)(pBuffer + ((5 * sizeof(int)) + (10 * (sizeof(char))) + (((10 * sizeof(char)) + (sizeof(int))) * *(int *)(pBuffer + (sizeof(int)))))), (char *)(pBuffer + ((5 * sizeof(int)) + (10 * (sizeof(char))) + (((10 * sizeof(char)) + (sizeof(int))) * (1 + *(int *)(pBuffer + (sizeof(int))))))));
    *(int *)(pBuffer + ((10 * sizeof(char)) + (5 * sizeof(int)) + (10 * (sizeof(char))) + (((10 * sizeof(char)) + (sizeof(int))) * *(int *)(pBuffer + (sizeof(int)))))) = *(int *)(pBuffer + ((10 * sizeof(char)) + (5 * sizeof(int)) + (10 * (sizeof(char))) + (((10 * sizeof(char)) + (sizeof(int))) * (1 + *(int *)(pBuffer + (sizeof(int)))))));
  }
  
  *(int *)pBuffer = *(int *)pBuffer - 1;
  
  pBuffer = realloc(pBuffer, (5 * sizeof(int)) + (10 * (sizeof(char))) + (((10 * sizeof(char)) + (sizeof(int))) * ((*(int *)pBuffer))));

  return pBuffer;
}