//
// Created by natha on 25/09/2025.
//

#ifndef FILA_H
#define FILA_H
/*
 Ponteiro void Fila
 */
typedef void* Fila;
/*
 Cria e retorna uma fila vazia
 */
void iniciarFila(Fila f);
/*
 Enfileira um item na fila
 */

int insercaoFila(Fila f);
/*
 Desinfileirar um item da fila
 */

int excluiritemFila(Fila f);
/*
 Exclui a fila eliminando todos os itens da fila
 */

void reinicializarFila(Fila f);



#endif //FILA_H
