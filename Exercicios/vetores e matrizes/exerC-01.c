/*Faça um programa que possua um vetor denominado A que armazene 6 numeros intei- ´
ros. O programa deve executar os seguintes passos:
(a) Atribua os seguintes valores a esse vetor: 1, 0, 5, -2, -5, 7.
(b) Armazene em uma variavel inteira (simples) a soma entre os valores das posic¸ ´ oes ˜
A[0], A[1] e A[5] do vetor e mostre na tela esta soma.
(c) Modifique o vetor na posiçao 4, atribuindo a esta posição o valor 100. ˜
(d) Mostre na tela cada valor do vetor A, um em cada linha.*/

#include<stdio.h>
int main(int argc, char const *argv[])
{
    int A[5];

    /*ATRIBUIÇÃO DE VALORES*/
    A[0]= 1;
    A[1]= 0;
    A[2]= 5;
    A[3]= -2;
    A[4]= -5;
    A[5]= 7;

    /*SOMA DOS VALORES DAS POSIÇÕES 0, 1 E 5*/
    int soma;
    soma = A[0]+A[1]+A[5];
    printf("Soma das posicoes 0, 1 e 5: %d\n", soma);

    /*ATRIBUIR UM VALOR DIFERENTE PARA A POSIÇÃO 4*/
    printf("Valor da posicao 4: %d\n", A[4]);
    printf("Novo valor da posicao 4: %d\n", A[4]=100);

    /*MOSTRAR NA TELA OS VALORES DO VETOR, CADA UM EM UMA LINHA*/
    int i, pos=0;
    for(i=0; i<=5; i++)
    {
        printf("%d :%d\n", pos, A[i]);
        //incremento da variavel pos
        pos++;
    }

    return 0;
}
