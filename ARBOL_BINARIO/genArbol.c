#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include "genArbol.h"

Arbol genArbol(char *exPostfija)
{
	Arbol a;
	Pila p;
	int i;
	char simbolo;
	pilaCreaVacia(&p);

	simbolo	= exPostfija[0];
	i = 0;

	while(simbolo != '\0')
	{
			if (simbolo == '+') // OPERADOR SUMA (+)
				{
					a = creaNodo(simbolo);
					a->der = pilaSuprime(&p);
					a->izq = pilaSuprime(&p);
					pilaInserta(&p,a);
				}

			else if (simbolo == '*') // OPERADOR PRODUCTO (+)
				{
					a = creaNodo(simbolo);
					a->der = pilaSuprime(&p);
					a->izq = pilaSuprime(&p);
					pilaInserta(&p,a);
				}
			
			else // OPERANDO CUALQUIERA (A,B,C,... | 1,2,3,...)
				{
					a = creaNodo(simbolo);
					pilaInserta(&p,a);
				}
			
			i = i + 1;
			simbolo = exPostfija[i];
	}

	a = pilaSuprime(&p);
	return a;
}
