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
#include "texto.h"
#include "geo.h"
#include "carregador.h"
#include "disparador.h"

typedef struct {
    int id;
    double x;
    double y;
    Pacote formaDisparo;
    Carregador carregadorEsq;
    Carregador carregadorDir;
}disparador;

Disparador CriarDisparador(int id,double x ,double y) {
    disparador* d = (disparador*) malloc (sizeof (disparador));
    if (d == NULL) {
        printf("Erro ao alocar memória ao criarDisparador!\n");

        perror("Motivo do erro");
        exit(1);
    }
    // Inicialização da struct
    d->id = id;
    d->x = x;
    d->y = y;
    d->formaDisparo = NULL; // O disparador começa desarmado
    d->carregadorDir = NULL;
    d->carregadorEsq = NULL;

    return d;
}

int getIDDisparador(Disparador d) {
    return ((disparador*)d)->id;
}

double getXDisparador(Disparador d) {
    return ((disparador*)d)->x;
}

void setXDisparador(Disparador d,double x) {
    ((disparador*)d)->x = x;
}

double getYDisparador(Disparador d) {
    return ((disparador*)d)->y;
}

void setYDisparador(Disparador d,double y) {
    ((disparador*)d)->y = y;
}

Pacote getFormaDisparador(Disparador d) {
    return ((disparador*)d)->formaDisparo;
}

void setFormaDisparador(Disparador d,Pacote formaDisparo) {
    ((disparador*)d)->formaDisparo = formaDisparo;
}

Carregador getCarregadorEsq(Disparador d) {
    return ((disparador*)d)->carregadorEsq;
}

Carregador getCarregadorDir(Disparador d) {
    return ((disparador*)d)->carregadorDir;
}

void setCarregadoresDisparador(Disparador d, Carregador esq, Carregador dir) {
    ((disparador*)d)->carregadorEsq = esq;
    ((disparador*)d)->carregadorDir = dir;
}

void desarmarDisparador(Disparador d) {
    // Simplesmente remove a referência à forma, mas não a destrói
    disparador* dis = ((disparador*)d);

    dis->formaDisparo = NULL;
}

void eliminarDisparador(Disparador d) {
    // Note: Assume que a formaDisparo (Pacote) e os Carregadores
    // serão eliminados ou liberados pelo módulo principal (main) ou por
    // outra função de gerenciamento de memória, e não por esta função
    disparador* dis = ((disparador*)d);
    free(dis);
}