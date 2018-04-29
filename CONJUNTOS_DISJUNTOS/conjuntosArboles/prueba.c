#include <stdio.h>
#include <stdlib.h>
#include "conjuntos.h"

int main()
{ 
  particion C;
  int i;


crea(C);
printf("\nSITUACION INICIAL: \n\n");
verParticion(C);

// Se forman las siguientes clases de equivalencia haciendo al primer elemento del conjunto su representatne:
// {7,0,13,15},{2,3,8,12},{11,1,4,6,14},{9,5,10}


unir(13,15,C);		// Mejor unir(buscar(13,C),buscar(15,C),C);
unir(7,0,C);			// Mejor unir(buscar(7,C),buscar(0,C),C);
unir(7,13,C);			// Mejor unir(buscar(7,C),buscar(13,C),C);

unir(8,12,C);			// Mejor ...
unir(3,8,C);			// Mejor ...
unir(2,3,C);			// Mejor ...

unir(6,1,C);			// Mejor ...
unir(6,4,C);			// Mejor ...
unir(11,14,C);		// Mejor ...
unir(11,6,C);			// Mejor ...

unir(5,10,C);			// Mejor ...
unir(9,5,C);			// Mejor ...


printf("SITUACION FINAL:   \n\n");

verParticion(C);

printf("\n\nEl elemento 5 pertenence a la clase de equivalencia con representante %d\n\n",buscar(5,C));

printf("\n\nPOR COMPRESION DE CAMINOS EL ELEMENTO 3 PERTENECE A LA CLASE DE EQUIVALENCIA CON REPRESENTANTE %d\n\n", buscarCompresionCaminos(3,C));
}
