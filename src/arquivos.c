//
// Created by natha on 16/10/2025.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "arquivos.h"


char* getNomeBase(char* nomeArq) {

    char* barra = strrchr(nomeArq, '/');
    char* Nome = (barra != NULL) ? barra + 1 : nomeArq;

    char* ponto = strrchr(Nome, '.');
    int tamanhoBase;

    if (ponto == NULL) {
        tamanhoBase = strlen(Nome);
    }else {
        tamanhoBase = ponto - Nome;
    }

    char* nomeBase = (char*) malloc(tamanhoBase + 1);
    if (nomeBase == NULL) {
        printf("Erro ao alocar memória de nomeBase!\n");

        perror("Motivo do erro");
        exit(1);
    }

    strncpy(nomeBase, Nome, tamanhoBase);
    nomeBase[tamanhoBase] = '\0';

    return nomeBase;
}