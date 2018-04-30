#include "pila.h"
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1 
#define FALSE 0

int pilaCreaVacia(Pila *p)
{
    *p = (Pila) malloc(sizeof(Pila*));
 	
 	if(*p == NULL)
 	  return -1; // Código de Error (-1): Ha ocurrido un error de memoria
 	
 	else
 	  {
        (*p)->elemento = -1;
        (*p)->sig = NULL;
        return 0;
      }
}

int pilaVacia(Pila *p)
{
    if((*p)->sig == NULL)
        return TRUE;

    else
        return FALSE;
}

int pilaInserta(Pila *p,tipoElemento elemento)
{
    Pila auxPila;
    
    if((auxPila = (Pila) (malloc(sizeof(Pila*)))) == NULL)
        return -2; // Código de Error (-2): Ha ocurrido un error de memoria
        
    else
    {       
        auxPila->sig = (*p);
        auxPila->elemento = elemento;
        (*p) = auxPila; 
    }
}

tipoElemento pilaSuprime(Pila *p)
{
    
    tipoElemento elemento;
    Pila aux;
    
    if(pilaVacia(p) == TRUE)
        exit(-3); // Código de Error (-3): La pila se encuentra vacia y no se puede extraer ningún elemento
        
    else
    {      
        elemento = (*p)->elemento;
        aux = (*p);
        (*p) = (*p)->sig;
        free(aux);
        return elemento;
    }
}
