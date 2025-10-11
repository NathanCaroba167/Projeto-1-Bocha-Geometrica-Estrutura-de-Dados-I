//
// Created by natha on 10/10/2025.
//

#ifndef CARREGADOR_H
#define CARREGADOR_H

#include "pilha.h"
#include "fila.h"

/*
 Módulo encarregado de executar e coordenar um carregador com operações de criar, get, carregar, 'carregadorvazio' e eliminar
 */

/*
 Ponteiro void Carregador
 */
typedef void* Carregador;

/// @brief Cria um carregador
/// @param id Identificador unico que se refere ao carregador
/// @return Ponteiro para o novo carregador criado
Carregador CriarCarregador(int id);

/// @brief Pega o ID do carregador sem modifica-lo
/// @param cr Ponteiro para o carregador analisado
/// @return Um inteiro que representa o ID do carregador
/// @warning
int getIDCarregador(Carregador cr);

/// @brief Pega a primeira forma do topo do carregador sem remove-lá
/// @param cr Ponteiro para o carregador que a forma será pega
/// @return Ponteiro para forma que foi pega ou NULL se o carregador estiver vazio
/// @warning
Forma getPrimeiraFormaCarregador(Carregador cr);///

/// @brief Pega a pilha relacionada ao carregador
/// @param cr Ponteiro para o carregador que a pilha será pega
/// @return Ponteiro para pilha que foi pega
Pilha getPilhaCarregador(Carregador cr);

/// @brief Carrega o carregador com formas vindas do chao
/// @param cr Ponteiro para o carregador que será carregado
/// @param chao Ponteiro para o chao que mandará as formas
void carregarCarregador(Carregador cr, Fila chao);

/// @brief Verifica se o carregador esta vazio
/// @param cr Ponteiro para o carregador que será verificado
/// @return True(1) se o carregador estiver vazio ou  False(0) se o carregador não estiver vazio
/// @warning
bool carregadorvazio(Carregador cr);///

/// @brief Libera a memória do carregador e de todas as formas dele
/// @param cr Ponteiro para o carregador que será liberado
/// @warning
void eliminarCarregador(Carregador cr);

#endif //CARREGADOR_H