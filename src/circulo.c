//
// Created by natha on 19/09/2025.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "circulo.h"

typedef struct{
  int id;
  float raio;
  float x,y;
  char* corP,*corB;
}circulo;

Circulo criar_circulo(int id, float raio, float x, float y, char* corP,char* corB){
  circulo* c  = (circulo*)malloc(sizeof(circulo));

  if(c==NULL){
    printf("Erro ao alocar memoria!\n");
    exit(1);
  }

  c->id=id;
  c->raio=raio;
  c->x=x;
  c->y=y;
  c->corP=corP;
  c->corB=corB;
}

int getId(Circulo c){
  circulo* c1 = ((circulo*)c);
  return c1->id;
  }

int setId(Circulo c, int id){
  circulo* c1 = ((circulo*)c);
  return c1->id = id;
}




float getRaio(Circulo c){
  circulo* c1 = ((circulo*)c);
  return c1->raio;
  }

float setRaio(Circu)

float getX(Circulo c){
  circulo* c1 = ((circulo*)c);
  return c1->x;
}

float getY(Circulo c){
  circulo* c1 = ((circulo*)c);
  return c1->y;
}

char* getCorP(Circulo c){
  circulo* c1 = ((circulo*)c);
  return c1->corP;
}

char* getCorB(Circulo c){
  circulo* c1 = ((circulo*)c);
  return c1->corB;
}



int main(){

  }