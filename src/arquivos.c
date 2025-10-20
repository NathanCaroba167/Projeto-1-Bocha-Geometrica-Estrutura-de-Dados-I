//
// Created by natha on 16/10/2025.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arquivos.h"


char* getNomeBase(char* nomeArq) {
    char* ponto = strrchr(nomeArq, '.');
    int tamanhoBase;

    if (ponto == NULL) {
        tamanhoBase = strlen(nomeArq);
    }else {
        tamanhoBase = ponto - nomeArq;
    }

    char* nomeBase = (char*) malloc(tamanhoBase + 1);
    if (nomeBase == NULL) {
        printf("Erro ao alocar memoria\n");
        return NULL;
    }

    strncpy(nomeBase, nomeArq, tamanhoBase);
    nomeBase[tamanhoBase] = '\0';

    return nomeBase;
}