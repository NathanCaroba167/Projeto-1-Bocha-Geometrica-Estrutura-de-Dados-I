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
 */
typedef void* Fila;
typedef struct Elemento* pont;

/// @brief Inicializa uma fila vazia.
/// @return Ponteiro para nova fila iniciada.
/// @warning
Fila iniciarFila();

/// @brief Enfileira um Pacote no fim da fila.
/// @param f Ponteiro para fila a qual o Pacote será enfileirado.
/// @param p Ponteiro para o Pacote que será enfileirado.
/// @warning
void inserirFila(Fila f, Pacote p);

/// @brief Desenfileira o Pacote do início da fila e libera o nó da fila.
/// @param f Ponteiro para fila que será retirada a forma.
/// @warning
void removerFila(Fila f);

/// @brief Pega o primeiro Pacote do início da fila sem removê-lo.
/// @param f Ponteiro para fila que o Pacote será pego.
/// @return Ponteiro para o Pacote que foi pego ou NULL se a fila estiver vazia.
/// @warning
Pacote getPrimeiraFormaFila(Fila f);

/// @brief Pega o Pacote do elemento da fila.
/// @param p Ponteiro para o elemento (nó) da fila.
/// @return Ponteiro para o Pacote que foi pego do elemento.
/// @warning
Pacote getFormaElementoFila(pont p);

/// @brief Pega o primeiro elemento (nó) da fila.
/// @param f Ponteiro para fila que o elemento será pego.
/// @return Ponteiro para o primeiro elemento que foi pego.
/// @warning
pont getPrimeiroElementoFila(Fila f);

/// @brief Pega o próximo elemento (nó) da fila a partir do elemento anterior.
/// @param p Ponteiro para o elemento anterior.
/// @return Ponteiro para o próximo elemento.
/// @warning
pont getProximoElementoFila(pont p);

/// @brief Verifica se a fila esta vazia.
/// @param f Ponteiro para fila que será verificada.
/// @return True (1) se a fila estiver vazia, ou False (0) se a fila não estiver vazia.
/// @warning
bool filavazia(Fila f);

/// @brief Retorna a quantidade de elementos da fila.
/// @param f Ponteiro para fila analisada.
/// @return Um inteiro que representa a quantidade de elementos da fila.
int getNumeroElementosFila(Fila f);///

/// @brief Libera a memória da fila, de todos os seus elementos (nós) e de todos os Pacotes nela contidos.
/// @param f Ponteiro para fila que será liberada.
/// @warning
void liberarFila(Fila f);

#endif //FILA_H
