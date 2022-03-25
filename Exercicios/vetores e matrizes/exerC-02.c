/*Crie um programa que le 6 valores inteiros e, em seguida, mostre na tela os valores lidos*/
#include<stdio.h>
int main(int argc, char const *argv[])
{
    int vetor[5];

    /*Lendo valores*/
    printf("Digite seis valores para o vetor.\n");
    for(int i=0; i<=5; i++)
        scanf("%d", &vetor[i]);    

    /*Imprimindo valores*/
    printf("Os numeros inseridos foram:\n");
    for (int i = 0; i <= 5; i++)
        printf("%d\n", vetor[i]);
    
    return 0;
}
