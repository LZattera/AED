/*1. Crie um programa que declare uma estrutura (registro) para o cadastro de alunos.
(a) Dever  ̃ao ser armazenados, para cada aluno: matr ́ıcula, sobrenome (apenas um) e
ano de nascimento.
(b) Ao in ́ıcio do programa, o usu  ́ario dever  ́a informar o n  ́umero de alunos que ser  ̃ao
armazenados
(c) O programa dever  ́a alocar dinamicamente a quantidade necess  ́aria de mem  ́oria
para armazenar os registros dos alunos.
(d) O programa dever  ́a pedir ao usu  ́ario que entre com as informac ̧  ̃oes dos alunos.
(e) Ao final, mostrar os dados armazenados e liberar a mem  ́oria alocada.*/
#include<stdio.h>
#include<stdlib.h>
struct aluno{
    char nome[20];
    char sobrenome[20];
    int matricula;
};
typedef struct aluno Aluno;
int main(){
    Aluno *al;
    int alunosArmazenados;
    printf("Digite quantos alunos serão armazenados: ");
    scanf("%d", &alunosArmazenados);
    //Alocando memória para a quant dita pelo usuario
    al = (Aluno*)malloc(alunosArmazenados * sizeof(Aluno));
    //inserindo informações 
    for(int i=0; i< alunosArmazenados; i++){
        printf("Nome: ");
        scanf("%s", al[i].nome);
        printf("Sobrenome: ");
        scanf("%s", al[i].sobrenome);
        printf("Matricula: ");
        scanf("%d", &al[i].matricula);
    }
    //imprimindo na tela alunos cadastrados
    printf("\n");
    printf("Alunos cadastrados\n");
    for(int i=0; i<alunosArmazenados; i++){
        printf("Nome: %s\n", al[i].nome);
        printf("Sobrenome: %s\n", al[i].sobrenome);
        printf("Matricula: %d\n", al[i].matricula);
    }
    //Liberando a memória alocada
    free(al);

    return 0;
}