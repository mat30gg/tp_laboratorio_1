#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#define TAM 5

int main(void) {
	int choice;
	int error;
	sEmployees employeeList[TAM];
	if(initEmployees(employeeList, TAM) == 1)
	{
		printf("ERROR DE MEMORIA");
	}

	do{
		printf("\nElija una opcion.");
		printf("\n(1) - Alta.");
		printf("\n(2) - Modificación.");
		printf("\n(3) - Baja.");
		printf("\n(4) - Listado por sector en orden alfabetico.");
		printf("\n(5) - Total y promedio de salarios.");
		printf("\n(-1) - SALIR.");
		fflush(stdin);
		scanf("%d", &choice);
		switch(choice)
		{
		case 1:
			error = employeeEntry(employeeList, TAM);
			if(error == 1)
			{
				printf("NO HAY LUGAR DISPONIBLE EN MEMORIA");
			}
		break;

		case 2:
		break;

		case 3:
		break;

		case 4:
		break;

		case 5:
		break;
		}
	}while(choice != 0);
	return EXIT_SUCCESS;
}
