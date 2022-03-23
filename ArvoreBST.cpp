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

No *encontraNoSucessor(No *apaga) {                  /** O parametro é a referencia para o No que deseja-se apagar */
    No *paidosucessor = apaga;
    No *sucessor = apaga;
    No *atual = apaga->getDir();                                                /** vai para a subarvore a direita */

    while (atual != nullptr) {                                      /**  enquanto nao chegar no no mais a esquerda */
        paidosucessor = sucessor;
        sucessor = atual;
        atual = atual->getEsq();                                                       /** caminha para a esquerda */
        /** (Explicação A) */
    }
    if (sucessor != apaga->getDir()) {      /** se sucessor nao é o filho a direita do nó que deverá ser eliminado */
        paidosucessor->setEsq(sucessor->getDir());    /** pai herda os filhos do sucessor que sempre será à direita */
        sucessor->setDir(apaga->getDir());                    /** guardando a referência à direita do sucessor para */
    }                                                            /** quando ele assumir a posição correta na árvore */
    /** (Explicação B) */
    return sucessor;
}

/** Explicação A
// *********************************************************************************
// quando sair do while "sucessor" sera o nó mais à esquerda da subarvore à direita
// "paidosucessor" sera o pai de sucessor e "apaga" o nó que devera ser eliminado
// *********************************************************************************/

/** Explicação B
// *********************************************************************************
// lembrando que o sucessor nunca poderá ter filhos a esquerda, pois, ele sempre será
// o nó mais à esquerda da subarvore à direita do nó "apaga".
// lembrando também que sucessor sempre será o filho à esquerda do pai
// *********************************************************************************/


bool ArvoreBST::removeElemento(int chave) {
    if (raiz == nullptr) return false;                                                      /** árvore está vazia */
    No *atual = raiz;
    No *pai = raiz;
    bool temFilhoEsq = true;                                               /** ****** Buscando o valor ********** */
    while (atual->getChave() != chave) {                                       /** enquanto nao encontrar a chave */
        pai = atual;
        if (chave < atual->getChave()) {                                                /** caminha para esquerda */
            atual = atual->getEsq();
            temFilhoEsq = true;
        } else {                                                                         /** caminha para direita */
            atual = atual->getDir();
            temFilhoEsq = false;
        }
        if (atual == nullptr) return false;                           /** encontrou uma folha e não achou a chave */
    }

    /** **************************************************************
    // se chegou aqui quer dizer que encontrou a chave na árvore
    // "atual": contém a referência ao nó a ser eliminado
    // "pai": contem a referência para o pai do nó a ser eliminado
    // "temFilhoEsq": verdadeiro se atual é filho a esquerda do pai
    // ***************************************************************/

    if (atual->getEsq() == nullptr && atual->getDir() == nullptr) {
    /** Se é uma folha, basta eliminá-lo e fazer o ptr do pai receber nullptr */
        if (atual == raiz) raiz = nullptr;
        else if (temFilhoEsq)
            pai->setEsq(nullptr);
        else
            pai->setDir(nullptr);                                                                /** apaga o nó */
    }

    else if (atual->getDir() == nullptr) {
    /** Se é pai e não possui um filho a direita, substitui pela subarvore a esquerda */
        if (atual == raiz) raiz = atual->getEsq();
        else if (temFilhoEsq) pai->setEsq(atual->getEsq());                      /** se for filho a esquerda do pai */
        else pai->setDir(atual->getEsq());                                        /** se for filho a direita do pai */
    }

    else if (atual->getEsq() == nullptr) {
    /** Se é pai e não possui um filho à esquerda, substitui pela subarvore à direita */
        if (atual == raiz) raiz = atual->getDir();
        else if (temFilhoEsq) pai->setEsq(atual->getDir());                      /** se for filho à esquerda do pai */
        else pai->setDir(atual->getDir());                                        /** se for filho à direita do pai */

    } else {                                                                       /** Se possui filhos à esq e dir */
        No *sucessor = encontraNoSucessor(atual);
        /** Usando o metodo sucessor para encontrar o no mais a esquerda da subarvore a direita (menor dos maiores) */
        if (atual == raiz) raiz = sucessor;
        else if (temFilhoEsq) pai->setEsq(sucessor);                             /** se for filho à esquerda do pai */
        else pai->setDir(sucessor);                                               /** se for filho à direita do pai */
        sucessor->setEsq(atual->getEsq());                /** acertando os ponteiros esquerda e direita do sucessor */
    }
    return true;
}



