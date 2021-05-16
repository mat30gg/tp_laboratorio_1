#include <stdio.h>
#include "ArrayEmployees.h"

int main(void)
{
	setbuf(stdout, NULL);
	int choice;
	sEmployees employeeList[TAM];
	if(initEmployees(employeeList, TAM))
	{
		printf("ERROR DE MEMORIA.");
	}
	do{
		printf("\n\n  Elija una opcion.");
		printf("\n 1 - Alta.");
		printf("\n 2 - Modificacion.");
		printf("\n 3 - Baja.");
		printf("\n 4 - Listado por sector en orden alfabetico.");
		printf("\n 5 - Total de promedio de salarios.");
		printf("\n 0 - SALIR.\n");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				if(employeeEntry(employeeList, TAM))
				{
					printf("ERROR AL CARGAR EL EMPLEADO/NO SE ENCONTRO LUGAR DISPONIBLE.");
				}
			break;
			case 2:
				if(findLoaded(employeeList, TAM) == 0)
				{
					printEmployees(employeeList, TAM);
					modifyEmployee(employeeList, TAM);
				}
				else
				{
					printf("\n\nNO SE CARGARON EMPLEADOS\n");
				}
			break;
			case 3:
				if(findLoaded(employeeList, TAM) == 0)
				{
					printEmployees(employeeList, TAM);
					removeEmployee(employeeList, TAM);
				}
				else
				{
					printf("\n\nNO SE CARGARON EMPLEADOS\n");
				}
			break;
			case 4:
				if(findLoaded(employeeList, TAM) == 0)
				{
					if(sortMenu(employeeList, TAM))
					{
						printf("\n\nERROR AL ORDENAR LISTADO.");
					}
				}
				else
				{
					printf("\n\nNO SE CARGARON EMPLEADOS\n");
				}
			break;
			case 5:
				if(findLoaded(employeeList, TAM) == 0)
				{
					if(AverageSalary(employeeList, TAM))
					{
						printf("\nERROR AL CALCULAR SALARIOS.");
					}
				}
				else
				{
					printf("\n\nNO SE CARGARON EMPLEADOS\n");
				}
			break;
		}

	}while(choice != 0);
	return 0;
}
