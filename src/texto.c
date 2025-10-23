//
// Created by natha on 19/09/2025.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "texto.h"

#include "linha.h"

typedef struct{
    char* fFamily;
    char* fWeight;
    char* fSize;
}estilo;

typedef struct{
    int i;
    double x,y;
    char* corB;
    char* corP;
    char a;
    char* txto;
    Estilo Estilo;
}texto;

Estilo CriarEstilo(char* fFamily, char* fWeight, char* fSize) {
    estilo* e = (estilo*)malloc(sizeof(estilo));
    if (e == NULL) {
        printf("Erro ao alocar memoria!\n");
        exit(1);
    }

    e->fFamily = (char*) malloc (strlen(fFamily) + 1);
    if (e->fFamily == NULL) {
        printf("Erro ao alocar memoria!\n");
        exit(1);
    }
    strcpy(e->fFamily,fFamily);

    e->fWeight = (char*) malloc (strlen(fWeight) + 1);
    if (e->fWeight == NULL) {
        printf("Erro ao alocar memoria!\n");
        exit(1);
    }
    strcpy(e->fWeight,fWeight);

    e->fSize = (char*) malloc (strlen(fSize) + 1);
    if (e->fSize == NULL) {
        printf("Erro ao alocar memoria!\n");
        exit(1);
    }
    strcpy(e->fSize,fSize);

    return e;
}

Texto CriarTexto(int i, double x, double y, char* corB, char* corP, char a, char* txto) {
    texto* t = (texto*)malloc(sizeof(texto));

    if (t == NULL) {
        printf("Erro ao alocar memoria\n");
        exit(1);
    }

    t->i = i;
    t->x = x;
    t->y = y;
    t->corB = (char*) malloc (strlen(corB) + 1);
    if (t->corB == NULL) {
        printf("Erro ao alocar memoria!\n");
        exit(1);
    }
    strcpy(t->corB,corB);

    t->corP = (char*) malloc (strlen(corP) + 1);
    if (t->corP == NULL) {
        printf("Erro ao alocar memoria!\n");
        exit(1);
    }
    strcpy(t->corP,corP);

    t->a = a;
    t->txto = (char*) malloc (strlen(txto) + 1);
    if (t->txto == NULL) {
        printf("Erro ao alocar memoria!\n");
        exit(1);
    }
    strcpy(t->txto,txto);

    return t;
}

int getIDTexto(Texto t) {
    return ((texto*)t)->i;
}

void setIDTexto(Texto t, int id) {
    ((texto*)t)->i = id;
}

double getXTexto(Texto t) {
    return ((texto*)t)->x;
}

void setXTexto(Texto t, double x) {
    ((texto*)t)->x = x;
}

double getYTexto(Texto t) {
    return ((texto*)t)->y;
}

void setYTexto(Texto t, double y) {
    ((texto*)t)->y = y;
}

char* getCorBTexto(Texto t) {
    return ((texto*)t)->corB;
}

void setCorBTexto(Texto t,char* corB) {
    texto* tex = (texto*)t;
    tex->corB = realloc (tex->corB,strlen(corB) + 1);
    if (tex->corB == NULL) {
        printf("Erro ao realocar memoria!\n");
        exit(1);
    }
    strcpy(tex->corB,corB);
}

char* getCorPTexto(Texto t) {
    return ((texto*)t)->corP;
}

void setCorPTexto(Texto t,char* corP) {
    texto* tex = (texto*)t;
    tex->corP = realloc (tex->corP,strlen(corP) + 1);
    if (tex->corP == NULL) {
        printf("Erro ao realocar memoria!\n");
        exit(1);
    }
    strcpy(tex->corP,corP);
}

char getATexto(Texto t) {
    return ((texto*)t)->a;
}

void setATexto(Texto t, char a) {
    ((texto*)t)->a = a;
}

char* getTxtoTexto(Texto t) {
    return ((texto*)t)->txto;
}

void setTxtoTexto(Texto t, char* txto) {
    texto* tex = (texto*)t;
    tex->txto = realloc (tex->txto,strlen(txto) + 1);
    if (tex->txto == NULL) {
        printf("Erro ao realocar memoria!\n");
        exit(1);
    }
    strcpy(tex->txto,txto);
}

char* getFontFamilyTexto(Estilo e) {
    return ((estilo*)e)->fFamily;
}

void setFontFamilyTexto(Estilo e, char* family) {
    estilo* est = (estilo*)e;
    est->fFamily = realloc (est->fFamily,strlen(family) + 1);
    if (est->fFamily == NULL) {
        printf("Erro ao realocar memoria!\n");
        exit(1);
    }
    strcpy (est->fFamily,family);
}

char* getFontWeightTexto(Estilo e) {
    return ((estilo*)e)->fWeight;
}

void setFontWeightTexto(Estilo e, char* weight) {
    estilo* est = (estilo*)e;
    est->fWeight = realloc (est->fWeight,strlen(weight) + 1);
    if (est->fWeight == NULL) {
        printf("Erro ao realocar memoria!\n");
        exit(1);
    }
    strcpy (est->fWeight,weight);
}

char* getFontSizeTexto(Estilo e) {
    return ((estilo*)e)->fSize;
}

void setFontSizeTexto(Estilo e, char* size) {
    estilo* est = (estilo*)e;
    est->fSize = realloc (est->fSize,strlen(size) + 1);
    if (est->fSize == NULL) {
        printf("Erro ao realocar memoria!\n");
        exit(1);
    }
    strcpy (est->fSize,size);
}

Estilo getEstilo(Texto t) {
    return ((texto*)t)->Estilo;
}

/*void calcExtremosTexto(Texto t) {


}
*/

size_t quantidadeCaracteresTexto(Texto t) {
    return strlen(((texto*)t)->txto);
}

/*Linha transformarTextoLinha(Texto t) {
    double x1,y1,x2,y2;
    switch (getATexto(t)) {
        case 'i':
            x1 = getXTexto(t);
            y1 = getYTexto(t);

            x2 = getXTexto(t) + 10.0 * quantidadeCaracteresTexto(t);
            y2 = getYTexto(t);

            break;
        case 'm':
            x1 = getXTexto(t) - 10.0 * quantidadeCaracteresTexto(t);
            y1 = getYTexto(t);

            x2 = (getXTexto(t) + 10.0 * quantidadeCaracteresTexto(t))/2;
            y2 = getYTexto(t);

            break;
        case 'f':
            x1 = getXTexto(t) - 10.0 * quantidadeCaracteresTexto(t);
            y1 = getYTexto(t);

            x2 = getXTexto(t);
            y2 = getYTexto(t);

            break;
        default:
            printf("Indice de ancora '%c' incorreto!\n",getATexto(t));
            break;
    }
    return l;

}*/


double calcAreaTexto(Texto t) {
    return 20 * (double) strlen(getTxtoTexto(t));
}

void eliminarTexto(Texto t) {
    texto* tex = (texto*)t;
    free(tex->corB);
    free(tex->corP);
    free(tex->txto);
    free(tex);
}