#include <stdio.h>
#include <stdlib.h>
#include "FDRDinamico.c"
#include <string.h>

int main()
{
    Fila *f = cria_fila();

    int num;
    char funcao[2];
    int loop = 1;
    printf("digite uma funcao que deseja operar utilizar:");
    printf("pb x para inserir um numero ao final da FDR\n");
    printf("pf x para inserir um numero ao inicio da FDR\n");
    printf("ob para remover um numero do final da FDR e imprimi-lo\n");
    printf("of para remover um numero do inicio da FDR e imprimi-lo\n");
    printf("rv para inverter a ordem dos elementos da FDR\n");
    printf("FF para liberar toda a memoria alocada e terminar a execucao\n");

    while (loop)
    { 

        scanf("%s", funcao);

        if (!strcmp(funcao, "pb"))
        { 
            printf("digite o numero que deseja adicionar\n");
            scanf("%d", &num);
            pushh_back(f, num);
        }
        else if (!strcmp(funcao, "pf"))
        {
            printf("digite o numero que deseja adicionar\n");
            scanf("%d", &num);
            pushh_front(f, num);
        }
        else if (!strcmp(funcao, "ob"))
        {
            printf("%d foi retirado do fim da fila\n", popp_back(f));
        }
        else if (!strcmp(funcao, "of"))
        {
            printf("%d foi retirado do comeco da fila\n", popp_front(f));
        }
        else if (!strcmp(funcao, "rv"))
        {
            reverse_fila(f);
        }
        if (!strcmp(funcao, "FF"))
        {
            freefila(f);
            loop = 0;
        }
    }
    return 0;
}
