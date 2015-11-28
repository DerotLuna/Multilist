# Multilist
Pilot (Visual Studio).

#pragma once
struct lista
{
	int valor;
	lista *prox;
};

struct principal {
	int valor;
	principal *sig;
	lista *aba;
};

bool vacio(principal *p)
{
	return (!(p));
}

bool vacioL(lista *p)
{
	return (!(p));
}

void secundaria(lista **p, int x) /*Insertar en lista sub-lista.*/
{
	lista *aux = new lista;
	aux->valor = x;
	aux->prox = (*p);
	(*p) = aux;
}

void insertar(principal **p, int x) /*Inserta en lista principal.*/
{
	principal *aux = new principal;
	aux->valor = x;
	aux->sig = (*p);
	aux->aba = NULL;
	(*p) = aux;
}

void eliminarS(lista **p) /*Elimina toda la sub-lista indicada.*/
{
	if (*p)
	{
		lista *t = (*p);
		(*p) = (*p)->prox;
		delete t;
		
		if (*p)
			eliminarS(p);
	}
}

void eliminar(principal **p, int x) /*Eliminar un (x) de la lista principal (con sub-lista).*/ /*Optimizar*/
{
	int z;
	principal *aux = (*p);
	if (!(vacio(*p)))
	{
		while ((aux) && (aux->sig))
		{
			if (aux->sig->valor == x) {
				principal *t = aux;
				aux = aux->sig->sig;
				eliminarS(&(t)->aba);
				delete t;
				break;
			}
			else
				aux = aux->sig;
		}
	}
}