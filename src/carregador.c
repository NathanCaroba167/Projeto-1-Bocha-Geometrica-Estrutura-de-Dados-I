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
#include "texto.h"
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
    // Inicializa a pilha interna, que deve ser uma pilha vazia
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
    if (p == NULL) {
        // Isso pode ocorrer se o chão estiver vazio.
        printf("Erro ao carregar Carregador de Fila vazia!\n");
        return;
    }
    // Coloca a forma na pilha do carregador
    empilharPilha(carr->p, p);

    // Registra o carregamento no arquivo txt
    reportarForma(txt,p);

    // Remove a forma da fila (chão)
    removerFila(chao);
}

bool carregadorvazio(Carregador cr) {
    carregador* carr = (carregador*)cr;
    // Delega a verificação de vazio para o módulo pilha
    return pilhavazia(carr->p);
}

void eliminarCarregador(Carregador cr) {
    carregador* carr = ((carregador*)cr);

    // Libera a memória da pilha interna e suas formas (se não for NULL)
    if (carr->p != NULL) {
        liberarPilha(carr->p);
    }
    // Libera a memória da estrutura Carregador
    free(carr);
}