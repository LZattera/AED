/*Implementar uma agenda com uma arvore onde o usu escolhe por qual fator ele vai querer ordenar/inserir (nome, tele, outro) e toda vez que o usu trocar o fator então tem que pegar a arv antiga e reordenar a arvore, em uma nova arv e detruir a antiga
Fazer o código mais generico possivel*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"agendaArvore.h"

struct NO{
    char name[10];
    int tel;
    int age;
    struct NO* esq;
    struct NO* dir;
};

int main(){
    ArvBin* raiz;
    raiz = CREATE(raiz);
    int op, op2;

    do{
        printf("-=-=AGENDA ARVORE-=-=\n");
        printf("1. INSERIR   \n");
        printf("2. REMOVER   \n");
        printf("3. BUSCAR   \n");
        printf("4. LISTAR   \n");
        printf("0.  SAIR    \n");
        scanf("%d", &op);
        switch(op){
            case 1:
                printf("1.  NOME    2.  TELEFONE    3.IDADE \n");
                scanf("%d", &op2);
                switch(op2){

                    case 3:
                        InsertAge(raiz);
                        break;
                }
                break;
            case 2:
                break;
            case 4:
                Print(raiz);
                break;
            
        }
    }while(op != 0);
    LiberaArv(raiz);//  ??????????? DEBUGAR AQUI
    return 0;
}

ArvBin* CREATE(ArvBin* raiz){
    raiz = (ArvBin*)malloc(sizeof(ArvBin));
    if(raiz != NULL){
        *raiz = NULL;
    }
    return raiz;
}

void LiberaArv(ArvBin *raiz){
    if(raiz == NULL) return;
    LiberaNO(*raiz);
    free(raiz);
}

void LiberaNO(struct NO* no){
    if(no == NULL) return;
    LiberaNO(no->esq);
    LiberaNO(no->dir);
    free(no);
    no = NULL;
}
//INSERT DATA BY AGE
int InsertAge(ArvBin* raiz){
    if(raiz == NULL) return 0;
    struct NO* novo;
    novo = (struct NO*)malloc(sizeof(struct NO));

    if(novo != NULL)
        printf("Name: ");
        scanf("%s", &novo->name);
        fflush(stdin);
        printf("Age: ");
        scanf("%d", &novo->age);
        printf("Telefone: ");
        scanf("%d", &novo->tel);
        novo->esq = NULL;
        novo->dir = NULL;

    if(*raiz == NULL)
        *raiz = novo;
    else{
        struct NO* atual = *raiz;
        struct NO* ant = NULL;

        while(atual != NULL){
            ant = atual;
            if(novo->age == atual->age){
                free(novo);
                return 0;//already exists
           } 
           if(novo->age > atual->age)
                atual = atual->dir;
            else
                atual = atual->esq;           
        }
        if(novo->age > ant->age)
            ant = ant->dir;
        else
            ant = ant->esq;
    }
    return 1;
}
void POP(ArvBin* raiz){

}
void Print(ArvBin* raiz){//algo errado com os ponteiro dir ou esq na hora de inserir o nó
    if(raiz == NULL) return;
    if(*raiz != NULL){
        printf("NAME: %s\n", (*raiz)->name);
        printf("AGE: %d\n", (*raiz)->age);
        printf("TEL: %d\n", (*raiz)->tel);
        Print(&(*raiz)->esq);
        Print(&(*raiz)->dir);
    }
}