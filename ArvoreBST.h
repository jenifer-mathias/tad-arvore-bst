using namespace std;

class ArvoreBST {

private:
    No* raiz;

public:
    ArvoreBST();
    void insereElemento(int chave);
    void insereAux(No* no, int chave);
    void imprimeEmOrdem(No* no);
    void imprimePreOrdem(No* no);
    void imprimePosOrdem(No* no);
    int imprimeAlturaArvore(No* no);
    No* pesquisaElemento(No* no, int chave);
    int contaNos(No* no);
    int contaFolhas(No* no);
    void valorMin(No* no);
    int valorMax(No* no);
    void removeElemento(No* no, int chave);
    No* getRaiz();
};
