#include<stdio.h>
int main(){
    int cont =0;
    char nome[20];

    printf("Digite seu nome: ");
    scanf("%s", &nome);

    for(int i=0;nome[i] != 0; i++){
        cont++;
    }

    printf("O tamanho da string eh %d", cont);
}