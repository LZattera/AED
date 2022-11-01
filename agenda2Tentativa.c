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
#define ANTPESSOA (sizeof(char*10)+sizeof(int)*2)

int main(){
    void *pAux = NULL;
    pAux = malloc(CONTADOR + P_AUX + P_AUX);
    *(int*)pAux = 0;//contador = 0
    
    void *pBuffer = NULL;
    pBuffer = malloc(OPCAO + P_AUX);

    while(1){
        printf("=-=MENU=-=\n");
        printf("1.  INSERIR\n");
        printf("2.  LISTAR\n");
        scanf("%d", (int*)pBuffer);
        switch(*(int*)pBuffer){
            case 1:
                InsertPerson(pBuffer, pAux);
                printf("Funcionou");
                break;
            case 2:
                break;
        }
    }
    free(pBuffer);
    free(pAux);
    return 0;
}

void InsertPerson(void *pBuffer, void *pAux){
    void *personInfo = NULL;
    personInfo = malloc(NOME + IDADE + TELEFONE + P_AUX + P_AUX);

    int *pCont = *(int*)pAux;
    void *personInfoAux = NULL;

    if(personInfo != NULL){
        printf("Digite as iformacoes: \n");
        printf("Nome> ");
        scanf("%s", (char*)personInfo);
        getchar();
        printf("Idade> ");
        scanf("%d", &*(int*)(personInfo + NOME));
        getchar();
        printf("Telefone> ");
        scanf("%d", &*(int*)(personInfo + NOME + IDADE));

        *(void **)(personInfo + PROXPESSOA) = NULL;
        *(void **)(personInfo + ANTPESSOA) = NULL;

        if(*pCont == 0){
            *(void **)(pAux + LASTPERSON) = personInfo;
            *(void**)(pAux + FIRSTPERSON) = personInfo;
            *pCont += 1;

            return;
        }

        pBuffer = *(void **)(pAux + FIRSTPERSON);

        while(pBuffer != NULL){
            if(strcmp((char*)personInfo, (char*)pBuffer) < 0){
                
            }
        }
    }
}