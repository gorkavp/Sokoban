// Este fichero se le da al alumno
#include <stdio.h>

int fuera_de_rango(int n, int min, int max) {
	return ((n < min) || (n > max));
}


int preguntar_n_en_rango(char *s, int min, int max) {
	int n, uno;
	char car;

	do {
		printf("%s [%d-%d]: ", s, min, max);
		uno = scanf("%d", &n);
		do {
			scanf("%c", &car);
		} while (car!='\n');
	} while (uno != 1 || fuera_de_rango(n, min, max));
	
	return n;
}



