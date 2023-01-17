#include <stdio.h>
#define MAX 50
void linearsearch(int arr[], int n, int x)
{
    int i, h = 0;
    for (i = 0; i < n; i++)
    {
        h++;
        if (arr[i] == x)
        {
            printf("busca linear: %d encontrado, %d comparacoes\n", x, h);
            return;
        }
    }
    printf("busca linear: %d nao encontrado, %d comparacoes\n", x, h);
}
void binarysearch(int arr[], int l, int r, int x, int h)
{
    if (r >= l)
    {
        h++;
        int meio = l + (r - l) / 2;
        if (arr[meio] == x)
        {
            printf("busca binaria: %d encontrado, %d comparacoes\n", x, h);
            return;
        }

        if (arr[meio] > x)
            return binarysearch(arr, l, meio - 1, x, h);

        return binarysearch(arr, meio + 1, r, x, h);
    }
    printf("busca binaria: %d nao encontrado, %d comparacoes\n", x, h);
}

int main()
{
    int arr[MAX];
    int n, a, x, h = 0;
    int i, j;
    printf("digite o tamanho do seu vetor: ");
    scanf("%d", &n);
    printf("digite os numeros do seu vetor:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a);
        arr[i] = a;
    }
    printf("digite o numero que deseja buscar:");
    scanf("%d", &x);
    for (j = 0; j < n; j++)
    {
        if (arr[j] > arr[j + 1])
        {
            printf("vetor nao ordenado\n");
            linearsearch(arr, n, x);
            return 0;
        }
    }
    linearsearch(arr, n, x);
    binarysearch(arr, 0, n - 1, x, h);
    return 0;
}