//
// Created by natha on 13/10/2025.
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
#include "fila.h"
#include "pilha.h"
#include "txt.h"
#include "carregador.h"
#include "disparador.h"
#include "estoque.h"
#include "arquivos.h"
#include "geo.h"
#include "qry.h"
#include "svg.h"

#define MAX_CAMINHO 256

// O estilo deve ser inicializado antes de ser passado para criarFormasNoChao
static Estilo EstiloGlobalTexto = NULL;

int main(int argc, char* argv[]) {
    // Variáveis de Argumentos
    char* dirEntrada = NULL; // -e
    char* nomeArqGeo = NULL; // -f
    char* nomeArqQry = NULL; // -q
    char* dirSaida = NULL; // -o

    // Variáveis de Estruturas de Dados
    Fila chao = NULL;
    Fila arena = NULL;

    // Análise de argumentos
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
        printf("ERRO: Parâmetros obrigatórios -f (.geo) e -o (diretorio saida1) não fornecidos!!\n");
        return 1;
    }

    // Construção de caminhos geo (necessário para SVG inicial)
    char caminhoCompletoGeo[MAX_CAMINHO];
    if (dirEntrada != NULL) {
        snprintf(caminhoCompletoGeo,MAX_CAMINHO, "%s/%s", dirEntrada, nomeArqGeo);
    } else {
        snprintf(caminhoCompletoGeo,MAX_CAMINHO, "%s", nomeArqGeo);
    }

    char* nomeBaseGeo = getNomeBase(nomeArqGeo);
    if (nomeBaseGeo ==  NULL) {
        printf("Erro: nome base do arquivo geo");
        return 1;
    }

    char caminhoSaidaSvgInicial[MAX_CAMINHO];
    snprintf(caminhoSaidaSvgInicial,MAX_CAMINHO, "%s/%s.svg", dirSaida, nomeBaseGeo);

    // Construção de caminhos qry (se existir)
    char caminhoCompletoQry[MAX_CAMINHO];
    char caminhoSaidaSvgFinal[MAX_CAMINHO];
    char caminhoSaidaTxt[MAX_CAMINHO];
    if (nomeArqQry != NULL) {
        if (dirEntrada != NULL) {
            snprintf(caminhoCompletoQry,MAX_CAMINHO, "%s/%s", dirEntrada, nomeArqQry);
        }else {
            strcpy(caminhoCompletoQry, nomeArqQry);
        }


        char* nomeBaseQry = getNomeBase(nomeArqQry);
        if (nomeBaseQry ==  NULL) {
            free(nomeBaseGeo);
            return 1;
        }
        char nomeCombinado[MAX_CAMINHO];
        snprintf(nomeCombinado,MAX_CAMINHO, "%s-%s", nomeBaseGeo, nomeBaseQry);

        snprintf(caminhoSaidaSvgFinal,MAX_CAMINHO, "%s/%s.svg", dirSaida, nomeCombinado);
        snprintf(caminhoSaidaTxt,MAX_CAMINHO, "%s/%s.txt", dirSaida, nomeCombinado);

        free(nomeBaseQry);
    }

    free(nomeBaseGeo);

    // Inicialização do estilo padrão (será substituído se 'ts' for encontrado no .geo)
    if (EstiloGlobalTexto == NULL) {
        EstiloGlobalTexto = CriarEstilo("Arial, sans-serif", "normal", "12");
        if (EstiloGlobalTexto == NULL) {
            printf("ERRO: Falha ao inicializar o estilo padrão de texto!\n");
            return 1;
        }
    }

    chao = iniciarFila();
    arena = iniciarFila();
    EstoqueD disparadores = CriarEstoqueDisparadores(5);
    EstoqueC carregadores = CriarEstoqueCarregadores(10);


    // Execução do fluxo .geo
    Arquivo arqGeo = NULL;
    arqGeo = abrirGeo(caminhoCompletoGeo);
    if (arqGeo == NULL) {
        printf("ERRO: ao tentar abrir o arquivo .geo");
        liberarFila(chao);
        liberarFila(arena);
        liberarEstoqueDisparadores(disparadores);
        liberarEstoqueCarregadores(carregadores);
        return 1;
    }

    criarFormasNoChao(arqGeo, chao,&EstiloGlobalTexto);
    fclose(arqGeo);

    // Geração do SVG Inicial
    Arquivo arqSvg = NULL;
    arqSvg = abrirSVG(caminhoSaidaSvgInicial);
    inicializarSVG(arqSvg);

    gerarSVG(chao,arqSvg,EstiloGlobalTexto);

    // Execução do fluxo .qry (se especificado)
    if (nomeArqQry != NULL) {
        Arquivo arqQry = NULL;
        arqQry = abrirQry(caminhoCompletoQry);
        Arquivo arqTxt = NULL;
        arqTxt = abrirTXT(caminhoSaidaTxt);
        Arquivo arqSvgFinal = NULL;
        arqSvgFinal = abrirSVG(caminhoSaidaSvgFinal);
        inicializarSVG(arqSvgFinal);
        if (arqQry == NULL) {
            printf("ERRO: ao tentar abrir o arquivo .qry");
            liberarFila(chao);
            liberarFila(arena);
            liberarEstoqueDisparadores(disparadores);
            liberarEstoqueCarregadores(carregadores);
            return 1;
        }
        LerComandosExecutar(arqSvgFinal, arqTxt,arqQry, chao, arena, disparadores, carregadores);
        fclose(arqQry);
        fclose(arqTxt);

        // Geração do SVG Final
        gerarSVG(chao,arqSvgFinal,EstiloGlobalTexto);
        fclose(arqSvgFinal);
    }

    fclose(arqSvg);

    // Limpeza da memória
    printf("Limpando a memória ...\n");
    liberarFila(chao);
    liberarFila(arena);
    liberarEstoqueDisparadores(disparadores);
    liberarEstoqueCarregadores(carregadores);
    if (EstiloGlobalTexto != NULL) {
        eliminarEstilo(EstiloGlobalTexto);
    }

    return 0;
}
