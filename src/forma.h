//
// Created by natha on 15/10/2025.
//

#ifndef FORMA_H
#define FORMA_H

typedef enum {
    CIRCULO,
    RETANGULO,
    LINHA,
    TEXTO
}TipoForma;

typedef struct pacote* Pacote;


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

/// @brief Libera a memoria alocada para o pacote
/// @param p Ponteiro para o pacote analisado
void liberarForma(Pacote p);

#endif //FORMA_H