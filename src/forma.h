//
// Created by natha on 15/10/2025.
//

#ifndef FORMA_H
#define FORMA_H

/*
 Módulo encarregado de executar e coordenar uma pilha com operações de iniciar, empilhar, desempilhar, get, 'pilhavazia' e liberar
 */

typedef enum {
    CIRCULO,
    RETANGULO,
    LINHA,
    TEXTO
}TipoForma;

/*
 Ponteiro void Pacote
 Ponteiro void Forma
 */
typedef void* Pacote;
typedef void* Forma;

/// @brief Cria o pacote da forma com o tipo dela
/// @param g Ponteiro para forma que será empacotada
/// @param tipo Tipo da forma que foi empacotada
/// @return Ponteiro para o pacote criado
/// @warning
Pacote CriarPacote(Forma g,TipoForma tipo);

/// @brief Pega a forma que está no pacote sem modifica-lo
/// @param p Ponteiro para o pacote analisado
/// @return Ponteiro para forma que foi pega
/// @warning
Forma getDadosForma(Pacote p);

/// @brief Pega o tipo da forma que está dentro do pacote sem modifica-lo
/// @param p Ponteiro para o pacote analisado
/// @return Ponteiro para o tipo de forma que foi pega
/// @warning
TipoForma getTipoForma(Pacote p);

/// @brief Pega a area da forma
/// @param p Ponteiro para a forma que a area será calculada
/// @return O valor da área da forma calculada
/// @warning
double getAreaForma(Pacote p);

/// @brief Pega o ID da forma sem modifica-la
/// @param p Ponteiro para a forma que será pego o ID
/// @return O ID da forma
int getIDForma(Pacote p);

/// @brief Pega a cor de borda da forma sem modifica-la
/// @param p Ponteiro para a forma que será pega a cor de borda
/// @return String com a cor de borda da forma
/// @warning
char* getCorBForma(Pacote p);

/// @brief Pega a cor de preenchimento da forma sem modifica-la
/// @param p Ponteiro para a forma que será pega a cor de preenchimento
/// @return String com a cor de preenchimento da forma
/// @warning
char* getCorPForma(Pacote p);

/// @brief Define a nova cor de borda da forma
/// @param p Ponteiro para a forma onde a cor de borda será definida
/// @param corB Nova cor de borda que será definida
/// @warning
void setCorBForma(Pacote p, char* corB);

/// @brief Define a nova cor de preenchimento da forma
/// @param p Ponteiro para a forma onde a cor de preenchimento será definida
/// @param corP Nova cor de preenchimento que será definida
/// @warning
void setCorPForma(Pacote p, char* corP);

/// @brief Armazena o maior ID do jogo
/// @param maior_id Maior ID do jogo
/// @warning
void armazenaMaiorId(int maior_id);

/// @brief Pega o Maior ID a ser definido
/// @return Maior ID a ser definido
/// @warning
int getMaiorId();

/// @brief Clona uma forma
/// @param p Ponteiro para forma que será clonada
/// @return Ponteiro para forma clonada
Pacote clonarForma(Pacote p);

/// @brief Libera a memoria alocada para o pacote
/// @param p Ponteiro para o pacote analisado
void liberarForma(Pacote p);

#endif //FORMA_H