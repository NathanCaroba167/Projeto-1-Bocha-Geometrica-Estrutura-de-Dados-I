//
// Created by natha on 16/10/2025.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "circulo.h"
#include "retangulo.h"
#include "linha.h"
#include "texto.h"
#include "forma.h"

#include "fila.h"

#include "geo.h"
#include "txt.h"

Arquivo abrirTXT(Nome arquivo) {
    Arquivo txt = fopen(arquivo,"w");
    if (txt == NULL) {
        printf("Erro ao abrir o arquivo txt!\n");

        perror("Motivo do erro");
        exit(1);
    }
    return txt;
}

void reportarForma(Arquivo txt,Pacote p) {

    TipoForma tipo = getTipoForma(p);

    switch (tipo) {
        case CIRCULO:
            Circulo c = getDadosForma(p);
            fprintf(txt, "Círculo ID =\"%d\" "
                 "Centro = X=\"%lf\" "
                 "Y =\"%lf\" "
                 "Raio =\"%lf\" "
                 "Cor de Borda =\"%s\" "
                 "Cor de Preenchimento =\"%s\" "
                 "\n",
                 getIDCirculo(c),
                 getXCirculo(c),
                 getYCirculo(c),
                 getRCirculo(c),
                 getCorBCirculo(c),
                 getCorPCirculo(c));
            break;
        case RETANGULO:
            Retangulo r = getDadosForma(p);
            fprintf(txt, "Retângulo ID =\"%d\" "
                 "Âncora(Ponto Inferior Esquerdo)= X =\"%lf\" "
                 "Y =\"%lf\" "
                 "Largura =\"%lf\" "
                 "Altura =\"%lf\" "
                 "Cor de Borda =\"%s\" "
                 "Cor de Preenchimento =\"%s\" "
                 "\n",
                 getIDRetangulo(r),
                 getXRetangulo(r),
                 getYRetangulo(r),
                 getWRetangulo(r),
                 getHRetangulo(r),
                 getCorBRetangulo(r),
                 getCorPRetangulo(r));
            break;
        case LINHA:
            Linha l = getDadosForma(p);
            fprintf(txt, "Linha ID =\"%d\" "
                 "Ponto de Ínicio = X =\"%lf\" "
                 "Y =\"%lf\" "
                 "Ponto de Fim = X2 = \"%lf\" "
                 "Y2 =\"%lf\" "
                 "Cor =\"%s\" "
                 "\n",
                 getIDLinha(l),
                 getX1Linha(l),
                 getY1Linha(l),
                 getX2Linha(l),
                 getY2Linha(l),
                 getCorLinha(l));
            break;
        case TEXTO:
            Texto t = getDadosForma(p);
            fprintf(txt, "Texto ID =\"%d\" "
                 "Âncora = X =\"%lf\" "
                 "Y =\"%lf\" "
                 "Cor de Borda =\"%s\" "
                 "Cor de Preenchimento =\"%s\" "
                 "Local da Âncora =\"%c\" "
                 "Conteúdo =\"%s\" "
                 "\n",
                 getIDTexto(t),
                 getXTexto(t),
                 getYTexto(t),
                 getCorBTexto(t),
                 getCorPTexto(t),
                 getATexto(t),
                 getTxtoTexto(t));
            break;
        default:
            printf("ERRO: tipo inválido!\n");
            break;
    }
}

void reportarPosiçãoFinal(Arquivo txt, Pacote p) {
    TipoForma tipo = getTipoForma(p);
    fprintf(txt, "Posição final - ");

    switch (tipo) {
        case CIRCULO:
            Circulo c = getDadosForma(p);
            fprintf(txt, "X =\"%lf\" "
                 "Y =\"%lf\" "
                 "\n",
                 getXCirculo(c),
                 getYCirculo(c));
            break;
        case RETANGULO:
            Retangulo r = getDadosForma(p);
            fprintf(txt, "X =\"%lf\" "
                 "Y =\"%lf\" "
                 "\n",
                 getXRetangulo(r),
                 getYRetangulo(r));
            break;
        case LINHA:
            Linha l = getDadosForma(p);
            fprintf(txt, "X =\"%lf\" "
                "Y =\"%lf\" "
                "X2 =\"%lf\" "
                "Y2 =\"%lf\" "
                "\n",
                getX1Linha(l),
                getY1Linha(l),
                getX2Linha(l),
                getY2Linha(l));
            break;
        case TEXTO:
            Texto t = getDadosForma(p);
            fprintf(txt, "X =\"%lf\" "
                "Y =\"%lf\" "
                "\n",
                getXTexto(t),
                getYTexto(t));
            break;
        default:
            printf("ERRO: tipo inválido!\n");
            break;
    }
}

void reportarÁreaTotalEsmagada(Arquivo txt, double areaRound, double areaTotal) {
    fprintf(txt, "Área do Round Esmagada: %lf\n"
                 "Área Total Esmagada: %lf"
                 "\n",
                 areaRound,
                 areaTotal);
}

void reportarResultadosFinais(Arquivo txt, double areaTotal, int instrucoes, int disparos, int formas_esmagadas, int formas_clonadas) {
    fprintf(txt, "Pontuação Final: %lf \n"
                 "Número total de instruções executadas: %d \n"
                 "Número total de disparos: %d \n"
                 "Número total de formas esmagadas: %d \n"
                 "Número total de formas clonadas: %d \n"
                 "\n",
                 areaTotal,
                 instrucoes,
                 disparos,
                 formas_esmagadas,
                 formas_clonadas);
}


