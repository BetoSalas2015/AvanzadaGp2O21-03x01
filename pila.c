//  Sesión 36 - 08/11/2021

#include <stdio.h>		//  par ala I/O del programa
#include <stdlib.h>		//  para system()
#include "Pila.h"		//  Para las funciones de Pila

// Prototipos
int prec(char op1, char op2);
void postfijo(char expresion[]);

//  Funciones


int main(void)
{
	char cadena[50];
	printf("Dame ña cadena a analizar: ");
	gets(cadena);



	system("pause");
	return 1;
}