//
// Created by natha on 13/10/2025.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "circulo.h"
#include "retangulo.h"
#include "linha.h"
#include "texto.h"
#include "carregador.h"
#include "disparador.h"
#include "estoque.h"
#include "arquivos.h"
#include "geo.h"
#include "qry.h"
#include "svg.h"


int main(int argc, char* argv[]) {
    char* dirEntrada = NULL; // -e
    char* nomeArqGeo = NULL; // -f
    char* nomeArqQry = NULL; // -q
    char* dirSaida = NULL; // -o
    Fila chao = NULL;
    Fila arena = NULL;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-e") == 0 && i + 1 < argc) {
            dirEntrada = argv[i + 1];
            i++;
        } else if (strcmp(argv[i], "-f") == 0 && i + 1 < argc) {
            nomeArqGeo = argv[i + 1];
            i++;
        } else if (strcmp(argv[i], "-o") == 0 && i + 1 < argc) {
            dirSaida = argv[i + 1];
            i++;
        } else if (strcmp(argv[i], "-q") == 0 && i + 1 < argc) {
            nomeArqQry = argv[i + 1];
            i++;
        }else {
            printf("Parametro '%s' inválido!!\n", argv[i]);
        }
    }

    if (nomeArqGeo == NULL || dirSaida == NULL) {
        printf("ERRO: Parâmetros obrigatórios -f (.geo) e -o (diretorio saida) não fornecidos!!\n");
        return 1;
    }

    char caminhoCompletoGeo[256];
    if (dirEntrada != NULL) {
        sprintf(caminhoCompletoGeo, "%s/%s", dirEntrada, nomeArqGeo);
    } else {
        sprintf(caminhoCompletoGeo, "%s", nomeArqGeo);
    }

    char* nomeBaseGeo = pegarNomeBase(nomeArqGeo);
    if (nomeBaseGeo ==  NULL) {
        printf("Erro: nome base do arquivo geo");
        return 1;
    }

    char caminhoSaidaSvgInicial[256];
    sprintf(caminhoSaidaSvgInicial, "%s/%s.svg", dirSaida, nomeBaseGeo);

    char caminhoCompletoQry[256];
    char caminhoSaidaSvgFinal[256];
    char caminhoSaidaTxt[256];
    if (nomeArqQry != NULL) {
        if (dirEntrada != NULL) {
            sprintf(caminhoCompletoQry, "%s/%s", dirEntrada, nomeArqQry);
        }else {
            strcpy(caminhoCompletoQry, nomeArqQry);
        }


        char* nomeBaseQry = pegarNomeBase(nomeArqQry);
        if (nomeBaseQry ==  NULL) {
            free(nomeBaseGeo);
            return 1;
        }
        char nomeCombinado[256];
        sprintf(nomeCombinado, "%s-%s", nomeBaseGeo, nomeBaseQry);

        sprintf(caminhoSaidaSvgFinal, "%s/%s.svg", dirSaida, nomeCombinado);
        sprintf(caminhoSaidaTxt, "%s/%s.txt", dirSaida, nomeCombinado);

        free(nomeBaseQry);
    }

    free(nomeBaseGeo);

    chao = iniciarFila();
    arena = iniciarFila();
    EstoqueD disparadores = CriarEstoqueDisparadores(5);
    EstoqueC carregadores = CriarEstoqueCarregadores(10);



    Arquivo arqGeo = NULL;
    arqGeo = abrirGeo(caminhoCompletoGeo);
    if (arqGeo == NULL) {
        printf("ERRO: ao tentar abrir o arquivo .geo");
        free(nomeBaseGeo);
        liberarFila(chao);
        liberarFila(arena);
        liberarEstoqueDisparadores(disparadores);
        liberarEstoqueCarregadores(carregadores);
        return 1;
    }

    criarFormasNoChao(arqGeo, chao);
    fclose(arqGeo);

    gerarSVG(chao,caminhoSaidaSvgInicial);


    if (nomeArqQry != NULL) {
        Arquivo arqQry = NULL;
        arqQry = abrirQry(caminhoCompletoQry);
        if (arqQry == NULL) {
            printf("ERRO: ao tentar abrir o arquivo .qry");
            free(nomeBaseGeo);
            liberarFila(chao);
            liberarFila(arena);
            liberarEstoqueDisparadores(disparadores);
            liberarEstoqueCarregadores(carregadores);
            return 1;
        }
        LerComandosExecutar(arqQry, chao, arena, disparadores, carregadores);///
        fclose(arqQry);

        gerarSVG(chao,caminhoSaidaSvgFinal);
        gerarTXT(caminhoSaidaTxt);///
    }

    printf("Limpando a memória ...\n");
    liberarFila(chao);
    liberarFila(arena);
    liberarEstoqueDisparadores(disparadores);
    liberarEstoqueCarregadores(carregadores);

    return 0;
}