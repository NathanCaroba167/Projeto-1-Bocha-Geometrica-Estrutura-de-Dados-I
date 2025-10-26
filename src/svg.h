//
// Created by natha on 04/10/2025.
//

#ifndef SVG_H
#define SVG_H

/*
 Módulo encarregado de ler um arquivo (.svg) e executar os comandos com as operações de abrir e ler
 */

/*
 Ponteiro do tipo FILE Arquivo
 Ponteiro char Nome
 */
typedef FILE* Arquivo;
typedef char* Nome;

/// @brief Cria e abre o arquivo SVG para escrita
/// @param arquivo Ponteiro para o nome do arquivo que será criado e aberto
/// @return Ponteiro para o arquivo que será criado e aberto
/// @warning
Arquivo abrirSVG(Nome arquivo);

/// @brief Adiciona a tag do arquivo SVG
/// @param svg Ponteiro para o arquivo que será inicializado
/// @warning
void inicializarSVG(Arquivo svg);

/// @brief Desenha um círculo no arquivo SVG
/// @param svg Ponteiro para o arquivo que receberá o desenho
/// @param c Círculo que será desenhado
/// @warning
void desenharCirculoSVG(Arquivo svg, Circulo c);

/// @brief Desenha um retângulo no arquivo SVG
/// @param svg Ponteiro para o arquivo que receberá o desenho
/// @param r Retângulo que será desenhado
/// @warning
void desenharRetanguloSVG(Arquivo svg, Retangulo r);

/// @brief Desenha uma linha no arquivo SVG
/// @param svg Ponteiro para o arquivo que receberá o desenho
/// @param l Linha que será desenhada
/// @warning
void desenharLinhaSVG(Arquivo svg, Linha l);

/// @brief Desenha um texto no arquivo SVG
/// @param svg Ponteiro para o arquivo que receberá o desenho
/// @param t Texto que será desenhado
/// @param e Estilo do texto que será desenhado
/// @warning
void desenharTextoSVG(Arquivo svg, Texto t, Estilo e);

/// @brief Desenha um asterisco vermelho no local da forma esmagada
/// @param svg Ponteiro para o arquivo que receberá o desenho
/// @param x Coordenada x do asterisco
/// @param y Coordenada y do asterisco
/// @warning
void desenharAsteriscoSVG(Arquivo svg, double x, double y);

/// @brief Desenha as dimensões do disparo a partir do disparador
/// @param svg Ponteiro para o arquivo que receberá o desenho
/// @param d Ponteiro para o disparador que será a referência
/// @param dx Distância da coordenada x a partir do disparador
/// @param dy Distância da coordenada y a partir do disparador
/// @warning
void desenharDimensoesDisparoSVG(Arquivo svg, Disparador d, double dx, double dy);

/// @brief Desenha formas da fila no arquivo SVG
/// @param svg Ponteiro para o arquivo SVG que receberá o desenho
/// @param chao Fila chao que mandará as formas
/// @param EstiloGlobalTexto Estilo global do texto
/// @warning
void desenharFormasDaFila(Arquivo svg, Fila chao,Estilo EstiloGlobalTexto);

/// @brief Fecha o arquivo SVG
/// @param svg Ponteiro para o arquivo que será fechado
/// @warning
void fecharSVG(Arquivo svg);

/// @brief Gera arquivo SVG após a leitura da fila
/// @param chao Fila chao que mandará as formas
/// @param caminho Caminho para o arquivo SVG
/// @param EstiloGlobalTexto Estilo global do texto
/// @warning
void gerarSVG(Fila chao, char* caminho, Estilo EstiloGlobalTexto);

#endif //SVG_H