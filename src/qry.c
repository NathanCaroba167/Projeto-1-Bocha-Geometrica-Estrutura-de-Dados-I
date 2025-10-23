//
// Created by natha on 09/10/2025.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "circulo.h"
#include "linha.h"
#include "retangulo.h"
#include "texto.h"
#include "forma.h"

#include "fila.h"
#include "pilha.h"
#include "txt.h"
#include "sobreposicao.h"
#include "carregador.h"
#include "disparador.h"
#include "estoque.h"
#include "svg.h"
#include "qry.h"

#define TAMANHO_MAX_BUFFER 256

Arquivo abrirQry(Nome arquivo) {
    Arquivo qry = fopen(arquivo,"r");
    if (qry == NULL) {
        printf("Erro ao abrir o arquivo\n");
        exit(1);
    }
    return qry;
}

void pd(EstoqueD e, int id, double x, double y) {
    Disparador d = getDisparadorPorId(e, id);
    if (d == NULL) {
        Disparador d1 = CriarDisparador(id, x, y);
        adicionarDisparador(e,d1);
    }
    setXDisparador(d,x);
    setYDisparador(d,y);
}

void lc(Arquivo txt,EstoqueC e,int id,int n,Fila chao) {
    Carregador c = getCarregadorPorId(e,id);
    if (c == NULL) {
        Carregador c1 = CriarCarregador(id);
        adicionarCarregador(e,c1);
        for (int i = 0 ; i < n ; i++) {
            carregarCarregador(txt,c1,chao);
        }
    }
    for (int i = 0 ; i < n ; i++) {
        carregarCarregador(txt,c,chao);
    }
}

void atch(EstoqueD e1, EstoqueC e2, int idD, int idCE, int idCD) {
    Disparador d = getDisparadorPorId(e1,idD);
    Carregador cE = getCarregadorPorId(e2,idCE);
    Carregador cD = getCarregadorPorId(e1,idCD);
    setCarregadoresDisparador(d,cE,cD);
}

void shft(Arquivo txt,EstoqueD e,int id,char botao, int n) {
    Disparador d = getDisparadorPorId(e,id);
    Carregador cE = getCarregadorEsq(d);
    Carregador cD = getCarregadorDir(d);
    if (botao == 'e') {
        for (int i = 0 ; i < n ; i++) {
            Pacote p = getFormaDisparador(d);
            if (p != NULL) {
                Pilha pl = getPilhaCarregador(cE);
                empilharPilha(pl,p);
            }
            Pilha pl2 = getPilhaCarregador(cD);
            Pacote p2 = getPrimeiraFormaPilha(pl2);
            setFormaDisparador(d,p2);
            desempilharPilha(pl2);
        }
    }else if (botao == 'd') {
        for (int i = 0 ; i < n ; i++) {
            Pacote p = getFormaDisparador(d);
            if (p != NULL) {
                Pilha pl = getPilhaCarregador(cD);
                empilharPilha(pl,p);
            }
            Pilha pl2 = getPilhaCarregador(cE);
            Pacote p2 = getPrimeiraFormaPilha(pl2);
            setFormaDisparador(d,p2);
            desempilharPilha(pl2);
        }
    }
    Pacote p = getFormaDisparador(d);
    reportarForma(txt,p);
}

void dsp(int n_eh_rjd,int disparos,Arquivo txt,EstoqueD e, Fila arena, int id, double dx, double dy) {
    Disparador d = getDisparadorPorId(e,id);
    double formaX = getXDisparador(d) + dx;
    double formaY = getYDisparador(d) + dy;
    Pacote p = getFormaDisparador(d);

    Forma f = getDadosForma(p);
    TipoForma tipo = getTipoForma(p);

    switch (tipo) {
        case CIRCULO:
            if (n_eh_rjd) {
                reportarForma(txt,p);
            }
            setXCirculo(f,formaX);
            setYCirculo(f,formaY);
            if (n_eh_rjd) {
                reportarPosiçãoFinal(txt,p);
            }
            inserirFila(arena,p);
            break;
        case RETANGULO:
            if (n_eh_rjd) {
                reportarForma(txt,p);
            }
            setXRetangulo(f,formaX);
            setYRetangulo(f,formaY);
            if (n_eh_rjd) {
                reportarPosiçãoFinal(txt,p);
            }
            inserirFila(arena,p);
            break;
        case LINHA:
            if (n_eh_rjd) {
                reportarForma(txt,p);
            }
            setX1Linha(f,formaX);
            setY1Linha(f,formaY);
            setX2Linha(f,formaX);
            setY2Linha(f,formaY);
            if (n_eh_rjd) {
                reportarPosiçãoFinal(txt,p);
            }
            inserirFila(arena,p);
            break;
        case TEXTO:
            if (n_eh_rjd) {
                reportarForma(txt,p);
            }
            setXTexto(f,formaX);
            setYTexto(f,formaY);
            if (n_eh_rjd) {
                reportarPosiçãoFinal(txt,p);
            }
            inserirFila(arena,p);
            break;
        default:
            printf("Tipo inválido!\n");
            break;
    }
    disparos++;

    desarmarDisparador(d);
}

void rjd(Arquivo txt,int disparos,EstoqueD e, Fila arena, int id, char botao, double dx, double dy, double ix, double iy) {
    shft(txt,e,id,botao,1);
    dsp(0,disparos,txt,e,arena,id,dx*ix,dy*iy);
}

void calc(Arquivo txt,Fila arena, Fila chao,double areaTotal,int formas_esmagadas, int formas_clonadas) {
    double areaRound = 0;

    pont atual = getPrimeiroElementoFila(arena);
    while (atual != NULL) {
        Pacote p1 = getPrimeiraFormaFila(arena);

        pont prox = getProximoElementoFila(atual);
        Pacote p2 = getFormaElementoFila(prox);

        if (verificarSobreposicao(p1,p2)) {
            double a1 = getAreaForma(p1);
            double a2 = getAreaForma(p2);
            if (a1 < a2) {
                fprintf(txt,"Forma %d (área %lf) sobrepoe Forma %d (área %lf): Forma %d destruída!\n",getIDForma(p1),a1,getIDForma(p2),a2,getIDForma(p1));
                areaRound += a1;
                removerFila(arena);
                inserirFila(chao,p2);
                formas_esmagadas++;
            }else {
                fprintf(txt,"Forma %d (área %lf) sobrepoe Forma %d (área %lf): Forma %d alterada e Forma %d clonada!!\n",getIDForma(p1),a1,getIDForma(p2),a2,getIDForma(p2),getIDForma(p1));
                char* corPp1 = getCorPForma(p1);
                char* corBp1 = getCorBForma(p1);

                setCorBForma(p2,corPp1);
                Pacote clone = clonarForma(p1);

                inserirFila(chao,p1);
                inserirFila(chao,p2);
                removerFila(arena);
                removerFila(arena);

                setCorBForma(clone,corPp1);
                setCorPForma(clone,corBp1);
                inserirFila(chao,clone);
                formas_clonadas++;
            }
        } else {
            fprintf(txt,"Forma %d e Forma %d: Não se sobrepoem!\n",getIDForma(p1),getIDForma(p2));
            inserirFila(chao,p1);
            inserirFila(chao,p2);
            removerFila(arena);
            removerFila(arena);
        }
        atual = getProximoElementoFila(prox);
    }
    areaTotal += areaRound;
    reportarÁreaTotalEsmagada(txt,areaRound,areaTotal);
}

void LerComandosExecutar(Arquivo txt,Arquivo qry, Fila chao, Fila arena, EstoqueD disparadores, EstoqueC carregadores) {
    char buffer[TAMANHO_MAX_BUFFER];
    double areaTotal = 0;
    int instrucoes = 0;
    int disparos = 0;
    int formas_esmagadas = 0;
    int formas_clonadas = 0;

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

            if (id_temp && x_temp && y_temp) {
                int id = atoi(id_temp);
                double x = atof(x_temp);
                double y = atof(y_temp);

                pd(disparadores,id,x,y);
                instrucoes++;
            }
        }else if (strcmp(comando, "lc") == 0) {
            char* id_temp = strtok(NULL," ");
            char* n_temp = strtok(NULL," ");

            if (id_temp && n_temp) {
                int id = atoi(id_temp);
                int n = atoi(n_temp);

                lc(txt,carregadores,id,n,chao);
                instrucoes++;
            }
        }else if (strcmp(comando, "atch") == 0) {
            char* id_temp = strtok(NULL," ");
            char* cE_temp = strtok(NULL," ");
            char* cD_temp = strtok(NULL," ");


            if (id_temp && cE_temp && cD_temp ) {
                int id = atoi(id_temp);
                int cE = atof(cE_temp);
                int cD = atof(cD_temp);

                atch(disparadores,carregadores,id,cE,cD);
                instrucoes++;
            }
        }else if (strcmp(comando, "shft") == 0) {
            char* id_temp = strtok(NULL," ");
            char* botao_temp = strtok(NULL," ");
            char* n_temp = strtok(NULL," ");

            if (id_temp && botao_temp && n_temp) {
                int id = atoi(id_temp);
                char botao = atof(botao_temp);
                int n = atof(n_temp);

                shft(txt,disparadores,id,botao,n);
                instrucoes++;
            }
        }else if (strcmp(comando, "dsp") == 0) {
            char* id_temp = strtok(NULL," ");
            char* dx_temp = strtok(NULL," ");
            char* dy_temp = strtok(NULL," ");
            char* vis_temp = strtok(NULL," ");

            char vis = atof(vis_temp);

            if (id_temp && dx_temp && dy_temp) {
                int id = atoi(id_temp);
                double dx = atof(dx_temp);
                double dy = atof(dy_temp);

                dsp(1,disparos,txt,disparadores,arena,id,dx,dy);
                instrucoes++;
            }
        }else if(strcmp(comando, "rjd") == 0) {
            char* id_temp = strtok(NULL," ");
            char* botao_temp = strtok(NULL," ");
            char* dx_temp = strtok(NULL," ");
            char* dy_temp = strtok(NULL," ");
            char* ix_temp = strtok(NULL," ");
            char* iy_temp = strtok(NULL," ");

            if (id_temp && botao_temp && dx_temp && dy_temp && ix_temp && iy_temp) {
                int id = atoi(id_temp);
                char botao = atof(botao_temp);
                double dx = atof(dx_temp);
                double dy = atof(dy_temp);
                double ix = atof(ix_temp);
                double iy = atof(iy_temp);

                rjd(txt,disparos,disparadores,arena,id,botao,dx,dy,ix,iy);
                instrucoes++;
            }

        }else if (strcmp(comando, "calc") == 0) {
            calc(txt,arena,chao,areaTotal,formas_esmagadas,formas_clonadas);
        }else{
            printf("Comando desconhecido: '%s'\n", comando);
        }
    }
    reportarResultadosFinais(txt,areaTotal, instrucoes, disparos, formas_esmagadas, formas_clonadas);
    fclose(qry);
}