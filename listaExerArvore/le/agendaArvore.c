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
    CREATE(raiz);
    int op;

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
                scanf("%d", &op);
                switch(op){
                    case 1:
                        break;
                    case 2:
                        break;
                    case 3:
                        POPAge(raiz);
                        break;
                }
                break;
            case 2:
                break;
            case 3:
                break;
            
        }
    }while(op != 0);
    LiberaArv(raiz);
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
struct NO* InsertData(){
    struct NO* aux;
    printf("Name: ");
    scanf("%s", (*aux).name);//problema no scanf
    printf("Age: ");
    scanf("%d", &(*aux).age);
    printf("Telefone: ");
    scanf("%d", &(*aux).tel);

    return aux;
}

//INSERT DATA BY AGE
int POPAge(ArvBin* raiz){
    if(raiz == NULL) return 0;
    struct NO* novo;
    novo = (struct NO*)malloc(sizeof(struct NO));
    if(novo != NULL)
        novo = InsertData();
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
void PrintTree(ArvBin* raiz){
    if(raiz == NULL) return;//se foi alocada
    if(*raiz == NULL) return;//se arv existe
    struct NO* atual= *raiz;
    while(atual != NULL){
        PrintTree(&((*raiz)->esq));
        PrintTree(&((*raiz)->dir));
        printf("Name: %d\n", (*atual).name);
        printf("Age: %d\n", (*atual).age);
        printf("Telephone: %d\n", (*atual).tel);
    }
}