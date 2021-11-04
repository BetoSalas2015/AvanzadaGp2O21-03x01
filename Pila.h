#include <malloc.h>		// "Memory ALLOCation" - Asignacion de memoria -

struct Nodo 
{
	char info;
	struct Nodo *sig;
};						//  DEfinimos las características del Nodo

typedef struct Nodo nodo;	//  Definimos el nuevo tipo de dato nodo

//   Prototipos
nodo *push(nodo *raiz, char dato);
void imprimePila(nodo *raiz);
nodo *pop(nodo *raiz, char *dato);
nodo *stackTop(nodo *raiz, char *dato);
int isEmpty(nodo *tope);

//  Definición de las funciones
nodo *push(nodo *raiz, char dato)	
{
	nodo *nuevo = NULL;
	nuevo = (nodo *) malloc( sizeof(nodo) ); // Creamos el nuevo nodo y guardamos su dirección en nuevo
	if( nuevo == NULL )					// Ya no hay memoria - Error de Overflow
	{
		printf("Ya no hay memoria disponible.");
		system("pause");
		return raiz;
	}
	nuevo->info = dato;
	nuevo->sig = NULL;
	if( raiz == NULL )			// La lista está vacía?
	{							//  Verdadero: la lista está vacía
		raiz = nuevo;
	} 
	else						// falso: la lista no está vacía
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
	while( recorre != NULL )		//  ¿ultimo No es el último nodo de la lista?
	{								//  Verdadero: Es el ultimo nodo de la lista
		printf("%c, \n", recorre->info);
		recorre = recorre -> sig;			//  Avanzo al siguiente nodo de la lista
	}
	putchar('\n');
}


nodo *pop(nodo *raiz, char *dato)
{
	nodo *siguiente = NULL, *elimina = NULL;
	;
	if(raiz != NULL)			//  Si podemos sacar información de la lista
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

nodo *stackTop(nodo *raiz, char *dato)
{
	if(raiz != NULL)			//  Si podemos sacar información de la lista
	{
		*dato = raiz ->info;
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
