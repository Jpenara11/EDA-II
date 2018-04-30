#ifndef __PILA_H
#define __PILA_H

typedef char tipoElemento;


typedef struct tipoCelda { 
	tipoElemento elemento; 
	struct tipoCelda * sig; 
	} tipoCelda;
	
typedef tipoCelda * Pila ;

int pilaCreaVacia(Pila *p);

int pilaVacia(Pila *p);

int pilaInserta(Pila *p,tipoElemento elemento);

tipoElemento pilaSuprime(Pila *p);

#endif
