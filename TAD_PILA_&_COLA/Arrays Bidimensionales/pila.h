#ifndef __PILA_H
#define __PILA_H
#define MAX 100

typedef char tipoElemento;

typedef struct {
    int tope;
    tipoElemento elementos[MAX];
} Pila;
	
int pilaCreaVacia(Pila *p);

int pilaVacia(Pila *p);

int pilaInserta(Pila *p,tipoElemento elemento);

tipoElemento pilaSuprime(Pila *p);

#endif
