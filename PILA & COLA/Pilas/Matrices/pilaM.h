#ifndef __PILAM_H
#define __PILAM_H

typedef int tipoElemento;
#define MAX 2

typedef struct {
    int tope;
    tipoElemento elementos[MAX];
} Pila;

int pilaCreaVacia(Pila *p);

int pilaVacia(Pila *p);

int pilaInserta(Pila *p,tipoElemento elemento);

tipoElemento pilaSuprime(Pila *p);

// FUNCIONES AUXILIARES

void crearPilaVacia(Pila *p);
void comprobarSiPilaVacia(Pila *p);
void insertarElementoEnPila(Pila *p);
void suprimirElementoEnPila(Pila *p);
int salirDelPrograma();

#endif
