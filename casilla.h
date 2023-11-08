#ifndef CASILLA_H
#define CASILLA_H

#define MAX_F 24
#define MAX_C 70

#define CAJA '0'
#define PARED '#'
#define JUGADOR '@'
#define OBJETIVO 'X'
#define SUELO ' '
#define GOL '!'

typedef char tplano[MAX_F + 2][MAX_C];

typedef struct {
    char es;
    char hay;
} tcasilla;

char leer_casilla(tcasilla casilla);		//return CAJA, return PARED, return JUGADOR, return OBJETIVO, return SUELO
void inic_casilla(char p, tcasilla *cas);

#endif
