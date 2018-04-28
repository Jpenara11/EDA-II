#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include "pilaM.h"

#define TRUE 1 // Creamos la constante VERDADERO que nos devuelve 1 en caso de que la comprobación sea verdadera
#define FALSE 0// Creamos la constante FALSO que nos devuelve 0 en caso de que la comprobación sea falsa

int pilaCreaVacia(Pila *p)
{
 	p->tope = -1;
 	
 	if(p->tope == -1)
 	  return 0;
 	
 	else if (p->tope != -1)
 	  return -3; // Código de Error (-3): No se ha podido crear correctamente la pila vacía
}

int pilaVacia(Pila *p)
{
 	if(p->tope == -1)
        return TRUE;

    else
        return FALSE;
}

int pilaInserta(Pila *p,tipoElemento elemento)
{
    if(p->tope == MAX - 1)
        return -1; // Código de Error (-1): Pila llena y no se puede insertar ningún elemento más

    else
    {
        p->tope = p->tope + 1;
        p->elementos[p->tope] = elemento;
        return 0;
    }
}

tipoElemento pilaSuprime(Pila *p)
{
    tipoElemento tope;

    if (pilaVacia(p) == TRUE)
    {
        return -2; // Código de Error (-2): Pila vacía y por tanto no se puede extraer ningún elemento
    }    
    
    else
    {
        tope = p->elementos[p->tope];
        p->tope = p->tope -1;
    
        return tope;
    }   
}

/* FUNCIÓN PRINCIPAL QUE EJECUTA LAS FUCIONES DE LA PILA ELABORADA CON MATRICES */

int main ()
{
    Pila PilaMat;
    char opcion;
    
    do
    {
        system("clear");
        puts("\n\n+-------------------+");
        puts("+ TAD PILA MATRICES +");
        puts("+-------------------+\n");
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
            case '1':crearPilaVacia(&PilaMat);
                     break;
            case '2':comprobarSiPilaVacia(&PilaMat);
                     break;
            case '3':insertarElementoEnPila(&PilaMat);
                     break;
            case '4':suprimirElementoEnPila(&PilaMat);
                     break;
            case 'S':salirDelPrograma();
                     break;
        }
        
    }while(opcion != 'S');
    
    sleep(1);
    return 0;
}

/* FUNCIONES PARA REALIZAR LAS OPERACIONES OPORTUNAS CON LA PILA */

void crearPilaVacia(Pila *p)
{
    int retorno = pilaCreaVacia(p);
    
    if(retorno == 0)
        puts("\nSE HA CREADO CORRECTAMENTE LA PILA!\n");
    
    else if(retorno == -3)// La función anterior devuelve un COD_ERROR(-3) en caso de que no se haya podido crear correctamente la pila vacía
        puts("\nNO SE HA PODIDO CORRECTAMENTE LA PILA!\n");
    
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
void insertarElementoEnPila(Pila *p)
{
    int retorno;
    tipoElemento elemento;
    
    printf("\nPORFAVOR, INTRODUZCA EL ELEMENTO QUE DESEA INSERTAR EN LA PILA: ");
    scanf("%d", &elemento);
    
    retorno = pilaInserta(p, elemento);
    
    if(retorno == -1) // La función anterior devuelve un COD_ERROR(-1) en caso de que la pila se encuentre llena actualmente
        puts("\nNO SE HA PODIDO REALIZAR LA INSERCION PORQUE LA PILA SE ENCUENTRA LLENA\n");
    
    else if (retorno == 0)
        puts("\nELEMENTO INSERTADO CORRECTAMENTE!\n");
        
    sleep(1);
}

void suprimirElementoEnPila(Pila *p)
{
    tipoElemento retorno = pilaSuprime(p);
    
    if(retorno == -2) // La función anterior devuelve un COD_ERROR(-2) en caso de que la pila se encuentre vacía actualmente
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
