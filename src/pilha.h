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
void empilharPilha(Pilha p, Pacote g);

/// @brief Desempilha a forma do topo da pilha
/// @param p Ponteiro para pilha que será retirada a forma
/// @warning
void desempilharPilha(Pilha p);

/// @brief Pega a primeira forma do topo da pilha sem remove-lá
/// @param p Ponteiro para pilha que a forma será pega
/// @return Ponteiro para forma que foi pega ou NULL se a pilha estiver vazia
/// @warning
Pacote getPrimeiraFormaPilha(Pilha p);

/// @brief Verifica se a pilha esta vazia
/// @param p Ponteiro para pilha que será verificada
/// @return True(1) se a pilha estiver vazia ou  False(0) se a pilha não estiver vazia
/// @warning
bool pilhavazia(Pilha p);

/// @brief Retorna a quantidade de elementos da pilha
/// @param p Ponteiro para pilha analisada
/// @return Um inteiro de representa a quantidade de elementos da pilha
int getNumeroElementosPilha(Pilha p);///

/// @brief Libera a memória da pilha e de todas as formas dela
/// @param p Ponteiro para pilha que será liberada
/// @warning
void liberarPilha(Pilha p);

#endif //PILHA_H
