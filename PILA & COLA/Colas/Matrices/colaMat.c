#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include "colaM.h"

#define TRUE 1 // Creamos la constante VERDADERO que nos devuelve 1 en caso de que la comprobación sea verdadera
#define FALSE 0// Creamos la constante FALSO que nos devuelve 0 en caso de que la comprobación sea falsa

void colaIncrementaIndice (int *pos)
{
    if(*pos == MAX)
        *pos = 0;
    
    else
        *pos = *pos + 1;
}

int colaCreaVacia(Cola *c)
{
 	c->tamano = 0;
 	c->frente = 0;
 	c->fondo = MAX;
 	
 	if (c->tamano == 0 && c->frente == 0 && c->fondo == MAX)
 	  return 0;
 	
 	else if(c->tamano != 0 || c->frente != 0 || c->fondo != MAX)
 	  return -1; // Código de Error (-1): No se ha podido crear correctamente la cola vacía
}

int colaVacia(Cola *c)
{
 	if(c->tamano == 0)
        return TRUE;

    else
        return FALSE;
}

int colaInserta(Cola *c,tipoElemento elemento)
{
    if(c->tamano == MAX)
        return -2; // Código de Error (-2): Cola llena y no se puede insertar ningún elemento más

    else
    {
        c->tamano = c->tamano + 1;
        colaIncrementaIndice(&(c->fondo));
        c->elementos[c->fondo] = elemento;
        
        return 0;
    }
}

tipoElemento colaSuprime(Cola *c)
{
    tipoElemento valor;

    if (colaVacia(c) == TRUE)
    {
        return -3; // Código de Error (-3): Cola vacía y por tanto no se puede extraer ningún elemento
    }    
    
    else
    {
        valor = c->elementos[c->frente];
        c->tamano = c->tamano - 1;
        colaIncrementaIndice(&(c->frente));
    
        return valor;
    }   
}

/* FUNCIÓN PRINCIPAL QUE EJECUTA LAS FUCIONES DE LA PILA ELABORADA CON MATRICES */

int main ()
{
    Cola ColaMat;
    char opcion;
    
    do
    {
        system("clear");
        puts("\n\n+-------------------+");
        puts("+ TAD COLA MATRICES +");
        puts("+-------------------+\n");
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
            case '1':crearColaVacia(&ColaMat);
                     break;
            case '2':comprobarSiColaVacia(&ColaMat);
                     break;
            case '3':insertarElementoEnCola(&ColaMat);
                     break;
            case '4':suprimirElementoEnCola(&ColaMat);
                     break;
            case 'S':salirDelPrograma();
                     break;
        }
        
    }while(opcion != 'S');
    
    sleep(1);
    return 0;
}

/* FUNCIONES PARA REALIZAR LAS OPERACIONES OPORTUNAS CON LA PILA */

void crearColaVacia(Cola *c)
{
    int retorno = colaCreaVacia(c);
    
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
void insertarElementoEnCola(Cola *c)
{
    int retorno;
    tipoElemento elemento;
    
    printf("\nPORFAVOR, INTRODUZCA EL ELEMENTO QUE DESEA INSERTAR EN LA COLA: ");
    scanf("%d", &elemento);
    
    retorno = colaInserta(c, elemento);
    
    if(retorno == -2) // La función anterior devuelve un COD_ERROR(-2) en caso de que la cola se encuentre llena actualmente
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
