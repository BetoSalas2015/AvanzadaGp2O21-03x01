//  Sesión 36 - 08/11/2021
#include <stdlib.h>		//  para system()
#include <stdio.h>		//  par ala I/O del programa
#include "Pila.h"


// Prototipos

int main(void)
{
	datos var;
	datos var2;

	nodo *pila = NULL;
	//  compañero 1 y 2
	var.car = 'R';
	pila = push(pila, var);

	imprimePila(pila);

	var2.numero = 3.14159;
	pila = push(pila, var2);

	imprimePila(pila);
	//----------------------------
	pila = pop(pila, &var);
	printf("El numero flotante que salio fue: %7.3f, \n", var.numero);

	pila = pop(pila, &var);
	printf("El char que salio fue: %c, \n", var.car);


	system("pause");
	return 1;
}