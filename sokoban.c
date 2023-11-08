#include <stdio.h>
#include "almacen.h"
#include "casilla.h"
#include "teclas.h"
#include "colores.h"
#include "fichero.h"
#include "preguntas.h"

int main() {
    int tecla = 0, mover = 0, fin = 0;
    tposicion casilla1, casilla2;
    tplano tablero;
    char plano[70], niv[500];
    talmacen almacen;
    char opcion[500] = "Que opcion eliges";
    char nivel[500] = "Por que nivel empiezas?";
    char nombre_fichero[50];
    char nombre_fichero1[50] = "Original.txt";
    char nombre_fichero2[50] = "Easy.txt";
    char nombre_fichero3[50] = "100Boxes.txt";
    char nombre_fichero4[50] = "696.txt";
    int i = 0, p, n, min = 0, max = 4, min2 = 1, max2, e = -1, j = 0, m, t = 1, k, s = 0, c = -1;
    FILE *fp;

    printf("Menu: Con que fichero de niveles quieres jugar?\n");
    printf("0) Yo introducire el nombre del fichero\n");
    printf("1) Original.txt The 50 original levels from Sokoban plus the 40 from Extra.\n");
    printf("2) Easy.txt Colection for testing purposes.\n");
    printf("3) 100Boxes.txt This collection includes 10 small levels of 10 packages each.\n");
    printf("4) 696.txt 696 collection.\n");
    p = preguntar_n_en_rango(opcion, min, max);

    switch (p) {

        case 0:

            printf("Introduce el nombre del fichero: ");
            scanf("%s", &nombre_fichero);

            if (nombre_fichero[0] == nombre_fichero1[0]) {

                for (i = 0; c != 1 && nombre_fichero1[i] != '\0'; i++) {
                    if (nombre_fichero[i] == nombre_fichero1[i])
                        c = 0;
                    else
                        c = 1;
                }
                if (c == 0) {
                    max2 = 90;
                    n = preguntar_n_en_rango(nivel, min2, max2);
                    fp = abrir_fichero(nombre_fichero);
                    if (fp != NULL) {

                        while (n != t) {
                            e = leer_linea_fichero(fp, plano);
                            if (e == 0)
                                t++;
                        }
                        e = 1;
                        while (e != 0) {
                            e = leer_linea_fichero(fp, plano);
                            m = es_nombre_nivel(plano);
                            if (m == 1) {
                                for (k = 2; plano[k] != '\0'; k++) {
                                    niv[s] = plano[k];
                                    s++;
                                }
                            }
                            for (i = 0; plano[i] != '\0'; i++)
                                tablero[j][i] = plano[i];
                            j++;
                        }

                    } else
                        printf("Error abriendo ficheros\n");
                } else {
                    printf("\nERROR: FICHERO NO ENCONTRADO.\n");
                    printf("PUEDE QUE EL NOMBRE NO SEA EL CORRECTO O QUE ESTE EN OTRO DIRECTORIO.\n");
                }
                break;

            } else if (nombre_fichero[0] == nombre_fichero2[0]) {

                for (i = 0; c != 1 && nombre_fichero2[i] != '\0'; i++) {
                    if (nombre_fichero[i] == nombre_fichero2[i])
                        c = 0;
                    else
                        c = 1;
                }
                if (c == 0) {
                    max2 = 2;
                    n = preguntar_n_en_rango(nivel, min2, max2);
                    fp = abrir_fichero(nombre_fichero);
                    if (fp != NULL) {

                        while (n != t) {
                            e = leer_linea_fichero(fp, plano);
                            if (e == 0)
                                t++;
                        }
                        e = 1;
                        while (e != 0) {
                            e = leer_linea_fichero(fp, plano);
                            m = es_nombre_nivel(plano);
                            if (m == 1) {
                                for (k = 2; plano[k] != '\0'; k++) {
                                    niv[s] = plano[k];
                                    s++;
                                }
                            }
                            for (i = 0; plano[i] != '\0'; i++)
                                tablero[j][i] = plano[i];
                            j++;
                        }

                    } else
                        printf("Error abriendo ficheros\n");
                } else {
                    printf("\nERROR: FICHERO NO ENCONTRADO.\n");
                    printf("PUEDE QUE EL NOMBRE NO SEA EL CORRECTO O QUE ESTE EN OTRO DIRECTORIO.\n");
                }
                break;

            } else if (nombre_fichero[0] == nombre_fichero3[0]) {

                for (i = 0; c != 1 && nombre_fichero3[i] != '\0'; i++) {
                    if (nombre_fichero[i] == nombre_fichero3[i])
                        c = 0;
                    else
                        c = 1;
                }
                if (c == 0) {
                    max2 = 10;
                    n = preguntar_n_en_rango(nivel, min2, max2);
                    fp = abrir_fichero(nombre_fichero);
                    if (fp != NULL) {

                        while (n != t) {
                            e = leer_linea_fichero(fp, plano);
                            if (e == 0)
                                t++;
                        }
                        e = 1;
                        while (e != 0) {
                            e = leer_linea_fichero(fp, plano);
                            m = es_nombre_nivel(plano);
                            if (m == 1) {
                                for (k = 2; plano[k] != '\0'; k++) {
                                    niv[s] = plano[k];
                                    s++;
                                }
                            }
                            for (i = 0; plano[i] != '\0'; i++)
                                tablero[j][i] = plano[i];
                            j++;
                        }

                    } else
                        printf("Error abriendo ficheros\n");
                } else {
                    printf("\nERROR: FICHERO NO ENCONTRADO.\n");
                    printf("PUEDE QUE EL NOMBRE NO SEA EL CORRECTO O QUE ESTE EN OTRO DIRECTORIO.\n");
                }
                break;

            } else if (nombre_fichero[0] == nombre_fichero4[0]) {

                for (i = 0; c != 1 && nombre_fichero4[i] != '\0'; i++) {
                    if (nombre_fichero[i] == nombre_fichero4[i])
                        c = 0;
                    else
                        c = 1;
                }
                if (c == 0) {
                    max2 = 696;
                    n = preguntar_n_en_rango(nivel, min2, max2);
                    fp = abrir_fichero(nombre_fichero);
                    if (fp != NULL) {

                        while (n != t) {
                            e = leer_linea_fichero(fp, plano);
                            if (e == 0)
                                t++;
                        }
                        e = 1;
                        while (e != 0) {
                            e = leer_linea_fichero(fp, plano);
                            m = es_nombre_nivel(plano);
                            if (m == 1) {
                                for (k = 2; plano[k] != '\0'; k++) {
                                    niv[s] = plano[k];
                                    s++;
                                }
                            }
                            for (i = 0; plano[i] != '\0'; i++)
                                tablero[j][i] = plano[i];
                            j++;
                        }

                    } else
                        printf("Error abriendo ficheros\n");
                } else {
                    printf("\nERROR: FICHERO NO ENCONTRADO.\n");
                    printf("PUEDE QUE EL NOMBRE NO SEA EL CORRECTO O QUE ESTE EN OTRO DIRECTORIO.\n");
                }

            } else {
                printf("\nERROR: FICHERO NO ENCONTRADO.\n");
                printf("PUEDE QUE EL NOMBRE NO SEA EL CORRECTO O QUE ESTE EN OTRO DIRECTORIO.\n");
                c=1;
            }
            break;
        case 1:

            max2 = 90;
            n = preguntar_n_en_rango(nivel, min2, max2);
            fp = abrir_fichero(nombre_fichero1);
            if (fp != NULL) {

                while (n != t) {
                    e = leer_linea_fichero(fp, plano);
                    if (e == 0)
                        t++;
                }
                e = 1;
                while (e != 0) {
                    e = leer_linea_fichero(fp, plano);
                    m = es_nombre_nivel(plano);
                    if (m == 1) {
                        for (k = 2; plano[k] != '\0'; k++) {
                            niv[s] = plano[k];
                            s++;
                        }
                    }
                    for (i = 0; plano[i] != '\0'; i++)
                        tablero[j][i] = plano[i];
                    j++;
                }

            } else
                printf("Error abriendo ficheros\n");
            break;

        case 2:

            max2 = 2;
            n = preguntar_n_en_rango(nivel, min2, max2);
            fp = abrir_fichero(nombre_fichero2);
            if (fp != NULL) {

                while (n != t) {
                    e = leer_linea_fichero(fp, plano);
                    if (e == 0)
                        t++;
                }
                e = 1;
                while (e != 0) {
                    e = leer_linea_fichero(fp, plano);
                    m = es_nombre_nivel(plano);
                    if (m == 1) {
                        for (k = 2; plano[k] != '\0'; k++) {
                            niv[s] = plano[k];
                            s++;
                        }
                    }
                    for (i = 0; plano[i] != '\0'; i++)
                        tablero[j][i] = plano[i];
                    j++;
                }

            } else
                printf("Error abriendo ficheros\n");
            break;

        case 3:

            max2 = 10;
            n = preguntar_n_en_rango(nivel, min2, max2);
            fp = abrir_fichero(nombre_fichero3);
            if (fp != NULL) {

                while (n != t) {
                    e = leer_linea_fichero(fp, plano);
                    if (e == 0)
                        t++;
                }
                e = 1;
                while (e != 0) {
                    e = leer_linea_fichero(fp, plano);
                    m = es_nombre_nivel(plano);
                    if (m == 1) {
                        for (k = 2; plano[k] != '\0'; k++) {
                            niv[s] = plano[k];
                            s++;
                        }
                    }
                    for (i = 0; plano[i] != '\0'; i++)
                        tablero[j][i] = plano[i];
                    j++;
                }

            } else
                printf("Error abriendo ficheros\n");
            break;

        case 4:

            max2 = 696;
            n = preguntar_n_en_rango(nivel, min2, max2);
            fp = abrir_fichero(nombre_fichero4);
            if (fp != NULL) {

                while (n != t) {
                    e = leer_linea_fichero(fp, plano);
                    if (e == 0)
                        t++;
                }
                e = 1;
                while (e != 0) {
                    e = leer_linea_fichero(fp, plano);
                    m = es_nombre_nivel(plano);
                    if (m == 1) {
                        for (k = 2; plano[k] != '\0'; k++) {
                            niv[s] = plano[k];
                            s++;
                        }
                    }
                    for (i = 0; plano[i] != '\0'; i++)
                        tablero[j][i] = plano[i];
                    j++;
                }

            } else
                printf("Error abriendo ficheros\n");
            break;
    }

    if (c != 1) {

        borrar_pantalla();
        inic_almacen(tablero, &almacen);
        printf("Pulsa flechas para moverte. Restart 'r'. Quit: 'q'\n");
        printf("También puedes puedes usar 'o'-'p' (izq-der) y 'a'-'z' (arriba-abajo)\n");
        printf_color(GREEN);
        printf("\nNivel: %s\n", niv);
        printf_reset_color();
        mostrar_contadores(&almacen);
        mostrar_almacen(&almacen);

        do {
            tecla = lee_tecla();
            switch (tecla) {
                case UP:
                    mover = move_up(&almacen, casilla1, casilla2);
                    break;
                case DOWN:
                    mover = move_down(&almacen, casilla1, casilla2);
                    break;
                case LEFT:
                    mover = move_left(&almacen, casilla1, casilla2);
                    break;
                case RIGHT:
                    mover = move_right(&almacen, casilla1, casilla2);
                    break;
                case RESTART:
                    inic_almacen(tablero, &almacen);
                    mover = 1;
                    break;
                case CANCEL:
                    fin = 2;
                    break;
                case OTHER:
                    mover = 0;
                    break;
            }

            borrar_pantalla();
            printf("Pulsa flechas para moverte. Restart 'r'. Quit: 'q'\n");
            printf("También puedes usar 'o'-'p' (izq-der) y 'a'-'z' (arriba-abajo)\n");
            printf_color(GREEN);
            printf("\nNivel: %s\n", niv);
            printf_reset_color();

            mostrar_contadores(&almacen);
            mostrar_almacen(&almacen);
            fin |= acabado(almacen, &t, &max2);

            if (fin == 2) {

                printf_color(GREEN);
                printf("\nAdios!!!");
                printf_reset_color();

            } else if (fin == 5) {

                e = 1;
                j = 0;
                t++;
                while (e != 0) {
                    e = leer_linea_fichero(fp, plano);
                    m = es_nombre_nivel(plano);
                    if (m == 1) {
                        for (k = 2; plano[k] != '\0'; k++) {
                            niv[s] = plano[k];
                            s++;
                        }
                    }
                    for (i = 0; plano[i] != '\0'; i++)
                        tablero[j][i] = plano[i];
                    j++;
                }

                borrar_pantalla();
                inic_almacen(tablero, &almacen);
                printf("Pulsa flechas para moverte. Restart 'r'. Quit: 'q'\n");
                printf("También puedes usar 'o'-'p' (izq-der) y 'a'-'z' (arriba-abajo)\n");
                printf_color(GREEN);
                printf("\nNivel: %s\n", niv);
                printf_reset_color();
                mostrar_contadores(&almacen);
                mostrar_almacen(&almacen);
                fin = 0;

            } else if (fin == 10) {
                printf_color(GREEN);
                printf("\nNIVEL SUPERADO!!!\n");
                printf("\nPulsa la tecla enter para continuar");
                scanf("%*c");
                printf("\nFelicidades!!! Has superado todos los niveles de este fichero!!!\n");
                printf_reset_color();
                switch (p) {
                    case 0:
                        cerrar_fichero(nombre_fichero);
                        break;
                    case 1:
                        cerrar_fichero(nombre_fichero1);
                        break;
                    case 2:
                        cerrar_fichero(nombre_fichero2);
                        break;
                    case 3:
                        cerrar_fichero(nombre_fichero3);
                        break;
                    case 4:
                        cerrar_fichero(nombre_fichero4);
                        break;
                }
            }
        } while (fin == 0 || fin == 5);
    }
}
