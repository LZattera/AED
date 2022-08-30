#include<stdio.h>
#include<stdlib.h>

int Myrand();

int main(){
    int *p, *pAux, vSize, i, userNum;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &vSize);

    p=(int*)malloc(sizeof(int)*vSize);

    //inserindo valores no vetor
    for(i=0; i < vSize; i++){
        *p = Myrand();//não esta inserido nenhum numero aleatorio
        p=p+2;
    }
    p = p-(vSize*2);//voltar para o inicio do vetor

    //imprimindo o vetor
    for(i=0; i< vSize; i++){
        printf("%d \n", *p);
        p=p+2;
    }
    p = p-(vSize*2);

    //Solicitando um num pro usuario
    printf("Digite um numero inteiro: ");
    scanf("%d", &userNum);

    //procurando numero dito pelo usuario
    for(i=0; i < vSize; i++){
        if(*p == userNum){
            printf("Numero  encontrado\n");
            //remover numero do vetor -- Não esta funcioando
            *pAux = p+2;
            *p = *pAux;
            //realocando o vetor
            p = realloc(p, vSize-1);
        }else{
            //encontrar dois numeros que somados dão o userNum se encontrar tire os dois do vetor
            int auxValue, currentNum;
            for(i = 0; i<vSize; i++){
                auxValue = userNum - *p;//valor que falta para completar a soma 
                currentNum = *p;
                for(i = 0; i<vSize; i++){//procurando esse valor no vetor
                    if(*p == auxValue){
                        printf("%d e %d somados dao o valor %d", *p, currentNum, userNum);
                        //remove numero do vetor -- Não esta funcioando
                        pAux = p+2;// talvez não precise auxliar nessa parte
                        p = pAux;
                        //realocando o vetor
                        p = realloc(p, vSize-1);
                    }
                    p = p+2;//avançando no vetor
                }
                printf("Numero nao encontrado\n");
            }
        }
        p = p+2;
    }

    free(p);
    return 0;
}

int Myrand(){

    return (rand()%10);//um numero aletório entre 0 e 10
}