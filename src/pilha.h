//
// Created by natha on 25/09/2025.
//

#ifndef PILHA_H
#define PILHA_H

/*
 Ponteiro void Pilha
 */
typedef void* Pilha;

/*
 Cria e retorna uma pilha vazia
 */
void criarpilha(Pilha p);
/*
 Empilha um item. Retorna true se bem-sucedido
 */

int empilhar(Pilha p, char* letra);
/*
 Desempilha o item do topo da pilha
 */
int desempilhar(Pilha p);
/*
 Reseta a pilha excluindo todos os itens, retornando uma pilha vazia
 */
void resetar(Pilha p);
/*
 Retorna a quantidade de elementos ou NULL se a pilha estiver vazia
 */

int numeroelementos(Pilha p);
/*
 Verifica se a pilha esta vazia. Retorna verdadeira se estiver vazia e false caso tiver pelo menos um elemento
 */

void pilhavazia(Pilha p);

#endif //PILHA_H
