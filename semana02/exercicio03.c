/* toda a informação incluída na agenda deve ficar num único lugar chamado: “void *pBuffer*/
#include<stdio.h>
#include<stdlib.h>

int main(){

    void *pBuffer;
    pBuffer = malloc(sizeof(int)+(sizeof(char)*10)+sizeof(int));//estarão armazenados
    // pBuffer = int op, char nome[10], int matricula

    do{
        printf("-=-= Menu -=-=\n");
        printf("1. Inserir\n");
        printf("2. Excluir\n");
        printf("3. Listar\n");
        scanf("%d", (int*)&(*pBuffer));

    }while(*pBuffer != 0);
    
    return 0;
}
