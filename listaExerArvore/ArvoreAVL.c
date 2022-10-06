/*Arvore AVL
    o Permite rebalanceamento local
    o Apenas na parte afetada pela inserção ou remoção é rebalanceada
    o Usa ROTAÇÕES'simples' o 'duplas' na etapa de rebalanceamento
    oBusca se manter como uma 'Arvore binária quase completa'
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

