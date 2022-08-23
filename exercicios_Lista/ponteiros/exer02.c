/*Escreva um programa que contenha duas variaveis inteiras. Compare seus enderecos e exiba o maior endereco*/

#include<stdio.h>

int main(){

    int var01, var02;

    (var01<var02)?printf("O endereco da var01 eh %d", &var01):
                  printf("O endereco da var02 eh %d", &var02);   

    return 0;
}