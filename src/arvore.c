#include <stdio.h>
#include <stdlib.h>
#include "include/arvore.h"

Arvore* criarArvore() {
    Arvore* arvore = (Arvore*) malloc(sizeof(Arvore));

    if (arvore == NULL) {
        printf("Erro ao alocar memoria da arvore.\n");
        return NULL;
    }

    arvore->raiz = NULL;

    return arvore;
}

NoArvore* criarNo(Livro* livro) {
    NoArvore* novo = (NoArvore*) malloc(sizeof(NoArvore));

    if (novo == NULL) {
        printf("Erro ao alocar memoria do no.\n");
        return NULL;
    }

    novo->livro = livro;
    novo->esquerda = NULL;
    novo->direita = NULL;

    return novo;
}

void inserirLivroArvore(Arvore* arvore, Livro* livro) {
    if (arvore == NULL || livro == NULL) {
        return;
    }

    arvore->raiz = inserirNo(arvore->raiz, livro);
}

NoArvore* inserirNo(NoArvore* raiz, Livro* livro) {

    if (raiz == NULL) {
        return criarNo(livro);
    }

    if (livro->codigo < raiz->livro->codigo) {
        raiz->esquerda = inserirNo(raiz->esquerda, livro);
    }
    else if (livro->codigo > raiz->livro->codigo) {
        raiz->direita = inserirNo(raiz->direita, livro);
    }

    return raiz;
}

Livro* buscarLivroArvore(Arvore* arvore, int codigo) {

    if (arvore == NULL) {
        return NULL;
    }

    return buscarNo(arvore->raiz, codigo);
}

Livro* buscarNo(NoArvore* raiz, int codigo) {

    if (raiz == NULL) {
        return NULL;
    }

    if (codigo == raiz->livro->codigo) {
        return raiz->livro;
    }

    if (codigo < raiz->livro->codigo) {
        return buscarNo(raiz->esquerda, codigo);
    }

    return buscarNo(raiz->direita, codigo);
}

void listarLivrosEmOrdem(Arvore* arvore) {

    if (arvore == NULL) {
        return;
    }

    emOrdem(arvore->raiz);
}

void emOrdem(NoArvore* raiz) {

    if (raiz != NULL) {

        emOrdem(raiz->esquerda);

        printf("codigo: %d\n", raiz->livro->codigo);
        printf("titulo: %s\n", raiz->livro->titulo);
        printf("autor: %s\n", raiz->livro->autor);
        printf("ano: %d\n", raiz->livro->ano);
        printf("quantidade total: %d\n", raiz->livro->quantidadeTotal);
        printf("quantidade disponivel: %d\n\n",
               raiz->livro->quantidadeDisponivel);

        emOrdem(raiz->direita);
    }
}

void listarLivrosPreOrdem(Arvore* arvore) {

    if (arvore == NULL) {
        return;
    }

    preOrdem(arvore->raiz);
}

void preOrdem(NoArvore* raiz) {

    if (raiz != NULL) {

        printf("codigo: %d - titulo: %s\n",
               raiz->livro->codigo,
               raiz->livro->titulo);

        preOrdem(raiz->esquerda);
        preOrdem(raiz->direita);
    }
}

void listarLivrosPosOrdem(Arvore* arvore) {

    if (arvore == NULL) {
        return;
    }

    posOrdem(arvore->raiz);
}

void posOrdem(NoArvore* raiz) {

    if (raiz != NULL) {

        posOrdem(raiz->esquerda);
        posOrdem(raiz->direita);

        printf("codigo: %d - titulo: %s\n",
               raiz->livro->codigo,
               raiz->livro->titulo);
    }
}

int contarLivros(Arvore* arvore) {

    if (arvore == NULL) {
        return 0;
    }

    return contarNos(arvore->raiz);
}

int contarNos(NoArvore* raiz) {

    if (raiz == NULL) {
        return 0;
    }

    return 1 + contarNos(raiz->esquerda)
             + contarNos(raiz->direita);
}

int calcularAlturaArvore(Arvore* arvore) {

    if (arvore == NULL) {
        return -1;
    }

    return calcularAltura(arvore->raiz);
}

int calcularAltura(NoArvore* raiz) {

    if (raiz == NULL) {
        return -1;
    }

    int alturaEsquerda = calcularAltura(raiz->esquerda);
    int alturaDireita = calcularAltura(raiz->direita);

    if (alturaEsquerda > alturaDireita) {
        return alturaEsquerda + 1;
    }

    return alturaDireita + 1;
}