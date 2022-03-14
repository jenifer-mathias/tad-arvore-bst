#include <iostream>

using namespace std;

class ArvoreBST {
private:
    No* raiz;

public:
    ArvoreBST() {
        raiz = nullptr;
    }

    void insereElemento(int chave) {
        if (raiz == nullptr)                                   /** verifica se árvore está vazia */
            raiz = new No(chave);                              /** cria um novo nó */
        else insereAux(raiz, chave);
    }

    void insereAux(No* no, int chave) {
        if (chave < no->getChave()) {                           /** se for menor, insere a esquerda */
            if (no->getEsq() == nullptr) {                      /** verifica se a esquerda está nula */
                No *novo_no = new No(chave);
                no->setEsq(novo_no);                            /** seta o novo nó à esquerda */
            } else {
                insereAux(no->getEsq(), chave);                 /** senão, continua percorrendo recursivamente */
            }
        } else if (chave > no->getChave()) {                    /** se for maior, insere a direita */
            if (no->getDir() == nullptr) {                      /** verifica se a direita está nula */
                No *novo_no = new No(chave);
                no->setDir(novo_no);                            /** seta o novo nó à direita */
            } else {
                insereAux(no->getDir(), chave);                 /** senão, continua percorrendo recursivamente */
            }
        }                             /** se for igual, não vai inserir, pois não pode existir 2 chaves iguais */
    }

    No *getRaiz() {
        return raiz;
    }

    void imprimeEmOrdem(No *no) {
        if (no != nullptr) {
            imprimeEmOrdem(no->getEsq());
            cout << no->getChave() << " ";
            imprimeEmOrdem(no->getDir());
        }
    }

    void imprimePreOrdem(No *no) {
        if (no != nullptr) {
            cout << no->getChave() << " ";
            imprimePreOrdem(no->getEsq());
            imprimePreOrdem(no->getDir());
        }
    }

    void imprimePosOrdem(No *no) {
        if (no != nullptr) {
            imprimePosOrdem(no->getEsq());
            imprimePosOrdem(no->getDir());
            cout << no->getChave() << " ";
        }
    }

    No *pesquisaElemento(No* no, int chave) {
        if (no == nullptr || no->getChave() == chave) return no;                     /** elemento não encontrado */
        if (no->getChave() == chave)
            return no;                            /** se o elemento a ser procurado for a raiz, retorna ele mesmo */
        if (no->getChave() > chave) {                         /** se o elemento a ser procurado maior que a chave */
            return pesquisaElemento(no->getEsq(), chave);       /** pesquisa o elemento a partir do lado esquerdo */
        } else {
            return pesquisaElemento(no->getDir(), chave);        /** pesquisa o elemento a partir do lado direito */
        }
    }

    int contaNos(No* no) {
        if (no == nullptr) return 0;
        else return (1 + contaNos(no->getEsq()) + contaNos(no->getDir()));
    }

    int imprimeAlturaArvore(No *no) {
        if(no == nullptr) return -1;                                                                 /** árvore vazia */
        else {
            if(no->getEsq() == nullptr && no->getDir() == nullptr) return 0;  /** árvore com altura zero, pois só tem um elemento */
            else {
                if (imprimeAlturaArvore(no->getEsq()) > imprimeAlturaArvore(no->getDir()))  /** Valida maior quantidade de nós para saber a altura */
                    return ( 1 + imprimeAlturaArvore(no->getEsq()) );
                else
                    return ( 1 + imprimeAlturaArvore(no->getDir()) );
            }
        }
    }

    void contaFolhas(No *no) {

    }

    void valorMin(No* no) {

    }

    void valorMax(No* no) {

    }

    void remove(No* no, int chave) {

    }
};