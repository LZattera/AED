/*
1- Implementar os algoritmos de ordenação Insertion Sort, Selection Sort, Quick Sort e Merge Sort.
2- O programa deve solicitar o tamanho do vetor de números (n) que será ordenado = OK
3- O programa deve preencher um vetor de tamanho n com números aleatórios. Usar srand(time(NULL)); no inicio do programa. - OK
4- Faça um código que verifica se o resultado dado por cada algoritmo de ordenação está correto.
5- Use a melhor lib (defina a melhor no item 7) para calcular quanto tempo cada algoritmo de ordenação levou para terminar: https://levelup.gitconnected.com/8-ways-to-measure-execution-time-in-c-c-48634458d0f9
6- No 1:1 vou perguntar sobre questões de desempenho relacionadas a esse exercício, então pense sobre desempenho, otimizações, avaliação de tempo, complexidade, hardware, etc
7- Faça teste de leaks de memória.
8-Termine a implementação da agenda que utiliza árvore. Implemente AVL e rubro negra. O user pode escolher qual algoritmo usar.
*/
#include<stdio.h>
#include<stdlib.h>//necessary for srand() and rand()
#include<time.h>//necessary for time()

int* QuickSort(int *data, int left, int right);//NEED ATENTION

int* QuickSort(int *data, int left, int right){
    int tmp, i = left, j = right, pivot;
    //Segmentation fault 
    pivot = data[(left + right)/2];
    do{
        while(data[i] < i)
            i++;
        while(data[j] > j)
            j--;
        if(i<=j){
            tmp = data[i];
            data[i] = data[j];
            data[j] = tmp;
            i++;
            j--;
        }
    }while(i<=j);
    if(left < j)
        QuickSort(data, left, j);
    if(right > i)
        QuickSort(data, i, right);
    return data;
}
int main(){
    int tamVetor, *data, i, op;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamVetor);
    srand(time(NULL));

    data = malloc(sizeof(int)*tamVetor);

    if(data){//insert data through srand function
        for(i = 0; i<tamVetor; i++){
            *(data+i) = rand() % 100;
        }
    }

    // printing the data from the array without ordering
    for(i = 0; i < tamVetor; i++){
        printf("%d : %d\n", (i+1), *(data+i));
    }

    //Sorting Algorithms
    int *quickSortResult  = QuickSort(data, 0, tamVetor);  
    printf("ordenacao QuickSort:");
    for(i = 0; i < tamVetor; i++){
        printf("%d : %d\n", (i+1), *(quickSortResult+i));
    }
    
    return 0;
}