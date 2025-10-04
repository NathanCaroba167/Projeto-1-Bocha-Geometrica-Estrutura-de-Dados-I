//
// Created by natha on 19/09/2025.
//

#ifndef TEXTO_H
#define TEXTO_H

typedef void* Texto;
/*
 Ponteiro void Texto
 */

Texto CriarTexto(int id, float x, float y, char* corB, char* corP, char a, char* txt, char* fs ,char* fw, char* ff);
/*
 Cria um texto com id, coordenadas x e y e um ponto ancora a , cor de borda, cor de preenchimento , o texto em si, familia de tamanho,familia de tipo e familia de estilo
 */
int getId(Texto t);
/*
 Pega o valor do id
 */
void setId(Texto t, int id);
/*
 Muda o valor do id
 */

float getX1(Texto t);
/*
 Pega o valor da coordenada x
 */
void setX1(Texto t, float x1);
/*
 Muda o valor da coordenada x
 */

float getY1(Texto t);
/*
 Pega o valor da coordenada y
 */
void setY1(Texto t, float y1);
/*
 Muda o valor da coordenada y
 */

char* getCor(Texto t);
void setCor(Texto t, char* cor);

void setFamilyWeight(Texto t, float fw);
/*
 Muda o tamanho do texto
 */



void eliminarTexto(Texto t);


#endif //TEXTO_H
