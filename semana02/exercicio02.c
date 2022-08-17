/*Programa que armazena todos os nomes na MESMA string
O tamanho da string tem de aumentar diminuir de acordo com a inserção e remoção dos nomes*/
#include<stdio.h>
#include<stdlib.h>

int main(){
    int op;
    char *listaDeNomes;
    listaDeNomes = (char*)malloc(sizeof(char));

    do{
        printf("-=-=Menu-=-=\n");
        printf("1,  Adicionar Nome \n");
        printf("2.  Remover Nome\n");
        printf("3.  Listar\n");
        printf("4.  Sair\n");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            AdicionarNome(listaDeNomes);
            break;
        case 4:
            printf("Saindo . . .\n");
            break;
        default:
            printf("Opcao invalida");
            break;
        }
    }while(op!=4);
}
char AdicionarNome(char *liNomes){
    char aux[10];

    printf("Digite o nome: ");
    scanf("%s", &aux);



}