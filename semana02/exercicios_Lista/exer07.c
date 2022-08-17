/*Crie um programa que compara duas strings (nao use a função strcmp)*/
#include<stdio.h>
#include<string.h>

int main(){
    char name1[10], name2[10];    

    printf("Nome 1: ");
    scanf("%s", name1);
    printf("Nome 2: ");
    scanf("%s", name2);

    if(strcmp(name1, name2) == 0){
        printf("As strings sao IGUAIS");
    }else{
        printf("As strings sao DIFERENTES");
    }
}