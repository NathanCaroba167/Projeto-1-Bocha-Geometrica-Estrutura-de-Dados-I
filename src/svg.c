//
// Created by natha on 04/10/2025.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "circulo.h"
#include "retangulo.h"
#include "linha.h"
#include "texto.h"
#include "disparador.h"
#include "svg.h"

void abrirSVG(Arquivo *svg,Nome arquivo) {
    *svg = fopen(arquivo,"w");
    if (*svg == NULL) {
        printf("Erro ao abrir o arquivo\n");
        exit(1);
    }
}

void inicializarSVG(Arquivo svg) {
    fprintf(svg,"<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"no\"?>\n");
    fprintf(svg,"<svg xmlns:svg=\"http://www.w3.org/2000/svg\" xmlns=\"http://www.w3.org/2000/svg\" width=\"1000\" height=\"1000\">\n");
    fprintf(svg,"</g>\n");
}

void desenharCirculoSVG(Arquivo svg, Circulo c) {
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
                 getFontFamilyTexto(t),
                 getFontWeightTexto(t),
                 getFontSizeTexto(t));

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

    fprintf(svg, "\t<text x=\"%lf\" "
                 "y=\"%lf\" "
                 "fill=\"purple\" "
                 "font-size=\"%d\" "
                 "text-anchor=\"middle\" "
                 ">%.2lf</text>\n",
                 (2 * getXDisparador(d) + dx)/2,
                 getYDisparador(d) - 5,
                 18,
                 dx);

    fprintf(svg, "\t<text x=\"%lf\" "
                 "y=\"%lf\" "
                 "fill=\"purple\" "
                 "font-size=\"%d\" "
                 "text-anchor=\"end\" "
                 ">%.2lf</text>\n",
                 getXDisparador(d) + dx + 5,
                 (2 * getYDisparador(d) + dy)/2,
                 18,
                 dy);

    fprintf(svg, "\t<text x=\"%lf\" "
                 "y=\"%lf\" "
                 "fill=\"red\" "
                 "font-size=\"%d\" "
                 "text-anchor=\"middle\" "
                 "dominant-baseline=\"middle\" "
                 ">*</text>\n",
                 getXDisparador(d) + dx,
                 getYDisparador(d) + dy,
                 22);
}

void fecharSVG(Arquivo svg) {
    fprintf(svg, "</g>\n");
    fprintf(svg,"</svg>\n");
    fclose(svg);

    printf("Arquivo SVG gerado com sucesso!\n");

}