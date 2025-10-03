//
// Created by natha on 02/09/2025.
//

#ifndef RETANGULO_H
#define RETANGULO_H

typedef void* Retangulo;

/*
 Ponteiro void Retangulo
*/

Retangulo criar_retangulo(int id,float x,float y,float w ,float h, char* corP, char* corB );
/*
 Cria um retangulo com um id, raio, coordenadas x e y de um ponto ancora, valor w referente a largura , h referente a altura e cor de borda e cor de preenchimento
 */

int getId(Retangulo r);
/*
 Pega o valor do id do retangulo
 */

void setId(Retangulo r,int id);
/*
 Muda o valor do id do retangulo
*/
float getX(Retangulo r);
/*
 Pega o valor da coordedada x do retangulo
 */

void setX(Retangulo r,float x);
/*
 Muda o valor da coordenada x do retangulo
 */

float getY(Retangulo r);
/*
 Pega o valor da coordedada y do retangulo
 */

void setY(Retangulo r,float y);
/*
 Muda o valor da coordedada y do retangulo
 */


float getW(Retangulo r);
/*
 Pega o valor da largura w do retangulo
 */
void setW(Retangulo r,float w);
/*
 Muda o valor da largura w do retangulo
 */

float getH(Retangulo r);
/*
 Pega o valor da altura h do retangulo
 */
void setH(Retangulo r,float h);
/*
 Muda o valor da altura h do retangulo
 */

char* getCorP(Retangulo r);
/*
 Pega o codigo svg(#FFFFFF) da cor de preenchimento do retangulo
 */

void setCorP(Retangulo r,char* corP);
/*
 Muda o codigo svg(#FFFFFF) da cor de preenchimento do retangulo
 */


char* getCorB(Retangulo r);
/*
 Pega o codigo svg(#FFFFFF) da cor de borda do retangulo
 */

void setCorB(Retangulo r,char* corB);
/*
 Muda o codigo svg(#FFFFFF) da cor de borda do retangulo
 */


void eliminaRetangulo(Retangulo r);
/*
 Elimina o retangulo no caso da destruicao por outra forma de area maior
 */
#endif