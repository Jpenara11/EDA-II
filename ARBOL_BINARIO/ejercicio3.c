#include <stdio.h>
#include <string.h>
#include "arbol.h"
#include "genArbol.h"

int main(void)
{ Arbol arbol; 
  char ex_postfija[10];

/* Generaci�n del �rbol algebraico */
  strcpy(ex_postfija,"AB+CDE+**\0");

  arbol = genArbol(ex_postfija);

/* Aplicaci�n de algunas operaciones y recorridos al �rbol ejemplo */

  printf("Recorrido en AMPLITUD: ");
  amplitud(arbol);
  printf("\n");

  printf("Recorrido en PRE_ORDEN: ");
  preOrden(arbol);
  printf("\n");

  printf("Recorrido en ORDEN: ");
  enOrden(arbol);
  printf("\n");
  printf("Recorrido en POST_ORDEN: ");
  postOrden(arbol);
  printf("\n");
  printf("Debe coinicidir con la expresi�n postfija inicial\n");


/* Evaluaci�n de un �rbol algebraico: operandos entre '0' y '9'*/

  strcpy(ex_postfija,"23+713+**\0");
  arbol = genArbol(ex_postfija);
  printf("Recorrido en PRE_ORDEN (prefija): ");
  preOrden(arbol);
  printf("\n");
  printf("Recorrido en ORDEN(infija): ");
  enOrden(arbol);
  printf("\n");
  printf("Recorrido en POST_ORDEN(postfija): ");
  postOrden(arbol);
  printf("\n");

/* Aplicar a este arbol las funciones del ejercicio 2 */

  return 1;
}
