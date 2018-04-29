#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include "pilaL.h"

#define TRUE 1 // Creamos la constante VERDADERO que nos devuelve 1 en caso de que la comprobación sea verdadera
#define FALSE 0// Creamos la constante FALSO que nos devuelve 0 en caso de que la comprobación sea falsa

int pilaCreaVacia(Pila **p)
{
 	*p = (Pila *) malloc(sizeof(Pila));
 	
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
    if(p->sig == NULL)
        return TRUE;

    else
        return FALSE;
}

int pilaInserta(Pila **p,tipoElemento elemento)
{
    Pila *auxPila;
    
    if((auxPila = (Pila *) (malloc(sizeof(Pila)))) == NULL)
        return -2; // Código de Error (-2): Ha ocurrido un error de memoria
        
    else
    {
        auxPila->elemento = elemento;
        (*p)->sig = auxPila;
        auxPila->sig = NULL;
        (*p) = (*p)->sig;
    }
    
}

tipoElemento pilaSuprime(Pila *p, Pila **pila)
{
    Pila *temp;
    tipoElemento elemento;
    
    if(pilaVacia(p) == 1)
        return -3; // Código de Error (-3): La pila se encuentra vacia y no se puede extraer ningún elemento
    
    else
    {
        temp = p;
        
        while(temp->sig != *pila)
        {
            temp = temp->sig;
        }
        
        elemento = (*pila)->elemento;
        temp->sig = NULL;
        free(*pila);
        *pila = temp;
        return (elemento);
    }
}

/* FUNCIÓN PRINCIPAL QUE EJECUTA LAS FUCIONES DE LA PILA ELABORADA MEDIANTE LISTAS ENLAZADAS */

int main ()
{
    Pila *PilaList, *pila;
    char opcion;
    
    do
    {
        system("clear");
        puts("\n\n+---------------------------+");
        puts("+ TAD PILA LISTAS ENLAZADAS +");
        puts("+---------------------------+\n");
        puts("1.- CREAR PILA VACIA");
        puts("2.- COMPROBAR PILA VACIA");
        puts("3.- INSERTAR ELEMENTO EN PILA");
        puts("4.- SUPRIMIR ELEMENTO EN PILA");
        puts("S.- SALIR DEL PROGRAMA\n");
        puts("NOTA: PORFAVOR PRIMERO CREE UNA PILA VACIA (OPCION 1)\n");
        printf("PORFAVOR, INTRODUZCA UNA OPCION: ");
        scanf("%c", &opcion);
        opcion = toupper(opcion);
        
        switch(opcion)
        {
            case '1':crearPilaVacia(&PilaList);
                     pila = PilaList;
                     break;
            case '2':comprobarSiPilaVacia(PilaList);
                     break;
            case '3':insertarElementoEnPila(&pila);
                     break;
            case '4':suprimirElementoEnPila(PilaList, &pila);
                     break;
            case 'S':salirDelPrograma();
                     break;
        }
        
    }while(opcion != 'S');

    sleep(1);
    return 0;
}

/* FUNCIONES PARA REALIZAR LAS OPERACIONES OPORTUNAS CON LA PILA */

void crearPilaVacia(Pila **p)
{
    int retorno = pilaCreaVacia(p);
    
    // La función anterior devuelve un 1 en caso de que la pila vacía se haya creado correctamente y un 0 en caso fallido
    
    if(retorno == -1)
        puts("\nFALLO DE MEMORIA EN LA CREACIÓN DE LA PILA\n");
    
    else if (retorno == 0)
        puts("\nSE HA CREADO CORRECTAMENTE LA PILA!\n");
    
    sleep(1);
}

void comprobarSiPilaVacia(Pila *p)
{
    int retorno = pilaVacia(p);
    
    if(retorno == 1) // La función anterior devuelve un TRUE(1) en caso de que la pila esté vacía y un FALSE(0) si no está vacía
        puts("\nLA PILA ACTUALMENTE SE ENCUENTRA VACIA\n");
    
    else if (retorno == 0)
        puts("\nLA PILA ACTUALMENTE NO SE ENCUENTRA VACIA\n");
    
    sleep(1);
    
}
void insertarElementoEnPila(Pila **p)
{
    int retorno;
    tipoElemento elemento;
    
    printf("\nPORFAVOR, INTRODUZCA EL ELEMENTO QUE DESEA INSERTAR EN LA PILA: ");
    scanf("%d", &elemento);
    
    retorno = pilaInserta(p, elemento);
    
    if(retorno == -2) // La función anterior devuelve un COD_ERROR(-2) en caso de que ocurra un error en memoria en la insercion
        puts("\nNO SE HA PODIDO REALIZAR LA INSERCION PORQUE LA PILA SE ENCUENTRA LLENA\n");
    
    else
        puts("\nELEMENTO INSERTADO CORRECTAMENTE!\n");
        
    sleep(1);
}

void suprimirElementoEnPila(Pila *p, Pila **pila)
{
    tipoElemento retorno = pilaSuprime(p, pila);
    
    if(retorno == -3) // La función anterior devuelve un COD_ERROR(-3) en caso de que la lista se encuentre vacía actualmente
        puts("\nPILA VACIA, NO SE PUEDE EXTRAER NINGUN ELEMENTO\n");
    
    else
        printf("\nEL TOPE DE SU PILA ES: %d\n\n", retorno);   
        
    sleep(1);
}

int salirDelPrograma()
{
    puts("\nSALIENDO DEL PROGRAMA...\n");
    sleep(1);
    exit(0);
}
