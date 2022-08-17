/*fac¸a um programa que leia um nome e imprima as 4 primeiras letras do nome*/
#include<stdio.h>

int main(){
    char name[20];
    int i;

    printf("Digite o nome: ");
    scanf("%s", name);

    //o MENOS 1 é por causa \0 que tem no final da string
    for(i=0; i<4;i++){
        printf("%c", name[i]);
    }
}