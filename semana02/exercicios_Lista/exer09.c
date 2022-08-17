/*Escreva um programa que substitui as ocorrencias de um caractere ‘0’ em uma string por outro caractere ‘1’.*/
#include<stdio.h>
#include<string.h>

int main(){
    char stringCaracteres[20];

    printf("Digite a string: ");
    scanf("%s", stringCaracteres);

    for(int i=0; i< strlen(stringCaracteres); i++){
        if(stringCaracteres[i] == '0')
            stringCaracteres[i]='1';
    }

    printf("%s", stringCaracteres);

    return 0;
}