#include <stdio.h>
#include <stdlib.h>

struct nodo
{
    int data;
    struct nodo *dir;
    struct nodo *esq;
};

struct nodo *verifica_vazia(struct nodo *raiz)
{
    return raiz == NULL;
}
struct nodo *criaArvore()
{
    return NULL;
}

struct nodo *NewNodo(int x)
{
    struct nodo *novo;
    novo = (struct nodo *)malloc(sizeof(struct nodo));
    novo->data = x;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

struct nodo *busca(struct nodo *raiz, int x)
{
    if (raiz == NULL || raiz->data == x)
        return raiz;
    else if (x < raiz->data)
        return busca(raiz->esq, x);
    else if (x > raiz->data)
        return busca(raiz->dir, x);
}

struct nodo *insere(struct nodo *raiz, int x)
{
    if (raiz == NULL)
    {
        printf("a\n");
        raiz = (struct nodo *)malloc(sizeof(struct nodo));
        raiz->data = x;
        raiz->esq = NULL;
        raiz->dir = NULL;
    }
    else if (x < raiz->data)
    {
        printf("b\n");
        raiz->esq = insere(raiz->esq, x);
    }
    else
    {
        printf("c\n");
        raiz->dir = insere(raiz->dir, x);
    }
    return raiz;
}

struct nodo *busca_minimo(struct nodo *raiz)
{
    if (raiz == NULL)
        return NULL;
    else if (raiz->esq != NULL)
        return busca_minimo(raiz->esq);
    return raiz;
}

struct nodo *delete(struct nodo *raiz, int x)
{
    if (raiz == NULL)
        return NULL;
    if (x < raiz->data)
        raiz->esq = delete (raiz->esq, x);
    else if (x > raiz->data)
        raiz->dir = delete (raiz->dir, x);
    else
    {
        if (raiz->esq == NULL && raiz->dir == NULL)
        {
            free(raiz);
            return NULL;
        }
        else if (raiz->esq == NULL || raiz->dir == NULL)
        {
            struct nodo *aux;
            if (raiz->esq == NULL)
                aux = raiz->dir;
            else
                aux = raiz->esq;
            free(raiz);
            return aux;
        }
        else
        {
            struct nodo *aux = busca_minimo(raiz->dir);
            raiz->data = aux->data;
            raiz->dir = delete (raiz->dir, aux->data);
        }
    }
    return raiz;
}

void inorder(struct nodo *raiz)
{
    if (raiz != NULL)
    {
        inorder(raiz->esq);
        printf(" %d ", raiz->data);
        inorder(raiz->dir);
    }
}

void preorder(struct nodo *raiz)
{
    if (raiz != NULL)
    {

        printf(" %d ", raiz->data);
        preorder(raiz->esq);
        preorder(raiz->dir);
    }
}

void posorder(struct nodo *raiz)
{
    if (raiz != NULL)
    {
        posorder(raiz->esq);
        posorder(raiz->dir);
        printf(" %d ", raiz->data);
    }
}

int main()
{
    int a, b, loop;
    struct nodo *raiz = criaArvore();
    while (loop == 0)
    {
        printf("para inserir um numero, digite 1\n");
        printf("para retirar um numero, digite 2\n");
        printf("para imprimir a arvore pre order, digite 3\n");
        printf("para imprimir a arvore  inorder, digite 4\n");
        printf("para imprimir a arvore pos order, digite 5\n");
        scanf("%d", &a);

        if (a == 1)
        {
            printf("digite o numero que deseja inserir\n");
            scanf("%d", &b);
            raiz = insere(raiz, b);
        }
        if (a == 2)
        {
            printf("digite o numero que deseja retirar\n");
            scanf("%d", &b);
            delete (raiz, b);
        }
        if (a == 3)
        {
            preorder(raiz);
        }
        if (a == 4)
        {
            inorder(raiz);
        }
        if (a == 5)
        {
            posorder(raiz);
        }
        if (a == 9)
        {
            loop = 1;
        }
    }
}
