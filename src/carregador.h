//
// Created by natha on 10/10/2025.
//

#ifndef CARREGADOR_H
#define CARREGADOR_H

/*
 Módulo encarregado de executar e coordenar um carregador com operações de criar, get, carregar, 'carregadorvazio' e eliminar.
 O Carregador encapsula uma Pilha e é usado para carregar formas do Chão.
 */

/*
 Ponteiro void Carregador
 */
typedef void* Carregador;

/// @brief Cria um novo carregador.
/// @param id Identificador único que se refere ao carregador.
/// @return Ponteiro para o novo carregador criado
Carregador CriarCarregador(int id);

/// @brief Pega o ID do carregador sem modifica-lo.
/// @param cr Ponteiro para o carregador analisado.
/// @return Um inteiro que representa o ID do carregador.
/// @warning
int getIDCarregador(Carregador cr);

/// @brief Pega a forma no topo da pilha do carregador sem remove-lá.
/// @param cr Ponteiro para o carregador que a forma será pega.
/// @return Ponteiro para forma (Pacote) que está no topo, ou NULL se a pilha estiver vazia.
/// @warning
Pacote getPrimeiraFormaCarregador(Carregador cr);

/// @brief Pega a pilha inteira relacionada ao carregador.
/// @param cr Ponteiro para o carregador que a pilha será pega.
/// @return Ponteiro para pilha que foi pega.
Pilha getPilhaCarregador(Carregador cr);

/// @brief Carrega uma forma do chão (Fila) para a pilha do carregador.
///        Remove a forma da Fila e a coloca na pilha, registrando a operação.
/// @param txt Ponteiro para o arquivo (.txt) que será escrito os dados da forma carregada.
/// @param cr Ponteiro para o carregador que será carregado.
/// @param chao Ponteiro para o chão (Fila) de onde a forma será removida.
void carregarCarregador(Arquivo txt,Carregador cr, Fila chao);

/// @brief Verifica se a pilha do carregador está vazia.
/// @param cr Ponteiro para o carregador que será verificado.
/// @return True (1) se o carregador estiver vazio, ou False(0) se o carregador não estiver vazio.
/// @warning
bool carregadorvazio(Carregador cr);

/// @brief Libera a memória do carregador e de sua pilha interna.
///        Também libera as formas da pilha interna.
/// @param cr Ponteiro para o carregador que será liberado.
/// @warning
void eliminarCarregador(Carregador cr);

#endif //CARREGADOR_H