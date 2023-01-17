#ifndef FDRDINAMICO_H_INCLUDED
#define FDRDINAMICO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodo
{
   int info;
   struct nodo *prox;
   struct nodo *ant;
} nodo;

typedef struct Fila
{
   struct nodo *inicio;
   struct nodo *fim;
   struct nodo *atual;
} Fila;

Fila *cria_fila();

void pushh_back(Fila *f, int x);

void pushh_front(Fila *f, int x);

int popp_back(Fila *f);

int popp_front(Fila *f);

void reverse_fila(Fila *f);

void freefila(Fila *f);

#endif // FDRDINAMICO_H_INCLUDED
