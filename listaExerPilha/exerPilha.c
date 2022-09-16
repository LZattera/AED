#include<stdio.h>
#include<stdlib.h>
#include"exerPilha.h"

struct element{
    struct person data;
    struct element *prox;
};
typedef struct element Elem;

int main(){
    Person* pe;
    pe = RESET();

    CLEAR(pe);
    free(pe);
    return 0;
}

Person* RESET(){
    Person* pe = (Person*)malloc(sizeof(Person));
    if(pe != NULL)
        *pe = NULL;
    return pe;
}

void CLEAR (Person *pe){
    if(pe != NULL) {//se a pilha existe
        Elem* no;
        while((*pe) != NULL){//enquanto a pilha tiver elementod
            no = *pe;
            pe = (*pe)->prox;
            free(no);
        }
        free(pe);//libera o topo
    }
}

int EMPTY(Person *pe){
    if(pe == NULL)//verifica se exsite pilha
        return 1;
    if(*pe == NULL)//verifica se topo da pilha aponta p/ NULL, se tem algum elemento
        return 1;
    return 0;
}

int PUSH(Person* pe, struct person al){
    if(pe == NULL) return 0;//verifica se existe pilha 
    Elem *no = (Elem*)malloc(sizeof(Elem));//aloca o novo no
    if(no == NULL) return 0;//verifica se foi criado corretamente
    no->data = al;//al é a struct de doas iinseridos pelo usuario
    no->prox = NULL;
    *pe = no;
    return 1;
}

int POP(Person* pe){
    if(pe == NULL) return 0;//se tem pilha
    if((*pe) == NULL) return 0;//se a pilha é vazia
    Elem *no = *pe;//no aux que recebe o topo da pilha
    *pe = no->prox;
    free(no);
    return 1;
}

/*1, criar uma funções que leia um arquivo com os dados que serão inseridos na pilha
1,2. Ligar essas funções com a função POP
2. Criar o menu da pilha*/