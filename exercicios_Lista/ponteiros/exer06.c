/*Elaborar um programa que leia dois valores inteiros (A e B). Em seguida faca uma funcao˜
que retorne a soma do dobro dos dois numeros lidos. A funcao devera armazenar o dobro 
de A na propria variavel A e o dobro de B na propria variavel B.*/

#include<stdio.h>
#include<stdlib.h>

int* SomaDoDobro(int *p);

int main(){
    int *p;
    p = (int*)malloc(sizeof(int)*2);//duas variveis inteiras, var01, var02;

    printf("Digite o valor da var01: ");
    scanf("%d", &p);//armazena na var01
    printf("Digite o valor da var02: ");
    scanf("%d", &(p+2));//anda para a segunda posição do ponteiro var02
    (p-2);//retorna para o inicio do ponteiro

    p = SomaDoDobro(p);

    printf("A soma do dobro da var01: %d", *p);
    printf("A soma do dobro da var02: %d", *(p+2));
    return 0;
}

int* SomaDoDobro(int *p){
    p += (*p) *2; 
    (p+2);//anda no ponteiro para variavel var02
    p += (*p)*2;

    (p-2);//retorna para o inicio do ponteiro var01

    return p;
}