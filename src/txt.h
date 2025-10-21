//
// Created by natha on 16/10/2025.
//

#ifndef TXT_H
#define TXT_H

/*
 Módulo encarregado de criar um arquivo (.txt) e reportar os resultados de comandos com as operações de abrir e reportar
 */

/// @brief Cria e abre o arquivo TXT para escrita
/// @param arquivo Ponteiro para o nome do arquivo que será criado e aberto
/// @return Ponteiro para o arquivo que será criado e aberto
/// @warning
Arquivo abrirTXT(Nome arquivo);

/// @brief Escreve no arquivo TXT os dados da forma recebida
/// @param txt Ponteiro para o arquivo que será escrito os dados
/// @param p Ponteiro para a forma que os dados seão avaliados
/// @warning
void reportarForma(Arquivo txt,Pacote p);

/// @brief Escreve a posição final de um ponto âncora da forma após o disparo no arquivo TXT
/// @param txt Ponteiro para o arquivo que será escrito a posição
/// @param p Ponteiro para a forma que foi disparada
/// @warning
void reportarPosiçãoFinal(Arquivo txt, Pacote p);

/// @brief Escreve a área total esmagada do round e a área total(Soma das áreas esmagadas de todos os rounds) no arquivo TXT
/// @param txt Ponteiro para o arquivo que será escrito as áreas
/// @param areaRound Área total esmagada do round
/// @param areaTotal Área total
/// @warning
void reportarÁreaTotalEsmagada(Arquivo txt, double areaRound, double areaTotal);

/// @brief Escreve o resultado final após a leitura do arquivo (.qry), com os dados da
/// Pontuação Final; Número total de Instruções executadas; Número total de Disparos;
/// Número total de Formas Esmagadas e Número total de Formas Clonadas, no arquivo TXT
/// @param txt Ponteiro para o arquivo que será escrito o resultado final
/// @param areaTotal Área total
/// @param instrucoes Número total de Instruções executadas
/// @param disparos Número total de Disparos
/// @param formas_esmagadas Número total de Formas Esmagadas
/// @param formas_clonadas Número total de Formas Clonadas
/// @warning
void reportarResultadosFinais(Arquivo txt, double areaTotal, int instrucoes, int disparos, int formas_esmagadas, int formas_clonadas);

#endif //TXT_H