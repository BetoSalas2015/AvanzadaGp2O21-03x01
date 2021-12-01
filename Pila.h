#include <malloc.h>		// "Memory ALLOCation" - Asignacion de memoria -
#include <stdio.h>

union Datos
{
	char car;
	float numero;
};

typedef union Datos datos;

struct Nodo 
{
	datos info;
	struct Nodo *sig;
};						//  DEfinimos las caracter�sticas del Nodo

typedef struct Nodo nodo;	//  Definimos el nuevo tipo de dato nodo


//   Prototipos
nodo *push(nodo *raiz, datos dato);
void imprimePila(nodo *raiz);
nodo *pop(nodo *raiz, datos *dato);
char stackTop(nodo *raiz);
int isEmpty(nodo *tope);

//  Definici�n de las funciones
nodo *push(nodo *raiz, datos dato)	
{
	nodo *nuevo = NULL;
	nuevo = (nodo *) malloc( sizeof(nodo) ); // Creamos el nuevo nodo y guardamos su direcci�n en nuevo
	if( nuevo == NULL )					// Ya no hay memoria - Error de Overflow
	{
		printf("Ya no hay memoria disponible.");
		system("pause");
		return raiz;
	}
	nuevo->info = dato;
	nuevo->sig = NULL;
	if( raiz == NULL )			// La lista est� vac�a?
	{							//  Verdadero: la lista est� vac�a
		raiz = nuevo;
	} 
	else						// falso: la lista no est� vac�a
	{
		nodo *ultimo = raiz;
		raiz = nuevo;
		raiz ->sig = ultimo;
	}	
	return raiz;
}

void imprimePila(nodo *raiz)
{
	nodo *recorre = raiz;
	while( recorre != NULL )		//  �ultimo No es el �ltimo nodo de la lista?
	{								//  Verdadero: Es el ultimo nodo de la lista
		printf("%c - %7.3f, ", recorre->info, recorre->info);
		recorre = recorre -> sig;			//  Avanzo al siguiente nodo de la lista
	}
	putchar('\n');
}


nodo *pop(nodo *raiz, datos *dato)
{
	nodo *siguiente = NULL, *elimina = NULL;
	;
	if(raiz != NULL)			//  Si podemos sacar informaci�n de la lista
	{
		elimina = raiz;
		siguiente = elimina->sig;
		raiz = siguiente;
		*dato = elimina ->info;
		free(elimina);		// Liberamos memoria reservada por malloc
		return raiz;
	}
	else            //No hay nada que sacar - Error deUnderflow!
	{
		printf("No hay nada que sacar de la lista");
		system("pause");
		return NULL;
	}
}

char stackTop(nodo *raiz)		// prec(stackTop(pila), symb)
{ 
	char dato;
	if(raiz != NULL)			//  Si podemos sacar informaci�n de la lista
	{
		dato = raiz ->info.car;
		return raiz;
	}
	else            //No hay nada que sacar - Error deUnderflow!
	{
		printf("No hay nada que sacar de la lista");
		system("pause");
		return NULL;
	}
}

int isEmpty(nodo *tope)
{
	if(tope == NULL)
		return 1;
	else
		return 0;
}
