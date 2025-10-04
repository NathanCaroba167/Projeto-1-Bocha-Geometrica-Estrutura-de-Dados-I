//
// Created by natha on 25/09/2025.
//

#ifndef PILHA_H
#define PILHA_H
/*
 Módulo encarregado de executar e coordenar uma pilha com operações de iniciar, empilhar, desempilhar, get, 'pilhavazia' e liberar
 */

/*
 Ponteiro void Pilha
 Ponteiro void Forma
 */
typedef void* Pilha;
typedef void* Forma;

/// @brief Inicializa um pilha
/// @return Ponteiro para nova pilha iniciada
/// @warning
Pilha iniciarPilha();

/// @brief Empilha uma forma no topo da pilha
/// @param p Ponteiro para pilha a qual a forma será empilhada
/// @param g Ponteiro para forma que será empilhada
/// @warning
void empilharPilha(Pilha p, Forma g);

/// @brief Desempilha a forma do topo da pilha
/// @param p Ponteiro para pilha que será retirada a forma
/// @warning
void desempilharPilha(Pilha p);

/// @brief Retorna a quantidade de elementos ou NULL se a pilha estiver vazia
/// @param p
/// @return
int numeroelementos(Pilha p);///

/// @brief Pega a primeira forma do topo da pilha sem remove-lá
/// @param p Ponteiro para pilha que a forma será pega
/// @return Ponteiro para forma que foi pega ou NULL se a fila estiver vazia
/// @warning
Forma getPrimeiraFormaPilha(Pilha p);

/// @brief Verifica se a pilha esta vazia
/// @param p Ponteiro para pilha que será verificada
/// @warning
void pilhavazia(Pilha p);

/// @brief Libera a memória da pilha e de todas as formas dela
/// @param p Ponteiro para pilha que será liberada
/// @warning
void liberarPilha(Pilha p);

#endif //PILHA_H
