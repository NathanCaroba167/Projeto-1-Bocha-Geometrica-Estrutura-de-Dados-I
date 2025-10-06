//
// Created by natha on 25/09/2025.
//

#ifndef DISPARADOR_H
#define DISPARADOR_H

/*
 Módulo responsavel de coordenar e executar um disparador com operações de criar, get, set, atirar e botões
 */

/*
 Ponteiro void Pilha
 Ponteiro void Forma
 Ponteiro void Disparador
 */
typedef void* Pilha;
typedef void* Forma;
typedef void* Disparador;

/*
 Cria um disparador de formas, com duas pilhas como carregadores e as coordenadas do disparador
 */
Disparador criar_disparador(Pilha e,Pilha d,double x , double y);

/*
 Pega a coordenada x do disparador sem modifica-la
 */
double getXDisparador(Disparador d);

/*
 Define a nova coordenada x do disparador
 */
void setXDispardor(Disparador d, double x);

/*
 Pega a coordenada y do disparador sem modifica-la
 */
double getYDisparador(Disparador d);

/*
 Define a nova coordenada y do disparador
 */
void setYDispardor(Disparador d, double y);

/*
 Lança a forma na arena mudando as coordenadas originais da forma
 */
void atirarForma(Forma g,double mx,double my);

/*
 Botao que faz a mudanca da forma que esta no pente pela forma que esta na pilha direita e a forma que estava no pente para pilha esquerda
 */
void botaoEsquerdo(Pilha e,Pilha d);

/*
 Botao que faz a mudanca da forma que esta no pente pela forma que esta na pilha esquerda e a forma que estava no pente para pilha direita
 */
void botaoDireiro(Pilha e,Pilha d);


#endif //DISPARADOR_H
