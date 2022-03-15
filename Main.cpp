#include <iostream>
#include "No.cpp"
#include "ArvoreBST.cpp"

using namespace std;

int main() {

    ArvoreBST arvoreBst;
    No *no;

    int opc;

    cout << "\n\n\n";
    cout << "\n---------------------------------------------------------------";
    cout << "\n                       TAD ÁRVORE BST";
    cout << "\n (esta árvore só aceita números inteiros maiores do que zero)";
    cout << "\n---------------------------------------------------------------";

    do {
        cout << "\n\n________________________   MENU   _____________________________\n";
        cout << "\n0 - sair";
        cout << "\n1 - inserir elemento";
        cout << "\n2 - remover elemento";
        cout << "\n3 - imprimir a árvore em ordem";
        cout << "\n4 - imprimir a árvore em pré-ordem";
        cout << "\n5 - imprimir a árvore em pós-ordem";
        cout << "\n6 - imprimir altura da árvore";
        cout << "\n7 - pesquisar elemento na árvore";
        cout << "\n8 - mostrar quantidade de nós";
        cout << "\n9 - mostrar quantidade de folhas";
        cout << "\n10 - consultar valor mínimo";
        cout << "\n11 - consultar valor máximo";
        cout << "\n\n_______________________________________________________________\n";

        cout << "\n\nInforme sua opção: ";
        cin >> opc;

        switch (opc) {

            /** Opção de saída */

            case 0: {
                cout << "\n Agradeço a participação!";
                cout << "\n\n ~~~~ Fim da execução! ~~~~\n\n";
                break;
            }

                /** Inserir elemento */

            case 1: {
                int item;
                cout << "Valor a ser inserido: ";
                cin >> item;
                // posteriormente colocar uma validação para quando o elemento já foi add.
                arvoreBst.insereElemento(item);
                cout << "\nElemento " << item << " adicionado com sucesso!";
                break;
            }

                /** Remover elemento */

            case 2: {
                int item;
                cout << "Valor a ser removido: ";
                cin >> item;
                if (arvoreBst.getRaiz() == nullptr) {
                    cout << "\n Elemento não encontrado!";
                    break;
                } else {
                    arvoreBst.removeElemento(arvoreBst.getRaiz(), item);
                    cout << "\nElemento " << item << " removido com sucesso!";
                    break;
                }
            }

                /** Imprimir a árvore em ordem */

            case 3: {
                if (arvoreBst.getRaiz() == nullptr) {
                    cout << "\n A árvore está vazia!";
                    break;
                } else {
                    arvoreBst.imprimeEmOrdem(arvoreBst.getRaiz());
                    break;
                }
            }

                /** Imprimir a a árvore em pré-ordem */

            case 4: {
                if (arvoreBst.getRaiz() == nullptr) {
                    cout << "\n A árvore está vazia!";
                    break;
                } else {
                    arvoreBst.imprimePreOrdem(arvoreBst.getRaiz());
                    break;
                }
            }

                /** Imprimir a a árvore em pós-ordem */

            case 5: {
                if (arvoreBst.getRaiz() == nullptr) {
                    cout << "\n A árvore está vazia!";
                    break;
                } else {
                    arvoreBst.imprimePosOrdem(arvoreBst.getRaiz());
                    break;
                }
            }

                /** Imprimir a altura da árvore */

            case 6: {
                int valor = arvoreBst.imprimeAlturaArvore(arvoreBst.getRaiz());
                if (valor == -1) {
                    cout << "\n A árvore está vazia!";
                    break;
                } else {
                    cout << "Altura da árvore: " << valor;
                    break;
                }
            }

                /** Pesquisar elemento na árvore */

            case 7: {
                int item;
                cout << "Elemento a ser procurado: ";
                cin >> item;
                No *elemento = arvoreBst.pesquisaElemento(arvoreBst.getRaiz(), item);
                if (elemento == nullptr) {
                    cout << "\n Elemento não encontrado!";
                    break;
                } else {
                    cout << "\nO elemento " << item << " está na árvore!";
                    break;
                }
            }

                /** Mostrar quantidade de nós */

            case 8: {
                cout << "Quantidade de nós na árvore: " << arvoreBst.contaNos(arvoreBst.getRaiz());
                break;
            }

                /** Mostrar quantidade de folhas */

            case 9: {
                cout << "Quantidade de folhas na árvore: " << arvoreBst.contaFolhas(arvoreBst.getRaiz());
                break;
            }

                /** Consultar valor mínimo */

            case 10: {
                cout << "Valor mínimo da árvore: " << arvoreBst.valorMinimo(arvoreBst.getRaiz());
                break;
            }

                /** Consultar valor máximo */

            case 11: {
                cout << "Valor máximo da árvore: " << arvoreBst.valorMaximo(arvoreBst.getRaiz());
                break;
            }

            default: {
                cout << "\n Opção inválida!";
                break;
            }
        }
    } while (opc != 0);
}



