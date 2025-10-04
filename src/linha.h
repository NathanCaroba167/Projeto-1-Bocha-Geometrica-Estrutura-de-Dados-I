//
// Created by natha on 19/09/2025.
//

#ifndef LINHA_H
#define LINHA_H

typedef void* Linha;
/*
 Ponteiro void Linha
 */

Linha criar_linha(int id, float x1, float y1, float x2, float y2 ,char* cor);
/*
 * @brief Cria uma linha com id , coordedada de x1 e y1 e coordenadas x2 e y2 referentes ao comeco e fim na linha respectivamente e cor da linha
 */

int getId(Linha l);
/*
 Pega o valor do id da linha
 */

void setId(Linha l, int id);
/*
 Muda o valor do id da linha
 */

float getX1(Linha l);
/*
 Pega o valor da coordedada x1 do ponto do comeco da linha
 */
void setX1(Linha l, float x1);
/*
 Muda o valor da coordedada x1 do ponto do comeco da linha
 */

float getY1(Linha l);
/*
 Pega o valor da coordedada y1 do ponto do comeco da linha
 */

void setY1(Linha l, float y1);
/*
 Muda o valor da coordedada y1 do ponto do comeco da linha
 */

float getX2(Linha l);
/*
 Pega o valor da coordedada x2 do ponto do fim da linha
 */
void setX2(Linha l, float x2);
/*
 Pega o valor da coordedada x2 do ponto do fim da linha
 */

float getY2(Linha l);
/*
 Pega o valor da coordedada y2 do ponto do fim da linha
 */
void setY2(Linha l, float y2);
/*
 Pega o valor da coordedada y2 do ponto do fim da linha
 */

char* getCor(Linha l);
/*
 Pega o codigo svg(#FFFFFF) da cor da linha
 */

void setCor(Linha l, char* cor);
/*
 Muda o codigo svg(#FFFFFF) da cor da linha
 */

void eliminarLinha(Linha l);
/*
 Elimina a linha no caso da destruicao por outra forma de area maior
 */



#endif //LINHA_H
