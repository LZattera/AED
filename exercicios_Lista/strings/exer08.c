/*Fac¸a um programa que conte o numero de 1’s que aparecem em um string. Exemplo:“0011001” -> 3*/
#include<stdio.h>
#include<string.h>

int main(){
    char stringBit[10];
    int cont =0;

    printf("Digite a string: ");
    scanf("%s", stringBit);

    for(int i=0; i<strlen(stringBit);i++){
        if(stringBit[i] == '1'){
            cont++;
        }
    }

    printf("%s -> %d", stringBit, cont);

    return 0;
}