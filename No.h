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

#ifndef TAD_ARVORE_BST_NO_H
#define TAD_ARVORE_BST_NO_H

class No {

private:
    No* esq;
    No* dir;

public:
    No(int);
    int  getChave();
    No* getEsq();
    No* getDir();
    void setEsq(No*);
    void setDir(No*);

    int chave;
};
#endif

