/*Criar uma arvore binaria onde o usuario insere valores nela e no final retornamos se a arvore eh AVL ou não*/
#include<stdio.h>
#include<stdlib.h>

typedef struct NO* AvrBin;
struct NO{
    int num;
    struct NO* esq;
    struct NO* dir;
};

AvrBin* CreateTree(){
    AvrBin *root = (AvrBin*)malloc(sizeof(AvrBin));
    if(root != NULL){
        *root = NULL;
    }
    return root;
}
void FreeTree(AvrBin *root){
    if(root == NULL) return;
    FreeNode(*root);
    free(root);
}
void FreeNode(struct NO *node){
    if(node == NULL) return;
    FreeNode(node->esq);
    FreeNode(node->dir);
    free(node);
    node = NULL;
}
int InsertNode(AvrBin *root, int info){
    if(root == NULL) return 0;
    struct NO *new;
    new = (struct NO*)malloc(sizeof(struct NO));
    if(new == NULL) return 0;
    new->num = info; 
    new->esq = NULL;
    new->dir = NULL;

    if(*root == NULL)
        *root = new;
    else{
        struct NO *currentNode = *root;
        struct NO *pastNode = NULL;
        while(currentNode != NULL){
            pastNode = currentNode;
            if(info == currentNode->num){
                free(new);
                return 0;
            }
            if(info > currentNode->num)
                currentNode = currentNode->dir;
            else
                currentNode = currentNode->esq;
        }
        if(info > pastNode->num)
            pastNode->dir = new;
        else
            pastNode->esq = new;
    }
    return 1;
}
void IsAvl(AvrBin* root){
    if(root == NULL) return 0;
    int treeBF, heigthLeft, heigthRigth; //Balance Factor

    // Calcular a altura para o fator de balanceamento
    
    if((*root)->esq != NULL)
        IsAvl(&(*root)->esq);
    if((*root)->dir != NULL)
        IsAvl(&(*root)->dir);

    heigthLeft = NodeHeigth((*root)->esq);
    heigthRigth = NodeHeigth((*root)->dir);

    treeBF = heigthLeft - heigthRigth;

    if(treeBF <= -1 || treeBF >= 1)
        printf("Os valores inseridos formam uma arvore AVL\n");
    else
        printf("Os valores inseridos NAO formam uma arvore AVL\n");
}
int NodeHeigth(AvrBin *root){
    int left, rigth;
    if(root == NULL) return 0;

    left = NodeHeigth(&(*root)->esq);
    rigth = NodeHeigth(&(*root)->dir);

    if(left > rigth)
        return left+1;
    else
        return rigth+1;
}
int main(){
    AvrBin *root;
    root = CreateTree();

    int op, info;
    do{
        printf("1.  Inserir numero\n");
        printf("2.  Encerrar insercao\n");
        scanf("%d", &op);
        switch(op){
            case 1:
                printf("Numero: ");
                scanf("%d", &info);
                InsertNode(root, info);
                break;
            case 2:
                IsAvl(root);
                break;
        }
    }while(op != 0);
    FreeTree(root);
    return 0;
}
/*dr Memory 
 debugar o código
*/