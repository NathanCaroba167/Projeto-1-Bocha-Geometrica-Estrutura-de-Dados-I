//
// Created by natha on 18/10/2025.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>

#include "forma.h"
#include "pilha.h"
#include "fila.h"
#include "texto.h"
#include "geo.h"
#include "carregador.h"
#include "disparador.h"
#include "estoque.h"

typedef struct {
    Disparador** disparadores;
    int quantidadeD;
    int capacidadeD;
}estoque_disparadores;

typedef struct {
    Carregador** carregadores;
    int quantidadeC;
    int capacidadeC;
}estoque_carregadores;

EstoqueD CriarEstoqueDisparadores(int capacidadeInicial) {
    estoque_disparadores* est = (estoque_disparadores*)malloc(sizeof(estoque_disparadores));
    if (est == NULL) {
        printf("Erro ao alocar memoria ao criarEstoqueDisparadores!\n");

        perror("Motivo do erro");
        exit(1);
    }
    est->disparadores = (Disparador**)malloc(sizeof(Disparador*) * capacidadeInicial);
    if (est->disparadores == NULL) {
        printf("Erro ao alocar memoria ao criar vetor disparadores!\n");
        free(est); // Libera a struct principal

        perror("Motivo do erro");
        exit(1);
    }
    est->quantidadeD = 0;
    est->capacidadeD = capacidadeInicial;
    return est;
}

void adicionarDisparador(EstoqueD e, Disparador d) {
    estoque_disparadores* est = (estoque_disparadores*)e;

    // Verifica e Realoca (Duplica a capacidade) se o estoque estiver cheio
    if (est->quantidadeD == est->capacidadeD) {
        est->capacidadeD *= 2;
        est->disparadores = realloc(est->disparadores, sizeof(Disparador*)*est->capacidadeD);
        if (est->disparadores == NULL) {
            printf("Erro ao realocar memoria de vetor de disparadores!\n");

            perror("Motivo do erro");
            exit(1);
        }
    }
    est->disparadores[est->quantidadeD] = d;
    est->quantidadeD++;
}

Disparador getDisparadorPorId(EstoqueD e, int id) {
    estoque_disparadores* est = (estoque_disparadores*)e;

    // Busca linear pelo ID
    for (int i = 0 ; i < est->quantidadeD; i++) {
        Disparador d = est->disparadores[i];

        if (getIDDisparador(d) == id) {
            return d;
        }
    }
    return NULL; // Não encontrado
}

void liberarEstoqueDisparadores(EstoqueD e) {
    estoque_disparadores* est = (estoque_disparadores*)e;

    // Libera todos os Disparadores armazenados
    for (int i = 0 ; i < est->quantidadeD; i++) {
        eliminarDisparador(est->disparadores[i]);
    }

    // Libera o vetor de ponteiros
    free(est->disparadores);
    // Libera a struct do Estoque
    free(e);
}

EstoqueC CriarEstoqueCarregadores(int capacidadeInicial) {
    estoque_carregadores* est = (estoque_carregadores*)malloc(sizeof(estoque_carregadores));
    if (est == NULL) {
        printf("Erro ao alocar memoria ao criarEstoqueCarregadores!\n");

        perror("Motivo do erro");
        exit(1);
    }
    est->carregadores = (Carregador**)malloc(sizeof(Carregador*) * capacidadeInicial);
    if (est->carregadores == NULL) {
        printf("Erro ao alocar memoria ao criar vetor carregadores!\n");
        free(est); // Libera a struct principal

        perror("Motivo do erro");
        exit(1);
    }
    est->quantidadeC = 0;
    est->capacidadeC = capacidadeInicial;
    return est;
}

void adicionarCarregador(EstoqueC e, Carregador cr) {
    estoque_carregadores* est = (estoque_carregadores*)e;

    // Verifica e Realoca (Duplica a capacidade) se o estoque estiver cheio
    if (est->quantidadeC == est->capacidadeC) {
        est->capacidadeC *= 2;
        est->carregadores = realloc(est->carregadores, sizeof(Carregador*)*est->capacidadeC);
        if (est->carregadores == NULL) {
            printf("Erro ao realocar memoria de vetor de carregadores!\n");

            perror("Motivo do erro");
            exit(1);
        }
    }
    est->carregadores[est->quantidadeC] = cr;
    est->quantidadeC++;
}

Carregador getCarregadorPorId(EstoqueC e, int id) {
    estoque_carregadores* est = (estoque_carregadores*)e;

    // Busca linear pelo ID
    for (int i = 0 ; i < est->quantidadeC; i++) {
        Carregador cr = est->carregadores[i];

        if (getIDCarregador(cr) == id) {
            return cr;
        }
    }
    return NULL; // Não encontrado
}

void liberarEstoqueCarregadores(EstoqueC e) {
    estoque_carregadores* est = (estoque_carregadores*)e;

    // Libera todos os Carregadores armazenados
    for (int i = 0 ; i < est->quantidadeC; i++) {
        eliminarCarregador(est->carregadores[i]);
    }

    // Libera o vetor de ponteiros
    free(est->carregadores);
    // Libera a struct do Estoque
    free(e);
}