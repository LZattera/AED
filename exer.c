#include<stdio.h>
#define MAX 5

int QuickSort(int data[MAX], int left, int rigth);

int QuickSort(int data[MAX], int left, int rigth){
    int tmp, pivo, i = left, j = rigth;
    pivo = (data[left+rigth/2]);//pegar o numero que esta no meio do vetor
    do{
        while(data[i]<pivo)//se o dado que esta no inicio do vetor for menor que o pivo
            i++;//o i que varre o vetor anda para direita
        while(data[j]>pivo)//se o dado q esta no final do vetor for maior que o vetor
            j--;//o j que varre o vetor anda para a esquerda
        if(i<=j){//SWAP troca os elemntos de lugar
            tmp = data[i];
            data[i] = data[j];
            data[j] = tmp;
            i++;
            j--;   
        }
    }while(i<=j);
    if(left < j)
        QuickSort(data, left, j);
    if(i < rigth)
        QuickSort(data, i, rigth);
}
int main(){
    int data[MAX] = {1,3,5,4,2};

    return 0;
}