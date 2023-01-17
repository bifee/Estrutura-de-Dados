#include "FilaEstatica.c"

typedef struct noA NoA;
typedef struct grafoA GrafoA;

struct noA
{
  int id;
  NoA *next;
};

NoA *createNode(int);

struct grafoA
{
  int *visitado;
  int V;
  NoA **Adj;
};

GrafoA *CriarGrafoA(int tamanho)
{
  GrafoA *G = malloc(sizeof(GrafoA));
  G->V = tamanho;
  G->Adj = malloc(tamanho * sizeof(NoA *));
  G->visitado = malloc(tamanho * sizeof(int));
  int i;
  for (i = 0; i < tamanho; i++)
  {
    G->Adj[i] = NULL;
    G->visitado[i] = 0;
  }
  return G;
}

NoA *createNode(int v)
{
  NoA *newNode = malloc(sizeof(NoA));
  newNode->id = v;
  newNode->next = NULL;
  return newNode;
}

void inserir_aresta_GrafoA(int a, int b, GrafoA *G)
{
  NoA *newNode = createNode(b);
  newNode->next = G->Adj[a];
  G->Adj[a] = newNode;

  newNode = createNode(a);
  newNode->next = G->Adj[b];
  G->Adj[b] = newNode;
}

int bfs(int r, int t, GrafoA *G)
{
  int d[n], p[n], i, x;
  struct Fila *f = cria_fila();
  for (i = 0; i < n; i++)
  {
    d[n] = 0;
    p[n] = 0;
  }
  d[r] = 0;
  p[r] = -1;
  G->visitado[r] = 1;
  insere_fila(f, r);
  while (!isEmpty(f))
  {
    int atual = remove_fila(f);
    NoA *temp = G->Adj[atual];
    while (temp)
    {
      x = temp->id;
      if (G->visitado[x] == 0)
      {
        G->visitado[x] = 1;
        d[x] = d[atual] + 1;
        p[x] = atual;
        insere_fila(f, x);
      }
      temp = temp->next;
    }
  }
  libera_Fila(f);
  return d[t];
}

void liberar_grafo_adj(GrafoA *G)
{
  int v;
  for (v = 0; v < G->V; v++)
  {
    if (G->Adj[v] != NULL)
    {
      free(G->Adj[v]);
    }
  }
  free(G->Adj);
  free(G->visitado);
  free(G);
}

int main()
{
  int a, b, x, y, N, M, c;
  int j;
  scanf("%d %d", &N, &M);

  GrafoA *G = CriarGrafoA(N + 1);
  for (j = 0; j < M; j++)
  {
    scanf("%d %d", &a, &b);
    inserir_aresta_GrafoA(a, b, G);
  }
  scanf("%d %d", &x, &y);
  c = bfs(x, y, G);
  printf("%d", c);
  liberar_grafo_adj(G);
  return 0;
}
