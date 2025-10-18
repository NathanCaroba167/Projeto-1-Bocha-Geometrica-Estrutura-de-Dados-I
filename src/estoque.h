//
// Created by natha on 18/10/2025.
//

#ifndef ESTOQUE_H
#define ESTOQUE_H

/*
 Módulo encarregado de executar e coordenar um estoque com operações de criar, adicionar, get e liberar
 */

/*
 Ponteiro void EstoqueD
 Ponteiro void EstoqueC
 */

typedef void* EstoqueD;
typedef void* EstoqueC;

/// @brief Cria um estoque de disparadores
/// @param capacidadeInicial capacidade inicial do estoque de disparadores
/// @return Ponteiro para o estoque de disparadores
/// @warning
EstoqueD CriarEstoqueDisparadores(int capacidadeInicial);

/// @brief Adiciona um disparador ao estoque
/// @param e Ponteiro para o estoque de disparadores
/// @param d Ponteiro para o disparador que será estocado
/// @warning
void adicionarDisparador(EstoqueD e, Disparador d);

/// @brief Pega um disparador no estoque pelo ID correspondente
/// @param e Ponteiro para o estoque de disparadores
/// @param id Identificador unico que se refere ao disparador
/// @return Ponteiro para o disparador que será pego
/// @warning
Disparador getDisparadorPorId(EstoqueD e, int id);

/// @brief Libera a memória do estoque de disparadores
/// @param e Ponteiro para o estoque de disparadores
/// @warning
void liberarEstoqueDisparadores(EstoqueD e);

/// @brief Cria um estoque de carregadores
/// @param capacidadeInicial capacidade inicial do estoque de carregadores
/// @return Ponteiro para o estoque de carregadores
/// @warning
EstoqueC CriarEstoqueCarregadores(int capacidadeInicial);

/// @brief Adiciona um carregador ao estoque
/// @param e Ponteiro para o estoque de carregadores
/// @param cr Ponteiro para o carregador que será estocado
/// @warning
void adicionarCarregador(EstoqueC e, Carregador cr);

/// @brief Pega um carregador no estoque pelo ID correspondente
/// @param e Ponteiro para o estoque de carregadores
/// @param id Identificador unico que se refere ao carregador
/// @return Ponteiro para o carregador que será pego
/// @warning
Carregador getCarregadorPorId(EstoqueC e, int id);

/// @brief Libera a memória do estoque de carregadores
/// @param e Ponteiro para o estoque de carregadores
/// @warning
void liberarEstoqueCarregadores(EstoqueC e);

#endif //ESTOQUE_H