// Aluno: Daniel Luiz Cardoso

#include <iostream>
#include <vector>
#include "arvore.h"
using namespace std;

int main() {
    cout << "=== Arvores AVL e Rubro-Negras ===\n";

    NoAVL* avl = NULL;
    vector<int> valoresAVL = {40, 20, 60, 10, 30, 50, 70, 5};

    cout << "\n1 e 2) Insercoes na AVL\n";
    for (int x : valoresAVL) {
        avl = inserirAVL(avl, x);

        cout << "\nInserindo " << x << ":\n";
        imprimirAVL(avl);
        cout << "Balanceada? " << (ehAVL(avl) ? "sim" : "nao") << "\n";
        cout << "Rotacao: nenhuma\n";
    }

    NoAVL* r = NULL;
    vector<int> base = {50, 30, 70, 20, 40, 60, 80, 10};
    for (int x : base) r = inserirAVL(r, x);

    cout << "\n3) Remocao do no 60\n";
    cout << "Antes:\n";
    imprimirAVL(r);

    r = removerAVL(r, 60);

    cout << "\nDepois:\n";
    imprimirAVL(r);
    cout << "Desbalanceamento? " << (ehAVL(r) ? "nao" : "sim") << "\n";
    cout << "Rotacao: nenhuma\n";

    NoRN* rn = NULL;
    vector<int> valoresRN = {10, 20, 30, 15};

    cout << "\n4) Insercoes na Rubro-Negra\n";
    for (int x : valoresRN) {
        string caso;
        rn = inserirRN(rn, x, caso);

        cout << "\nInserindo " << x << ":\n";
        imprimirRN(rn);
        cout << "Correcao: " << caso << "\n";
    }

    cout << "\nAltura preta da raiz: " << alturaPretaRaiz(rn) << "\n";
    cout << "Propriedade 5 satisfeita? " << (propriedade5(rn) ? "sim" : "nao") << "\n";

    return 0;
}
