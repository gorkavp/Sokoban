#include <stdio.h>
#include <memory.h>
#include "almacen.h"
#include "teclas.h"
#include "colores.h"

void inic_almacen(tplano p, talmacen *alm) {
    int i = 0, j, maxj = 0;

    reset_almacen(alm);

    while (p[i][0] != ';') {
        j = 0;
        while (p[i][j] != '\0') {
            inic_casilla(p[i][j], &alm->mat[i][j]);
            if (p[i][j] == '$')
                alm->cont.cajas++;
            else if (p[i][j] == '@') {
                alm->pos.posx = j;
                alm->pos.posy = i;
            }
            j++;
        }
        if (j > maxj)
            maxj = j;
        i++;
    }
    alm->tamanyo.posx = maxj;
    alm->tamanyo.posy = i;
}

void reset_almacen(talmacen *alm) {
    memset(&alm->mat, ' ', sizeof (alm->mat));
    memset(&alm->cont, 0, sizeof (alm->cont));
}

void mostrar_almacen(talmacen *alm) {
    int y, x;
    char esta_casilla = '0';
    alm->cont.goles = 0;

    for (y = 0; y < alm->tamanyo.posy; y++) {
        for (x = 0; x < alm->tamanyo.posx; x++) {
            esta_casilla = leer_casilla(alm->mat[y][x]);
            if (esta_casilla == JUGADOR) {
                alm->pos.posx = x;
                alm->pos.posy = y;
                printf_color(GREEN);
                printf("%c", esta_casilla);
                printf_reset_color();
            } else if (esta_casilla == OBJETIVO) {
                printf_color(BLUE);
                printf("%c", esta_casilla);
                printf_reset_color();
            } else if (esta_casilla == CAJA) {
                printf_color(YELLOW);
                printf("%c", esta_casilla);
                printf_reset_color();
            } else if (esta_casilla == PARED) {
                printf_color(RED);
                printf("%c", esta_casilla);
                printf_reset_color();
            } else if (esta_casilla == SUELO) {
                printf("%c", esta_casilla);
            } else if (esta_casilla == GOL) {
                alm->cont.goles++;
                esta_casilla = CAJA;
                printf_color(YELLOW);
                printf("%c", esta_casilla);
                printf_reset_color();
            }
        }
        printf("\n");
    }
}

int move_up(talmacen *alm, tposicion casilla1, tposicion casilla2) {
    int mover;

    casilla1.posx = alm->pos.posx;
    casilla1.posy = alm->pos.posy - 1;
    casilla2.posx = alm->pos.posx;
    casilla2.posy = alm->pos.posy - 2;

    mover = movimiento(&(*alm), casilla1, casilla2);
    return mover;
}

int move_down(talmacen *alm, tposicion casilla1, tposicion casilla2) {
    int mover;

    casilla1.posx = alm->pos.posx;
    casilla1.posy = alm->pos.posy + 1;
    casilla2.posx = alm->pos.posx;
    casilla2.posy = alm->pos.posy + 2;

    mover = movimiento(&(*alm), casilla1, casilla2);
    return mover;
}

int move_left(talmacen *alm, tposicion casilla1, tposicion casilla2) {
    int mover;

    casilla1.posx = alm->pos.posx - 1;
    casilla1.posy = alm->pos.posy;
    casilla2.posx = alm->pos.posx - 2;
    casilla2.posy = alm->pos.posy;

    mover = movimiento(&(*alm), casilla1, casilla2);
    return mover;
}

int move_right(talmacen *alm, tposicion casilla1, tposicion casilla2) {
    int mover;

    casilla1.posx = alm->pos.posx + 1;
    casilla1.posy = alm->pos.posy;
    casilla2.posx = alm->pos.posx + 2;
    casilla2.posy = alm->pos.posy;

    mover = movimiento(&(*alm), casilla1, casilla2);
    return mover;
}

int movimiento(talmacen *alm, tposicion casilla1, tposicion casilla2) {
    int mover = 0;
    char cas1, cas2;

    cas1 = leer_casilla(alm->mat[casilla1.posy][casilla1.posx]);

    switch (cas1) {
        case PARED:
            mover = 0;
            break;
        case OBJETIVO:
        case SUELO:
            mover = 1;
            alm->cont.pasos++;
            alm->mat[casilla1.posy][casilla1.posx].hay = JUGADOR;
            alm->mat[alm->pos.posy][alm->pos.posx].hay = SUELO;
            break;
        case GOL:
        case CAJA:
            cas2 = leer_casilla(alm->mat[casilla2.posy][casilla2.posx]);
            if (cas2 == SUELO || cas2 == OBJETIVO) {
                mover = 1;
                alm->cont.pasos++;
                alm->cont.empujes++;
                alm->mat[casilla1.posy][casilla1.posx].hay = JUGADOR;
                alm->mat[casilla2.posy][casilla2.posx].hay = CAJA;
                alm->mat[alm->pos.posy][alm->pos.posx].hay = SUELO;
            }
            break;
        default:
            break;
    }

    return mover;
}

void mostrar_contadores(talmacen *alm) {

    printf("goles = %d          cajas_en_goles = %d\n", alm->cont.cajas, alm->cont.goles);
    printf("num_pasos = %d      num_empujes = %d\n", alm->cont.pasos, alm->cont.empujes);
}

int acabado(talmacen almacen, int *nivel, int *maxnivel) {

    int fin;

    if (almacen.cont.cajas == almacen.cont.goles) {

        if ((*nivel) == (*maxnivel))
            fin = 10;
        else {
            fin = 5;
            printf_color(GREEN);
            printf("\nNIVEL SUPERADO!!!\n");
            printf("\nPulsa la tecla enter para continuar");
            printf_reset_color();
            scanf("%*c");
        }
    }
    return fin;
}
