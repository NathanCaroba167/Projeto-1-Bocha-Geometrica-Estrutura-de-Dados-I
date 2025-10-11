//
// Created by natha on 19/09/2025.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "linha.h"

typedef struct{
    int i;
    double x1,y1;
    double x2,y2;
    char* cor;
}linha;

Linha CriarLinha(int i,double x1,double y1, double x2,double y2,char* cor) {
    linha* l = (linha*)malloc(sizeof(linha));

    if(l == NULL) {
        printf("Erro ao alocar memoria!\n");
        exit(1);
    }

    l->i = i;
    l->x1 = x1;
    l->y1 = y1;
    l->x2 = x2;
    l->y2 = y2;
    l->cor = (char*) malloc (strlen(cor) + 1);
    if (l->cor == NULL) {
        printf("Erro ao alocar memoria!\n");
        exit(1);
    }
    strcpy(l->cor,cor);
    return l;
}

int getIDLinha(Linha l) {
    return ((linha*)l)->i;
}

void setIDLinha(Linha l, int id) {
    ((linha*)l)->i = id;
}

double getX1Linha(Linha l) {
    return ((linha*)l)->x1;
}

void setX1Linha(Linha l, double x1) {
    ((linha*)l)->x1 = x1;
}

double getY1Linha(Linha l) {
    return ((linha*)l)->y1;
}

void setY1Linha(Linha l, double y1) {
    ((linha*)l)->y1 = y1;
}

double getX2Linha(Linha l) {
    return ((linha*)l)->x2;
}

void setX2Linha(Linha l, double x2) {
    ((linha*)l)->x2 = x2;
}

double getY2Linha(Linha l) {
    return ((linha*)l)->y2;
}

void setY2Linha(Linha l, double y2) {
    ((linha*)l)->y2 = y2;
}

char* getCorLinha(Linha l) {
    return ((linha*)l)->cor;
}

void setCorLinha(Linha l, char* cor) {
    linha* lin = (linha*)l;
    lin->cor = realloc (lin->cor,strlen(cor) + 1);
    if (lin->cor == NULL) {
        printf("Erro ao realocar memoria!\n");
        exit(1);
    }
    strcpy(lin->cor,cor);
}

double calcAreaLinha(Linha l) {
    return 2 * sqrt(pow(getX1Linha(l)-getX2Linha(l),2) + pow(getY1Linha(l)-getY2Linha(l),2));
}

void eliminarLinha(Linha l) {
    linha* lin = (linha*)l;
    free(lin->cor);
    free(lin);
}