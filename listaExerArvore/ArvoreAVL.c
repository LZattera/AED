/*Arvore AVL
    o Permite rebalanceamento local
    o Apenas na parte afetada pela inserção ou remoção é rebalanceada
    o Usa ROTAÇÕES 'simples' o 'duplas' na etapa de rebalanceamento
    o Busca se manter como uma 'Arvore binária quase completa'
    o Custo max O(logN)
    o A partir do fb - fator de balanceamento(diferença entre as alturas das sub arv esq e dir) saberemos ondedeve ser balanceada a arvore
    o Se o fb for != de 1 ou -1 a sub arv deve ser balanceada*/
#include<stdio.h>
#include<stdlib.h>
#include"ArvoreAVL.h"

struct NO{
    int info;
    int alt;//altura da subArvore
    struct NO *esq;
    struct NO *dir;
};

int main(){
    ArvAVL *raiz;

    return 0;
}

int alt_NO(struct NO* no){//calcula altura do no
    if(no == NULL) return -1;
    else
        return no->alt;
}

int fatorBalanceamento(struct NO* no){
    return labs(alt_NO(no->esq)-alt_NO(no->dir));//labs arredonda o valor
}

int maior(int x, int y){
    if(x > y)
        return x;
    else
        return y;
}

void RotaçãoLL(ArvAVL* raiz){
    struct NO *no;
    no = (*raiz)->esq;
    (*raiz)->esq=no->dir;
    no->dir = *raiz;
    (*raiz)->alt = maior(alt_NO((*raiz)->esq), alt_NO((*raiz)->dir))+1;
    no->alt = maior(alt_NO(no->esq), alt_NO(no->dir))+1;
    *raiz = no;
}

void RotaçãoRR(ArvAVL* raiz){
    struct NO* no;
    no = (*raiz)->dir;
    (*raiz)->dir = no->esq;
    no->esq = *raiz;
    (*raiz)->alt = maior(alt_NO((*raiz)->esq), alt_NO((*raiz)->dir))+1;
    no->alt= maior(alt_NO(no->esq), alt_NO(no->dir))+1;
    *raiz = no;
}

void RotaçãoLR(ArvAVL *raiz){
    RotaçãoRR(&(*raiz)->esq);
    RotaçãoLL(raiz);
}

void RotaçãoRL(ArvAVL *raiz){
    RotaçãoLL(&(*raiz)->dir);
    RotaçãoRR(raiz);
}

int PUSH(ArvAVL *raiz, int valor){
    int res;
    if(*raiz == NULL){//arv vazia ou no folha
        struct NO *novo;
        novo = (struct NO*)malloc(sizeof(struct NO));
        if(novo == NULL) return 0;

        novo->info = valor;
        novo->alt = 0;
        novo->dir = NULL;
        novo->esq = NULL;
        *raiz = novo;
        return 1;
    } 
    struct NO *atual = *raiz;
    if(valor > atual->info){
        if((res = PUSH(&(atual->esq),valor)) == 1){
            if(fatorBalanceamento(atual) >= 2){
                if(valor < (*raiz)->esq->info){
                    RotaçãoLL(raiz);
                }else{
                    RotaçãoLR(raiz);
                }
            }
        }
    }else{
        if(valor > atual->info){
            if((res = PUSH(&(atual->dir),valor)) == 1){
                if(fatorBalanceamento(atual) >= 2){
                    if((*raiz)->dir->info < valor){
                        RotaçãoRR(raiz);
                    }else{
                        RotaçãoRL(raiz);
                    }
                }
            }
        }else{
            printf("Valor duplicado\n");
            return 0; 
        }
    }
    atual->alt = maior(alt_NO(atual->esq), alt_NO(atual->dir))+1;
    return res;
}

int POP(ArvAVL* raiz, int valor){
    //Procura o no a ser removido
    if(*raiz == NULL){
        printf("Valor não existe\n");
        return 0;
    }
    int res;
    if(valor < (*raiz)->info){
        if((res = POP(&(*raiz)->esq, valor)) == 1){
            if(fatorBalanceamento(*raiz) >= 2){
                if(alt_NO((*raiz)->dir->esq) <=alt_NO((*raiz)->dir->dir))
                    RotaçãoRR(raiz);
                else
                    RotaçãoRL(raiz);
            }
        }
    }
    if((*raiz)->info < valor){
        if((res=POP(&(*raiz)->dir, valor)) == 1){
            if(fatorBalanceamento(*raiz) >= 2){
                if(alt_NO((*raiz)->esq->dir) <= alt_NO((*raiz)->esq->esq))
                    RotaçãoLL(raiz);
                else
                    RotaçãoLR(raiz);
            }
        }
    }
    if((*raiz)->info == valor){
        if((*raiz)->esq == NULL || (*raiz)->dir == NULL){
            struct NO *oldNode = (*raiz);
            if((*raiz)->esq != NULL)
                *raiz = (*raiz)->esq;
            else
                *raiz =(*raiz)->dir;
            free(oldNode);
        }else{
            struct NO* temp = ProcuraMenor((*raiz)->dir);
            (*raiz)->info = temp->info;
            POP(&(*raiz)->dir, (*raiz)->info);
            if(fatorBalanceamento(*raiz) >= 2){
                if(alt_NO((*raiz)->esq->dir) <= alt_NO((*raiz)->esq->esq)){
                    RotaçãoLL(raiz);
                }else{
                    RotaçãoLR(raiz);
                }
            }           
            return 1;
        }
        return res;
    }
}
struct NO* ProcuraMenor(struct NO* atual){//vai tratar o no com dois filhos
    struct NO *no1 = atual;
    struct NO *no2 = atual->esq;
    while(no2 != NULL){
        no1 = no2;
        no2 = no2->esq;
    }
    return no1;
}