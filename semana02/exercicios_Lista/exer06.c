/*Ler nome, sexo e idade. Se sexo for feminino e idade menor que 25, imprime o nome da pessoa e a palavra “ACEITA”, caso contrario imprimir “N ´ AO ACEITA”. */
#include<stdio.h>
#include<stdlib.h>

struct cadastro{
    char nome[20];
    int idade;
    char sexo;
}Cadastro;

int main(){
    printf("Cadastro\n");
    printf("Nome: ");
    scanf("%s", Cadastro.nome);
    printf("Idade: ");
    scanf("%d", &Cadastro.idade);
    printf("Sexo [F/M]: ");
    scanf("%c", &Cadastro.sexo);

    /*if((Cadastro.sexo == 'F' || Cadastro.sexo == 'f') && Cadastro.idade <= 25){
        printf("%s ACEITA", Cadastro.nome);
    }else{
        printf("%s NAO ACEITA", Cadastro.nome);
    }*/
    char aux = (char*)Cadastro.sexo;
    ((aux == 'F' || aux == 'f') && Cadastro.idade <= 25)?printf("ACEITA"):printf("NAO ACEITA");
    return 0;
}