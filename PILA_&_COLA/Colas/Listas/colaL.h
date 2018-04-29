#ifndef __COLAL_H
#define __COLAL_H

typedef int tipoElemento;

typedef struct tipoCelda { 
	tipoElemento elemento; 
	struct tipoCelda * sig; 
	} Cola;

int colaCreaVacia(Cola **c, Cola **fondo);

int colaVacia(Cola *c);

int colaInserta(Cola **fondo, tipoElemento elemento);

tipoElemento colaSuprime(Cola *c);

// FUNCIONES AUXILIARES

void crearColaVacia(Cola **c, Cola **fondo);
void comprobarSiColaVacia(Cola *c);
void insertarElementoEnCola(Cola **fondo);
void suprimirElementoEnCola(Cola *c);
int salirDelPrograma();

#endif
