#include<stdlib.h>
#include<stdio.h>

int ** criaMatriz(int m, int n);
void leiaMatriz(int **mat, int m, int n);
int somaMatriz(int **mat, int m, int n);
int* colunaMatriz(int ** mat, int m, int n, int ncoluna);
void liberaMatriz(int **mat, int ncoluna);
void imprimeMatriz(int **mat, int m, int n);
void imprimeVetor (int *vet, int n);

int main(){
    int op, l, c, soma, nc;
    int **mat = NULL;
    int *vet = NULL;

    do
    {
        //MENU
        printf("\n--------------MENU-----------------\n");
        printf("1. Cria uma matriz linhas x colunas\n");
        printf("2. Ler os elementos da matriz\n");
        printf("3. Soma dos elemntos da matriz\n");
        printf("4. Elementos de uma coluna da matriz\n");
        printf("5. Imprimir matriz\n");
        printf("6. Sair\n");
        printf("Opcao: ");
        scanf("%d", &op);

        switch (op)
        {
            case 1:
                printf("Digite o numero de linhas: ");
                scanf("%d", &l);
                printf("Digite o numero de colunas: ");
                scanf("%d", &c);
                mat = criaMatriz(l, c);
                break;

            case 2:
                printf("Digite os elementos da matriz: \n");
                leiaMatriz(mat, l, c);
                break;

            case 3:
                soma = somaMatriz(mat, l, c);
                printf("A soma dos elementos da matriz eh %d", soma);
                break;

            case 4:
                printf("Que coluna da matriz gostaria de ver: ");
                scanf("%d", &nc);
                vet = colunaMatriz(mat, l, c, nc);
                printf("O valores dessa coluna sao:\n");
                imprimeVetor(vet, c);
                break;

            case 5:
                imprimeMatriz(mat, l, c);
                break;

            case 6:
                liberaMatriz(mat, l);
                break; 

            default: 
                printf("Opcao Invalida\n");
                break;
        }
        
        
    } while (op!=6);

    return 0;
}

int ** criaMatriz(int l, int c)//Retornando um ptr de ptr com a loc da alocação da matriz
{
    int **mat = (int **)malloc((sizeof(int *)*l));//espaco para as linhas
    if(!mat){printf("ERRO-Memoria insuficiente"); exit(1);}

    for(int i=0; i<c; i++)
    {
        mat[i]= (int*)malloc(sizeof(int) * c);//dentro das linhas alocado espaço para as colunas
    }

    return mat;
}

void leiaMatriz(int **mat, int l, int c)
{
    int a, cont=1;

    for(int i=0; i<l; i++)
    {
        for(int j=0; j<c; j++)
        {
            printf("%d elemento: ", cont++);
            scanf("%d", &a);
            mat[i][j]= a;
        }
    }

}

int somaMatriz(int **mat, int l, int c) 
{
    int soma=0, i, j;

    for(i=0;i<l;i++)
    {
        for(j=0; j<c; j++)
        {
            soma = soma + mat[i][j];
        }
    }

    return soma;
}

int* colunaMatriz(int ** mat, int l, int c, int ncoluna)//Retorna um vetor com os el da coluna
{
    int *vet = (int *)malloc(sizeof(int) * c);
    int i, j;
    ncoluna--;

    for(i=0; i<l; i++)
    {
     for (j=0;j<c;j++)
     {
         if (j==ncoluna)
         {
             vet[i] = mat[i][j];
         }
     }
    }

    return vet;
}

void imprimeVetor (int *vet, int c)
{
    for(int i = 0; i<c; i++)
    {
        printf("%d\t", vet[i]);
   }

    free(vet);
}

void imprimeMatriz(int **mat, int l, int c)
{
    int i, j;
    for(i=0; i<l; i++)
    {
        for(j=0;j<c;j++)
        {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
}


void liberaMatriz(int **mat, int nlinhas)
{
    int i;
    for(i=0;i<nlinhas; i++)
    {
        free(mat[i]);
    }
    
    free(mat);
}