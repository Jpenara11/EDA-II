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
 	  return -1; // C�digo de Error (-1): No se ha podido crear correctamente la cola vac�a
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
        return -2; // C�digo de Error (-2): Cola llena y no se puede insertar ning�n elemento m�s

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
        return -3; // C�digo de Error (-3): Cola vac�a y por tanto no se puede extraer ning�n elemento
    }    
    
    else
    {
        valor = c->elementos[c->frente];
        c->tamagno = c->tamagno - 1;
        colaIncrementaIndice(&(c->frente));
    
        return valor;
    }   
}
