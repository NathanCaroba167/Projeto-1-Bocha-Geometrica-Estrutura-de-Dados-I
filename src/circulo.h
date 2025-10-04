//
// Created by natha on 19/09/2025.
//

#ifndef CIRCULO_H
#define CIRCULO_H


typedef void* Circulo;
/*
 Ponteiro void Circulo
 */

Circulo criar_circulo(int id, float raio, float x, float y, char* corP,char* corB);
/*
  Cria um circulo com um id, raio, coordenadas x e y do centro do circulo e cor de borda e cor de preenchimento
  O raio deve existir, diferente de 0
 */

int getId(Circulo c);
/*
 Pega o valor do id do circulo
 */

int setId(Circulo c, int id);
/*
 Muda o valor do id do circulo
 */

float getRaio(Circulo c);
/*
 Pega o valor do raio do circulo
 */

void setRaio(Circulo c, float raio);
/*
 Muda o valor do raio do circulo
 */

float getX(Circulo c);
/*
 Pega o valor da coordedada x do centro do circulo
 */

void setX(Circulo c, float x);
/*
 Muda o valor da coordedada x do centro do circulo
 */

float getY(Circulo c);
/*
 Pega o valor da coordedada y do centro do circulo
 */

void setY(Circulo c, float y);
/*
 Muda o valor da coordedada y do centro do circulo
 */


char* getCorP(Circulo c);
/*
 Pega o codigo svg(#FFFFFF) da cor de preenchimento do circulo
 */

void setCorP(Circulo c, char* corP);
/*
 Muda o codigo svg(#FFFFFF) da cor de preenchimento do circulo
 */


char* getCorB(Circulo c);
/*
 Pega o codigo svg(#FFFFFF) da cor de borda do circulo
 */

void setCorB(Circulo c, char* corB);
/*
 Pega o codigo svg(#FFFFFF) da cor de borda do circulo
 */

void eliminaCirculo(Circulo c);
/*
 Elimina o circulo no caso da destruicao por outra forma de area maior
 */

#endif //CIRCULO_H
