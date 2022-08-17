/*Digite um nome, calcule e retorne quantas letras tem esse nome*/
#include<stdio.h>
#include<string.h>
int main(){
    char name[20];
    int i, tam=0;

    printf("Digite um nome: ");
    scanf("%s", name);
    
    for(i=0; i < strlen(name); i++){
        tam++;
    }
    printf("%d", tam);

    return 0;
}