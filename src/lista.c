#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    if (lista -> inicio == NULL) {
        return 1;
    } else {
        return 0;
    }
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
    if (listaVazia(lista) == 1) {
        printf("Nenhum emprestimo registrado no historico.\n");
        return;
    }

    printf("\n===== HISTORICO DE EMPRESTIMOS =====\n");

    NoLista* atual = lista->inicio;
    int contador = 1;

    while (atual != NULL) {
        printf("\n[%d]\n", contador++);
        printf("Usuario : %s\n", atual->emprestimo.nomeUsuario);
        printf("Codigo  : %d\n", atual->emprestimo.codigoLivro);
        printf("Titulo  : %s\n", atual->emprestimo.tituloLivro);
        atual = atual->proximo;
    }

    printf("\n====================================\n");
}

void removerEmprestimo(Lista* lista, Emprestimo emprestimo) {
    if (lista == NULL || listaVazia(lista) == 1) {
        printf("Nenhum livro para remover da lista de empréstimos.\n");
        return;
    }

    NoLista* atual = lista->inicio;
    NoLista* anterior = NULL;

    while (atual != NULL) {
        if (strcmp(atual->emprestimo.nomeUsuario, emprestimo.nomeUsuario) == 0 && 
            atual->emprestimo.codigoLivro == emprestimo.codigoLivro) {
            break;
        }
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == NULL) {
        printf("Registro de empréstimo não encontrado no histórico.\n");
        return;
    }

    if (anterior == NULL) {
        lista->inicio = atual->proximo;
    } else {
        anterior->proximo = atual->proximo;
    }

    free(atual);
    printf("Registro de empréstimo antigo removido do histórico ativo.\n");
}