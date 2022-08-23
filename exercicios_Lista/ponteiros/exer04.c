/*Faca um programa que leia 2 valores inteiros e chame uma func¸ao que receba estas ˜
2 variaveis e troque o seu conteudo, ou seja, esta funcao e chamada passando duas ´
variaveis A e B por exemplo e, ap os a execucao da funcao, A contera o valor de B e B ´
tera o valor de A*/

#include<stdio.h>

void TrocaValores(var01, var02);

int main(){

    int var01, var02;

    printf("Digite o valor da var01: ");
    scanf("%d", &var01);
    printf("Digite o valor da var02: ");
    scanf("%d", &var02);

    TrocaValores(var01, var02);

    return 0;
}
void TrocaValores(var01, var02){
    int aux;
    aux = var01;
    var01 = var02;
    var02 = aux;

    printf("O valor da var01: %d\n", var01);
    printf("O valor da var02: %d", var02);
}