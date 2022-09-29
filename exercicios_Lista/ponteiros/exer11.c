/*Crie um programa que contenha um array contendo 5 elementos inteiros. Leia esse array
do teclado e imprima o enderec¸o das posic¸oes contendo valores pares*/
#include<stdio.h>
#include<stdlib.h>

int main(){
    void *p = malloc(sizeof(int)*5);
    void *aux = malloc(sizeof(int));
    
    *(int*)aux = 0;
    
    do{
        printf("Digite o valor: ");
        scanf("%d", (int*)p);
    
        p = p + 4;

        *(int*)aux = *(int*)aux +1;
    }while(*(int*)aux < 5);

    p = p - 20;//4*5

    for(*(int*)aux = 0; *(int*)aux <5 ; *(int*)aux = *(int*)aux +1){
        if(*(int*)p % 2 == 0){
            printf("endereco na memoria> %d\n", (int*)p);
            printf("Endereco no vetor> %d\n", *(int*)aux);
        }
        p = p + 4;
    }

    free(aux);
    free(p);
}