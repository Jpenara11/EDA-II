#define TRUE 1 // Creamos la constante VERDADERO que nos devuelve 1 en caso de que la comprobación sea verdadera
#define FALSE 0// Creamos la constante FALSO que nos devuelve 0 en caso de que la comprobación sea falsa

#include "cola.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int colaCreaVacia(Cola *c)
{
    if ( (c = (Cola *)malloc(sizeof(Cola))) == NULL)
        return -1; // Código de Error (-1): No se ha podido crear correctamente la cola vacía
    
    else
    {
        c->frente = NULL;
        c->fondo = NULL;
        return 0;
    }
}

int colaVacia(Cola *c)
{

   if (c->frente == NULL && c->fondo == NULL)
       return TRUE;
    
    else
        return FALSE;
}

int colaInserta(Cola *c,tipoElemento elemento)
{
    tipoCelda2 * aux;
    
    if ((aux = (tipoCelda2 *)malloc(sizeof(tipoCelda2))) == NULL)
            return -1;// Código de Error (-1): No se ha podido crear correctamente el frente
    
    aux->elemento = elemento;    
    aux->sig = NULL;

    if (colaVacia(c) == TRUE)
    {     
        
        c->frente = aux;
        c->fondo = aux;
        return 0;
    }
    
    else
    {
        c->fondo->sig = aux;
        c->fondo = aux;
        return 0;
    }
}

tipoElemento colaSuprime(Cola *c)
{
    tipoElemento ValorRetorno;
    tipoCelda2 *aux;
    
  if (colaVacia(c) == TRUE)
    return -3; // Código de Error (-3): No se ha podido extraer ningún elemento debido a que la cola está vacía

    else
        {
            aux = c->frente;
	    ValorRetorno = aux->elemento;
            c->frente = c->frente->sig;

	    if(c->frente == NULL)
		c->fondo = NULL;
            
            free(aux);
            return ValorRetorno;
        }
}
