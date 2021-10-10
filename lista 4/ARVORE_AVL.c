#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int maior(int x, int y);
int balanceamento_NO(struct NO* no);
int alt_NO(struct NO* no);
int remove_arvAVL(arvAVL *raiz, int valor);
int insere_arvAVL(arvAVL * raiz, int x);
int verificacao(struct NO* raiz);
void libera_NO(struct  NO* no);
arvAVL* cria_arv();
void libera_arv(arvAVL* raiz);

typedef struct NO* arvAVL;

struct NO
{
    int info;
    int alt;
    struct NO *esq;
    struct NO *dir;
};

int main()
{
    int valor, qtdNo;
    arvAVL* raiz;//ponteiro para ponteiro
    raiz = cria_arv();

    printf("Quantos nós deseja para árvore?");
    scanf("%d", &qtdNo);

    srand(time(0));

    for(int i=0; i<= qtdNo ; i++)
        valor = insere_arv(raiz, (rand()%100));

    int x = insere_arvAVL(raiz, valor);
    int x = remove_arvAVL(raiz, valor);
}
int insere_arvAVL(arvAVL * raiz, int x)
{
    int res;
    if(*raiz == NULL)
    {
        struct NO *novo;
        novo = (struct NO*)malloc(sizeof(struct NO));
        if(novo == NULL)
            return 0;
        
        novo->info = x;
        novo->alt = 0;
        novo->dir= NULL;
        novo->esq = NULL;
        return 1;
    }

    struct NO *atual = *raiz;
    if(x < atual->info)
    {
        if((res=insere_arvAVL(&(atual->esq), x)) == 1)
        {
            if(balanceamento_NO(atual) >= 2)
            {
                if(x < (*raiz)->esq->info)
                {
                    rotaçãoLL(raiz);
                }else{
                    rotaçãoLR(raiz);
                }
            }
        }
    }
    else{
        if(x >atual->info)
        {
            if((res = insere_arvAVL(&(atual->dir), x)) == 1)
            {
                if(balanceamento_NO(atual) >= 2)
                {
                    if((*raiz)->dir->info < x)
                    {
                        rotaçãoRR(raiz);
                    }else{
                        rotaçãoRL(raiz);
                    }
                }
            }
         } else{
                printf("Valor duplicado!\n");
                return 0;
        }
    }
    atual->alt = maior(alt_NO(atual->esq), alt_NO(atual->dir)) + 1;
    return res;
}

int remove_arvAVL(arvAVL *raiz, int valor)
{
    if(*raiz == NULL)// Valor não existe
    {
        printf("Valor não existe!\n");
        return 0;
    }
    int res;
    if(valor < (*raiz)->info)
    {
        if((res = remove_arvAVL(&(*raiz)->esq, valor)) == 1)
        {
            if(balanceamento_NO(*raiz) >= 2)
            {
                if(alt_NO((*raiz)->dir->esq) <= alt_NO((*raiz)->dir->dir))
                    rotaçãoRR(raiz);
                else
                    rotaçãoRL(raiz);
            }
        }
    }
    if((*raiz)->info < valor)
    {
        if((res=remove_arvAVL(&(*raiz)->dir, valor))==1)
        {
            if(balanceamento_NO(*raiz)>=2)
            {
                if(alt_NO((*raiz)->esq->dir) <= alt_NO((*raiz)->esq->esq))
                    rotaçãoLL(raiz);
                else
                    rotaçãoLR(raiz);
            }
        }
    }
    if((*raiz)->info == valor)
    {
        if(((*raiz)->esq == NULL || (*raiz)->dir == NULL))
        {
            struct NO *Novelho = (*raiz);
            if((*raiz)->esq != NULL)
                *raiz = (*raiz)->esq;
            else
                *raiz = (*raiz)->dir;
            free(Novelho);
        }else{
            struct NO* temp;
            (*raiz)->info = temp->info;
            remove_arvAVL(&(*raiz)->dir, (*raiz)->info);
            if(balanceamento_NO(*raiz) >=2)
            {
                if(alt_NO((*raiz)->esq->dir) <= alt_NO((*raiz)->esq->esq))
                    rotaçãoLL(raiz);
                else
                    rotaçãoLR(raiz);
            }
        }
        return 1;
    }
    return res;
}

//ROTAÇÕES
void rotaçãoLL(arvAVL *raiz)
{
    struct NO *no;

    no = (*raiz)->esq;
    (*raiz)->esq = no->dir;
    no->dir = *raiz;
    (*raiz)->alt = maior(alt_NO((*raiz)->esq),alt_NO((*raiz)->dir))+1;
    no->alt = maior(alt_NO(no->esq), alt_NO(no->dir))+1;
    *raiz = no;    
}
void rotaçãoRR(arvAVL *raiz)
{
    struct NO *no;

    no = (*raiz)->dir;
    (*raiz)->dir = no->esq;
    no->esq = (*raiz);
    (*raiz)->alt = maior(alt_NO((*raiz)->esq),alt_NO((*raiz)->dir))+1;
    no->alt = maior(alt_NO(no->dir), (*raiz)->alt)+1;
    (*raiz) = no;    
}
void rotaçãoLR(arvAVL *raiz)
{
    rotaçãoRR(&(*raiz)->esq);
    rotaçãoLL(raiz);
}
void rotaçãoRL(arvAVL *raiz)
{
    rotaçãoLL(&(*raiz)->dir);
    rotaçãoRR(raiz);
}

//calcula a altura do nó
 int alt_NO(struct NO* no)
 {
     if(no == NULL)
        return -1;
    else
        return no->alt;
 }
 //Calcula o fator de balaceamento de um nó
 int balanceamento_NO(struct NO* no)
 {
     return labs(alt_NO(no->esq)-alt_NO(no->dir));
 }
 //Calcula o maior valor
 int maior(int x, int y)
 {
     if(x>y)
        return x;
    else
        return y;  
 }

 //libera arvore
void libera_NO(struct  NO* no)//Percorre a arvore
{
    if(no == NULL)
        return;
    libera_NO(no->esq);
    libera_NO(no->dir);
    free(no);
    no = NULL;
}
void libera_arv(arvAVL* raiz)
{
    if(raiz == NULL)
        return;
    libera_NO(*raiz);//Libera os nós ligados a raiz
    free(raiz);//Libera a raiz
}
 
 //cria árvore
 arvAVL* cria_arv()
{
    arvAVL* raiz = (arvAVL*)malloc(sizeof(arvAVL));
    if(raiz != NULL)
        *raiz = NULL;
    return raiz;
}

int verificacao(struct NO* raiz)
{
    int fb;

    if(raiz == NULL)
        return 1;
    
    if(!Verificacao(raiz->esq))
        return 0;
    if(!Verificacao(raiz->dir))
        return 0;

    fb = alt_NO(raiz);
    if((fb > 1) || (fb < -1))
        return 0;
    else
        return -1;
}