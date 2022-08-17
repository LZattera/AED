/*Ler nome, sexo e idade. Se sexo for feminino e idade menor que 25, imprime o nome da pessoa e a palavra “ACEITA”, caso contrario imprimir “N ´ AO ACEITA”. */
#include<stdio.h>

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
    scanf("%s", &Cadastro.sexo);

    /*if((Cadastro.sexo == 'F' || Cadastro.sexo == 'f') && Cadastro.idade <= 25){
        printf("%s ACEITA", Cadastro.nome);
    }else{
        printf("%s NAO ACEITA", Cadastro.nome);
    }*/

    ((Cadastro.sexo == 'F' || Cadastro.sexo == 'f') && Cadastro.idade <= 25)?printf("%s ACEITA", Cadastro.nome):printf("%s NAO ACEITA", Cadastro.nome);
    return 0;
}