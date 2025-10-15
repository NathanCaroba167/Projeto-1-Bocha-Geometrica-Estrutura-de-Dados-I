//
// Created by natha on 09/10/2025.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "disparador.h"
#include "carregador.h"
#include "svg.h"
#include "qry.h"

#define TAMANHO_MAX_BUFFER 256

void abrirQry(Arquivo *qry,Nome arquivo) {
    *qry = fopen(arquivo,"r");
    if (*qry == NULL) {
        printf("Erro ao abrir o arquivo\n");
        exit(1);
    }
}

void LerComandosExecutar(Arquivo qry, Fila chao) {
    char buffer[TAMANHO_MAX_BUFFER];
    while(fgets(buffer,sizeof(buffer),qry) != NULL) {
        if (buffer[0] == '\n') {
            continue;
        }

        char* comando = strtok(buffer," ");
        if (comando == NULL) {
            continue;
        }

        if (strcmp(comando, "pd") == 0) {
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
                inserirFila(chao ,CriarCirculo(id, x, y, r, corB, corP));
            }
        }else if (strcmp(comando, "lc") == 0) {
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
                inserirFila(chao, CriarRetangulo(id, x, y, w, h, corB, corP));
            }
        }else if (strcmp(comando, "atch") == 0) {
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
                inserirFila(chao,CriarLinha(id, x, y, x2, y2, cor));
            }
        }else if (strcmp(comando, "shft") == 0) {
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
                inserirFila(chao,CriarTexto(id, x, y, corB, corP, a, txto));
            }
        }else if (strcmp(comando, "dsp") == 0) {
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
                inserirFila(chao,CriarTexto(id, x, y, corB, corP, a, txto));
            }
        }else if(strcmp(comando, "rjd") == 0) {
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
                inserirFila(chao,CriarTexto(id, x, y, corB, corP, a, txto));
            }

        }else if (strcmp(comando, "ljd") == 0) {
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
                inserirFila(chao,CriarTexto(id, x, y, corB, corP, a, txto));
            }
        }else{
            printf("Comando desconhecido: '%s'\n", comando);
        }
    }
    fclose(qry);
}