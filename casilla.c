#include <stdio.h>
#include "casilla.h"

void inic_casilla(char p, tcasilla *cas)
{
	if(p == ' ')
	{
		(*cas).es = SUELO;
		(*cas).hay = SUELO;
	}
	else if(p == '#')
	{
		(*cas).es = PARED;
		(*cas).hay = PARED;
	}
	else if(p == '.')
	{
		(*cas).es = OBJETIVO;
		(*cas).hay = SUELO;
	}
	else if(p == '@')
	{
		(*cas).es = SUELO;
		(*cas).hay = JUGADOR;
	}
	else if(p == '$')
	{
		(*cas).es = SUELO;
		(*cas).hay = CAJA;
	}
}

char leer_casilla(tcasilla casilla)
{
	char esta_casilla = SUELO;

	if(casilla.es == PARED)
		esta_casilla = PARED;
	else if(casilla.es == SUELO)
	{
		if(casilla.hay == JUGADOR)
			esta_casilla = JUGADOR;
		else if(casilla.hay == CAJA)
			esta_casilla = CAJA;
	}
	else if(casilla.es == OBJETIVO)
	{
		if(casilla.hay == CAJA)
			esta_casilla = GOL;
		else if(casilla.hay == JUGADOR)
			esta_casilla = JUGADOR;
		else
			esta_casilla = OBJETIVO;
	}
	return esta_casilla;
}
