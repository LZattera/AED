/*Crie um programa que contenha um array de float contendo 10 elementos. Imprima o
endereco de cada posicao desse array*/
//POR QUE APARECE UM 0.00 NO INICIO DA LISTAGEM DOS NUMEROS???

#include<stdio.h>
#include<stdlib.h>
int main(){
    float *p;
    p = (float*)malloc(sizeof(float)*10);//um array de float com 10 posições, O tamanho do float eh 4

    for(int i=0; i<10; i++){
        printf("Digite um valor: ");
        scanf("%f", &(*p));
        p = p+4;
    }
    printf("Numeros inseridos\n");
    for(int i=0; i<=10; i++){
        printf("%.2f\n", *p);
        p=p-4;
    }

    free(p);
    return 0; 
}