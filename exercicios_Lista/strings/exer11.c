/*Faça um programa que receba do usuario uma string. O programa imprime a string sem
suas vogais*/

#include<stdio.h>
#include<string.h>

int main(){
    char stringSemVogais[20];
    int i;
printf("Digite a string    scanf("%s", stringSemVogais);

    for(i=0; i<strlen(stringSemVogais);i++){
        if(stringSemVogais[i] == 'a' || stringSemVogais[i] == 'e'||stringSemVogais[i] == 'i'||stringSemVogais[i] == 'o'|| == 'u'){
               printf("%s"