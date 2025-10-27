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
    if (p == NULL) {
        return 0;
    }
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

double getXForma(Pacote p) {
    TipoForma tipo = getTipoForma(p);
    switch (tipo) {
        case CIRCULO:
            Circulo c = getDadosForma(p);
            return getXCirculo(c);
        case RETANGULO:
            Retangulo r = getDadosForma(p);
            return getXRetangulo(r);
        case LINHA:
            Linha l = getDadosForma(p);
            return getX1Linha(l);
        case TEXTO:
            Texto t = getDadosForma(p);
            return getXTexto(t);
        default:
            printf("ERRO: tipo inválido!\n");
            return 0.0;
    }
}

double getYForma(Pacote p) {
    TipoForma tipo = getTipoForma(p);
    switch (tipo) {
        case CIRCULO:
            Circulo c = getDadosForma(p);
            return getYCirculo(c);
        case RETANGULO:
            Retangulo r = getDadosForma(p);
            return getYRetangulo(r);
        case LINHA:
            Linha l = getDadosForma(p);
            return getY1Linha(l);
        case TEXTO:
            Texto t = getDadosForma(p);
            return getYTexto(t);
        default:
            printf("ERRO: tipo inválido!\n");
            return 0.0;
    }
}

char* getCorBForma(Pacote p) {
    if (p == NULL) {
        return NULL;
    }
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
    if (p == NULL) {
        return NULL;
    }
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
    if (p == NULL) {
        return;
    }
    TipoForma tipo = getTipoForma(p);

    switch (tipo) {
        case CIRCULO:
            Circulo c = getDadosForma(p);
            setCorBCirculo(c,corB);
            break;
        case RETANGULO:
            Retangulo r = getDadosForma(p);
            setCorBRetangulo(r,corB);
            break;
        case LINHA:
            Linha l = getDadosForma(p);
            setCorLinha(l,corB);
            break;
        case TEXTO:
            Texto t = getDadosForma(p);
            setCorBTexto(t,corB);
            break;
        default:
            printf("ERRO: tipo inválido!\n");
            return;
    }
}

void setCorPForma(Pacote p, char* corP) {
    if (p == NULL) {
        return;
    }
    TipoForma tipo = getTipoForma(p);

    switch (tipo) {
        case CIRCULO:
            Circulo c = getDadosForma(p);
            setCorBCirculo(c,corP);
            break;
        case RETANGULO:
            Retangulo r = getDadosForma(p);
            setCorBRetangulo(r,corP);
            break;
        case LINHA:
            break;
        case TEXTO:
            Texto t = getDadosForma(p);
            setCorBTexto(t,corP);
            break;
        default:
            printf("ERRO: tipo inválido!\n");
            return;
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
                getCorBRetangulo(r),
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
    if (p == NULL) {
        return;
    }
    TipoForma tipo = getTipoForma(p);

    switch (tipo) {
        case CIRCULO:
            Circulo c = getDadosForma(p);
            eliminarCirculo(c);
            break;
        case RETANGULO:
            Retangulo r = getDadosForma(p);
            eliminarRetangulo(r);
            break;
        case LINHA:
            Linha l = getDadosForma(p);
            eliminarLinha(l);
            break;
        case TEXTO:
            Texto t = getDadosForma(p);
            eliminarTexto(t);
            break;
        default:
            printf("ERRO: tipo inválido encontrado em liberarForma!\n");
            return;
    }
    free(p);
}