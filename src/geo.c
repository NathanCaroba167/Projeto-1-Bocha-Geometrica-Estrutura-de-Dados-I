//
// Created by natha on 09/10/2025.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "forma.h"
#include "fila.h"

#include "circulo.h"
#include "retangulo.h"
#include "linha.h"
#include "texto.h"
#include "geo.h"

#define TAMANHO_MAX_BUFFER 256

Arquivo abrirGeo(Nome arquivo) {
    Arquivo geo = fopen(arquivo,"r");
    if (geo == NULL) {
        printf("Erro ao abrir o arquivo\n");
        exit(1);
    }
    return geo;
}

void criarFormasNoChao(Arquivo geo, Fila chao) {
    char buffer[TAMANHO_MAX_BUFFER];
    while(fgets(buffer,sizeof(buffer),geo) != NULL) {
        if (buffer[0] == '\n') {
            continue;
        }

        char* comando = strtok(buffer," ");
        if (comando == NULL) {
            continue;
        }

        if (strcmp(comando, "c") == 0) {
            char* id_temp = strtok(NULL," ");
            char* x_temp = strtok(NULL," ");
            char* y_temp = strtok(NULL," ");
            char* r_temp = strtok(NULL," ");
            char* corB = strtok(NULL," ");
            char* corP = strtok(NULL," ");

            if (id_temp && x_temp && y_temp && r_temp && corB && corP) {
                int id = atoi(id_temp);
                double x = atof(x_temp);
                double y = atof(y_temp);
                double r = atof(r_temp);
                Circulo c = CriarCirculo(id, x, y, r, corB, corP);
                inserirFila(chao ,CriarPacote(c,CIRCULO));
            }
        }else if (strcmp(comando, "r") == 0) {
            char* id_temp = strtok(NULL," ");
            char* x_temp = strtok(NULL," ");
            char* y_temp = strtok(NULL," ");
            char* w_temp = strtok(NULL," ");
            char* h_temp = strtok(NULL," ");
            char* corB = strtok(NULL," ");
            char* corP = strtok(NULL," ");

            if (id_temp && x_temp && y_temp && w_temp && h_temp && corB && corP) {
                int id = atoi(id_temp);
                double x = atof(x_temp);
                double y = atof(y_temp);
                double w = atof(w_temp);
                double h = atof(h_temp);
                Retangulo r = CriarRetangulo(id, x, y, w, h, corB, corP);
                inserirFila(chao,CriarPacote(r,RETANGULO));
            }
        }else if (strcmp(comando, "l") == 0) {
            char* id_temp = strtok(NULL," ");
            char* x_temp = strtok(NULL," ");
            char* y_temp = strtok(NULL," ");
            char* x2_temp = strtok(NULL," ");
            char* y2_temp = strtok(NULL," ");
            char* cor = strtok(NULL," ");

            if (id_temp && x_temp && y_temp && x2_temp && y2_temp && cor) {
                int id = atoi(id_temp);
                double x = atof(x_temp);
                double y = atof(y_temp);
                double x2 = atof(x2_temp);
                double y2 = atof(y2_temp);
                Linha l = CriarLinha(id, x, y, x2, y2, cor);
                inserirFila(chao,CriarPacote(l,LINHA));
            }
        }else if (strcmp(comando, "t") == 0) {
            char* id_temp = strtok(NULL," ");
            char* x_temp = strtok(NULL," ");
            char* y_temp = strtok(NULL," ");
            char* corB = strtok(NULL," ");
            char* corP = strtok(NULL," ");
            char* a_temp = strtok(NULL," ");
            char* txto = a_temp + strlen(a_temp) + 1;
            while (*txto == ' ') {
                txto++;
            }
            txto[strcspn(txto,"\n")] = 0;
            if (id_temp && x_temp && y_temp && corB && corP && a_temp && txto) {
                int id = atoi(id_temp);
                double x = atof(x_temp);
                double y = atof(y_temp);
                char a = a_temp[0];
                Texto t = CriarTexto(id, x, y, corB, corP, a, txto);
                inserirFila(chao,CriarPacote(t,TEXTO));
            }
        }else if (strcmp(comando, "ts") == 0) {
            char* fFamily  = strtok(NULL," ");
            char* fWeight = strtok(NULL," ");
            char* fSize = strtok(NULL," ");
            CriarEstilo(fFamily,fWeight,fSize);
        }else {
            printf("Comando desconhecido: '%s'\n", comando);
        }
    }
    fclose(geo);
}