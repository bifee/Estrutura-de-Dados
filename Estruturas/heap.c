#include <stdio.h>
#include <stdlib.h>

void siftdown(int i, int v[], int n)
{
    while (i * 2 <= n)
    {
        int l;
        if (i * 2 + 1 > n)
            l = i * 2;

        else if (v[i * 2] > v[i * 2 + 1])
            l = i * 2;
        else
            l = i * 2 + 1;

        if (v[i] < v[l])
        {
            int aux = v[l];
            v[l] = v[i];
            v[i] = aux;
            i = l;
        }
        else
            break;
    }
}

int pop(int v[], int n)
{
    int x = v[1];
    v[1] = v[n--];
    siftdown(1, v, n);
    return x;
}

void siftup(int i, int v[])
{
    while (i > 1 && v[i] > v[i / 2])
    {
        int aux = v[i];
        v[i] = v[i / 2];
        v[i / 2] = aux;
        i = i / 2;
    }
}

void push(int x, int v[], int n)
{
    v[++n] = x;
    siftup(n, v);
}

int main()
{
    int n, x, r, opcao;
    x = n = r = 0;
    int v[1000];

    do
    {
        printf("\t0 - sair\n\t1 - inserir\n\t2 - remover\n");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            printf("digite um valor: ");
            scanf("%d", &x);
            push(x, v, n);
            n++;
            int i = 1;
            for (i = 1; i <= n; i++)
            {
                printf("%d", v[i]);
            }
            break;
        case 2:
            r = pop(v, n);
            n--;
            printf("%d foi removido\n", r);
            break;
        default:
            if (opcao != 0)
                printf("opcao invalida\n");
        }
    } while (opcao != 0);
}