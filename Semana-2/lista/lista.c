#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int idade;
    int altura;
    char nome[50];
}Pessoa;

int main(){
 
    Pessoa *p=(Pessoa *)malloc(sizeof(Pessoa));
    if(!p){printf("ERRO-Memoria insuficiente");exit(1);}

    int op, n_inse=0;//n_inse: num de cadastros

    do
    {
        //MENU
        printf("1.Inserir\n");
        printf("2.Sair\n");
        scanf("%d", &op);

        switch (op)
        {
            case 1:
                
                p=(Pessoa *)realloc(p,sizeof(Pessoa));
 
                printf("Nome: ");
                scanf("%s", (p+n_inse)->nome);
                printf("Idade: ");
                scanf("%d", &(p+n_inse)->idade);
                printf("Altura: ");
                scanf("%d", &(p+n_inse)->altura);
                 n_inse ++;

                continue; 

            case 2: //Listar

                printf("Dados Salvos\n");
                for (int i = 0; i < n_inse; i++)
                {
                    printf("Nome: %s\n", (p+i)->nome);
                    printf("Idade: %d\n", (p+i)->idade);
                    printf("Altura: %d\n", (p+i)->altura);
                }

                free(p);
            
        }
    }while(op!=2);
}