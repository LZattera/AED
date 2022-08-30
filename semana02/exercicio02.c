/*Programa que armazena todos os nomes na MESMA string
O tamanho da string tem de aumentar diminuir de acordo com a inserção e remoção dos nomes*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){

    char stringAux[20];
    char *listaStrings;
    int op;

    listaStrings = (char*)malloc(sizeof(char));//primeirra alocação do ponteiro para poder usar o relloc
    do{
        printf("Digite seu  nome: ");
        scanf("%s", &stringAux);

        stringAux[strlen(stringAux)+1] = '>';

        listaStrings = realloc(listaStrings, (sizeof(char)*strlen(stringAux)));//Alocando espaço para a string inserida

        printf("Deseja continuar [0-SIM / 1-NAO]:   ");
        scanf("%d", &op);

    }while(op == 0);
    
    //IMPRIMINDO STRING
    printf("%c", *listaStrings);
    

    return 0;
}