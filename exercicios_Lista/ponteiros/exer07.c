/*Crie um programa que contenha uma funcao que permita passar por parametro dois numeros inteiros A e B. A funcao devera calcular a soma entre estes dois numeros e armazenar o resultado na variavel A. Esta funcao nao devera possuir retorno, mas devera modificar o valor do primeiro parametro. Imprima os valores de A e B na funcao principal*/

#include<stdio.h>
#include<stdlib.h>

int* CalculateTheSum (int *p);

int main(){
    int *p;
    p = (int*)malloc(sizeof(int)*2);

    printf("Digite o valor da var01> ");
    scanf("%d", &(*p));//var01
    printf("Digite o valor da var02> ");
    scanf("%d", &(*(p+2)));//var02

    printf("A soma dos dois nuemros eh %d", CalculateTheSum(p));

    free(p);

    return 0;
}

int* CalculateTheSum (int *p){
    return (*p += *(p+2));
}