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

/// @rief Abre o arquivo .qry para leitura
/// @param qry Ponteiro para o arquivo que será aberto
/// @param arquivo Ponteiro para o nome do arquivo que será aberto
void abrirQry(Arquivo *qry,Nome arquivo);

/// @brief Cria formas lidas do (.qry) e coloca-as no chao
/// @param qry Ponteiro para o arquivo que será lido
/// @param chao Ponteiro para o chao que receberá as formas
void LerComandosExecutar(Arquivo qry,Fila chao);

#endif //QRY_H