#include <stdio.h>
#include <stdlib.h>

struct nodo
{
    int data;
    struct nodo *dir;
    struct nodo *esq;
};

struct nodo *NewNodo(int x)
{
    struct nodo *novo;
    novo = (struct nodo *)malloc(sizeof(struct nodo));
    novo->data = x;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

int busca(struct nodo *raiz, int x)
{
    if (raiz == NULL)
        return 0;
    else if (raiz->data == x)
        return 1;
    else if (x < raiz->data)
        return busca(raiz->esq, x);
    else if (x > raiz->data)
        return busca(raiz->dir, x);
}

struct nodo *reconstroi(int *v, int a, int b)
{
    if (a > b)
        return NULL;

    struct nodo *r2 = NewNodo(v[a]);

    int i;
    for (i = a; i <= b; i++)
    {

        if (v[i] > r2->data)
        {
            break;
        }
    }
    r2->esq = reconstroi(v, a + 1, i - 1);

    r2->dir = reconstroi(v, i, b);

    return r2;
}

int main()
{
    int a, b, tam = 0, i = 1;
    int v[100];
    scanf("%d", &tam);
    for (i = 0; i < tam; i++)
    {
        scanf("%d", &v[i]);
    }
    printf("\n");
    struct nodo *raiz = reconstroi(v, 0, tam - 1);
    scanf("%d", &a);
    while (a != -1)
    {
        b = busca(raiz, a);
        if (b == 1)
            printf("%d encontrado\n", a);
        else
            printf("%d nao encontrado\n", a);
        scanf("%d", &a);
    }
    return 0;
}