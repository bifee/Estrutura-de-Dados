#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define n 100
typedef struct
{
    int pilha[n];
    int top;
} Pilha;

void inicia_pilha(Pilha *p)
{
    p->top = -1;
}

int pilha_cheia(Pilha *p)
{
    if (p->top == n - 1)
        return 1;
    else
        return 0;
}

int pilha_vazia(Pilha *p)
{
    if (p->top == -1)
        return 1;
    else
        return 0;
}

void empilhar(Pilha *p, int x)
{
    if (pilha_cheia(p) == 1)
        printf("Pilha cheia!");
    else
    {
        p->top++;
        p->pilha[p->top] = x;
    }
}

int desempilhar(Pilha *p)
{
    int aux;
    if (pilha_vazia(p) == 1)
        printf("Pilha cheia!");
    else
    {
        aux = p->pilha[p->top];
        p->top--;
    }
    return aux;
}

float operacao(float a, float b, char x)
{
    switch (x)
    {
    case '+':
        return a + b;
        break;
    case '*':
        return a * b;
        break;
    default:
        return 0.0;
    }
}
float fatorial(int a)
{
    int i;
    for (i = a - 1; i > 0; i--)
        a = a * i;
    return a;
}
float resolver_expressao(char *x)
{
    Pilha *p = (Pilha *)malloc(sizeof(Pilha));
    inicia_pilha(p);
    float num;
    int i, h;
    int n1, n2, n3;
    h = strlen(x);
    for (i = 0; i < h; i++)
    {
        if (x[i] == '+' || x[i] == '*')
        {
            n1 = desempilhar(p);
            n2 = desempilhar(p);
            num = operacao(n2, n1, x[i]);
            empilhar(p, num);
        }
        else if (x[i] == '!')
        {
            n3 = desempilhar(p);
            num = fatorial(n3);
            empilhar(p, num);
        }
        else
        {
            num = x[i] - '0';
            empilhar(p, num);
        }
    }
    n1 = desempilhar(p);
    num = n1;
    free(p);
    return num;
}
int main()
{
    char exp[50];

    scanf("%s", &exp);
    printf("%f\n", resolver_expressao(exp));
}