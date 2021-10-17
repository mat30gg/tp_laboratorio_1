#include <stdio.h>
#include <stdlib.h>

#include "funciones.h"

int main(void) {
	setbuf(stdout, NULL);
	int eleccion;
	int x;
	int y;
	float resultadoDiv[1];
	int resultados[5];
	x = 0;
	y = 0;
	do{
		printf("Que desea hacer?\nIngrese valor numerico.");
		printf("\n[1] Modificar primer operando. A = %d ", x);
		printf("\n[2] Modificar segundo operando. B = %d ", y);
		printf("\n[3] Calcular operaciones.");
		printf("\n[4] Imprimir resultados.");
		printf("\n[5] SALIR\n");
		scanf("%d", &eleccion);
		switch(eleccion)
		{
		case 1:
			x = IngresoDeValorA();
		break;
		case 2:
			y = IngresoDeValorB();
		break;
		case 3:
			CalcularOperaciones(x, y, resultados, resultadoDiv);
		break;
		case 4:
			InformarResultados(x, y, resultados, resultadoDiv);
		break;
		}
	}while(eleccion != 5);
	return EXIT_SUCCESS;
}
