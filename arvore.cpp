#include <iostream>
#include <algorithm>
#include <cmath>
#include "arvore.h"
using namespace std;

NoAVL* novoAVL(int x) {
    return new NoAVL{x, NULL, NULL};
}

NoRN* novoRN(int x) {
    return new NoRN{x, 'V', NULL, NULL, NULL};
}

int altura(NoAVL* r) {
    if (r == NULL) return 0;
    return 1 + max(altura(r->esq), altura(r->dir));
}

int fb(NoAVL* r) {
    if (r == NULL) return 0;
    return altura(r->esq) - altura(r->dir);
}

NoAVL* inserirAVL(NoAVL* r, int x) {
    if (r == NULL) return novoAVL(x);

    if (x < r->chave) r->esq = inserirAVL(r->esq, x);
    else if (x > r->chave) r->dir = inserirAVL(r->dir, x);

    return r;
}

NoAVL* removerAVL(NoAVL* r, int x) {
    if (r == NULL) return NULL;

    if (x < r->chave) r->esq = removerAVL(r->esq, x);
    else if (x > r->chave) r->dir = removerAVL(r->dir, x);
    else {
        if (r->esq == NULL) return r->dir;
        if (r->dir == NULL) return r->esq;

        NoAVL* aux = r->dir;
        while (aux->esq != NULL) aux = aux->esq;

        r->chave = aux->chave;
        r->dir = removerAVL(r->dir, aux->chave);
    }

    return r;
}

bool ehAVL(NoAVL* r) {
    if (r == NULL) return true;
    return abs(fb(r)) <= 1 && ehAVL(r->esq) && ehAVL(r->dir);
}

void imprimirAVLAux(NoAVL* r, string espaco, string lado) {
    if (r == NULL) return;

    cout << espaco << lado << r->chave << "(FB=" << fb(r) << ")\n";
    imprimirAVLAux(r->esq, espaco + "  ", "E->");
    imprimirAVLAux(r->dir, espaco + "  ", "D->");
}

void imprimirAVL(NoAVL* r) {
    imprimirAVLAux(r, "", "");
}

void rotacaoEsq(NoRN*& raiz, NoRN* x) {
    NoRN* y = x->dir;
    x->dir = y->esq;

    if (y->esq != NULL) y->esq->pai = x;
    y->pai = x->pai;

    if (x->pai == NULL) raiz = y;
    else if (x == x->pai->esq) x->pai->esq = y;
    else x->pai->dir = y;

    y->esq = x;
    x->pai = y;
}

void corrigirRN(NoRN*& raiz, NoRN* no, string& caso) {
    caso = "nenhuma";

    if (no == raiz || no->pai->cor == 'P') {
        raiz->cor = 'P';
        return;
    }

    NoRN* pai = no->pai;
    NoRN* avo = pai->pai;
    NoRN* tio = avo->esq;
    if (pai == avo->esq) tio = avo->dir;

    if (tio != NULL && tio->cor == 'V') {
        caso = "Caso 1 - recolorir";
        pai->cor = 'P';
        tio->cor = 'P';
        avo->cor = 'V';
    } else {
        caso = "Caso 3 - rotacao esquerda + recolorir";
        rotacaoEsq(raiz, avo);
        pai->cor = 'P';
        avo->cor = 'V';
    }

    raiz->cor = 'P';
}

NoRN* inserirRN(NoRN* raiz, int x, string& caso) {
    NoRN* novo = novoRN(x);
    NoRN* pai = NULL;
    NoRN* atual = raiz;

    while (atual != NULL) {
        pai = atual;
        if (x < atual->chave) atual = atual->esq;
        else atual = atual->dir;
    }

    novo->pai = pai;

    if (pai == NULL) raiz = novo;
    else if (x < pai->chave) pai->esq = novo;
    else pai->dir = novo;

    corrigirRN(raiz, novo, caso);
    return raiz;
}

void imprimirRNAux(NoRN* r, string espaco, string lado) {
    if (r == NULL) return;

    cout << espaco << lado << r->chave << "(" << r->cor << ")\n";
    imprimirRNAux(r->esq, espaco + "  ", "E->");
    imprimirRNAux(r->dir, espaco + "  ", "D->");
}

void imprimirRN(NoRN* r) {
    imprimirRNAux(r, "", "");
}

int contarPretos(NoRN* r) {
    if (r == NULL) return 1;

    int e = contarPretos(r->esq);
    int d = contarPretos(r->dir);

    if (e == -1 || d == -1 || e != d) return -1;
    if (r->cor == 'P') return e + 1;
    return e;
}

int alturaPretaRaiz(NoRN* r) {
    int total = contarPretos(r);
    if (r != NULL && r->cor == 'P') total--;
    return total;
}

bool propriedade5(NoRN* r) {
    return contarPretos(r) != -1;
}
