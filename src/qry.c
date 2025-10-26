//
// Created by natha on 09/10/2025.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>

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
        printf("Erro ao abrir o arquivo qry!\n");

        perror("Motivo do erro");
        exit(1);
    }
    return qry;
}

void pd(EstoqueD e, int id, double x, double y) {
    Disparador d = getDisparadorPorId(e, id);
    if (d == NULL) {
        Disparador d1 = CriarDisparador(id, x, y);
        adicionarDisparador(e,d1);
    } else {
        setXDisparador(d,x);
        setYDisparador(d,y);
    }
}

void lc(Arquivo txt,EstoqueC e,int id,int n,Fila chao) {
    Carregador c = getCarregadorPorId(e,id);
    if (c == NULL) {
        Carregador c1 = CriarCarregador(id);
        adicionarCarregador(e,c1);
        for (int i = 0 ; i < n ; i++) {
            carregarCarregador(txt,c1,chao);
        }
    }else {
        for (int i = 0 ; i < n ; i++) {
            carregarCarregador(txt,c,chao);
        }
    }
}

void atch(EstoqueD e1, EstoqueC e2, int idD, int idCE, int idCD) {
    Disparador d = getDisparadorPorId(e1,idD);
    Carregador cE = getCarregadorPorId(e2,idCE);
    Carregador cD = getCarregadorPorId(e2,idCD);

    if (cE == NULL) {
        cE = CriarCarregador(idCE);
        adicionarCarregador(e2,cE);
    }

    if (cD == NULL) {
        cD = CriarCarregador(idCD);
        adicionarCarregador(e2,cD);
    }

    setCarregadoresDisparador(d,cE,cD);
}

void shft(Arquivo txt,EstoqueD e,int id,char botao, int n) {
    Disparador d = getDisparadorPorId(e,id);

    if (d == NULL) {
        printf( "ERRO no comando shft: Disparador com ID %d nao existe.\n", id);
        return;
    }
    Carregador cE = getCarregadorEsq(d);
    Carregador cD = getCarregadorDir(d);
    if (cE == NULL || cD == NULL) {
        printf( "ERRO no comando shft: Disparador %d nao tem carregadores anexados.\n", id);
        return;
    }

    Pilha pilhaEsq = getPilhaCarregador(cE);
    Pilha pilhaDir = getPilhaCarregador(cD);

    if (botao == 'e') {
        for (int i = 0 ; i < n ; i++) {
            Pacote p = getFormaDisparador(d);
            if (p != NULL) {
                empilharPilha(pilhaEsq,p);
            }
            Pacote p2 = getPrimeiraFormaPilha(pilhaDir);
            setFormaDisparador(d,p2);
            desempilharPilha(pilhaDir);
        }
    }else if (botao == 'd') {
        for (int i = 0 ; i < n ; i++) {
            Pacote p = getFormaDisparador(d);
            Pacote p2 = getPrimeiraFormaPilha(pilhaEsq);
            if (p2 == NULL) {
                printf("ERRO: Pilha Esquerda vazia!\n");
                break;
            }
            if (p != NULL) {
                empilharPilha(pilhaDir,p);
            }
            setFormaDisparador(d,p2);
            desempilharPilha(pilhaEsq);
        }
    }
    Pacote p = getFormaDisparador(d);
    if (p == NULL) {
        printf("ERRO: Disparador %d vazio após shft.\n", id);
        return;
    }
    reportarForma(txt,p);
}

void dsp(int n_eh_rjd,int* disparos,Arquivo txt,EstoqueD e, Fila arena, int id, double dx, double dy) {
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
    (*disparos)++;

    desarmarDisparador(d);
}

void rjd(Arquivo txt,int* disparos,EstoqueD e, Fila arena, int id, char botao, double dx, double dy, double ix, double iy) {
    Disparador d = getDisparadorPorId(e,id);
    if (d == NULL) {
        printf("ERRO rjd: Disparador %d nao encontrado!\n", id);
        return;
    }
    int i = 0;
    while (1) {
        shft(txt,e,id,botao,1);

        Pacote p = getFormaDisparador(d);
        if (p == NULL) {
            break;
        }

        double corrente_dx = dx + i * ix;
        double corrente_dy = dy + i * iy;

        dsp(0,disparos,txt,e,arena,id,corrente_dx,corrente_dy);

        i++;
    }

}

void calc(Arquivo txt,Fila arena, Fila chao,double* areaTotal,int* formas_esmagadas, int* formas_clonadas) {
    double areaRound = 0;

    pont atual;
    pont proximo;

    while ((atual = getPrimeiroElementoFila(arena)) != NULL) {

        proximo = getProximoElementoFila(atual);
        if (proximo == NULL) {
            break;
        }
        Pacote p1 = getFormaElementoFila(atual);
        Pacote p2 = getFormaElementoFila(proximo);

        if (verificarSobreposicao(p1,p2)) {
            double a1 = getAreaForma(p1);
            double a2 = getAreaForma(p2);
            if (a1 < a2) {
                fprintf(txt,"Forma %d (área %lf) sobrepoe Forma %d (área %lf): Forma %d destruída!\n",getIDForma(p1),a1,getIDForma(p2),a2,getIDForma(p1));
                areaRound += a1;
                (*formas_esmagadas)++;

                removerFila(arena);
                removerFila(arena);
                inserirFila(chao,p2);
                liberarForma(p1);
            }else {
                fprintf(txt,"Forma %d (área %lf) sobrepoe Forma %d (área %lf): Forma %d alterada e Forma %d clonada!!\n",getIDForma(p1),a1,getIDForma(p2),a2,getIDForma(p2),getIDForma(p1));
                char* corPp1 = getCorPForma(p1);
                char* corBp1 = getCorBForma(p1);

                setCorBForma(p2,corPp1);
                Pacote clone = clonarForma(p1);

                removerFila(arena);
                removerFila(arena);

                inserirFila(chao,p1);
                inserirFila(chao,p2);

                setCorBForma(clone,corPp1);
                setCorPForma(clone,corBp1);
                inserirFila(chao,clone);
                (*formas_clonadas)++;
            }
        } else {
            fprintf(txt,"Forma %d e Forma %d: Não se sobrepoem!\n",getIDForma(p1),getIDForma(p2));

            removerFila(arena);
            removerFila(arena);

            inserirFila(chao,p1);
            inserirFila(chao,p2);

        }
    }

    if ((atual = getPrimeiroElementoFila(arena)) != NULL) {
        Pacote unico = getFormaElementoFila(atual);
        fprintf(txt, "Forma %d: Única restante na arena. Movida para o chao!\n", getIDForma(unico));

        removerFila(arena);
        inserirFila(chao,unico);
    }

    (*areaTotal) += areaRound;
    reportarÁreaTotalEsmagada(txt,areaRound,*areaTotal);
}

void LerComandosExecutar(Arquivo txt,Arquivo qry, Fila chao, Fila arena, EstoqueD disparadores, EstoqueC carregadores) {
    char buffer[TAMANHO_MAX_BUFFER];
    double areaTotal = 0;
    int instrucoes = 0;
    int disparos = 0;
    int formas_esmagadas = 0;
    int formas_clonadas = 0;

    while(fgets(buffer,sizeof(buffer),qry) != NULL) {

        buffer[strcspn(buffer,"\n")] = 0;

        if (buffer[0] == '\n' || buffer[0] == '\0') {
            continue;
        }

        char* comando = strtok(buffer," ");
        if (comando == NULL) {
            continue;
        }
        printf("comando: %s\n",comando);

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
                int cE = atoi(cE_temp);
                int cD = atoi(cD_temp);

                atch(disparadores,carregadores,id,cE,cD);
                instrucoes++;
            }
        }else if (strcmp(comando, "shft") == 0) {
            char* id_temp = strtok(NULL," ");
            char* botao_temp = strtok(NULL," ");
            char* n_temp = strtok(NULL," ");

            if (id_temp && botao_temp && n_temp) {
                int id = atoi(id_temp);
                char botao = botao_temp[0];
                int n = atoi(n_temp);

                shft(txt,disparadores,id,botao,n);
                instrucoes++;
            }
        }else if (strcmp(comando, "dsp") == 0) {
            char* id_temp = strtok(NULL," ");
            char* dx_temp = strtok(NULL," ");
            char* dy_temp = strtok(NULL," ");
            //char* vis_temp = strtok(NULL," ");//

            //char vis = atof(vis_temp);*//

            if (id_temp && dx_temp && dy_temp) {
                int id = atoi(id_temp);
                double dx = atof(dx_temp);
                double dy = atof(dy_temp);

                dsp(1,&disparos,txt,disparadores,arena,id,dx,dy);
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
                char botao = botao_temp[0];
                double dx = atof(dx_temp);
                double dy = atof(dy_temp);
                double ix = atof(ix_temp);
                double iy = atof(iy_temp);

                rjd(txt,&disparos,disparadores,arena,id,botao,dx,dy,ix,iy);
                instrucoes++;
            }

        }else if (strcmp(comando, "calc") == 0) {
            calc(txt,arena,chao,&areaTotal,&formas_esmagadas,&formas_clonadas);
        }else{
            printf("Comando desconhecido: '%s' \n", comando);
        }
    }
    reportarResultadosFinais(txt,areaTotal, instrucoes, disparos, formas_esmagadas, formas_clonadas);
}