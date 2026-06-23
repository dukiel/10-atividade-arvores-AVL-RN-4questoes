#ifndef ARVORE_H
#define ARVORE_H

#include <string>
using namespace std;

struct NoAVL {
    int chave;
    NoAVL *esq, *dir;
};

struct NoRN {
    int chave;
    char cor;
    NoRN *esq, *dir, *pai;
};

NoAVL* inserirAVL(NoAVL* r, int x);
NoAVL* removerAVL(NoAVL* r, int x);
bool ehAVL(NoAVL* r);
void imprimirAVL(NoAVL* r);

NoRN* inserirRN(NoRN* r, int x, string& caso);
void imprimirRN(NoRN* r);
int alturaPretaRaiz(NoRN* r);
bool propriedade5(NoRN* r);

#endif
