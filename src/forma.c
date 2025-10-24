//
// Created by natha on 15/10/2025.
//
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include "circulo.h"
#include "retangulo.h"
#include "linha.h"
#include "texto.h"
#include "forma.h"

static int MAIOR_ID = 0;

typedef struct {
    Forma form;
    TipoForma tipo;
}pacote;

Pacote CriarPacote(Forma g,TipoForma tipo) {
    pacote* p = (Pacote)malloc(sizeof(pacote));
    if (p == NULL) {
        printf("Erro ao alocar memória ao criarPacote!\n");

        perror("Motivo do erro");
        exit(1);
    }
    p->form = g;
    p->tipo = tipo;

    return p;
}

Forma getDadosForma(Pacote p) {
    return ((pacote*)p)->form;

}

TipoForma getTipoForma(Pacote p) {
    return ((pacote*)p)->tipo;

}

double getAreaForma(Pacote p) {
    TipoForma tipo = getTipoForma(p);
    switch (tipo) {
        case CIRCULO:
            Circulo c = getDadosForma(p);
            return calcAreaCirculo(c);
        case RETANGULO:
            Retangulo r = getDadosForma(p);
            return calcAreaRetangulo(r);
        case LINHA:
            Linha l = getDadosForma(p);
            return calcAreaLinha(l);
        case TEXTO:
            Texto t = getDadosForma(p);
            return calcAreaTexto(t);
        default:
            printf("ERRO: tipo inválido!\n");
            return 0.0;
    }
}

int getIDForma(Pacote p) {
    TipoForma tipo = getTipoForma(p);

    switch (tipo) {
        case CIRCULO:
            Circulo c = getDadosForma(p);
            return getIDCirculo(c);
        case RETANGULO:
            Retangulo r = getDadosForma(p);
            return getIDRetangulo(r);
        case LINHA:
            Linha l = getDadosForma(p);
            return getIDLinha(l);
        case TEXTO:
            Texto t = getDadosForma(p);
            return getIDTexto(t);
        default:
            printf("ERRO: tipo inválido!\n");
            return 0;
    }
}

char* getCorBForma(Pacote p) {
    TipoForma tipo = getTipoForma(p);

    switch (tipo) {
        case CIRCULO:
            Circulo c = getDadosForma(p);
            return getCorBCirculo(c);
        case RETANGULO:
            Retangulo r = getDadosForma(p);
            return getCorBRetangulo(r);
        case LINHA:
            Linha l = getDadosForma(p);
            return getCorLinha(l);
        case TEXTO:
            Texto t = getDadosForma(p);
            return getCorBTexto(t);
        default:
            printf("ERRO: tipo inválido!\n");
            return NULL;
    }
}

char* getCorPForma(Pacote p) {
    TipoForma tipo = getTipoForma(p);

    switch (tipo) {
        case CIRCULO:
            Circulo c = getDadosForma(p);
            return getCorPCirculo(c);
        case RETANGULO:
            Retangulo r = getDadosForma(p);
            return getCorPRetangulo(r);
        case LINHA:
            Linha l = getDadosForma(p);
            return CorComplementarLinha(l);
        case TEXTO:
            Texto t = getDadosForma(p);
            return getCorPTexto(t);
        default:
            printf("ERRO: tipo inválido!\n");
            return NULL;
    }
}

void setCorBForma(Pacote p, char* corB) {
    TipoForma tipo = getTipoForma(p);

    switch (tipo) {
        case CIRCULO:
            Circulo c = getDadosForma(p);
            return setCorBCirculo(c,corB);
        case RETANGULO:
            Retangulo r = getDadosForma(p);
            return setCorBRetangulo(r,corB);
        case LINHA:
            Linha l = getDadosForma(p);
            return setCorLinha(l,corB);
        case TEXTO:
            Texto t = getDadosForma(p);
            return setCorBTexto(t,corB);
        default:
            printf("ERRO: tipo inválido!\n");
    }
}

void setCorPForma(Pacote p, char* corP) {
    TipoForma tipo = getTipoForma(p);

    switch (tipo) {
        case CIRCULO:
            Circulo c = getDadosForma(p);
            return setCorBCirculo(c,corP);
        case RETANGULO:
            Retangulo r = getDadosForma(p);
            return setCorBRetangulo(r,corP);
        case LINHA:
            break;
        case TEXTO:
            Texto t = getDadosForma(p);
            return setCorBTexto(t,corP);
        default:
            printf("ERRO: tipo inválido!\n");
    }
}

void armazenaMaiorId(int maior_id) {
    MAIOR_ID = maior_id + 1;
}

int getMaiorId() {
    return MAIOR_ID;
}

Pacote clonarForma(Pacote p) {
    TipoForma tipo = getTipoForma(p);

    int novo_id = getMaiorId();

    switch (tipo) {
        case CIRCULO: {
            Circulo c = getDadosForma(p);
            Circulo clone = CriarCirculo(novo_id,
                getXCirculo(c),
                getYCirculo(c),
                getRCirculo(c),
                getCorBCirculo(c),
                getCorPCirculo(c));
            MAIOR_ID++;
            return CriarPacote(clone,CIRCULO);
        }
        case RETANGULO: {
            Retangulo r = getDadosForma(p);
            Retangulo clone = CriarRetangulo(novo_id,
                getXRetangulo(r),
                getYRetangulo(r),
                getWRetangulo(r),
                getHRetangulo(r),
                getCorBForma(r),
                getCorPRetangulo(r));
            MAIOR_ID++;
            return CriarPacote(clone,RETANGULO);
        }
        case LINHA: {
            Linha l = getDadosForma(p);
            Linha clone = CriarLinha(novo_id,
                getX1Linha(l),
                getY1Linha(l),
                getX2Linha(l),
                getY2Linha(l),
                getCorLinha(l));
            MAIOR_ID++;
            return CriarPacote(clone,LINHA);
        }
        case TEXTO: {
            Texto t = getDadosForma(p);
            Texto clone = CriarTexto(novo_id,
                getXTexto(t),
                getYTexto(t),
                getCorBTexto(t),
                getCorPTexto(t),
                getATexto(t),
                getTxtoTexto(t));
            MAIOR_ID++;
            return CriarPacote(clone,TEXTO);
        }
        default:
            printf("ERRO: tipo inválido!\n");
            return NULL;
    }
}

void liberarForma(Pacote p) {
    free(p);
}