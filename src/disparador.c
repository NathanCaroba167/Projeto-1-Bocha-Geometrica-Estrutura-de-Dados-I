//
// Created by natha on 25/09/2025.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "forma.h"
#include "pilha.h"
#include "fila.h"
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
        printf("Erro ao alocar memoria!\n");
        exit(1);
    }
    d->id = id;
    d->x = x;
    d->y = y;
    d->formaDisparo = NULL;

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
    free(((disparador*)d)->formaDisparo);
}

/*void dispararDisparador(Disparador d, double dx,double dy, Fila arena) {

}*/

void eliminarDisparador(Disparador d) {
    disparador* dis = ((disparador*)d);
    free(dis);
}