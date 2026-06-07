#include <stdio.h>
#include <stdlib.h>
#include "include/fila.h"

int filaVazia(Fila* fila) {
    if (fila -> inicio == NULL) {
        return 1;
    } else {
        return 0;
    }
}

void exibirReservas(Fila* fila) {
    if (filaVazia(fila) == 1) {
        printf("Nenhum usuário na fila de espera.\n");
        return;
    }

    NoFila *aux = fila -> inicio;

    while (aux != NULL)
    {
        printf("O usuário %s: %d\n", aux -> reserva.nomeUsuario, aux -> reserva.codigoLivro);
        aux = aux -> proximo;
    }
}

Fila* criarFila() {
    Fila *fila = (Fila*) malloc(sizeof(Fila));
    if (fila != NULL){
        fila -> inicio = NULL;
        fila -> fim = NULL;
    }
    return fila;
}

void enfileirarReserva(Fila* fila, Reserva reserva) {
    NoFila *new = (NoFila*) malloc(sizeof(NoFila));
    if (new != NULL) {
        new -> reserva = reserva;
        new -> proximo = NULL;

        if (filaVazia(fila) == 0) {
            fila -> fim -> proximo = new;
            fila -> fim = new;
        } else {
            fila -> inicio = new;
            fila -> fim = new;
        }
        fila -> quantidade++;
    }
}

Reserva desenfileirarReserva(Fila* fila) {
    Reserva reservaRemovida;
    if (filaVazia(fila) == 1) {
        printf("Nenhum usuário na fila de espera.\n");
        reservaRemovida.codigoLivro = -1;
    } else {
        NoFila *aux = fila -> inicio;
        reservaRemovida = aux -> reserva;

        fila -> inicio = fila -> inicio -> proximo;

        if (fila -> inicio == NULL) {
            fila -> fim = NULL;
        }
        free(aux);
        aux = NULL;
        fila -> quantidade--;
    }
    return reservaRemovida;
}