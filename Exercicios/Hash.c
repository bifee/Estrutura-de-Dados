#include <stdio.h>
#include <stdlib.h>

void inicializarTabela(int t[])
{
    int i;
    for (i = 0; i < 11; i++)
    {
        t[i] = 0;
    }
}

int funcaoHash(int chave)
{
    return chave % 11;
}

void inserir(int t[], int valor)
{
    int id = funcaoHash(valor);
    while (t[id] != 0)
    {
        id = funcaoHash(id + 1);
    }
    t[id] = valor;
}

void imprimir(int t[])
{
    int i;
    for (i = 0; i < 11; i++)
    {
        printf("%d = %d\n", i, t[i]);
    }
}

int main()
{

    int valor, i, tabela[11];

    inicializarTabela(tabela);

    while (valor != -1)
    {
        scanf("%d", &valor);
        if (valor != -1)
        {
            inserir(tabela, valor);
        }
    }
    for (i = 0; i <= 10; i++)
    {
        if (tabela[i] == 0)
        {
            printf("__ ");
        }
        else
        {
            printf("%d ", tabela[i]);
        }
    }
    printf("\n");
    for (i = 0; i <= 10; i++)
    {
        printf(" %d ", i);
    }
    return 0;
}