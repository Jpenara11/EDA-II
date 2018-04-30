#ifndef __COLA_H
#define __COLA_H
#define MAX 100

typedef char tipoElemento;

typedef struct {
	int tamagno;
    int frente, fondo;
	tipoElemento elementos[MAX];
	} Cola;

void colaIncrementaIndice (int *pos);

int colaCreaVacia(Cola *c);

int colaVacia(Cola *c);

int colaInserta(Cola *c, tipoElemento elemento);

tipoElemento colaSuprime(Cola *c);

#endif
