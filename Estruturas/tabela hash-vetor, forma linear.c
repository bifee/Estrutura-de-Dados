#include <stdio.h>
#include <stdlib.h>

/* 2*numero de elementos, pega numero primo mais proximo(TAM)*/
#define TAM 31

void inicializarTabela(int t[])
{
    int i;
    for (i = 0; i < TAM; i++)
    {
        t[i] = 0; /*recebe zero pois neste caso, 0 n faz parte dos conjuntos inseridos na tabela*/
    }
}

int funcaoHash(int chave)
{
    return chave % TAM;
}

void inserir(int t[], int valor)
{
    int id = funcaoHash(valor);
    while (t[id] != 0)
    { /*utilizado o zero pois neste caso 0 quer dizer que n possui elemento (funcao inicializar)*/
        id = funcaoHash(id + 1);
    }
    t[id] = valor;
}

int busca(int t[], int chave)
{
    int id = funcaoHash(chave);
    printf("\nIndice gerado: %d\n", id);
    while (t[id] != 0)
    {
        if (t[id] == chave)
            return t[id];
        else
            id = funcaoHash(id + 1);
    }
    return 0; /* 0 pois é o indicador q a posicao ta vazia*/
}

void imprimir(int t[])
{
    int i;
    for (i = 0; i < TAM; i++)
    {
        printf("%d = %d\n", i, t[i]);
    }
}

int main()
{

    int opcao, valor, retorno, tabela[TAM];

    inicializarTabela(tabela);

    while (opcao != 0)
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
    }
}