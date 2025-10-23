//
// Created by natha on 25/09/2025.
//

#ifndef FILA_H
#define FILA_H

/*
 Módulo encarregado de executar e coordenar uma fila com operações de iniciar, inserir, remover, get, 'filavazia' e liberar
 */

/*
 Ponteiro void Fila
 Ponteiro void Forma
 */
typedef void* Fila;
typedef void* Forma;
typedef struct Elemento* pont;

/// @brief Inicializa uma fila
/// @return Ponteiro para nova fila iniciada
/// @warning
Fila iniciarFila();

/// @brief Enfileira uma forma no fim da fila
/// @param f Ponteiro para fila a qual a forma será enfileirada
/// @param p Ponteiro para forma que será enfileirada
/// @warning
void inserirFila(Fila f, Pacote p);

/// @brief Desenfileira a forma do início da fila
/// @param f Ponteiro para fila que será retirada a forma
/// @warning
void removerFila(Fila f);

/// @brief Pega a primeira forma do início da fila sem remove-lá
/// @param f Ponteiro para fila que a forma será pega
/// @return Ponteiro para forma que foi pega ou NULL se a fila estiver vazia
/// @warning
Pacote getPrimeiraFormaFila(Fila f);

/// @brief Pega a forma do elemento da fila
/// @param p Ponteiro para o elemento da fila
/// @return Ponteiro para forma que foi pega do elemento
/// @warning
Pacote getFormaElementoFila(pont p);

/// @brief Pega o primeiro elemento da fila
/// @param f Ponteiro para fila  que o elemento será pego
/// @return Ponteiro para o elemento que foi pego
/// @warning
pont getPrimeiroElementoFila(Fila f);

/// @brief Pega o próximo elemento da fila a partir do elemento anterior
/// @param p Ponteiro para o elemento anterior
/// @return Ponteiro para o próximo elemento
/// @warning
pont getProximoElementoFila(pont p);

/// @brief Verifica se a fila esta vazia
/// @param f Ponteiro para fila que será verificada
/// @warning
int filavazia(Fila f);

/// @brief Retorna a quantidade de elementos da fila
/// @param f Ponteiro para fila analisada
/// @return Um inteiro que representa a quantidade de elementos da fila
int getNumeroElementosFila(Fila f);///

/// @brief Libera a memória da fila e de todas as formas dela
/// @param f Ponteiro para fila que será liberada
/// @warning
void liberarFila(Fila f);


#endif //FILA_H
