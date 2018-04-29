#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "conjuntos.h"

void crea(particion C)
{
  int i;

  for(i = 0; i < MAXIMO; i++)
  {
    if((C[i].primero = (tipoCelda *) malloc(sizeof(tipoCelda))) == NULL) exit(-1);
    C[i].ultimo = C[i].primero;
    C[i].primero->elemento = C[i].ultimo->elemento = i;
    C[i].ultimo->sig = NULL;
  }
}

tipoElemento buscar(tipoElemento x, particion C)
{
  tipoCelda * aux;
  int i;

  for(i = 0; i < MAXIMO; i++)
  {
    if((aux = (tipoCelda *) malloc(sizeof(tipoCelda))) == NULL) exit(-1);
    aux = C[i].primero;

    while(aux != NULL)
    {
      if(aux->elemento == x)
        return i; // "i" coincide con el representante de cada particion

      aux = aux->sig;
    }
  }

  aux = NULL;
  free(aux);
}

void unir(tipoElemento x, tipoElemento y, particion C)
{
  tipoElemento RepX, RepY;

  RepX = buscar(x, C);
  RepY = buscar(y, C);

  C[RepX].ultimo->sig = C[RepY].primero;
  C[RepX].ultimo = C[RepY].ultimo; 
  C[RepY].primero = C[RepY].ultimo = NULL;
}

// Funciones auxiliares para ver contenido de Partición y Clase de Equivalencia

void verParticion(particion C)
{ int i;
   tipoCelda *aux;
    for (i =0;i<MAXIMO;i++) {
         aux = C[i].primero;
         if (aux!=NULL)  printf("\n\nClase equivalencia representante %d: ",i);
        while (aux!=NULL)
        { printf("%d ",aux->elemento);
         aux=aux->sig;
        }
    }
}

void verClaseEquivalencia(tipoElemento x,particion C)
{ int representante;
  tipoCelda *aux;
  
    representante = buscar(x,C);
    printf("\n\nClase de Equivalencia de %d cuyo representante es %d: ", x,representante);
    aux = C[representante].primero;
    while (aux)
        { printf(" %d ",aux->elemento);
          aux=aux->sig;
        }
    printf("\n\n");
}