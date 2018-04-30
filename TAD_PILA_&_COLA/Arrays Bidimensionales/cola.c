#define TRUE 1
#define FALSE 0

void colaIncrementaIndice (int *pos)
{
    if(*pos == MAX)
        *pos = 0;
    
    else
        *pos = *pos + 1;
}

int colaCreaVacia(Cola *c)
{
 	c->tamagno = 0;
 	c->frente = 0;
 	c->fondo = MAX;
 	
 	if (c->tamagno == 0 && c->frente == 0 && c->fondo == MAX)
 	  return 0;
 	
 	else if(c->tamagno != 0 || c->frente != 0 || c->fondo != MAX)
 	  return -1; // Código de Error (-1): No se ha podido crear correctamente la cola vacía
}

int colaVacia(Cola *c)
{
 	if(c->tamagno == 0)
        return TRUE;

    else
        return FALSE;
}

int colaInserta(Cola *c,tipoElemento elemento)
{
    if(c->tamagno == MAX)
        return -2; // Código de Error (-2): Cola llena y no se puede insertar ningún elemento más

    else
    {
        c->tamagno = c->tamagno + 1;
        colaIncrementaIndice(&(c->fondo));
        c->elementos[c->fondo] = elemento;
        
        return 0;
    }
}

tipoElemento colaSuprime(Cola *c)
{
    tipoElemento valor;

    if (colaVacia(c) == TRUE)
    {
        return -3; // Código de Error (-3): Cola vacía y por tanto no se puede extraer ningún elemento
    }    
    
    else
    {
        valor = c->elementos[c->frente];
        c->tamagno = c->tamagno - 1;
        colaIncrementaIndice(&(c->frente));
    
        return valor;
    }   
}
