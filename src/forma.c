//
// Created by natha on 15/10/2025.
//
#include "geo.h"
#include "forma.h"

#include <stdio.h>
#include <stdlib.h>


typedef struct pacote{
    Forma form;
    TipoForma tipo;
};

Pacote CriarPacote(Forma g,TipoForma tipo) {
    Pacote p = (Pacote)malloc(sizeof(Pacote));
    if (p == NULL) {
        printf("Erro ao alocar memoria!\n");
        exit(1);
    }
    p->form = g;
    p->tipo = tipo;

    return p;
}

Forma getDadosForma(Pacote p) {
    return p ? p->form: NULL;

}

TipoForma getTipoForma(Pacote p) {
    return p ? p->tipo: -1;

}

void liberarForma(Pacote p) {
    free(p);
}