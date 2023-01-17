//algoritimo que cria uma lista a partir de dos numeros nao nulos de uma matriz
#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
    int i, j;
    int data;
    struct nodo *prox;
} nodo;

void impressora(nodo *head, int N, int M)
{

    nodo *aux;
    aux = head;
    int i, j, variavel = 0;

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
        {
            while (head != NULL)
            {
                if (head->i == i && head->j == j)
                {
                    printf("%d ", head->data);
                    variavel = 1;
                }
                head = head->prox;
            }
            if (variavel == 0)
            {
                printf("%d ", 0);
            }
            head = aux;
            variavel = 0;
        }
        printf("\n");
    }
}

nodo *newNodo(nodo *head, int info, int i, int j)
{
    nodo *novo = (nodo *)malloc(sizeof(nodo));
    novo->data = info;
    novo->j = j;
    novo->i = i;
    novo->prox = head;
    return novo;
}

void remove_node(nodo *head, int i, int j)
{
    struct nodo *aux1, *aux2;
    aux1 = head;
    aux2 = head;
    while (aux2 != NULL)
    {
        if (aux2->i == i && aux2->j == j)
        {
            if (aux2->prox == NULL)
            {
                aux1->prox = NULL;
                free(aux2);
                return;
            }
            else if (aux2 == head)
            {
                head = head->prox;
                free(aux2);
                return;
            }
            else
            {
                aux1->prox = aux2->prox;
                free(aux2);
                return;
            }
        }
        else
        {
            aux1 = aux2;
            aux2 = aux2->prox;
        }
    }
}

int verif(nodo *head, int info, int i, int j)
{
    if (info != 0)
    {
        while (head != NULL)
        {
            if (head->i == i && head->j == j)
            {
                head->data = info;
                return 1;
            }
            else
            {
                head = head->prox;
            }
        }
        return -1;
    }
}

int main()
{
    int N, M, ret;
    nodo *head = NULL;
    int i, j, x, aux;
    scanf("%d %d", &N, &M);
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
        {
            scanf("%d", &aux);
            if (aux != 0)
            {
                head = newNodo(head, aux, i, j);
            }
        }
    }

    while (i != -1 && j != -1 && x != -1)
    {
        scanf("%d %d %d", &i, &j, &x);
        if (i, j, x == -1)
        {
            break;
        }
        ret = verif(head, x, i, j);
        if (ret == -1)
        {
            head = newNodo(head, x, i, j);
        }
        if (x == 0)
        {
            remove_node(head, i, j);
        }
    }
    impressora(head, N, M);
    return 0;
}
