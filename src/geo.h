//
// Created by natha on 09/10/2025.
//

#ifndef GEO_H
#define GEO_H

#include "fila.h"
/*
 Módulo encarregado de ler um arquivo (.geo) e inicializar as formas com as operações de abrir e criar
 */

/*
 Ponteiro do tipo FILE Arquivo
 */
typedef FILE* Arquivo;
typedef char* Nome;

/// @rief Abre o arquivo .geo para leitura
/// @param geo Ponteiro para o arquivo que será aberto
/// @param arquivo Ponteiro para o nome do arquivo que será aberto
void abrirGeo(Arquivo *geo,Nome arquivo);

/// @brief Cria formas lidas do (.geo) e coloca-as no chao
/// @param geo Ponteiro para o arquivo que será lido
/// @param chao Ponteiro para o chao que receberá as formas
void criarFormasNoChao(Arquivo geo,Fila chao);

#endif //GEO_H