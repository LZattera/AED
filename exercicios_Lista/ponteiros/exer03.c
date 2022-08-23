/*Escreva um programa que contenha duas variaveis inteiras. Leia essas variaveis do teclado. Em seguida, compare seus enderecos e exiba o conteudo do maior endereco.*/

#include<stdio.h>

int main(){
    int var01, var02;

    printf("Digite o valor da var01: ");
    scanf("%d", &var01);
    printf("Digite o valor da var02: ");
    scanf("%d", &var02);

    (var01<var02)?printf("O endereco da var01 eh %d", &var01):
                  printf("O endereco da var02 eh %d", &var02);

    return 0;
}