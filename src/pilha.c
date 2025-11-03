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

#include "fila.h"

typedef struct Elemento {
    Pacote form; // O Pacote (Forma) armazenado
    struct Elemento* prox;
}Elemento;

typedef Elemento* pont;

typedef struct Pilha {
    int tamanho;
    pont topo; // Topo da pilha (para inserção e remoção)
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
    // O novo elemento aponta para o topo anterior
    nova->prox = PILHA->topo;
    // O novo elemento se torna o novo topo
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

    // O topo avança para o próximo elemento
    PILHA->topo = PILHA->topo->prox;
    PILHA->tamanho--;

    // O Pacote (form) NÃO é liberado aqui; o nó é liberado
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
    pont atual = PILHA->topo;
    pont proximo;

    // Percorre a pilha, liberando Pacote e depois o nó
    while (atual != NULL) {
        proximo = atual->prox;

        if (atual->form != NULL) {
            liberarForma(atual->form);
        }

        free(atual); // Libera o nó (Elemento)

        atual = proximo;
    }

    // Limpa os campos e libera a struct principal
    PILHA->topo = NULL;
    PILHA->tamanho = 0;
    free(PILHA);
}
