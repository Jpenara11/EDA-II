#ifndef __COLAM_H
#define __COLAM_H

typedef int tipoElemento;
#define MAX 4

typedef struct {
	int tamano;
    int frente, fondo;
	tipoElemento elementos[MAX];
	} Cola;
	
int colaCreaVacia(Cola *c);

int colaVacia(Cola *c);

void colaIncrementaIndice (int *pos);

int colaInserta(Cola *c, tipoElemento elemento);

tipoElemento colaSuprime(Cola *c);

// FUNCIONES AUXILIARES

void crearColaVacia(Cola *c);
void comprobarSiColaVacia(Cola *c);
void insertarElementoEnCola(Cola *c);
void suprimirElementoEnCola(Cola *c);
int salirDelPrograma();

#endif
