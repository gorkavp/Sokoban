#ifndef ALMACEN_H
#define ALMACEN_H

#include "casilla.h"

typedef struct {
    int goles;
    int pasos;
    int empujes;
    int cajas;

} tcontadores;

typedef struct {
    int posx;
    int posy;

} tposicion;

typedef struct {
    tcasilla mat[MAX_F][MAX_C];
    tposicion tamanyo;
    tposicion pos;
    tcontadores cont;
    char nivel[MAX_C];

} talmacen;

void inic_almacen(tplano p, talmacen *alm);
void reset_almacen(talmacen *alm);
void mostrar_almacen(talmacen *alm);
int move_up(talmacen *alm, tposicion casilla1, tposicion casilla2);
int move_down(talmacen *alm, tposicion casilla1, tposicion casilla2);
int move_left(talmacen *alm, tposicion casilla1, tposicion casilla2);
int move_right(talmacen *alm, tposicion casilla1, tposicion casilla2);
int movimiento(talmacen *alm, tposicion casilla1, tposicion casilla2);
int acabado(talmacen almacen, int *nivel, int *maxnivel);
void mostrar_contadores(talmacen *alm);

#endif
