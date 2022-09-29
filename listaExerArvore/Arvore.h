typedef struct NO* ArvBin;

ArvBin* CriaArvore();
void LiberaArvore(ArvBin* raiz);
void LiberaNO(struct NO* no);
int Vazia(ArvBin* raiz);
int Altura(ArvBin* raiz);
int TotalNOS(ArvBin* raiz);
void PosOrdem(ArvBin* raiz);
void EmOrdem(ArvBin* raiz);
void PreOrdem(ArvBin* raiz);