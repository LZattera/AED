/*TESTAR
1- ISNERÇÃO
2- REMOÇÃO
3- CONSULTA
4- INSERÇÃO POR NOME
5- REMOÇÃO POR NOME
6- CONSULTA POR NOME
7- IMPRIMIR PRE/  / EM/  / POS/  /*/
#include<stdio.h>
#include<stdlib.h>
#include"Arvore.h"

struct NO{
    char name[10];
    int ID;
    struct NO *esq;
    struct NO *dir; 
};

int main(){
    ArvBin *raiz;
    raiz = CriaArvore();
    int op;

    do{
        printf("-=-=Menu-=-=\n");
        printf("1.  Inserir\n");
        printf("2.  Remover\n");
        printf("3.  Buscar\n");
        printf("4.  Listar\n");
        printf("0.  SAIR\n");
        scanf("%d", &op);
        switch(op){
            case 1:
                PUSH(raiz);
                break;
            case 4:
                printf("1.  Listar PRE Ordem\n");
                printf("2.  Listar EM Ordem\n");
                printf("3.  Listar POS Ordem\n");
                scanf("%d", &op);
                switch(op){
                    case 1:
                        PreOrdem(raiz);
                        break;
                    case 2:
                        EmOrdem(raiz);
                        break;
                    case 3:
                        PosOrdem(raiz);
                        break;
                    default:
                        printf("Numero invalido\n");
                        break;
                }
        }
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
        printf("%d\n", (*raiz)->ID);
        PreOrdem(&((*raiz)->esq));
        PreOrdem(&((*raiz)->dir));
    }
}
void EmOrdem(ArvBin* raiz){
    if(raiz == NULL) return;
    if(*raiz != NULL){
        EmOrdem(&((*raiz)->esq));
        printf("%d\n",(*raiz)->ID);
        EmOrdem(&((*raiz)->dir));
    }
}
void PosOrdem(ArvBin* raiz){
    if(raiz == NULL) return;
    if(*raiz != NULL){
        PosOrdem(&((*raiz)->esq));
        PosOrdem(&((*raiz)->dir));
        printf("%d\n", (*raiz)->ID);
    }
}
//INSERINDO ITENS NA ARVORE
int PUSH (ArvBin* raiz){
    if(raiz==NULL) return 0;
    struct NO* novo;
    novo = (struct NO*)malloc(sizeof(struct NO));
    if(novo == NULL) return 0;

    struct NO* aux = InsertData();
    novo->ID = aux->ID;
    *novo->name = aux->name;
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
            if(aux->ID == atual->ID){
                free(novo);
                return 0;//dado ja existe
            }
            if(aux->ID >atual->ID)
                atual = atual->dir;
            else
                atual = atual->esq;
        }
        if(aux->ID > ant->ID)
            ant->dir = novo;
        else
            ant->esq = novo;   
    }
    return 1;
}
//REMOVENDO UM NO
int POP(ArvBin *raiz, int valor){
    if(raiz == NULL) return 0;
    struct NO* atual = *raiz;
    struct NO* ant = NULL;
    while(atual != NULL){
        if(valor == atual->ID){
            if(atual == *raiz)
                *raiz = RemoveAtual(atual);
            else{
                if(ant->dir == atual)
                    ant->dir = RemoveAtual(atual);
                else
                    ant->esq = RemoveAtual(atual);
            }
            return 1;
        }
    }
    ant = atual;
    if(valor > atual->ID)
        atual = atual->dir;
    else
        atual = atual->dir;
}
struct NO* RemoveAtual(struct NO* atual){
    struct NO *no1, *no2;
    if(atual->esq == NULL){
        //Sem filho a esquerda, aponta para o filho da direita(Trata no folha e no com 1 filho)
        no2 = atual->dir;
        free(atual);
        return no2;
    }
    //Procura filho mais a direita na subatv da esquerda
    no1 = atual;
    no2 = atual->esq;
    while(no2->dir != NULL){
        no1 = no2;
        no2 = no2->dir;
    }
    //Copia o filho mais a direita na subarv esquerda para olugar do no removido
    if (no1 != atual){
        no1->dir= no2->esq;
        no2->esq = atual->esq;
    }
    no2->dir = atual->dir;
    free(atual);
    return no2;
    
}
//CONSULTA NA ARVORE
int Consulta(ArvBin* raiz, int valor){
    if(raiz == NULL) return 0;
    struct NO* atual = *raiz;
    while(atual != NULL){
        if(valor == atual->ID)
            return 1;
        if(valor > atual->ID)
            atual = atual->dir;
        else
            atual = atual->esq;
    }
    return 0;
}
struct NO* InsertData(){
    struct NO* aux;
    printf("ID: ");
    scanf("%d", &aux->ID);
    printf("Name: ");
    scanf("%s", aux->name);
    return aux;
} 