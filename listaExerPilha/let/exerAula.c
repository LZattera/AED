#include<stdio.h>
#include<stdlib.h>
#include"exerPilha.h"

struct element{
    struct person data;
    struct element *prox;
};
typedef struct element Elem;

int main(){
    Person* pe;
    pe = RESET();
    int op;
    
    do{
        printf("-=-=MENU-=-=\n");
        printf("1.   INSERIR\n");
        printf("2.   DELETA PESSOA DO TOPO\n");
        printf("3.   DELETA POR NOME\n");
        printf("4.   LIMPA LISTA\n");
        printf("5.   IMPRIMIR PILHA\n");
        printf("0.   SAIR\n");
        scanf("%d", &op);
        switch(op){
            case 1:
                //função q le os dados de um arquivo
                PUSH(pe);
                break;
            case 2:
                if(!POP(pe))
                    printf("Não foi possivel excluir do topo\n");
                break;
            case 5:
                PrintStack(pe);
                break;
        }

    }while(op != 0);
    free(pe);
    return 0;
}

Person* RESET(){
    Person* pe = (Person*)malloc(sizeof(Person));
    if(pe != NULL)
        *pe = NULL;
    return pe;
}

void CLEAR (Person *pe){
    if(pe != NULL) {//se a pilha existe
        Elem* no;
        while((*pe) != NULL){//enquanto a pilha tiver elementod
            no = *pe;
            pe = (*pe)->prox;
            free(no);
        }
        free(pe);//libera o topo
    }
}

int EMPTY(Person *pe){
    if(pe == NULL)//verifica se exsite pilha
        return 1;
    if(*pe == NULL)//verifica se topo da pilha aponta p/ NULL, se tem algum elemento
        return 1;
    return 0;
}

int PUSH(Person* pe){

    /*SÓ ESTA LENDO/ARMAZENANDO O ULTIMO ITEM DO ARQUIVO*/

    if(pe == NULL) return 0;//verifica se existe pilha 
    Elem *no = (Elem*)malloc(sizeof(Elem));//aloca o novo no
    if(no == NULL) return 0;//verifica se foi criado corretamente

    no->data = ReadData();//ess função retorn a uma struct com os dados lidos de um arq
    no->prox = NULL;
    *pe = no;

    return 1;
}

int POP(Person* pe){
    if(pe == NULL) return 0;//se tem pilha
    if((*pe) == NULL) return 0;//se a pilha é vazia

    Elem *no = *pe;//no aux que recebe o topo da pilha
    *pe = no->prox;
    free(no);

    return 1;
}

/*1, criar uma funções que leia um arquivo com os dados que serão inseridos na pilha - FEITO
1,2. Ligar essas funções com a função POP - FEITO
2. Criar o menu da pilha - FEITO
3. Arrumar função que imprimi a pilha - FEITO
4. Testar função que deleta da pilha
5. Arrumar a função ReadData para ler mais de um conjunto de dados
*/

struct person ReadData(){       

    /*COM ERRO ELE SÓ ARMAZENA O ULTIMO ITEM LIDO*/

    struct person aux;
    char *teste;//PRA QUE ESSE TESTE??
    //abrindo arquivo
    FILE *arq;
    arq = fopen("Data.txt", "rt");//abrindo para leitura (rt) arq 'Data' 
    if(arq == NULL)
        printf("Problema com a abertura do arquivo");
    
    while(!feof(arq) || teste != "&&"){
            teste = fscanf(arq, "%s",aux.name);
            //printf("%s\n", aux.name);
            teste = fscanf(arq, "%d", &aux.age);
            //printf("%d\n", aux.age);
    }
    fclose(arq);

    return aux;//retorna a struct comos dados lidos do arq
    //e se tiver mais de um conj de dados no arq ainda vai funcionar????
}

int PrintStack(Person* pe){
    if(pe == NULL) return 0;
    if((*pe) == NULL) return 0;

    Elem *no = *pe;

    while(no != NULL){
        printf("%d\n", no->data.age);
        printf("%s\n", no->data.name);
        no = no->prox;
    }
    
    return 1;
}