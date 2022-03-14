#ifndef TAD_ARVORE_BST_NO_H
#define TAD_ARVORE_BST_NO_H

class No {

private:
    int chave;
    No* esq;
    No* dir;

public:
    No(int);
    int  getChave();
    No* getEsq();
    No* getDir();
    void setEsq(No*);
    void setDir(No*);
};
#endif

