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

// Aqui se presenta el problema!!!!! (solo la funcion cambiar)
void cambiar(principal **p, lista **q, int x) // parametros: lista principal completa, sub-lita a enlazar, numero X que se va a eliminar de la principal 
{
	int n;
	printf("\n Numero a buscar para realizar el cambio :");
	scanf("%i \n", &n);
	principal *aux = (*p); 
	while ((aux) && (aux->sig))
	{
		aux = aux->sig;
		if (aux->valor == n && n != x) // se busca la caja principal a enlazar con sublista de X, mientras sea distinto de X
		{
			lista *t = aux->aba; // se asigna un auxiliar hacia la sublista que ya tiene la caja principal que se le desea enlazar la otra sublista
			while (t->prox) // busca el final de la sublista de la caja principal
				t = t->prox;
			t->prox = (*q); //enlaza la ultima caja de la sublista, con el puntero de la sublita de la caja a eliminar
			break;
		}
	}
}

void buscar(principal **p, int x, bool flag) // busca el la caja principal a eliminar
{
	principal *aux = (*p);
	if (!(vacio(*p)))
	{
		while ((aux) && (aux->sig))
		{
			if (aux->sig->valor == x) { // se evalua para buscar el numero a eliminar
				principal *t = aux->sig;
				aux->sig = aux->sig->sig;
				if (flag) // depende de la opcion del usuario, de lo que desea hacer
					eliminarS(&(t)->aba); // elimina toda la sub-lista
				else
					cambiar(p, &(t)->aba, x); // busca otra caja principal para poner la sub-lista de la caja a eliminar
				delete t;
				break;
			}
			aux = aux->sig;
		}
	}
}
