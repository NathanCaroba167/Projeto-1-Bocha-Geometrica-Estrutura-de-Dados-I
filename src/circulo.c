//
// Created by natha on 19/09/2025.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "circulo.h"

#define PI 3.14159265

typedef struct{
  int i;
  double r;
  double x,y;
  char* corP,*corB;
}circulo;

Circulo CriarCirculo(int i, double x, double y, double r, char* corB,char* corP){
  circulo* c  = (circulo*)malloc(sizeof(circulo));

  if(c==NULL){
    printf("Erro ao alocar memoria!\n");
    exit(1);
  }

  c->i = i;
  c->x = x;
  c->y = y;
  c->r = r;
  c->corB = corB;
  c->corP = corP;
}

int getIDCirculo(Circulo c){
  return ((circulo*)c)->i;
}

void setIDCirculo(Circulo c, int id){
  ((circulo*)c)->i = id;
}

double getXCirculo(Circulo c){
  return ((circulo*)c)->x;
  }

void setXCirculo(Circulo c,double x) {
  ((circulo*)c)->x = x;
}

double getYCirculo(Circulo c){
  return ((circulo*)c)->y;
}

void setYCirculo(Circulo c,double y){
  ((circulo*)c)->y = y;
}

double getRCirculo(Circulo c) {
  return ((circulo*)c)->r;
}

void setRCirculo(Circulo c,double r) {
  ((circulo*)c)->r = r;
}

char* getCorBCirculo(Circulo c){
  return ((circulo*)c)->corB;
}

void setCorBCirculo(Circulo c,char* corB) {
  ((circulo*)c)->corB = corB;
}

char* getCorPCirculo(Circulo c){
  return ((circulo*)c)->corP;
}

void setCorPCirculo(Circulo c, char* corP) {
  ((circulo*)c)->corP = corP;
}

double calcAreaCirculo(Circulo c) {
  return PI*pow(getRCirculo(c) ,2);
}