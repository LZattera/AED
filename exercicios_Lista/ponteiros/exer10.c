/*Crie um programa que contenha um array de inteiros contendo 5 elementos. Utilizando apenas aritmetica de ponteiros, leia esse array do teclado e imprima o dobro de cada valor lido*/

#include<stdio.h>
#include<stdlib.h>

int main(){
    void *p = malloc(sizeof(sizeof(int)*5));// array de int com 5 elementos
    void *aux = malloc(sizeof(int));

    for(*(int*)aux = 0; *(int*)aux < 5; *(int*)aux = *(int*)aux +1){
        printf("Digite os valores do vetor: ");
        scanf("%d", (int*)p);

        p += 4;//vai pro proximo lugar do vetor
    }
    
    p -= 20;//sizeof(int)(que no caso eh 4) * 5 (num de elemntos do vetor)
    printf("\n");

    printf("Ordem inserida\n");
    for(*(int*)aux = 0; *(int*)aux < 5; *(int*)aux = *(int*)aux +1){
        printf("%d\n", *(int*)p);
        p += 4;//vai pro proximo lugar do vetor
    }

    p -= 4;//volta a ultima casa que foi andada no loop anterior
    printf("Ordem reversa\n");
    for(*(int*)aux = 0; *(int*)aux < 5; *(int*)aux = *(int*)aux +1){
        printf("%d\n", *(int*)p);
        p -= 4;//vai pro proximo lugar do vetor
    }

    free(aux);
    free(p);

    return 0;
}