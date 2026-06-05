#include <stdio.h>
#include <stdlib.h>
#include "include/lista.h"

Lista* criarLista() {
    Lista* lista = (Lista*) malloc(sizeof(Lista));
    if (lista == NULL) {
        printf("Erro: falha ao alocar memoria para a lista.\n");
        return NULL;
    }
    lista->inicio = NULL;
    return lista;
}

int listaVazia(Lista* lista) {
    if (lista == NULL) return 1;
    return (lista->inicio == NULL);
}

void inserirEmprestimo(Lista* lista, Emprestimo emprestimo) {
    if (lista == NULL) return;

    NoLista* novo = (NoLista*) malloc(sizeof(NoLista));
    if (novo == NULL) {
        printf("Erro: falha ao alocar memoria para o emprestimo.\n");
        return;
    }

    novo->emprestimo = emprestimo;
    novo->proximo    = lista->inicio;
    lista->inicio    = novo;
}

void listarEmprestimos(Lista* lista) {
    if (listaVazia(lista)) {
        printf("Nenhum emprestimo registrado no historico.\n");
        return;
    }

    printf("\n===== HISTORICO DE EMPRESTIMOS =====\n");

    NoLista* atual = lista->inicio;
    int contador = 1;

    while (atual != NULL) {
        printf("\n[%d]\n", contador++);
        printf("  Usuario : %s\n", atual->emprestimo.nomeUsuario);
        printf("  Codigo  : %d\n", atual->emprestimo.codigoLivro);
        printf("  Titulo  : %s\n", atual->emprestimo.tituloLivro);
        atual = atual->proximo;
    }

    printf("\n====================================\n");
}