#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define NOME (sizeof(char)*10)
#define IDADE (sizeof(int))
#define TELEFONE (sizeof(int))

#define OPCAO  (sizeof(int))
#define CONTADOR  (sizeof(int))
#define P_AUX (sizeof(void**))

#define FIRSTPERSON (sizeof(int))
#define LASTPERSON (sizeof(int)+sizeof(void**))

#define PROXPESSOA ((sizeof(char)*10)+(sizeof(int)*2)+sizeof(void**))
//NOME | IDADE + TELEFONE | PPROX
#define ANTPESSOA ((sizeof(char*10)+sizeof(int)*2))

int main(){
    void *pAux = NULL;
    pAux = malloc(CONTADOR + P_AUX + P_AUX);
    *(int*)pAux = 0;//contador = 0
    
    void *pBuffer = NULL;
    pBuffer = malloc(OPCAO + P_AUX);

    while(1){
        printf("=-=MENU=-=\n");
        printf("1.  INSERIR\n");
        scanf("%d", (int*)pBuffer);
        switch(*(int*)pBuffer){
            case 1:
                printf("Funcionou");
                break;
        }
    }
    free(pBuffer);
    free(pAux);
    return 0;
}