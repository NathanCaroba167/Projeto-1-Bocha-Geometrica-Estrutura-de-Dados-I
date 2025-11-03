//
// Created by natha on 25/09/2025.
//

#ifndef DISPARADOR_H
#define DISPARADOR_H

/*
 Módulo responsavel de coordenar e executar um disparador com operações de criar, get, set, desarmar e eliminar
 */

/*
 Ponteiro void Disparador
 */
typedef void* Disparador;

/// @brief Cria um disparador.
/// @param id Identificador único que se refere ao disparador.
/// @param x Coordenada x do disparador.
/// @param y Coordenada y do disparador.
/// @return Ponteiro para o novo disparador criado.
Disparador CriarDisparador(int id,double x ,double y);

/// @brief Pega o ID do disparador sem modifica-lo.
/// @param d Ponteiro para o disparador analisado.
/// @return Um inteiro que representa o ID do disparador.
/// @warning
int getIDDisparador(Disparador d);

/// @brief Pega a coordenada x do disparador sem modifica-la.
/// @param d Ponteiro para o disparador analisado.
/// @return Um double que representa a coordenada x do disparador.
/// @warning
double getXDisparador(Disparador d);

/// @brief Define a nova coordenada x do disparador.
/// @param d Ponteiro para o disparador onde a coordenada x será definida.
/// @param x Nova coordenada x que será definida.
/// @warning
void setXDisparador(Disparador d,double x);

/// @brief Pega a coordenada y do disparador sem modifica-la.
/// @param d Ponteiro para o disparador analisado.
/// @return Um double que representa a coordenada y do disparador.
/// @warning
double getYDisparador(Disparador d);

/// @brief Define a nova coordenada y do disparador.
/// @param d Ponteiro para o disparador onde a coordenada y será definida.
/// @param y Nova coordenada y que será definida.
/// @warning
void setYDisparador(Disparador d,double y);

/// @brief Pega a forma que está na posição de disparo do disparador sem remove-lá.
/// @param d Ponteiro para o disparador que a forma será pega.
/// @return Ponteiro para forma que foi pega.
/// @warning
Pacote getFormaDisparador(Disparador d);

/// @brief Define a nova forma da posição de disparo do disparador.
/// @param d Ponteiro para o disparador onde a forma será definida.
/// @param formaDisparo Nova forma da posição de disparo que será definida.
/// @warning
void setFormaDisparador(Disparador d,Pacote formaDisparo);

/// @brief Pega o carregador que está acoplado no lado esquerdo do disparador.
/// @param d Ponteiro para o disparador que o carregador será pego.
/// @return Ponteiro para o carregador que foi pego.
/// @warning
Carregador getCarregadorEsq(Disparador d);

/// @brief Pega o carregador que está acoplado no lado direito do disparador.
/// @param d Ponteiro para o disparador que o carregador será pego.
/// @return Ponteiro para o carregador que foi pego.
/// @warning
Carregador getCarregadorDir(Disparador d);

/// @brief Encaixa os novos carregadores no lado esquerdo e direito do disparador.
/// @param d Ponteiro para o disparador onde os carregadores serão encaixados.
/// @param esq Novo carregador esquerdo do disparador que será definido.
/// @param dir Novo carregador direito do disparador que será definido.
/// @warning
void setCarregadoresDisparador(Disparador d,Carregador esq,Carregador dir);

/// @brief Desarma o disparador (tira a forma da posição de disparo).
/// @param d Ponteiro para o disparador que será desarmado.
/// @warning
void desarmarDisparador(Disparador d);

/// @brief Liberar a memória alocada para o disparador.
/// @param d Ponteiro para o disparador que será liberado.
/// @warning
void eliminarDisparador(Disparador d);

#endif //DISPARADOR_H
