//
// Created by natha on 09/10/2025.
//

#ifndef QRY_H
#define QRY_H

/*
 Módulo encarregado de ler um arquivo (.qry) e executar os comandos com as operações de abrir e ler
 */

/*
 Ponteiro do tipo FILE Arquivo
 Ponteiro char Nome
 */
typedef FILE* Arquivo;
typedef char* Nome;

/// @brief Abre o arquivo .qry para leitura
/// @param arquivo Ponteiro para o nome do arquivo que será aberto
/// @return Ponteiro para o arquivo que será aberto
Arquivo abrirQry(Nome arquivo);

/// @brief Lê comandos do (.qry) e executa na arena
/// @param txt Ponteiro para o arquivo que será escrito os dados da leitura
/// @param qry Ponteiro para o arquivo que será lido
/// @param chao Ponteiro para o chao que receberá as formas
/// @param arena Ponteiro para a arena onde estão as formas
/// @param disparadores Ponteiro para o estoque de disparadores
/// @param carregadores Ponteiro para o estoque de carregadores
/// @warning
void LerComandosExecutar(Arquivo txt,Arquivo qry,Fila chao,Fila arena,EstoqueD disparadores, EstoqueC carregadores);

#endif //QRY_H