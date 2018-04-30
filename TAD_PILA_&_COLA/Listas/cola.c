#include "cola.h"
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1 // Creamos la constante VERDADERO que nos devuelve 1 en caso de que la comprobación sea verdadera
#define FALSE 0// Creamos la constante FALSO que nos devuelve 0 en caso de que la comprobación sea falsa

int colaCreaVacia(Cola *c)
{
    if ((c = (Cola *)malloc(sizeof(Cola))) == NULL)
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
    
    if (colaVacia(c) == TRUE)
    {     
        aux->elemento = elemento;    
        aux->sig = NULL;
        c->frente = aux;
        c->fondo = aux;
        return 0;
    }
    
    else
    {
        aux->elemento = elemento;
        aux->sig = NULL;
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
    exit(-3); // Código de Error (-3): No se ha podido extraer ningún elemento debido a que la cola está vacía

    else
        {
            ValorRetorno = c->frente->elemento;
            aux = c->frente;
            c->frente = c->frente->sig;
            free(aux);
            return ValorRetorno;
        }
}
