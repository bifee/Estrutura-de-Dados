#include <stdio.h>
#include <stdlib.h>

/* 2*numero de elementos, pega numero primo mais proximo(TAM)*/
#define TAM 31

typedef struct no
{
    int chave;
    struct no *prox;
} No;
typedef struct
{
    No *inicio;
    int tam;

} lista;

void inicializarlista(lista *lis)
{
    lis->inicio = NULL;
    lis->tam = 0;
}

void inserirlista(lista *lis, int valor)
{
    No *novo = malloc(sizeof(No));
    if (novo)
    {
        novo->chave = valor;
        novo->prox = lis->inicio;
        lis->inicio = novo;
        lis->tam++;
    }
    else
        printf("erro ao alocar memoria");
}

int buscarlista(lista *lis, int valor)
{
    No *aux = lis->inicio;
    while (aux != NULL && aux->chave != valor)
    {
        aux = aux->prox;
    }
    if (aux != NULL)
        return aux->chave;
    else
        return 0;
}

void imprimirlista(lista *lis)
{
    No *aux = lis->inicio;
    printf("tam: %d: ", lis->tam);
    while (aux != NULL)
    {
        printf("%d ", aux->chave);
        aux = aux->prox;
    }
}

void inicializarTabela(lista t[])
{
    int i;
    for (i = 0; i < TAM; i++)
    {
        inicializarlista(&t[i]);
    }
}

int funcaoHash(int chave)
{
    return chave % TAM;
}

void inserir(lista t[], int valor)
{
    int id = funcaoHash(valor);
    inserirlista(&t[id], valor);
}

int busca(lista t[], int chave)
{
    int id = funcaoHash(chave);
    printf("\nIndice gerado: %d\n", id);
    return buscarlista(&t[id], chave);
}

void imprimir(lista t[])
{
    int i;
    for (i = 0; i < TAM; i++)
    {
        printf("%2d = ", i);
        imprimirlista(&t[i]);
        printf("\n");
    }
}

int main()
{

    int opcao, valor, retorno;
    lista tabela[TAM];

    inicializarTabela(tabela);

    do
    {
        printf("\n\t0 - Sair\n\t1 - inserir\n\t2 - Buscar\n\t3 - imprimir\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("\tqual valor deseja inserir? ");
            scanf("%d", &valor);
            inserir(tabela, valor);
            break;
        case 2:
            printf("\tqual valor deseja buscar? ");
            scanf("%d", &valor);
            retorno = busca(tabela, valor);
            if (retorno != 0)
                printf("\tvalor encontrado: %d\n", retorno);
            else
                printf("\tvalor nao encontrado");
            break;
        case 3:
            imprimir(tabela);
            break;
        case 0:

        default:
            printf("opcao invalida");
        }
    } while (opcao != 0);

    return 0;
}