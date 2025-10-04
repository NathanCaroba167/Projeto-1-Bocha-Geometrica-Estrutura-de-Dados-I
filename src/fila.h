//
// Created by natha on 25/09/2025.
//

#ifndef FILA_H
#define FILA_H

/*
 Módulo encarregado de executar e coordenar uma fila com operações de iniciar, inserir, remover, 'filavazia' e liberar
 */

/*
 Ponteiro void Fila
 Ponteiro void Forma
 */
typedef void* Fila;
typedef void* Forma;

/// @brief Inicializa uma fila
/// @return Ponteiro para nova fila iniciada
/// @warning
Fila iniciarFila();

/// @brief Enfileira uma forma na lista
/// @param f Ponteiro para fila a qual a forma será enfileirada
/// @param g Ponteiro para forma que será enfileirada
/// @warning
void inserirFila(Fila f, Forma g);

/// @brief Desenfileira a forma do início da fila
/// @param f Ponteiro para fila que será retirado a forma
/// @warning
void removerFila(Fila f);

/// @brief Pega a primeira forma do início da fila sem remove-lá
/// @param f Ponteiro para fila que a forma será pega
/// @return Ponteiro para forma que foi pega ou NULL se a fila estiver vazia
/// @warning
Forma getPrimeiraFormaFila(Fila f);

/// @brief Verifica se a fila esta vazia
/// @param f Ponteiro para fila que será verificada
/// @warning
void filavazia(Fila f);

/// @brief Libera a memória da fila e de todas as formas dela
/// @param f Ponteiro para fila que será liberada
/// @warning
void liberarFila(Fila f);


#endif //FILA_H
