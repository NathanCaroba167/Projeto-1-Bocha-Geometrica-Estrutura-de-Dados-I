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

/// @brief Inicializa um pilha vazia.
/// @return Ponteiro para nova pilha iniciada.
/// @warning
Pilha iniciarPilha();

/// @brief Empilha um Pacote no topo da pilha.
/// @param p Ponteiro para pilha a qual o Pacote será empilhada.
/// @param g Ponteiro para o Pacote que será empilhado.
/// @warning
void empilharPilha(Pilha p, Pacote g);

/// @brief Desempilha o Pacote do topo da pilha e libera o nó da pilha
/// @param p Ponteiro para pilha que será retirada a forma.
/// @warning
void desempilharPilha(Pilha p);

/// @brief Pega o Pacote do topo da pilha sem remove-lo.
/// @param p Ponteiro para pilha que o Pacote será pego.
/// @return Ponteiro para o Pacote que foi pego ou NULL se a pilha estiver vazia.
/// @warning
Pacote getPrimeiraFormaPilha(Pilha p);

/// @brief Verifica se a pilha está vazia.
/// @param p Ponteiro para pilha que será verificada.
/// @return True (1) se a pilha estiver vazia ou False (0) se a pilha não estiver vazia.
/// @warning
bool pilhavazia(Pilha p);

/// @brief Retorna a quantidade de elementos da pilha.
/// @param p Ponteiro para pilha analisada.
/// @return Um inteiro de representa a quantidade de elementos da pilha.
int getNumeroElementosPilha(Pilha p);

/// @brief Libera a memória da pilha, de todos os seus elementos (nós) e de todos os Pacotes contidos nela.
/// @param p Ponteiro para pilha que será liberada.
/// @warning
void liberarPilha(Pilha p);

#endif //PILHA_H
