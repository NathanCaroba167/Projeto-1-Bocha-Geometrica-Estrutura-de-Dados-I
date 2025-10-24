//
// Created by natha on 10/10/2025.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>

#include "forma.h"
#include "pilha.h"
#include "fila.h"
#include "geo.h"
#include "txt.h"
#include "carregador.h"

typedef struct {
    int id;
    Pilha p;
}carregador;

Carregador CriarCarregador(int id) {
    carregador* cr = (carregador*)malloc(sizeof(carregador));

    if (cr == NULL) {
        printf("Erro ao alocar memória ao criarCarregador!\n");

        perror("Motivo do erro");
        exit(1);
    }

    cr->id = id;
    cr->p = iniciarPilha();
    return cr;
}

int getIDCarregador(Carregador cr) {
    return ((carregador*)cr)->id;
}

Pacote getPrimeiraFormaCarregador(Carregador cr) {
    carregador* carr = (carregador*)cr;
    return getPrimeiraFormaPilha(carr->p);
}

Pilha getPilhaCarregador(Carregador cr) {
    return ((carregador*)cr)->p;
}

void carregarCarregador(Arquivo txt, Carregador cr, Fila chao) {
    carregador* carr = (carregador*)cr;
    Pacote p = getPrimeiraFormaFila(chao);
    empilharPilha(carr->p, p);
    reportarForma(txt,p);
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