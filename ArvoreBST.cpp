#include <iostream>
#include "No.h"
#include "ArvoreBST.h"

using namespace std;

ArvoreBST::ArvoreBST() {
    raiz = nullptr;
}

void ArvoreBST::insereElemento(int chave) {
    if (raiz == nullptr)                                   /** verifica se árvore está vazia */
        raiz = new No(chave);                              /** cria um novo nó */
    else insereAux(raiz, chave);
}

void ArvoreBST::insereAux(No *no, int chave) {
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

No *ArvoreBST::getRaiz() {
    return raiz;
}

void ArvoreBST::imprimeEmOrdem(No *no) {
    if (no != nullptr) {
        imprimeEmOrdem(no->getEsq());
        cout << no->getChave() << " ";
        imprimeEmOrdem(no->getDir());
    }
}

void ArvoreBST::imprimePreOrdem(No *no) {
    if (no != nullptr) {
        cout << no->getChave() << " ";
        imprimePreOrdem(no->getEsq());
        imprimePreOrdem(no->getDir());
    }
}

void ArvoreBST::imprimePosOrdem(No *no) {
    if (no != nullptr) {
        imprimePosOrdem(no->getEsq());
        imprimePosOrdem(no->getDir());
        cout << no->getChave() << " ";
    }
}

No *ArvoreBST::pesquisaElemento(No *no, int chave) {
    if (no == nullptr || no->getChave() == chave) return no;                           /** elemento não encontrado */
    if (no->getChave() == chave)
        return no;                                 /** se o elemento a ser procurado for a raiz, retorna ele mesmo */
    if (no->getChave() > chave) {                              /** se o elemento a ser procurado maior que a chave */
        return pesquisaElemento(no->getEsq(), chave);            /** pesquisa o elemento a partir do lado esquerdo */
    } else {
        return pesquisaElemento(no->getDir(), chave);             /** pesquisa o elemento a partir do lado direito */
    }
}

int ArvoreBST::imprimeAlturaArvore(No *no) {
    if (no == nullptr) return -1;                                                                 /** árvore vazia */
    else {
        if (no->getEsq() == nullptr && no->getDir() == nullptr)
            return 0;                                          /** árvore com altura zero, pois só tem um elemento */
        else {
            if (imprimeAlturaArvore(no->getEsq()) >
                imprimeAlturaArvore(no->getDir()))          /** Valida maior quantidade de nós para saber a altura */
                return (1 + imprimeAlturaArvore(no->getEsq()));
            else
                return (1 + imprimeAlturaArvore(no->getDir()));
        }
    }
}

int ArvoreBST::contaNos(No *no) {
    if (no == nullptr) return 0;                                                                    /** não há nós */
    else return (1 + contaNos(no->getEsq()) + contaNos(no->getDir()));                /** Valida a contagem de nós */
}

int ArvoreBST::contaFolhas(No *no) {
    if (no == nullptr) return 0;
    else if (no->getEsq() == nullptr && no->getDir() == nullptr)
        return 1;
    else
        return contaFolhas(no->getEsq()) + contaFolhas(no->getDir());
}

int ArvoreBST::valorMinimo(No *no) {
    if (no == nullptr) return 0;
    if (no->getEsq() == nullptr) return no->getChave();         /** se a árvore estiver vazia, retorna 0 elementos */
    else return valorMinimo(no->getEsq());               /** senão, continua percorrendo recursivamente à esquerda */
}

int ArvoreBST::valorMaximo(No *no) {
    if (no == nullptr) return 0;
    if (no->getDir() == nullptr) return no->getChave();         /** se a árvore estiver vazia, retorna 0 elementos */
    else return valorMaximo(no->getDir());                /** senão, continua percorrendo recursivamente à direita */
}

No *ArvoreBST::removeElemento(No *no, int chave) {
    /** árvore vazia */
    if (no == nullptr) return nullptr;

    /** pesquisa valor a ser removido */
    if (chave < no->getChave()) {
        no->setEsq(removeElemento(no->getEsq(), chave));
    } else if (chave > no->getChave())
        no->setDir(removeElemento(no->getDir(), chave));

    else {

        /** nó não possui filhos - remoção em folhas */
        if (no->getEsq() == nullptr && no->getDir() == nullptr) {
            no = nullptr;
        }

            /** nó sem filhos em uma duas subárvores */
            /** possui filhos à direita */
        else if (no->getEsq() == nullptr) {
            No *temp1 = no->getDir();
            delete no;
            return temp1;
        }
            /** possui filhos à esquerda */
        else if (no->getDir() == nullptr) {
            No *temp2 = no->getEsq();
            delete no;
            return temp2;
        }

        else {
            No *temp3 = reinterpret_cast<No *>(valorMinimo(no->getDir()));
            no->chave = temp3->getChave();
            no->setDir(removeElemento(no->getDir(), temp3->getChave()));
        }
    }
    return no;
}


