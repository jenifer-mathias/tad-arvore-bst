using namespace std;

class ArvoreBST {

private:
    No *raiz;

public:
    ArvoreBST();

    No *getRaiz();

    void insereElemento(int chave);

    void insereAux(No *no, int chave);

    void imprimeEmOrdem(No *no);

    void imprimePreOrdem(No *no);

    void imprimePosOrdem(No *no);

    int imprimeAlturaArvore(No *no);

    No *pesquisaElemento(No *no, int chave);

    int contaNos(No *no);

    int contaFolhas(No *no);

    int valorMinimo(No *no);

    int valorMaximo(No *no);

    No *removeElemento(No *no, int chave);
};
