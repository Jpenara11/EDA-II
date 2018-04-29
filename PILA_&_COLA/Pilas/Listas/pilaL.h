#ifndef __PILAL_H
#define __PILAL_H

typedef int tipoElemento;

typedef struct tipoCelda { 
	tipoElemento elemento; 
	struct tipoCelda * sig; 
	} tipoCelda;
	
typedef tipoCelda  Pila;

int pilaCreaVacia(Pila **p);

int pilaVacia(Pila *p);

int pilaInserta(Pila **p,tipoElemento elemento);

tipoElemento pilaSuprime(Pila *p, Pila **pila);

// FUNCIONES AUXILIARES

void crearPilaVacia(Pila **p);
void comprobarSiPilaVacia(Pila *p);
void insertarElementoEnPila(Pila **p);
void suprimirElementoEnPila(Pila *pila, Pila **p);
int salirDelPrograma();

#endif
