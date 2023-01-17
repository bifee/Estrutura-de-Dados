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

    struct nodo *r2 = NewNodo(v[b]);

    int i;
    for (i = b; i >= a; i--)
    {
        if (v[i] < r2->data)
        {
            break;
        }
    }

    r2->dir = reconstroi(v, i + 1, b - 1);

    r2->esq = reconstroi(v, a, i);

    return r2;
}
int max(int x, int y)
{
    if (x > y)
        return x;
    else
        return y;
}

int altura(struct nodo *x)
{
    if (x == NULL)
        return 0;
    return 1 + max(altura(x->esq), altura(x->dir));
}

int AVL(struct nodo *raiz)
{
    int AE;
    int AD;
    if (raiz == NULL)
        return 1;
    AE = altura(raiz->esq);
    AD = altura(raiz->dir);
    if (abs(AE - AD) <= 1 && AVL(raiz->esq) && AVL(raiz->dir))
        return 1;
    else
        return 0;
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
    if (AVL(raiz) == 1)
        printf("arvore eh AVL");
    else
        printf("arvore nao eh AVL");
    return 0;
}