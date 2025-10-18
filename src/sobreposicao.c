//
// Created by natha on 15/10/2025.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include "geo.h"
#include "circulo.h"
#include "retangulo.h"
#include "linha.h"
#include "texto.h"
#include "forma.h"
#include "sobreposicao.h"


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
            Linha l = transformarTextoLinha(t);
            return getBox(l);
        }
        default:
            box.xmin = box.ymin = box.xmax = box.ymax = 0;
    }
    return box;
}

bool boxSobrepoem(Box b1,Box b2) {
    return !(b1.xmax < b2.xmin || b1.xmin > b2.xmax || b1.ymax < b2.ymin || b1.ymin > b2.ymax);
}

bool verificarSobreposicao(Pacote g1,Pacote g2) {

    Box b1= getBox(g1);
    Box b2= getBox(g2);

    if (boxSobrepoem(b1,b2)) return false;

    TipoForma t1 = getTipoForma(g1);
    TipoForma t2 = getTipoForma(g2);

    if (t1 == RETANGULO && t2 == RETANGULO) {
        return true;
    }else if (t1 == CIRCULO && t2 == CIRCULO) {
        double dx = getXCirculo(g1) - getXCirculo(g2);
        double dy = getYCirculo(g1) - getYCirculo(g2);
        double dT = sqrt(dx*dx + dy*dy);

        return dT <= (getRCirculo(g1) + getRCirculo(g2));
    }else if (t1 == RETANGULO && t2 == CIRCULO || t1 == CIRCULO && t2 == RETANGULO) {
        return true;
    }else if (t1 == LINHA && t2 == LINHA) {
        double x1 = getX1Linha(g1);
        double y1 = getY1Linha(g1);
        double x2 = getX2Linha(g1);
        double y2 = getY2Linha(g1);

        double x3 = getX1Linha(g2);
        double y3 = getY1Linha(g2);
        double x4 = getX2Linha(g2);
        double y4 = getY2Linha(g2);

        double denom = (x1-x2)*(y3-y4) - (y1-y2)*(x3-x4);
        if (denom == 0) return false;

        double px = ((x1*y2 - y1*x2)*(x3 - x4) - (x1-x2)*(x3*y4 - y3*x4)) / denom;
        double py = ((x1*y2 - y1*x2)*(y3-y4) - (y1-y2)*(x3*y4 - y3*x4)) / denom;

        bool dentro1 = px >= fmin(x1,x2) && px <= fmax(x1,x2) && py >= fmin(y1,y2) && py <= fmax(y1,y2);
        bool dentro2 = px >= fmin(x3,x4) && px <= fmax(x3,x4) && py >= fmin(y3,y4) && py <= fmax(y3,y4);

        return dentro1 && dentro2;
    }else if (t1 == LINHA && t2 == CIRCULO || t1 == CIRCULO && t2 == LINHA) {
        return true;
    }else if (t1 == LINHA && t2 == RETANGULO || t1 == RETANGULO && t2 == LINHA) {
        return true;
    }

}

