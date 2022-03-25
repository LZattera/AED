/*Ler um conjunto de numeros reais, armazenando-o em vetor e calcular o quadrado das ´
componentes deste vetor, armazenando o resultado em outro vetor. Os conjuntos temˆ
10 elementos cada. Imprimir todos os conjuntos.
*/
#include<stdio.h>
int main(int argc, char const *argv[])
{
    float vetor1[9], vetor2[9];//vetor2 tem o resultado da conta
    int i;
    //Lendo valores
    printf("Digite os valores do conjunto:\n");
    for(i=0; i<=9;i++)
        scanf("%f", &vetor1[i]);
    
    //Fazendo o quadrado dos elementos do vetor1
    for(i=0; i<=9;i++)
        vetor2[i] = vetor1[i] * vetor1[i];

    //Imprimindo os valores dos conjuntos
    printf("O quadrado do vetor inserido eh:\n");
    for(i=0;i<=9;i++)
        printf("%.1f\n", vetor2[i]);
        
    return 0;
}
