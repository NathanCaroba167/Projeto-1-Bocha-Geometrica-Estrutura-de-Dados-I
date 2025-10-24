//
// Created by natha on 25/09/2025.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "forma.h"
#include "fila.h"

typedef struct Elemento {
    Pacote form;
    struct Elemento* prox;
}Elemento;

typedef Elemento* pont;

typedef struct {
    int tamanho;
    pont inicio;
    pont fim;
}fila;

Fila iniciarFila() {
    fila* f = (fila*) malloc(sizeof(fila));
    if (f == NULL) {
        printf("Erro ao alocar memória ao iniciarFila!\n");

        perror("Motivo do erro");
        exit(1);
    }
    f->inicio = NULL;
    f->fim = NULL;
    f->tamanho = 0;
    return f;
}

void inserirFila(Fila f, Pacote p) {
    fila* FILA = (fila*)f;
    pont nova = (Elemento*) malloc(sizeof(Elemento));
    if (nova == NULL) {
        printf("Erro ao alocar memória ao criar novo elemento na fila!\n");

        perror("Motivo do erro");
        exit(1);
    }
    nova->form = p;
    nova->prox = NULL;

    if (filavazia(f)) {
        FILA->inicio = nova;
    }else {
        FILA->fim->prox = nova;
    }
    FILA->fim = nova;
    FILA->tamanho++;
}

void removerFila(Fila f) {
    fila* FILA = (fila*)f;
    if (filavazia(f)) {
        printf("Fila vazia!\n");
        exit(1);
    }
    pont elemInicio = FILA->inicio;
    FILA->inicio = FILA->inicio->prox;

    if (filavazia(f)) {
        FILA->fim = NULL;
    }

    FILA->tamanho--;
    free(elemInicio -> form);
    free(elemInicio);
}

Pacote getPrimeiraFormaFila(Fila f) {
    fila* FILA = (fila*)f;
    if (filavazia(f)) {
        printf("Fila vazia!\n");
        return NULL;
    }else {
        return FILA->inicio->form;
    }
}

Pacote getFormaElementoFila(pont p) {
    return p->form;
}

pont getPrimeiroElementoFila(Fila f) {
    fila* FILA = (fila*)f;
    return FILA->inicio;
}

pont getProximoElementoFila(pont p) {
    return p->prox;
}

int filavazia(Fila f) {
    fila* FILA = (fila*)f;
    return FILA->inicio == NULL ? 1 : 0;
}

int getNumeroElementosFila(Fila f) {
    fila* FILA = (fila*)f;
    return FILA->tamanho;
}

void liberarFila(Fila f) {
    fila* FILA = (fila*)f;
    pont elemInicio = FILA->inicio;
    while (!filavazia(f)) {
        pont proxInicio = elemInicio->prox;
        free(elemInicio);
        elemInicio = proxInicio;
    }
    FILA->inicio = NULL;
    FILA->fim = NULL;
    FILA->tamanho = 0;
    free(FILA);
}