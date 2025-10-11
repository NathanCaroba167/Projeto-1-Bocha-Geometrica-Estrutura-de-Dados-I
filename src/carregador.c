//
// Created by natha on 10/10/2025.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "carregador.h"

typedef struct {
    int id;
    Pilha p;
}carregador;

Carregador CriarCarregador(int id) {
    carregador* cr = malloc(sizeof(carregador));

    if (cr == NULL) {
        printf("Erro ao alocar memoria!\n");
        exit(1);
    }

    cr->id = id;
    cr->p = iniciarPilha();
    return cr;
}

int getIDCarregador(Carregador cr) {
    return ((carregador*)cr)->id;
}

Forma getPrimeiraFormaCarregador(Carregador cr) {
    carregador* carr = (carregador*)cr;
    return getPrimeiraFormaPilha(carr->p);
}

Pilha getPilhaCarregador(Carregador cr) {
    return ((carregador*)cr)->p;
}

void carregarCarregador(Carregador cr, Fila chao) {
    carregador* carr = (carregador*)cr;
    empilharPilha(carr->p, getPrimeiraFormaFila(chao));
    removerFila(chao);
}

bool carregadorvazio(Carregador cr) {
    carregador* carr = (carregador*)cr;
    return pilhavazia(carr->p);
}

void eliminarCarregador(Carregador cr) {
    carregador* carr = ((carregador*)cr);
    liberarPilha(carr->p);
    free(carr);
}