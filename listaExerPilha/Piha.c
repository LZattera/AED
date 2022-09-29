#include<stdio.h>
#include<stdlib.h>
#include"Pilha.h"

struct elemento{
    struct aluno dados;
    struct elemento *prox;
};
typedef struct elemento Elem;

int main(){
    Pilha* pi;
    pi = CriaPilha();

    LiberaPilha(pi);
    return 0;
}

Pilha* CriaPilha(){
    Pilha* pi = (Pilha*)malloc(sizeof(Pilha));
    if(pi!=NULL)
        *pi = NULL;
    return pi;
}

void LiberaPilha(Pilha* pi){
    if(pi != NULL){
        Elem* no;
        while(*pi != NULL){
            no = *pi;
            *pi = (*pi)->prox;
            free(no);
        }
        free(pi);
    }
}

int InserePilha(Pilha* pi){
    if(pi == NULL) return 0;//pilha não existe
    Elem *no = (Elem*)malloc(sizeof(Elem));
    if(no == NULL) return 0;
    no->dados;  // = dados;
    no->prox = (*pi);
    *pi = no;
    return 1;
}

int RemovePilha(Pilha* pi){
    if(pi == NULL) return 0;//pilha ñ existe
    if(*pi == NULL) return 0;//pilha vazia
    Elem* no;
    
}