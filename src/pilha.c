//
// Created by natha on 25/09/2025.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

typedef struct Elemento {
    Forma form;
    struct Elemento* prox;
}Elemento;

typedef Elemento* pont;

typedef struct Pilha {
    int tamanho;
    pont topo;
}pilha;

Pilha iniciarPilha() {
    pilha* p = (pilha*) malloc(sizeof(pilha));
    if (p == NULL) {
        printf("Erro ao alocar memoria!");
        exit(1);
    }
    p->topo = NULL;
    p->tamanho = 0;
    return p;
}

void empilharPilha(Pilha p, Forma g) {
    pilha* PILHA = (pilha*)p;
    pont nova = (Elemento*) malloc(sizeof(Elemento));
    if (nova == NULL) {
        printf("Erro ao alocar memoria!");
        exit(1);
    }
    nova->form = g;
    nova->prox = PILHA->topo;
    PILHA->topo = nova;
    PILHA->tamanho++;
}

void desempilharPilha(Pilha p) {
    pilha* PILHA = (pilha*)p;
    if (pilhavazia(p)) {
        printf("Pilha vazia!");
        exit(1);
    }
    pont elemTopo = PILHA->topo;

    PILHA->topo = PILHA->topo->prox;
    PILHA->tamanho--;
    free(elemTopo -> form);
    free(elemTopo);
}

Forma getPrimeiraFormaPilha(Pilha p) {
    pilha* PILHA = (pilha*)p;
    if (pilhavazia(p)) {
        printf("Pilha vazia!");
        return NULL;
    }else {
        return PILHA->topo->form;
    }
}

int pilhavazia(Pilha p) {
    pilha* PILHA = (pilha*)p;
    return PILHA->topo == NULL ? 1 : 0;
}

int getNumeroElementosPilha(Pilha p) {
    pilha* PILHA = (pilha*)p;
    return PILHA->tamanho;
}

void liberarPilha(Pilha p) {
    pilha* PILHA = (pilha*)p;
    pont elemTopo = PILHA->topo;
    while (!pilhavazia(p)) {
        pont proxTopo = elemTopo->prox;
        free(elemTopo);
        elemTopo = proxTopo;
    }
    PILHA->topo = NULL;
    PILHA->tamanho = 0;
    free(PILHA);
}
