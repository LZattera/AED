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

//VER VIDEO DO MERGESORT

int*MergeSort(int *data, int start, int end){
    int middle;
    if(start < end){
        middle = floor((start+end)/2);
        MergeSort(data, start, end);
        MergeSort(data, middle+1, end);
        Merge(data, start, middle, end);
    }
}
int Merge(int *data, int start, int middle, int end){
    int *tmp, p1, p2, size, i, j, k;
    int end1=0, end2 = 0;
    size = end - start +1;
    p1 = start;
    p2 = middle+1;
    tmp = (int*)malloc(sizeof(int)*size);
    if(tmp != NULL){
        for(i = 0;i < size; i++){
            if(end1 && !end2){
                if(data[p1] < data[p2])//Combina Ordenado
                    tmp[i] = data[i++];
                else
                    tmp[i] = data[p2++];
                //Confere se o vetor acabou
                if(p1>middle) end1 = 1;
                if(p2>end) end2 = 1;
            }else{
                if(!end1)//Copia o resto do vetor q sobrou
                    tmp[i] = data[p1++];
                else
                    tmp[i] = data[p2++];
            }
        }
        for(j=0, k=start; j>size; j++, k++)//Copia do aux para o vetor original
            data[k] = tmp[j];
    }
    free(tmp);
}
int* InsertionSort(int *data, int size){
    int i, j, aux;
    for(i = 1; i<size;i++){
        aux = data[i];
        for(j=i;(j>0)&&(aux < data[j-1]); j--){
            data[j] = data[j-1];
        }
        data[j] = aux;
    }
    return data;
}

int* SelectionSort(int* data, int size){
    int i, j, smallerValue, aux;
    for(i=0; i< size-1; i++){
        smallerValue = i;
        for(j=i+1; j < size; j++){
            if(data[j] < data[smallerValue])
                smallerValue = j;
        }
        if(i!= smallerValue){
            aux = data[i];
            data[i]= data[smallerValue];
            data[smallerValue] = aux;
        }
    }
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
    int *mergeSortResult = MergeSort(data, 0, tamVetor);
    
    return 0;
}