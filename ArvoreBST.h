/** ******************************************************************
 TAD Árvore BST
 Estrutura de Dados II

 GRUPO

 Nome: Gabriela Lopes Francisco
 TIA: 31744591

 Nome: Giulia Barbieri Quagliano
 TIA: 42013070

 Nome: Jenifer Mathias dos Santos
 TIA: 32092946

 Nome: Lucas Martins de Souza
 TIA: 31943187
****************************************************************** */

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

    bool removeElemento(int chave);
};
