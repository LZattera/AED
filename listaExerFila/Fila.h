struct aluno{
    int matricula;
    char nome[30];
    float n1, n2, n3;
};
typedef struct fila Fila;//nó descritor

Fila* CriaFila(); 
void LiberaFila(Fila* fi);
int TamanhoFila(Fila* fi);
int FilaVazia(Fila* fi);
int RemoveFila(Fila* fi);
int InsereFila(Fila* fi);
int ConsultaFila(Fila* fi);
int ImprimiFila(Fila* fi);
struct aluno InsereDados();