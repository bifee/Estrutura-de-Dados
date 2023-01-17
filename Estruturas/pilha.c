#include <stdio.h>
#include <stdlib.h>
#define MAXTAM 100
typedef struct
{
    int pilha[MAXTAM];
    int top;
} pilha;

void inicia_pilha(pilha *p)
{
    p->top = -1;
}

int pilha_vazia(pilha *p)
{
    if (p->top == -1)
    {
        return 1;
    }
    else
        return 0;
}

int pilha_cheia(pilha *p)
{
    if (p->top == MAXTAM - 1)
    {
        printf("pilha esta cheia!\n");
        return 1;
    }
    else
        return 0;
}

void pilha_insere(int x, pilha *p)
{
    if (pilha_cheia(p) == 1)
    {
        printf("pilha esta cheia!\n");
    }
    else
    {
        p->top++;
        p->pilha[p->top] = x;
    }
}

int remove_pilha(pilha *p)
{
    int aux;
    if (pilha_vazia(p) == 1)
    {
        printf("pilha esta vazia!\n");
        return 0;
    }
    aux = p->pilha[p->top];
    p->top--;
    return aux;
}

int main()
{
    pilha *p = (pilha *)malloc(sizeof(pilha));
    inicia_pilha(p);
    int a, b, loop, aux;
    while (loop == 0)
    {
        printf("para inserir um numero, digite 1\n");
        printf("para retirar um numero, digite 2\n");
        printf("para sair do programa, digite 9\n");
        scanf("%d", &a);

        if (a == 1)
        {
            printf("digite o numero que deseja inserir\n");
            scanf("%d", &b);
            pilha_insere(b, p);
        }
        if (a == 2)
        {
            printf("digite o numero que deseja retirar\n");
            int aux = remove_pilha(p);
            if (aux != 0)
                printf("%d removido\n", aux);
        }
        if (a == 9)
        {
            loop = 1;
        }
    }
    free(p);
    return 0;
}
