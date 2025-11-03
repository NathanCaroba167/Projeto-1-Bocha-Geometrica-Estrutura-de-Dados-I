//
// Created by natha on 04/10/2025.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>

#include "circulo.h"
#include "retangulo.h"
#include "linha.h"
#include "texto.h"
#include "forma.h"

#include "pilha.h"
#include "fila.h"
#include "txt.h"
#include "carregador.h"
#include "disparador.h"
#include "svg.h"

Arquivo abrirSVG(Nome arquivo) {
    Arquivo svg = fopen(arquivo,"w");
    if (svg == NULL) {
        printf("Erro ao abrir o arquivo svg!\n");

        perror("Motivo do erro");
        exit(1);
    }
    return svg;
}

void inicializarSVG(Arquivo svg) {
    if (svg == NULL) return;
    fprintf(svg,"<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"no\"?>\n");
    fprintf(svg,"<svg xmlns:svg=\"http://www.w3.org/2000/svg\" xmlns=\"http://www.w3.org/2000/svg\" width=\"1000\" height=\"1000\">\n");
    fprintf(svg,"\t<g>\n");
}

void desenharCirculoSVG(Arquivo svg, Circulo c) {
    if (svg == NULL || c == NULL) return;
    fprintf(svg, "<circle id=\"%d\" "
                 "cx=\"%lf\" "
                 "cy=\"%lf\" "
                 "r=\"%lf\" "
                 "stroke=\"%s\" "
                 "fill=\"%s\" "
                 "opacity=\"%lf\" "
                 "stroke-width=\"%lf\" "
                 "/>\n",
                 getIDCirculo(c),
                 getXCirculo(c),
                 getYCirculo(c),
                 getRCirculo(c),
                 getCorBCirculo(c),
                 getCorPCirculo(c),
                 0.5,
                 1.5);
}

void desenharRetanguloSVG(Arquivo svg, Retangulo r) {
    if (svg == NULL || r == NULL) return;
    fprintf(svg, "\t<rect id=\"%d\" "
                 "x=\"%lf\" "
                 "y=\"%lf\" "
                 "width=\"%lf\" "
                 "height=\"%lf\" "
                 "stroke=\"%s\" "
                 "fill=\"%s\" "
                 "opacity=\"%lf\" "
                 "stroke-width=\"%lf\" "
                 "/>\n",
                 getIDRetangulo(r),
                 getXRetangulo(r),
                 getYRetangulo(r),
                 getWRetangulo(r),
                 getHRetangulo(r),
                 getCorBRetangulo(r),
                 getCorPRetangulo(r),
                 0.5,
                 1.5);

}

void desenharLinhaSVG(Arquivo svg, Linha l) {
    if (svg == NULL || l == NULL) return;
    fprintf(svg, "\t<line id=\"%d\" "
                 "x1=\"%lf\" "
                 "y1=\"%lf\" "
                 "x2=\"%lf\" "
                 "y2=\"%lf\" "
                 "stroke=\"%s\" "
                 "stroke-width=\"%lf\" "
                 "/>\n",
                 getIDLinha(l),
                 getX1Linha(l),
                 getY1Linha(l),
                 getX2Linha(l),
                 getY2Linha(l),
                 getCorLinha(l),
                 1.5);

}

void desenharTextoSVG(Arquivo svg, Texto t, Estilo e) {
    if (svg == NULL || t == NULL || e == NULL) return;
    fprintf(svg, "\t<text id=\"%d\" "
                 "x=\"%lf\" "
                 "y=\"%lf\" "
                 "stroke=\"%s\" "
                 "fill=\"%s\" "
                 "font-family=\"%s\" "
                 "font-weight=\"%s\" "
                 "font-size=\"%spt\" ",
                 getIDTexto(t),
                 getXTexto(t),
                 getYTexto(t),
                 getCorBTexto(t),
                 getCorPTexto(t),
                 getFontFamilyTexto(e),
                 getFontWeightTexto(e),
                 getFontSizeTexto(e));

    switch (getATexto(t)) {
        case 'i':
            fprintf(svg, "text-anchor=\"start\" ");
            break;
        case 'm':
            fprintf(svg, "text-anchor=\"middle\" ");
            break;
        case 'f':
            fprintf(svg, "text-anchor=\"end\" ");
            break;
        default:
            printf("Indice de ancora '%c' incorreto!\n",getATexto(t));
            break;
    }
    fprintf(svg, ">%s</text>\n", getTxtoTexto(t));

}

void desenharAsteriscoSVG(Arquivo svg, double x, double y) {
    if (svg == NULL) return;
    fprintf(svg, "\t<text x=\"%lf\" "
                 "y=\"%lf\" "
                 "fill=\"red\" "
                 "font-size=\"%d\" "
                 ">*</text>\n",
                 x,
                 y,
                 18);
}

void desenharDimensoesDisparoSVG(Arquivo svg, Disparador d, double dx, double dy) {
    if (svg == NULL || d == NULL) return;

    // Linha principal do disparo
    fprintf(svg, "\t<line x1=\"%lf\" "
                 "y1=\"%lf\" "
                 "x2=\"%lf\" "
                 "y2=\"%lf\" "
                 "stroke=\"purple\" "
                 "stroke-width=\"%lf\" "
                 "/>\n",
                 getXDisparador(d),
                 getYDisparador(d),
                 getXDisparador(d) + dx,
                 getYDisparador(d) + dy,
                 1.5);

    // Linha tracejada vertical (dy)
    fprintf(svg, "\t<line x1=\"%lf\" "
                 "y1=\"%lf\" "
                 "x2=\"%lf\" "
                 "y2=\"%lf\" "
                 "stroke=\"purple\" "
                 "stroke-dasharray=\"3,3\" "
                 "stroke-width=\"%lf\" "
                 "/>\n",
                 getXDisparador(d) + dx,
                 getYDisparador(d),
                 getXDisparador(d) + dx,
                 getYDisparador(d) + dy,
                 1.2);

    // Linha tracejada horizontal (dx)
    fprintf(svg, "\t<line x1=\"%lf\" "
                 "y1=\"%lf\" "
                 "x2=\"%lf\" "
                 "y2=\"%lf\" "
                 "stroke=\"purple\" "
                 "stroke-dasharray=\"3,3\" "
                 "stroke-width=\"%lf\" "
                 "/>\n",
                 getXDisparador(d) + dx,
                 getYDisparador(d) + dy,
                 getXDisparador(d),
                 getYDisparador(d) + dy,
                 1.2);

    // Número de dimensão X (horizontal)
    fprintf(svg, "\t<text x=\"%lf\" "
                 "y=\"%lf\" "
                 "fill=\"purple\" "
                 "font-size=\"%d\" "
                 "text-anchor=\"middle\" "
                 ">%.2lf</text>\n",
                 (2 * getXDisparador(d) + dx)/2, // Ponto médio X
                 getYDisparador(d) - 5,
                 18,
                 dx);

    // Texto de dimensão Y (vertical)
    fprintf(svg, "\t<text x=\"%lf\" "
                 "y=\"%lf\" "
                 "fill=\"purple\" "
                 "font-size=\"%d\" "
                 "text-anchor=\"end\" "
                 ">%.2lf</text>\n",
                 getXDisparador(d) + dx + 5,
                 (2 * getYDisparador(d) + dy)/2, // Ponto médio Y
                 18,
                 dy);
}

void desenharFormasDaFila(Arquivo svg, Fila chao, Estilo EstiloGlobalTexto) {
    if (svg == NULL || chao == NULL || filavazia(chao)) {
        exit(1);
    }

    pont atual = getPrimeiroElementoFila(chao);

    while (atual != NULL) {
        Pacote p = getFormaElementoFila(atual);

        TipoForma tipo = getTipoForma(p);
        Forma forma = getDadosForma(p);

        switch (tipo) {
            case CIRCULO:
                desenharCirculoSVG(svg, forma);
                break;
            case RETANGULO:
                desenharRetanguloSVG(svg, forma);
                break;
            case LINHA:
                desenharLinhaSVG(svg, forma);
                break;
            case TEXTO:
                desenharTextoSVG(svg, forma, EstiloGlobalTexto);
                break;
            default:
                printf("ERRO: tipo inválido!\n");
                break;
        }

        atual = getProximoElementoFila(atual);
    }
}

void fecharSVG(Arquivo svg) {
    if (svg == NULL) return;
    fprintf(svg, "</g>\n");
    fprintf(svg,"</svg>\n");

    printf("Arquivo SVG gerado com sucesso!\n");

}

void gerarSVG(Fila chao, Arquivo arqSvg,Estilo EstiloGlobalTexto) {
    desenharFormasDaFila(arqSvg, chao,EstiloGlobalTexto);
    fecharSVG(arqSvg);
}