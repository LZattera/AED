#include<stdio.h>
#include<stdlib.h>
#include"Fila.h"

struct fila{//nó descritor
    struct elemento *inicio;
    struct elemento *final;
};
struct elemento{//tipo de dado que representa meu tipo de elemento 
    struct aluno dados;
    struct elemento *prox;
};
typedef struct elemento Elem;

int main(){
    Fila *fi;
    fi = CriaFila();
    int op;

    do{
        printf("-=-=MENU-=-=\n");
        printf("1.   INSERIR\n");
        printf("2.   DELETA PESSOA\n");
        printf("3.   IMPRIMIR FILA\n");
        printf("4.  CONSULTA\n");
        printf("0.   SAIR\n");
        scanf("%d", &op);
        switch(op){
            case 1:
                InsereFila(fi);
                break;
            case 2:
                RemoveFila(fi);
                break;
            case 3:
                ImprimiFila(fi);
                break;
            case 4:
                ConsultaFila(fi);
                break;
            case 0:
                break;
        }
    }while(op != 0);

    LiberaFila(fi);
    return 0;
}

Fila* CriaFila(){
    Fila* fi =(Fila*)malloc(sizeof(Fila));
    if(fi != NULL){
        fi->final = NULL;
        fi->inicio = NULL;
    }
    return fi;
}

void LiberaFila(Fila* fi){
    if(fi != NULL){
        Elem* no;
        while(fi->inicio != NULL){
            no = fi->inicio;
            fi->inicio = fi->inicio->prox;
            free(no);
        }
        free(fi);
    }
}

int TamanhoFila(Fila* fi){
    if(fi == NULL) return 0;
    int cont = 0;
    Elem* no = fi->inicio;
    while(no != NULL){
        cont ++;
        no = no->prox;
    }
    return cont;
}

int FilaVazia(Fila* fi){
    if(fi == NULL) return 1;
    if(fi->inicio == NULL) return 1;
    return 0;
}

int InsereFila(Fila* fi){
    if(fi == NULL) return 0;
    Elem *no = (Elem*)malloc(sizeof(Elem));
    if(no == NULL) return 0;
    no->dados = InsereDados();
    no->prox = NULL;
    if(fi->final == NULL)//Fila Vazia
        fi->inicio = no;
    else
        fi->final->prox = no;
    fi->final = no;
    return 1;
}

int RemoveFila(Fila* fi){
    if(fi == NULL)return 0;
    if(fi->inicio == NULL)//fila vazia
        return 0;
    Elem* no = fi->inicio;
    fi->inicio = fi->inicio->prox;
    if(fi->inicio == NULL)//filaficou vazia
        fi->final = NULL;
    free(no);
    return 1;
}

int ConsultaFila(Fila* fi){
    if(fi == NULL) return 0;
    if(fi->inicio == NULL) return 0;
    //só consulta o primeiro elemento da fila
    printf("Nome: %s", fi->inicio->dados.nome);
    printf("Matricula: %d", fi->inicio->dados.matricula);
    printf("Notas\n");
    printf("N1> %.2f", fi->inicio->dados.n1);
    printf("N2> %.2f", fi->inicio->dados.n2);
    printf("N3> %.2f", fi->inicio->dados.n3);
    return 1;
}

int ImprimiFila(Fila* fi){
    if(fi == NULL) return 0;
    if(fi->inicio == NULL) return 0;
    Elem* no = fi->inicio;
    while (no != NULL){
        printf("Nome: %s\n", no->dados.nome);
        printf("Matricula: %d\n", no->dados.matricula);
        printf("Notas\n");
        printf("N1> %.2f\n", no->dados.n1);
        printf("N2> %.2f\n", no->dados.n2);
        printf("N3> %.2f\n", no->dados.n3);
        no=no->prox;
    }
    return 1;
}

struct aluno InsereDados(){
    struct aluno al;
    
    printf("Insira os dados\n");
    printf("Nome: ");
    scanf("%s", &al.nome);
    printf("Matricula: ");
    scanf("%d", &al.matricula);
    printf("Notas\n");
    printf("N1> ");
    scanf("%f", &al.n1);
    printf("N2> ");
    scanf("%f", &al.n2);
    printf("N3> ");
    scanf("%f", &al.n3);

    return al;
}