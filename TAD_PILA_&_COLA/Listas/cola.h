#ifndef __COLA_H
#define __COLA_H

typedef char tipoElemento;

typedef struct tipoCelda2 { 
	tipoElemento elemento; 
	struct tipoCelda2 * sig; 
	} tipoCelda2;

typedef struct {
        tipoCelda2 *frente, *fondo;
} Cola;

int colaCreaVacia(Cola *c);

int colaVacia(Cola *c);

int colaInserta(Cola *c, tipoElemento elemento);

tipoElemento colaSuprime(Cola *c);

#endif
