/*Elaborar um programa que leia dois valores inteiros (A e B). Em seguida faca uma funcao que retorne a soma do dobro dos dois numeros lidos. A funcao devera armazenar o dobro de A na propria variavel A e o dobro de B na propria variavel B. - USAR ARITMETICA DE PONTEIRO*/

#include<stdio.h>
#include<stdlib.h>

int* DoubleSum(int *p);

int main(){
    int *p;
    p = (int *)malloc(sizeof(int)*2);//alocado espaço para dois inteiros dentro do ponteiro

    printf("Digite o valor da var01: ");
    scanf("%d", &(*p));
    printf("Digite o valor da var02: ");
    scanf("%d", &(*(p+2)));
    p-2;//volta para a var01;


    printf("var01> %d\n", *p);
    printf("var02> %d\n", *(p+2));

    p = DoubleSum(p);

    //soma do dobro das variaveis var01 e var02
    *p = *p + *(p+2);

    printf("A soma do dobro eh %d ", *p);

    free(p);
    return 0;
}

int* DoubleSum(int *p){
    *p = *p *2; // va01 = var01 * 2
    *(p+2) = *(p+2) *2;//var02 = var02 * 2
    return p;
}

