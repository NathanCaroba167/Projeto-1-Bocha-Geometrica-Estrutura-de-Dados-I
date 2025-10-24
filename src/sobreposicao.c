//
// Created by natha on 15/10/2025.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#include "circulo.h"
#include "retangulo.h"
#include "linha.h"
#include "texto.h"
#include "forma.h"
#include "sobreposicao.h"

typedef struct {
    double x, y;
}Ponto;


typedef struct {
    double xmin,ymin,xmax,ymax;
}Box;

Box getBox(Pacote g1) {
    Box box;
    TipoForma tipo = getTipoForma(g1);

    switch (tipo) {
        case RETANGULO: {
            Retangulo r = getDadosForma(g1);

            box.xmin = getXRetangulo(r);
            box.ymin = getYRetangulo(r);
            box.xmax = box.xmin + getWRetangulo(r);
            box.ymax = box.ymin + getHRetangulo(r);
            break;
        }
        case CIRCULO: {
            Circulo c = getDadosForma(g1);

            box.xmin = getXCirculo(c) - getRCirculo(c);
            box.xmax = getXCirculo(c) + getRCirculo(c);
            box.ymin = getYCirculo(c) - getRCirculo(c);
            box.ymax = getYCirculo(c) + getRCirculo(c);
            break;
        }
        case LINHA: {
            Linha l = getDadosForma(g1);

            box.xmin = fmin(getX1Linha(l), getX2Linha(l));
            box.xmax = fmax(getX1Linha(l), getX2Linha(l));
            box.ymin = fmin(getY1Linha(l), getY2Linha(l));
            box.ymax = fmax(getY1Linha(l), getY2Linha(l));
            break;
        }
        case TEXTO: {
            Texto t = getDadosForma(g1);

            double x1, x2;
            switch (getATexto(t)) {
                case 'i':
                    x1 = getXTexto(t);
                    x2 = getXTexto(t) + 10.0 * quantidadeCaracteresTexto(t);
                    break;
                case 'm':
                    x1 = (getXTexto(t) - 10.0 * quantidadeCaracteresTexto(t))/2;
                    x2 = (getXTexto(t) + 10.0 * quantidadeCaracteresTexto(t))/2;
                    break;
                case 'f':
                    x1 = getXTexto(t) - 10.0 * quantidadeCaracteresTexto(t);
                    x2 = getXTexto(t);
                    break;
                default:
                    printf("Indice de ancora '%c' incorreto!\n",getATexto(t));
                    exit(1);
            }
            box.xmin = fmin(x1, x2);
            box.xmax = fmax(x1, x2);
            box.ymin = getYTexto(t);
            box.ymax = getYTexto(t);
            break;
        }
        default:
            box.xmin = box.ymin = box.xmax = box.ymax = 0;
    }
    return box;
}

bool boxVerificaNaoSobreposição(Box b1,Box b2) {
    return (b1.xmax < b2.xmin || b1.xmin > b2.xmax || b1.ymax < b2.ymin || b1.ymin > b2.ymax);
}

double max(double a, double b) {
    return a > b ? a : b;
}
double min(double a, double b) {
    return a < b ? a : b;
}

int calcularOrientacao(Ponto p, Ponto q, Ponto r) {
    double val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);

    if (val > -1e-9 && val < 1e-9) {
        return 0;
    }

    return (val > 0) ? 1 : 2;
}

int estaNoSegmento(Ponto p, Ponto q, Ponto r) {
    if (q.x <= fmax(p.x, r.x) && q.x >= fmin(p.x, r.x) && q.y <= fmax(p.y, r.y) && q.y >= fmin(p.y, r.y)) {
        return 1;
    }
    return 0;
}

bool pontoDentroRetangulo(Retangulo r, Ponto p) {
    double rx = getXRetangulo(r);
    double ry = getYRetangulo(r);
    double rw = getWRetangulo(r);
    double rh = getHRetangulo(r);

    if (p.x >= rx && p.x <= rx + rw && p.y >= ry && p.y <= ry + rh) {
        return true;
    }
    return false;
}

bool verificarIntersecaoSegmentos(Ponto p1,Ponto p2,Ponto p3, Ponto p4) {
    int o1 = calcularOrientacao(p1, p2, p3);
    int o2 = calcularOrientacao(p1, p2, p4);
    int o3 = calcularOrientacao(p3, p4, p1);
    int o4 = calcularOrientacao(p3, p4, p2);

    if (o1 != o2 && o3 != o4) {
        return true;
    }

    if (o1 == 0 && estaNoSegmento(p1, p3, p2)) {
        return true;
    }

    if (o2 == 0 && estaNoSegmento(p1, p4, p2)) {
        return true;
    }

    if (o3 == 0 && estaNoSegmento(p3, p1, p4)) {
        return true;
    }

    if (o4 == 0 && estaNoSegmento(p3, p2, p4)) {
        return true;
    }

    return false;

}

bool SobrepoeRetanguloCirculo(Retangulo r , Circulo c) {
    double PontoX_MaisProximo = max(getXRetangulo(r), min(getXCirculo(c),(getXRetangulo(r) + getWRetangulo(r))));
    double PontoY_MaisProximo = max(getYRetangulo(r), min(getYCirculo(c),(getYRetangulo(r) + getHRetangulo(r))));

    if (PontoX_MaisProximo == getXCirculo(c) && PontoY_MaisProximo ==  getYCirculo(c)) {
        return true;
    }

    double distX = getXCirculo(c) - PontoX_MaisProximo;
    double distY = getYCirculo(c) - PontoY_MaisProximo;

    double distTotal = (distX * distX) + (distY * distY);
    double raioQuadrado = getRCirculo(c) * getRCirculo(c);

    if (distTotal <= raioQuadrado) {
        return true;
    }
    return false;
}

bool SobrepoeLinhaLinha(Linha l1, Linha l2) {
    Ponto p1 = {getX1Linha(l1), getY1Linha(l1)};
    Ponto p2 = {getX2Linha(l1), getY2Linha(l1)};
    Ponto p3 = {getX1Linha(l2), getY1Linha(l2)};
    Ponto p4 = {getX2Linha(l2), getY2Linha(l2)};

    return verificarIntersecaoSegmentos(p1, p2, p3, p4);
}

bool SobrepoeLinhaCirculo(Linha l, Circulo c) {
    double PontoX_MaisProximo = max(getX1Linha(l), min(getXCirculo(c),(getX1Linha(l) + getX2Linha(l))));
    double PontoY_MaisProximo = max(getY1Linha(l), min(getYCirculo(c),(getY1Linha(l) + getY2Linha(l))));

    if (PontoX_MaisProximo == getXCirculo(c) && PontoY_MaisProximo ==  getYCirculo(c)) {
        return true;
    }

    double distX = getXCirculo(c) - PontoX_MaisProximo;
    double distY = getYCirculo(c) - PontoY_MaisProximo;

    double distTotal = (distX * distX) + (distY * distY);
    double raioQuadrado = getRCirculo(c) * getRCirculo(c);

    if (distTotal <= raioQuadrado) {
        return true;
    }
    return false;

}

bool SobrepoeLinhaRetangulo(Linha l, Retangulo r) {
    Ponto p1 = {getX1Linha(l), getY1Linha(l)};
    Ponto p2 = {getX2Linha(l), getY2Linha(l)};

    if (pontoDentroRetangulo(r,p1) || pontoDentroRetangulo(r,p2)) {
        return true;
    }

    double rx = getXRetangulo(r);
    double ry = getYRetangulo(r);
    double rw = getWRetangulo(r);
    double rh = getHRetangulo(r);

    Ponto c1 = {rx, ry};
    Ponto c2 = {rx + rw, ry};
    Ponto c3 = {rx + rw, ry + rh};
    Ponto c4 = {rx, ry + rh};

    if (verificarIntersecaoSegmentos(p1,p2,c2,c2)) {
        return true;
    }
    if (verificarIntersecaoSegmentos(p1,p2,c4,c3)) {
        return true;
    }
    if (verificarIntersecaoSegmentos(p1,p2,c1,c4)) {
        return true;
    }
    if (verificarIntersecaoSegmentos(p1,p2,c2,c3)) {
        return true;
    }

    return false;
}

bool SobrepoeTextoTexto(Box b1,Box b2) {
    Ponto p1 ={b1.xmin, b1.ymin};
    Ponto p2 ={b1.xmax, b1.ymax};
    Ponto p3 = {b2.xmin, b2.ymin};
    Ponto p4 = {b2.xmax, b2.ymax};

    return verificarIntersecaoSegmentos(p1,p2,p3,p4);
}

bool SobrepoeTextoRetangulo(Box b1, Retangulo r) {
    Ponto p1 ={b1.xmin, b1.ymin};
    Ponto p2 ={b1.xmax, b1.ymax};

    if (pontoDentroRetangulo(r,p1) || pontoDentroRetangulo(r,p2)) {
        return true;
    }

    double rx = getXRetangulo(r);
    double ry = getYRetangulo(r);
    double rw = getWRetangulo(r);
    double rh = getHRetangulo(r);

    Ponto c1 = {rx, ry};
    Ponto c2 = {rx + rw, ry};
    Ponto c3 = {rx + rw, ry + rh};
    Ponto c4 = {rx, ry + rh};

    if (verificarIntersecaoSegmentos(p1,p2,c2,c2)) {
        return true;
    }
    if (verificarIntersecaoSegmentos(p1,p2,c4,c3)) {
        return true;
    }
    if (verificarIntersecaoSegmentos(p1,p2,c1,c4)) {
        return true;
    }
    if (verificarIntersecaoSegmentos(p1,p2,c2,c3)) {
        return true;
    }

    return false;
}

bool SobrepoeTextoCirculo(Box b1, Circulo c) {
    double PontoX_MaisProximo = max(b1.xmin, min(getXCirculo(c),(b1.xmin + b1.xmax)));
    double PontoY_MaisProximo = max(b1.ymin, min(getYCirculo(c),(b1.ymin + b1.ymax)));

    if (PontoX_MaisProximo == getXCirculo(c) && PontoY_MaisProximo ==  getYCirculo(c)) {
        return true;
    }

    double distX = getXCirculo(c) - PontoX_MaisProximo;
    double distY = getYCirculo(c) - PontoY_MaisProximo;

    double distTotal = (distX * distX) + (distY * distY);
    double raioQuadrado = getRCirculo(c) * getRCirculo(c);

    if (distTotal <= raioQuadrado) {
        return true;
    }
    return false;
}

bool verificarSobreposicao(Pacote g1,Pacote g2) {

    Box b1 = getBox(g1);
    Box b2 = getBox(g2);

    if (boxVerificaNaoSobreposição(b1,b2)) return false;

    TipoForma t1 = getTipoForma(g1);
    TipoForma t2 = getTipoForma(g2);

    if (t1 == RETANGULO && t2 == RETANGULO) {
        return true;
    }else if (t1 == CIRCULO && t2 == CIRCULO) {
        Circulo c1 = getDadosForma(g1);
        Circulo c2 = getDadosForma(g2);
        double dx = getXCirculo(c1) - getXCirculo(c2);
        double dy = getYCirculo(c1) - getYCirculo(c2);
        double dT = sqrt(dx*dx + dy*dy);

        return dT <= (getRCirculo(c1) + getRCirculo(c2));
    }else if ((t1 == RETANGULO && t2 == CIRCULO) || (t1 == CIRCULO && t2 == RETANGULO)) {
        if (t1 == RETANGULO) {
            Retangulo r = getDadosForma(g1);
            Circulo c = getDadosForma(g2);
            return SobrepoeRetanguloCirculo(r,c);
        }else {
            Retangulo r = getDadosForma(g2);
            Circulo c = getDadosForma(g1);
            return SobrepoeRetanguloCirculo(r,c);
        }
    }else if (t1 == LINHA && t2 == LINHA) {
        Linha l1 = getDadosForma(g1);
        Linha l2 = getDadosForma(g2);
        return SobrepoeLinhaLinha(l1,l2);
    }else if ((t1 == LINHA && t2 == CIRCULO) || (t1 == CIRCULO && t2 == LINHA)) {
        if (t1 == LINHA) {
            Linha l = getDadosForma(g1);
            Circulo c = getDadosForma(g2);
            return SobrepoeLinhaCirculo(l,c);
        } else {
            Linha l = getDadosForma(g2);
            Circulo c = getDadosForma(g1);
            return SobrepoeLinhaCirculo(l,c);
        }
    }else if ((t1 == LINHA && t2 == RETANGULO) || (t1 == RETANGULO && t2 == LINHA)) {
        if (t1 == LINHA) {
            Linha l = getDadosForma(g1);
            Retangulo r = getDadosForma(g2);
            return SobrepoeLinhaRetangulo(l,r);
        } else {
            Linha l = getDadosForma(g2);
            Retangulo r = getDadosForma(g1);
            return SobrepoeLinhaRetangulo(l,r);
        }
    } else if (t1 == TEXTO && t2 == TEXTO) {
        return SobrepoeTextoTexto(b1,b2);
    }else if ((t1 == TEXTO && t2 == RETANGULO) || (t1 == RETANGULO && t2 == TEXTO)) {
        if (t1 == TEXTO) {
            Retangulo r = getDadosForma(g2);
            return SobrepoeTextoRetangulo(b1,r);
        }else {
            Retangulo r = getDadosForma(g1);
            return SobrepoeTextoRetangulo(b2,r);
        }
    } else if ((t1 == TEXTO && t2 == CIRCULO) || (t1 == CIRCULO && t2 == TEXTO)) {
        if (t1 == TEXTO) {
            Circulo c = getDadosForma(g2);
            return SobrepoeTextoCirculo(b1,c);
        } else {
            Circulo c = getDadosForma(g1);
            return SobrepoeTextoCirculo(b2,c);
        }
    }
    return false;
}

