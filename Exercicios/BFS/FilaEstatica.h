#include <stdio.h>
#include <stdlib.h>
#define n 100

typedef struct fila Fila;

struct fila
{
    int fila[n];
    int fim;
    int inicio;
};

void insere_fila(Fila *f, int x);

int remove_fila(Fila *f);

int isEmpty(Fila *f);

Fila *cria_fila();

void imprimeFila(Fila *f);

void libera_Fila(Fila *f);
