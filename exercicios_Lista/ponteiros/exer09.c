/*Crie um programa que contenha uma matriz de float contendo 3 linhas e 3 colunas.
Imprima o endereco de cada posicao dessa matriz*/

#include<stdio.h>
#include<stdlib.h>

int main(){

    void *p;//ponteiro void
    p = malloc(sizeof(float)*9);//alocando dinamicamente uma matriz de ponteiro

    for(int i = 0; i< 9; i++){
        printf("Digite um numero: ");
        scanf("%f", (float*)&(*p));
        p = p + sizeof(float);
    }
    p = p - (sizeof(float)*9);//volta para o inicio do ponteiro
    //IMPRIMIR ELEMENTOS
    for(int i = 0;i<9;i++){
        printf("%.2f", (float*)*(p));

    }

    free(p);
    return 0;
}