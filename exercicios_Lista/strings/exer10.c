/*Faça um programa que receba uma palavra e a imprima de tras-para-frente*/
#include<stdio.h>
#include<string.h>

int main(){
    char stringImprimir[20];

    printf("Digite a string: ");
    scanf("%s", stringImprimir);

    for(int i = strlen(stringImprimir) ; i>=0; i--){
        printf("%c", stringImprimir[i]);
    }
}