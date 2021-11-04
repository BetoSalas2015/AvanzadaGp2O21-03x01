//  Sesión 35 - 04/11/2021

#include <stdio.h>		//  par ala I/O del programa
#include <stdlib.h>		//  para system()
#include "Pila.h"		//  Para las funciones de Pila

int main(void)
{
	nodo *pila = NULL;
	char car;

	pila = push(pila, 'R');
	pila = push(pila, 'o');
	pila = push(pila, 'b');
	pila = push(pila, 'e');
	pila = push(pila, 'r');
	pila = push(pila, 't');
	pila = push(pila, 'o');

	imprimePila(pila);

	pila = stackTop(pila,&car);
	printf("Lo que está en el tope de la pila es %c\n", car);

	imprimePila(pila);

	pila = pop(pila,&car);
	printf("Lo que salió de la pila es %c\n", car);

	imprimePila(pila);

	system("pause");
	return 1;
}