#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include "colaL.h"

#define TRUE 1 // Creamos la constante VERDADERO que nos devuelve 1 en caso de que la comprobación sea verdadera
#define FALSE 0// Creamos la constante FALSO que nos devuelve 0 en caso de que la comprobación sea falsa

int colaCreaVacia(Cola **c, Cola **fondo)
{
    if ((*c = (Cola *)malloc(sizeof(Cola))) == NULL)
        return -1; // Código de Error (-1): No se ha podido crear correctamente la cola vacía
    
    else
    {
        (*c)->elemento = -1;
        (*c)->sig = NULL;
        *fondo = *c;
        return 0;
    }
}

int colaVacia(Cola *c)
{
    if (c->sig == NULL)
        return TRUE;
    
    else
        return FALSE;
}

int colaInserta(Cola **fondo,tipoElemento elemento)
{
    Cola * aux;
    
    if ((aux = (Cola *)malloc(sizeof(Cola))) == NULL)
        return -2; // Código de Error (-2): No se ha podido insertar correctamente el elemento en la cola
    
    else
        {
            aux->elemento = elemento;
            aux->sig = NULL;
            (*fondo)->sig = aux;
            *fondo = aux;
            return 0;
        }
}

tipoElemento colaSuprime(Cola *c)
{
    tipoElemento ValorRetorno;
    Cola *aux;
    
  if (colaVacia(c) == TRUE)
    return -3; // Código de Error (-3): No se ha podido extraer ningún elemento debido a que la cola está vacía

    else
        {
            ValorRetorno = c->sig->elemento;
            aux = c->sig;
            c->sig = aux->sig;
            free(aux);
            return ValorRetorno;
        }
}

/* FUNCIÓN PRINCIPAL QUE EJECUTA LAS FUCIONES DE LA PILA ELABORADA CON MATRICES */

int main ()
{
    Cola *ColaList;
    Cola *fondo;
    char opcion;
    
    do
    {
    	system("clear");
        puts("\n\n+---------------------------+");
        puts("+ TAD COLA LISTAS ENLAZADAS +");
        puts("+---------------------------+\n");
        puts("1.- CREAR COLA VACIA");
        puts("2.- COMPROBAR COLA VACIA");
        puts("3.- INSERTAR ELEMENTO EN COLA");
        puts("4.- SUPRIMIR ELEMENTO EN COLA");
        puts("S.- SALIR DEL PROGRAMA\n");
        puts("NOTA: PORFAVOR PRIMERO CREE UNA COLA VACIA (OPCION 1)\n");
        printf("PORFAVOR, INTRODUZCA UNA OPCION: ");
        scanf("%c", &opcion);
        opcion = toupper(opcion);
        
        switch(opcion)
        {
            case '1':crearColaVacia(&ColaList, &fondo);
                     break;
            case '2':comprobarSiColaVacia(ColaList);
                     break;
            case '3':insertarElementoEnCola(&fondo);
                     break;
            case '4':suprimirElementoEnCola(ColaList);
                     break;
            case 'S':salirDelPrograma();
                     break;
        }
        
    }while(opcion != 'S');
    
    sleep(1);
    return 0;
}

/* FUNCIONES PARA REALIZAR LAS OPERACIONES OPORTUNAS CON LA PILA */

void crearColaVacia(Cola **c, Cola **fondo)
{
   int retorno = colaCreaVacia(c, fondo);
    
    if(retorno == 0)
        puts("\nSE HA CREADO CORRECTAMENTE LA COLA!\n");
    
    else if(retorno == -1)// La función anterior devuelve un COD_ERROR(-1) en caso de que no se haya podido crear correctamente la cola vacía
        puts("\nNO SE HA PODIDO CORRECTAMENTE LA COLA!\n");
    
    sleep(1);
}

void comprobarSiColaVacia(Cola *c)
{
    int retorno = colaVacia(c);
    
    if(retorno == 1) // La función anterior devuelve un TRUE(1) en caso de que la cola esté vacía y un FALSE(0) si no está vacía
        puts("\nLA COLA ACTUALMENTE SE ENCUENTRA VACIA\n");
    
    else if (retorno == 0)
        puts("\nLA COLA ACTUALMENTE NO SE ENCUENTRA VACIA\n");
    
    sleep(1);
    
}
void insertarElementoEnCola(Cola **fondo)
{
    int retorno;
    tipoElemento elemento;
    
    printf("\nPORFAVOR, INTRODUZCA EL ELEMENTO QUE DESEA INSERTAR EN LA COLA: ");
    scanf("%d", &elemento);
    
    retorno = colaInserta(fondo, elemento);
    
    if(retorno == -2) // La función anterior devuelve un COD_ERROR(-2) en caso de que no se haya podido insertar correctamente el elemento en la cola
        puts("\nNO SE HA PODIDO REALIZAR LA INSERCION PORQUE LA COLA SE ENCUENTRA LLENA\n");
    
    else if (retorno == 0)
        puts("\nELEMENTO INSERTADO CORRECTAMENTE!\n");
        
    sleep(1);
}

void suprimirElementoEnCola(Cola *c)
{
    tipoElemento retorno = colaSuprime(c);
    
    if(retorno == -3) // La función anterior devuelve un COD_ERROR(-3) en caso de que la cola se encuentre vacía actualmente
        puts("\nCOLA VACIA, NO SE PUEDE EXTRAER NINGUN ELEMENTO\n");
    
    else
        printf("\nEL FRENTE DE SU COLA ES: %d\n\n", retorno);   
        
    sleep(1);
}

int salirDelPrograma()
{
    puts("\nSALIENDO DEL PROGRAMA...\n");
    sleep(1);
    exit(0);
}
