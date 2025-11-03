//
// Created by natha on 18/10/2025.
//

#ifndef ESTOQUE_H
#define ESTOQUE_H

/*
 Módulo encarregado de executar e coordenar estoques dinâmicos para Disparadores e Carregadores
 com operações de criar, adicionar, get e liberar
 */

/*
 Ponteiro void EstoqueD
 Ponteiro void EstoqueC
 */

typedef void* EstoqueD;
typedef void* EstoqueC;

/// @brief Cria um estoque de disparadores com capacidade inicial.
/// @param capacidadeInicial Capacidade inicial do estoque de disparadores.
/// @return Ponteiro para o estoque de disparadores criado.
/// @warning
EstoqueD CriarEstoqueDisparadores(int capacidadeInicial);

/// @brief Adiciona um disparador ao estoque.
/// @param e Ponteiro para o estoque de disparadores.
/// @param d Ponteiro para o disparador que será estocado.
/// @warning
void adicionarDisparador(EstoqueD e, Disparador d);

/// @brief Pega um disparador no estoque pelo ID correspondente.
/// @param e Ponteiro para o estoque de disparadores.
/// @param id Identificador único que se refere ao disparador.
/// @return Ponteiro para o disparador encontrado ou NULL se não existir.
/// @warning
Disparador getDisparadorPorId(EstoqueD e, int id);

/// @brief Libera a memória do estoque de disparadores e de todos os Disparadores nele contidos.
/// @param e Ponteiro para o estoque de disparadores.
/// @warning
void liberarEstoqueDisparadores(EstoqueD e);

/// @brief Cria um estoque de carregadores com capacidade inicial.
/// @param capacidadeInicial Capacidade inicial do estoque de carregadores.
/// @return Ponteiro para o estoque de carregadores criado.
/// @warning
EstoqueC CriarEstoqueCarregadores(int capacidadeInicial);

/// @brief Adiciona um carregador ao estoque.
/// @param e Ponteiro para o estoque de carregadores.
/// @param cr Ponteiro para o carregador que será estocado.
/// @warning
void adicionarCarregador(EstoqueC e, Carregador cr);

/// @brief Pega um carregador no estoque pelo ID correspondente.
/// @param e Ponteiro para o estoque de carregadores.
/// @param id Identificador único que se refere ao carregador.
/// @return Ponteiro para o carregador encontrado ou NULL se não existir.
/// @warning
Carregador getCarregadorPorId(EstoqueC e, int id);

/// @brief Libera a memória do estoque de carregadores e de todos os Carregadores nele contidos.
/// @param e Ponteiro para o estoque de carregadores.
/// @warning
void liberarEstoqueCarregadores(EstoqueC e);

#endif //ESTOQUE_H