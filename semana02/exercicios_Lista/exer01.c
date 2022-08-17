/*Fac¸a um programa que entao leia uma string e a imprima.*/
#include<stdio.h>
int main(){
    char nome[10];
    printf("Digite seu nome: ");
    scanf("%s", &nome);

    printf("%s", nome);
    return 0;
}