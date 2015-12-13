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
	bool flag = false;
	if (vacioL(*p))
	{
		lista *aux = new lista;
		aux->valor = x;
		aux->prox = (*p);
		(*p) = aux;
		flag = true;
	}
	else
	{
		lista *t = (*p);
		while (t)
		{
			if (t->valor == x)
			{
				flag = true;
				break;
			}
			t = t->prox;
		}

		if (!flag)
		{
			lista *aux = new lista;
			aux->valor = x;
			aux->prox = NULL;
			t = (*p);
			while (t->prox)
				t = t->prox;
			t->prox = aux;
		}
		else printf("Repetido!");
	}
}

void insertar(principal **p, int x) /*Inserta en lista principal.*/
{
	bool flag = false;
	if (vacio(*p)) 
	{
		principal *aux = new principal;
		aux->valor = x;
		aux->sig = (*p);
		aux->aba = NULL;
		(*p) = aux;
		flag = true;
	}
	else
	{
		principal *t = (*p);
		while (t)
		{
			if (t->valor == x)
			{
				flag = true;
				break;
			}
			t = t->sig;
		}

		if (!flag)
		{
			principal *aux = new principal;
			aux->valor = x;
			aux->aba = NULL;
			aux->sig = NULL;
			t = (*p);
			while (t->sig)
				t = t->sig;
			t->sig = aux;
		}
		else printf("Repetido!");
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
