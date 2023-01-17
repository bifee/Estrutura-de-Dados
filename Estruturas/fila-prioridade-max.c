#include <stdlib.h>
#include <stdio.h>

typedef struct
{
    int tam;
    int v[];
} filap;

void push(filap *f, int x)
{
    f->v[f->tam++] = x;
    printf("oi");
    int i = f->tam - 1;
    while (i > 0 && f->v[i] < f->v[i - 1])
    {
        int aux = f->v[i];
        f->v[i] = f->v[i - 1];
        f->v[i - 1] = aux;
        i--;
    }
}

int pop(filap *f)
{
    int x = f->v[f->tam - 1];
    f->tam--;
    return x;
}

void imprimir(filap *f)
{
    int i;
    for (i = 0; i < f->tam; i++)
        ;
    printf("%d", f->v[i]);
}

int main()
{
    int opcao, r, valor;
    filap *f = NULL;
    do
    {
        printf("\t0 - sair\n\t1 - inserir\n\t2 - remover\n\t3 - imprimir\n");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            printf("digite um valor: ");
            scanf("%d", &valor);
            push(f, valor);
            break;
        case 2:
            r = pop(f);
            printf("%d foi removido\n", r);
            break;
        case 3:
            imprimir(f);
            break;
        default:
            if (opcao != 0)
                printf("opcao invalida\n");
        }
    } while (opcao != 0);
    return 0;
}