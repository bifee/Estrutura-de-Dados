#include <stdio.h>
#include <stdlib.h>

typedef struct grafoM
{
    int Ar;
    int Ver;
    int **Mat;
} GrafoM;

void dfs(int x, int N, GrafoM *g, int visitado[])
{

    int i;
    visitado[x] = 1;
    for (i = 1; i <= N; i++)
        if (g->Mat[x][i] && !visitado[i])
        {
            dfs(i, N, g, visitado);
        }
}
GrafoM *constroimatrix(int tamanho)
{

    GrafoM *g = (GrafoM *)malloc(sizeof(GrafoM));
    g->Ar = 0;
    g->Ver = tamanho;
    g->Mat = (int **)malloc((tamanho + 1) * sizeof(int *));
    int k;
    for (k = 0; k < g->Ver + 1; k++)
    {
        g->Mat[k] = (int *)malloc((tamanho + 1) * sizeof(int));
    }
    int i, j;
    for (i = 0; i < g->Ver + 1; i++)
    {
        for (j = 0; j < g->Ver + 1; j++)
        {
            g->Mat[i][j] = 0;
        }
    }
    return g;
}

void inserir_aresta_GrafoM(int a, int b, GrafoM *G)
{
    G->Mat[a][b] = 1;
    G->Mat[b][a] = 1;
}

int main()
{
    int visitado[100];
    int a, b, N, M;
    int i, j, contador = 0;

    scanf("%d %d", &N, &M);

    GrafoM *g1 = constroimatrix(N);

    for (i = 1; i <= N; i++)
    {
        visitado[i] = 0;
    }
    for (i = 0; i < M; i++)
    {
        scanf("%d %d", &a, &b);
        inserir_aresta_GrafoM(a, b, g1);
    }
    for (i = 1; i <= N; i++)
    {
        if (visitado[i] == 0)
        {
            dfs(i, N, g1, visitado);
            contador++;
        }
    }
    printf("\n%d", contador);
    return 0;
}
