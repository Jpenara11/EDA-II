#ifndef CONJUNTOS_H
#define CONJUNTOS_H

#define MAXIMO 16

typedef int particion[MAXIMO];
typedef int tipoConjunto;
typedef int tipoElemento;

void crea(particion C);
void creaTamano(particion C);
void creaAltura(particion C);

tipoElemento buscar(tipoElemento x, particion C);
tipoElemento buscarTamano(tipoElemento x, particion C);
tipoElemento buscarAltura(tipoElemento x, particion C);
tipoElemento buscarCompresionCaminos(tipoElemento x, particion C);

void unir(tipoElemento x, tipoElemento y, particion C);
void unirTamano(tipoElemento x, tipoElemento y, particion C);
void unirAltura(tipoElemento x, tipoElemento y, particion C);

void verParticion(particion C);

#endif

