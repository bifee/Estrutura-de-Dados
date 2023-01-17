#include <stdlib.h>
#include <stdio.h>

typedef struct no
{
    int valor;
    struct no *prox;
} no;

void inserir_na_fila(no **fila, int num)
{
    no *aux, *novo = malloc(sizeof(no));
    if (novo != NULL)
    {
        novo->valor = num;
        novo->prox = NULL;
        if (*fila == NULL)
        {
            *fila = novo;
        }
        else
        {
            aux = *fila;
            while (aux->prox != NULL)
                aux = aux->prox;
            aux->prox = novo;
        }
    }
    else
        printf("erro ao alocar memoria\n");
}

no *remove_fila(no **fila)
{
    no *remover = NULL;

    if (*fila != NULL)
    {
        remover = *fila;
        *fila = remover->prox;
    }
    else
        printf("fila vazia\n");
    return remover;
}

void imprimir(no *fila)
{
    printf("\t------------ FILA ------------\n");
    while (fila != NULL)
    {
        printf("%d ", fila->valor);
        fila = fila->prox;
    }

    printf("\t------------ FIM FILA ------------\n");
}
int main()
{
    no *r, *fila = NULL;
    int opcao, valor;
    do
    {
        printf("\t0 - sair\n\t1 - inserir\n\t2 - remover\n\t3 - imprimir\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("digite um valor: ");
            scanf("%d", &valor);
            inserir_na_fila(&fila, valor);
            break;
        case 2:
            r = remove_fila(&fila);
            if (r != NULL)
            {
                printf("removido: %d\n", r->valor);
                free(r);
            }
            break;
        case 3:
            imprimir(fila);
            break;
        default:
            if (opcao != 0)
            {
                printf("opcao invalida\n");
            }
        }
    } while (opcao != 0);
    return 0;
}