/*Faca um programa que leia dois valores inteiros e chame uma func¸ao que receba estes ˜
2 valores de entrada e retorne o maior valor na primeira variavel e o menor valor na 
segunda variavel. Escreva o conteudo das 2 variaveis na tela*/

#include<stdio.h>
#include<stdlib.h>

int* MaiorValor(var01, var02);

int main(){

    int var01, var02;
    int *pont;

    printf("Digite o valor da var01: ");
    scanf("%d", &var01);
    printf("Digite o valor da var02: ");
    scanf("%d", &var02);

    pont = MaiorValor(var01, var02);

    printf("O maior foi %d\n", *pont);
    printf("O menor foi %d", *(pont+2));

    free(pont);
    
    return 0;
}

int* MaiorValor(var01, var02){
    int *p;
    p = (int*)malloc(sizeof(int)*2);

    if(var01 > var02){ 
        *p = var01;
        *(p+2) = var02;//anvançando para o segundo espaço reservado para int
    }else{
        *p = var02;
        *(p+2) = var01;
    }
    (p-2);//voltando pro inicio do ponteiro

    return p;
}