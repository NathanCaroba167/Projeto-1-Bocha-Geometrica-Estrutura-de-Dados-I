//
// Created by natha on 25/09/2025.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>

#include "forma.h"
#include "pilha.h"

typedef struct Elemento {
    Pacote form;
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
        printf("Erro ao alocar memória ao iniciarPilha!\n");

        perror("Motivo do erro");
        exit(1);
    }
    p->topo = NULL;
    p->tamanho = 0;
    return p;
}

void empilharPilha(Pilha p, Pacote g) {
    pilha* PILHA = (pilha*)p;
    pont nova = (Elemento*) malloc(sizeof(Elemento));
    if (nova == NULL) {
        printf("Erro ao alocar memória ao criar novo elemento na pilha!\n");

        perror("Motivo do erro");
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
        printf("Pilha vazia!\n");
        return;
    }
    pont elemTopo = PILHA->topo;

    PILHA->topo = PILHA->topo->prox;
    PILHA->tamanho--;
    free(elemTopo);
}

Pacote getPrimeiraFormaPilha(Pilha p) {
    pilha* PILHA = (pilha*)p;
    if (pilhavazia(p)) {
        printf("Pilha vazia!\n");
        return NULL;
    }else {
        return PILHA->topo->form;
    }
}

bool pilhavazia(Pilha p) {
    pilha* PILHA = (pilha*)p;
    return PILHA->topo == NULL ? true : false;
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
