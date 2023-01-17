#include "FilaEstatica.h"

Fila *cria_fila()
{
    Fila *fi = (Fila *)malloc(sizeof(Fila));
    fi->fim = 0;
    int i;
    for (i = 0; i < n; i++)
    {
        fi->fila[i] = 0;
    }

    return fi;
}

void insere_fila(Fila *f, int x)
{

    if (f->fim == n - 1)
    {
        printf("fila esta cheia\n");
        return;
    }
    else
    {
        if (f->inicio == -1)
            f->inicio = 0;
        f->fila[f->fim] = x;
        f->fim++;
    }
}

int remove_fila(Fila *f)
{
    int x, i;
    if (f->fim == 0)
    {
        printf("fila esta vazia\n");
        return -1;
    }
    else
    {
        x = f->fila[0];
        for (i = 0; i < f->fim; i++)
            f->fila[i] = f->fila[i + 1];
    }
    f->fim--;
    return x;
}

int isEmpty(Fila *f)
{
    if (f->fim == 0)
        return 1;
    else
        return 0;
}
void imprimeFila(Fila *f)
{
    int i;
    for (i = 0; i < f->fim; i++)
    {
        printf("%d ", f->fila[i]);
    }
}

void libera_Fila(Fila *f)
{
    free(f);
}