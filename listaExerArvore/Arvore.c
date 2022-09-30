#include<stdio.h>
#include<stdlib.h>
#include"Arvore.h"

struct NO{
    int info;
    struct NO *esq;
    struct NO *dir; 
};

int main(){
    ArvBin *raiz;
    raiz = CriaArvore();
    int op;

    do{
        printf("-=-=Menu-=-=\n");
        printf("\n");
    }while(op != 0);
    LiberaArvore(raiz);
}
//IMPLEMENTAÇÃO DA ARVORE
ArvBin* CriaArvore(){
    ArvBin* raiz = (ArvBin*)malloc(sizeof(ArvBin));
    if(raiz != NULL)
        *raiz = NULL;
    return raiz;
}
void LiberaArvore(ArvBin* raiz){
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
//INFORMAÇÕES DA ARVORE
int Vazia(ArvBin* raiz){
    if(raiz == NULL) return 1;
    if(*raiz == NULL) return 1;
    return 0;
}
int Altura(ArvBin* raiz){
    if(raiz == NULL) return 0;
    if(*raiz == NULL) return 0;
    int altESQ = Altura(&((*raiz)->esq));
    int altDIR = Altura(&((*raiz)->dir));
    if(altESQ > altDIR)
        return (altESQ+1);
    else
        return(altDIR+1);
}
int TotalNOS(ArvBin* raiz){
    if(raiz == NULL) return 0;
    if(*raiz == NULL) return 0;
    int altESQ = TotalNOS(&((*raiz)->esq));
    int altDIR = TotalNOS(&((*raiz)->dir));
    return(altDIR+altESQ);
}
//PERCORRENDO A ARVORE (PRE, EM, POS)
void PreOrdem(ArvBin* raiz){
    if(raiz == NULL) return;
    if(*raiz != NULL){
        printf("%d\n", (*raiz)->info);
        PreOrdem(&((*raiz)->esq));
        PreOrdem(&((*raiz)->dir));
    }
}
void EmOrdem(ArvBin* raiz){
    if(raiz == NULL) return;
    if(*raiz != NULL){
        EmOrdem(&((*raiz)->esq));
        printf("%d\n",(*raiz)->info);
        EmOrdem(&((*raiz)->dir));
    }
}
void PosOrdem(ArvBin* raiz){
    if(raiz == NULL) return;
    if(*raiz != NULL){
        PosOrdem(&((*raiz)->esq));
        PosOrdem(&((*raiz)->dir));
        printf("%d\n", (*raiz)->info);
    }
}
//INSERINDO ITENS NA ARVORE
int PUSH (ArvBin* raiz){
    if(raiz==NULL) return 0;
    struct NO* novo;
    novo = (struct NO*)malloc(sizeof(struct NO));
    if(novo == NULL) return 0;
    //novo->info = DADOS;
    novo->esq = NULL;
    novo->dir = NULL;
    //onde inserir
    if(*raiz == NULL)
        *raiz = novo;
    else{
        struct NO *atual = *raiz;
        struct NO *ant = NULL;
        while(atual != NULL){
            ant = atual;
            if(valor == atual->info){
                free(novo);
                return 0;//dado ja existe
            }
            if(valor >atual->info)
                atual = atual->dir;
            else
                atual = atual->esq;
        }
        if(valor > ant->info)
            ant->dir = novo;
        else
            ant->esq = novo;   
    }
    return 1;
}
//REMOVENDO UM NO
int POP(ArvBin *raiz){
    if(raiz == NULL) return 0;
    if(*raiz == NULL) return 0;
    struct NO* aux = raiz;

}