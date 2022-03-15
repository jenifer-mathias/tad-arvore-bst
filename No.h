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
    void setChave(int chave);

    int chave;
};
#endif

