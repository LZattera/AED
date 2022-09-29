struct aluno{
    int matricula;
    char nome[30];
};
typedef struct elemento *Pilha;

Pilha* CriaPilha();
void LiberPilha(Pilha* pi);