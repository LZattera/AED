/*Quebrar em partes a agenda
1. Primerio uma agenda com variaveis
    1.2 Colocar para ele ler os valores de um arquivo txt
2. Ir substituindo as var por ponteiros
3. Implementando o pBuffer
4. Implementar com lista encadeada*/
#include<stdio.h>
#include<stdlib.h>

struct agenda{
    char name[10];
    int tel;
};
typedef struct agenda Agenda;
int main(){

    Agenda *ag;
    ag = (Agenda*)malloc(sizeof(Agenda)*10);//Alocando um vetor de 10 posiçoes para os contatos
    int op;
    
    do{
        printf("-=-=MENU-=-=\n");
        printf("1.  Adicionar\n");
        printf("2.  Remover\n");
        printf("3.  Listar\n");
        printf("0.  Sair\n");
        scanf("%d", &op);
        switch(op){
            case 1:
                for(int i = 0; i< 3; i++){//inserir 10 contatos
                    printf("Digite o nome: ");
                    scanf("%s", ag[i].name);
                    printf("Digite o telofone (11 numeros): ");
                    scanf("%d", &ag[i].tel);

                    printf("%s  %d \n", ag[i].name, ag[i].tel);
                }

                break;
            case 2:
                //RemovePerson();
                break;
            case 3:
                //PrintAgenda();
                break;
        }
    }while(op != 0);
    return 0;
}

Agenda* AddPerson(Agenda *ag){
    if(ag != NULL){

        printf("Digite o nome: ");
        scanf("%s", ag->name);
        printf("Digite o telofone (11 numeros): ");
        scanf("%d", &ag->tel);
    
        printf("nome: %s telofone: %d\n", ag->name, ag->tel);
    }
    return ag;
}
