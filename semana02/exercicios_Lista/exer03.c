/*Entre com um nome e imprima o nome somente se a primeira letra do nome for ‘a’ (maiuscula ou minuscula*/
#include<stdio.h>

int main(){
    char name[20], aux;

    printf("Digite o nome: ");
    scanf("%s", name);

    aux = name[0];

    if(aux == 'a' || aux == 'A'){
        printf("%s", name);
    }else{
        printf("Nome nao inicia com a letra 'a' ou 'A'");
    }

    return 0;
}