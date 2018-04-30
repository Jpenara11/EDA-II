#include "conjuntos.h"
#include <stdio.h>

void crea(particion C)
{
    int i;
    
    for (i = 0; i < MAXIMO; i++)
        C[i] = 0;
}

void creaTamano(particion C)
{
    int i;
    
    for (i = 0; i < MAXIMO; i++)
        C[i] = -1;
}

void creaAltura(particion C)
{
    int i;
    
    for (i = 0; i < MAXIMO; i++)
        C[i] = -1;
}

tipoElemento buscar(tipoElemento x, particion C)
{
    if (C[x] == 0)
        return x;
    else
        return (buscar(C[x], C));
}

tipoElemento buscarTamano(tipoElemento x, particion C)
{
    if (C[x] < 0)
        return x;
    else
        return buscarTamano (C[x], C);
}

tipoElemento buscarAltura(tipoElemento x, particion C)
{
    if (C[x] < 0)
        return x;
    else
        return buscarAltura (C[x], C);
}

tipoElemento buscarCompresionCaminos(tipoElemento x, particion C)
{
	if (C[x] <= 0) return x; // SI ES LA RAIZ (CLASE DE EQUIVALENCIA) LA DEVOLVEMOS
		
	else return(buscarCompresionCaminos(C[x], C)); //SINO SEGUIMOS BUSCANDO HASTA ENCONTRARLA
}

void unir(tipoElemento x, tipoElemento y, particion C)
{
    C[y] = buscar(x, C); // Nos aseguramos que sea la raiz
}

void unirTamano(tipoElemento x, tipoElemento y, particion C)
{
	tipoElemento eqX, eqY;
	
	eqX = x;
	eqY = y;
	
	if (C[x] > 0) 
		eqX = buscarTamano(x, C); //Obtenemos clase equivalencia del nodo hijo
	
	if (C[y] > 0) 
		eqY = buscarTamano(y, C);//Obtenemos clase equivalencia del nodo hijo
		
	if (C[eqX] == C[eqY])
	{
		C[eqX] += C[eqY]; 
		C[eqY] = eqX; 
	}
	
	else if (C[eqX] > C[eqY]) //El arbol con raiz "y" es MAS NEGATIVO (MAYOR TAMANO)
	{
		C[eqY] += C[eqX];
		C[eqX] = eqY;
	}	
					
	else // El arbol con raiz "x" es MAS NEGATIVO (MAYOR TAMANO)
	{
		C[eqX] += C[eqY];
		C[eqY] = eqX;	
	}
}

void unirAltura(tipoElemento x, tipoElemento y, particion C)
{
	tipoElemento eqX, eqY;
	
	if (C[x] > 0) 
		eqX = buscarAltura(x, C); //Obtenemos clase equivalencia del nodo hijo
	
	if (C[y] > 0) 
		eqY = buscarAltura(y, C);//Obtenemos clase equivalencia del nodo hijo
		
	if (C[eqX] == C[eqY]) // Si tienen las mismas alturas -> h = h+1
	{
		C[eqX] += -1; 
		C[eqY] = eqX; 
	}
	
	else if (C[eqX] > C[eqY]) //El arbol con raiz "y" es MAS NEGATIVO (MAYOR TAMANO)
	{
		C[eqX] = eqY;
	}	
					
	else // El arbol con raiz "x" es MAS NEGATIVO (MAYOR TAMANO)
	{
		C[eqY] = eqX;	
	}
}

// Función auxiliar para ver contenido de Partición 

void verParticion(particion C)
{ 
	int i;

    printf("\n");
    for (i =0;i<MAXIMO;i++) printf("|%2d",C[i]);
    printf("| contenido  vector\n");
    for (i =0;i<MAXIMO;i++) printf("---");
    printf("\n");
    for (i =0;i<MAXIMO;i++) printf(" %2d",i);
    printf("  índices vector\n\n");
}
