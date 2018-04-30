#define TRUE 1
#define FALSE 0

int pilaCreaVacia(Pila *p)
{
 	p->tope = -1;
 	
 	if(p->tope == -1)
 	  return 0;
 	
 	else if (p->tope != -1)
 	  return -1; // C�digo de Error (-1): No se ha podido crear correctamente la pila vac�a
}

int pilaVacia(Pila *p)
{
 	if(p->tope == -1)
        return TRUE;

    else
        return FALSE;
}

int pilaInserta(Pila *p,tipoElemento elemento)
{
    if(p->tope == MAX - 1)
        return -2; // C�digo de Error (-2): Pila llena y no se puede insertar ning�n elemento m�s

    else
    {
        p->tope = p->tope + 1;
        p->elementos[p->tope] = elemento;
        return 0;
    }
}

tipoElemento pilaSuprime(Pila *p)
{
    tipoElemento tope;

    if (pilaVacia(p) == TRUE)
    {
        return -3; // C�digo de Error (-3): Pila vac�a y por tanto no se puede extraer ning�n elemento
    }    
    
    else
    {
        tope = p->elementos[p->tope];
        p->tope = p->tope -1;
    
        return tope;
    }   
}
