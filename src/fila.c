//
// Created by natha on 25/09/2025.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>

#include "forma.h"
#include "fila.h"

// Definição completa do nó
typedef struct Elemento {
    Pacote form; // O Pacote (Forma) armazenado
    struct Elemento* prox;
}Elemento;

typedef Elemento* pont;

// Definição da estrutura principal da fila
typedef struct {
    int tamanho;
    pont inicio; // Ínicio da fila (para remoção)
    pont fim;    // Fim da fila (para inserção)
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
    nova->prox = NULL; // Novo  elemento sempre vai para o fim

    if (filavazia(f)) {
        FILA->inicio = nova;
    }else {
        FILA->fim->prox = nova;
    }
    FILA->fim = nova; // O novo nó se torna o fim
    FILA->tamanho++;
}

void removerFila(Fila f) {
    fila* FILA = (fila*)f;
    if (filavazia(f)) {
        // Erro fatal, tentando remover de fila vazia
        printf("Fila vazia!\n");
        exit(1);
    }
    pont elemInicio = FILA->inicio;
    FILA->inicio = FILA->inicio->prox; // Atualiza o ínicio para o próximo nó

    if (filavazia(f)) {
        FILA->fim = NULL; // Se ficou vazia, o fim também deve ser NULL
    }

    FILA->tamanho--;

    // Note: O Pacote (form) NÃO é liberado aqui, pois a função 'liberarFila'
    // ou a lógica de consumo é responsável por isso. Apenas o nó é liberado
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

bool filavazia(Fila f) {
    fila* FILA = (fila*)f;
    return FILA->inicio == NULL ? true : false;
}

int getNumeroElementosFila(Fila f) {
    fila* FILA = (fila*)f;
    return FILA->tamanho;
}

void liberarFila(Fila f) {
    fila* FILA = (fila*)f;

    pont atual = FILA->inicio;
    pont proximo;

    // Percorre a fila, liberando Pacote e depois o nó
    while (atual != NULL) {
        proximo = atual->prox;

        if (atual->form != NULL) {
            liberarForma(atual->form);
        }

        free(atual); // Libera o nó (Elemento)

        atual = proximo;
    }

    // Apenas por segurança, embora free(FILA) elimine a struct
    FILA->inicio = NULL;
    FILA->fim = NULL;
    FILA->tamanho = 0;

    free(FILA); // Libera a struct principal da fila
}