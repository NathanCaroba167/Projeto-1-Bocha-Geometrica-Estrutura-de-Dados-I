//
// Created by natha on 16/10/2025.
//

#ifndef ARQUIVOS_H
#define ARQUIVOS_H

/*
 Módulo encarregado de pegar o nome base de um arquivo a partir da operação de get
 */

/// @brief Pega o nome base do arquivo (tudo antes do '.')
/// @param nomeArq Nome do arquivo que será analisado
/// @return String com o nome base do arquivo
/// @warning
char* getNomeBase(char* nomeArq);

#endif //ARQUIVOS_H