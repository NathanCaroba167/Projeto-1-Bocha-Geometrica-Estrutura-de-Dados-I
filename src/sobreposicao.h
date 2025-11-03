//
// Created by natha on 15/10/2025.
//

#ifndef SOBREPOSICAO_H
#define SOBREPOSICAO_H

/*
 Módulo encarregado de verificar as sobreposições das formas a partir da operação de verificar
 */

/// @brief Verifica se duas formas (Pacotes) estão sobrepostas.
/// @param g1 Ponteiro para primeira forma analisada.
/// @param g2 Ponteiro para segunda forma analisada.
/// @return True (1) se houver sobreposição ou False (0) se não houver sobreposição.
bool verificarSobreposicao(Pacote g1,Pacote g2);

#endif //SOBREPOSICAO_H