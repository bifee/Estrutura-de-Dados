#include "FDRDinamico.h"

Fila *cria_fila()
{
	Fila *f = (Fila *)malloc(sizeof(Fila));
	f->inicio = f->fim = NULL;
	return f;
}

void pushh_back(Fila *f, int x)
{
	nodo *novo = (nodo *)malloc(sizeof(nodo));
	novo->info = x;
	novo->prox = NULL;
	novo->ant = f->fim;

	if (f->fim == NULL)
	{
		f->fim = novo;
		f->inicio = novo;
	}
	else
	{
		f->fim->prox = novo;
		f->fim = novo;
	}
}

void pushh_front(Fila *f, int x)
{
	nodo *novo = (nodo *)malloc(sizeof(nodo));
	novo->info = x;
	novo->ant = NULL;
	novo->prox = f->inicio;

	if (f->inicio == NULL)
	{
		f->fim = novo;
		f->inicio = novo;
	}
	else
	{
		f->inicio->ant = novo;
		f->inicio = novo;
	}
}

int popp_back(Fila *f)
{

	int data = f->fim->info;
	struct nodo *temp = f->fim;
	if (f->inicio == f->fim)
	{
		f->fim = NULL;
		f->inicio = NULL;
	}
	else
	{
		f->fim = f->fim->ant;
		f->fim->prox = NULL;
		/
	}
	free(temp);
	return data;
}

int popp_front(Fila *f)
{
	int data = f->inicio->info;
	struct nodo *temp = f->inicio;
	if (f->inicio == f->fim)
	{
		f->fim = NULL;
		f->inicio = NULL;
	}
	else
	{
		f->inicio = f->inicio->prox;
		f->inicio->ant = NULL;
	}
	free(temp);
	return data;
}

void reverse_fila(Fila *f)
{
	struct nodo *atual, *temp;
	atual = f->inicio;
	while (atual != NULL)
	{
		temp = atual->prox;
		atual->prox = atual->ant;
		atual->ant = temp;
		atual = temp;
	}

	temp = f->inicio;
	f->inicio = f->fim;
	f->fim = temp;
}

void freefila(Fila *f)
{
	int temp;
	while (f->fim != NULL)
	{
		temp = popp_back(f);
	}
	free(f);
}
