# Multilist
Pilot (Visual Studio).
#include <stdio.h>
#include <stdlib.h>
#include "Primitivas.h"

// (x) lista principal.         (y) sub-lista. 

void mostrar(principal *p) //Muestra la lista principal completa.
{
	principal *aux = p;
	while (aux)
	{
		printf(" %i ->", aux->valor);
		aux = aux->sig;
	}
	printf(" NULL");

}

void mostrarT(principal *p) //Muestra un valor de la lista principal.
{
	principal *aux = p;
	if (aux->sig)
		printf(" %i ->", aux->valor);
	else
	{
		printf(" %i ->", aux->valor);
		printf(" NULL");
	}

}

void mostrar22(lista *p) //Muestra toda una sub-lista, segun se le indique su principal.
{
	lista *aux = p;
	while (aux)
	{
		printf( " %i ->", aux->valor);
		aux = aux->prox;
	}
	printf(" NULL");
}

void mostrar2(principal *p, int x) //Busca el valor indicado (x) para mandar puntero a mostrar22 y mostrar su sub-lista.        Optimizar
{
	principal *aux = p;
	if (!(vacio(p)))
	{
		while (aux)
		{
			if (aux->valor == x) {
				mostrar22((aux)->aba);
				break;
			}
			else
				aux = aux->sig;
		}
	}

}

void buscar(principal *p, int x) //Buscar en el principal el valor (x) indicado para asi insertar en su sub-lista un valor (y).     Optimizar
{
	int z;
	principal *aux = p;
	if (!(vacio(p)))
	{
		while (aux)
		{
			if (aux->valor == x) {
				printf("\n Ingrese el elemento: ");
				scanf("%i", &z);
				secundaria(&(aux)->aba, z);
				break;
			}
			else
				aux = aux->sig;
		}
	}
}

void mostrarTodo(principal *p) //Muestra cada caja de lista principal con su debida sub-lista.       Optimizar
{
	principal *aux = p; 
	int cont = 1;
	if (!vacio(p))
	{
		while (aux)
		{
			printf("\n\n Caja [%i] principal con su sublista : \n\n" , cont);
			mostrarT(aux);
			printf("\n\n");
			mostrar2(p, aux->valor);
			aux = aux->sig;
			cont++;
		}
	}
}

int buscarY(lista *p, int y)
{
	lista *aux = p;
	if (!(vacioL(aux)))
	{
		if (aux->valor == y)
			return 1;
		buscarY(aux->prox, y);
	}
	return 0;
}

void secPrin(principal *p, int y) //Toma un (x) y busca si tiene un (y) y asi mostrar todos los (x) que la contengan.        Modificar
{
	principal *aux = p;
	if (!(vacio(p)))
	{
		while (aux)
		{
				if (buscarY((aux)->aba, y) == 1)
					printf("\n El x = %i tiene contenido en su sub-lista el valor y = %i.", aux->valor, y);
				aux = aux->sig;
		}
	}
}

int arch(FILE *archivo)
{
	char caracteres[100];

	archivo = fopen("prueba.txt", "r");

	if (archivo == NULL)
		exit(1);

	printf("\nEl contenido del archivo de prueba es \n\n");
	while (feof(archivo) == 0)
	{
		fgets(caracteres, 100, archivo);
		printf("%s", caracteres);
	}

	fclose(archivo);
	return 0;
}

void main()
{
	int op = -1, n = 0; 
	principal *p = NULL;
	while (op != 0) {
		system("cls");
		printf("\n\n                              Menu principal. \n\n\n");
		printf("\n 1. Insertar en lista principal.");
		printf("\n 2. Insertar a la sub-lista de un principal (x).");
		printf("\n 3. Mostrar lista principal.");
		printf("\n 4. Mostrar sub-lista.");
		printf("\n 5. Mostrar todo.");
		printf("\n 6. Eliminar un elemento (x) de la lista principal.");
		printf("\n 7. Buscar un (y) en las sub-listas y mostrar las (x) que las contienen.");
		printf("\n 8. Guardar datos en un archivo."); //No hecha
		printf("\n 9. Leer datos desde el archivo."); //No hecha
		printf("0. Salir. \n\n");
		printf("Indique opcion (1-5): ");
		op = 0;
		scanf("%i", &op);
		system("cls");
		printf("\n\n");
		bool flag = true;
		switch (op)
		{
			case 1: printf("Indique el numero a ingresar: ");
				scanf("%i", &n);
				insertar(&p, n);
				break;

			case 2:
				printf("Numero a buscar para insertar en la sub-lista :");
				scanf("%i", &n);
				buscar(p, n);
				break;

			 case 3:
				printf("\n\n Lista Principal \n\n ");
				mostrar(p);
				break;
		
			case 4: printf("\n\n Sub-lista. \n\n");
				printf("Numero a buscar para imprimir la sublista :");
				scanf("%i", &n);
				mostrar2(p, n);
				break;

			case 5: printf("\n\n                      Lista principal con sus sub-listas: \n\n");
				mostrarTodo(p);
			break; 

			case 6:
				printf("Numero a buscar para eliminar de la lista principal (Elimina toda su sub-lista). :");
				scanf("%i", &n);
				buscar(&p, n, flag);
				break;
			
			case 7: printf("Numero de la sub-lista (y) a buscar su (x) en principal :");
				scanf("%i", &n);
				secPrin(p, n);
				break;

			case 9: FILE *archivo;
				arch(archivo);
				break;

			case 10:
				printf("Numero a buscar para eliminar de la lista principal \n(Guarda sublista en otra caja principal):");
				scanf("%i", &n);
				flag = false;
				buscar(&p, n, flag);
				break;
		}
		if (op)
		{
			printf("\n\n");
			system("pause");
			system("cls");
		}
	}
}
