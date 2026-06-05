#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/livro.h"

Livro* criarLivro(int codigo, char titulo[], char autor[], int ano, int quantidadeTotal) {
    Livro* novo = (Livro*) malloc(sizeof(Livro));
    if (novo == NULL) {
        printf("Erro: falha ao alocar memoria para o livro.\n");
        return NULL;
    }

    novo->codigo               = codigo;
    novo->ano                  = ano;
    novo->quantidadeTotal      = quantidadeTotal;
    novo->quantidadeDisponivel = quantidadeTotal;

    strncpy(novo->titulo, titulo, sizeof(novo->titulo) - 1);
    novo->titulo[sizeof(novo->titulo) - 1] = '\0';

    strncpy(novo->autor, autor, sizeof(novo->autor) - 1);
    novo->autor[sizeof(novo->autor) - 1] = '\0';

    return novo;
}

void exibirLivro(Livro* livro) {
    if (livro == NULL) {
        printf("Erro: livro invalido.\n");
        return;
    }
    printf("------------------------------\n");
    printf("Codigo    : %d\n",  livro->codigo);
    printf("Titulo    : %s\n",  livro->titulo);
    printf("Autor     : %s\n",  livro->autor);
    printf("Ano       : %d\n",  livro->ano);
    printf("Total     : %d\n",  livro->quantidadeTotal);
    printf("Disponivel: %d\n",  livro->quantidadeDisponivel);
    printf("------------------------------\n");
}

int obterCodigoLivro(Livro* livro) {
    if (livro == NULL) return -1;
    return livro->codigo;
}

int obterQuantidadeDisponivel(Livro* livro) {
    if (livro == NULL) return 0;
    return livro->quantidadeDisponivel;
}

void emprestarExemplar(Livro* livro) {
    if (livro == NULL) return;

    if (livro->quantidadeDisponivel > 0) {
        livro->quantidadeDisponivel--;
    } else {
        printf("Aviso: nenhum exemplar disponivel para emprestimo.\n");
    }
}

void devolverExemplar(Livro* livro) {
    if (livro == NULL) return;

    if (livro->quantidadeDisponivel < livro->quantidadeTotal) {
        livro->quantidadeDisponivel++;
    } else {
        printf("Aviso: todos os exemplares ja estao disponiveis.\n");
    }
}