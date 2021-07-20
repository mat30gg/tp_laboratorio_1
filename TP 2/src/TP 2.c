#include <stdio.h>
#include "ArrayEmployees.h"
#include "input.h"



int main(void)
{
	setbuf(stdout, NULL);
	int choice;
	int aux;
	sEmployees employeeList[TAM];
	if(initEmployees(employeeList, TAM))
	{
		printf("ERROR DE MEMORIA.");
	}
	HardcodearEmpleados(employeeList);
	do{
		printf("\n -------------------");
		printf("\n ||Menu:");
		printf("\n ||1 - Alta.");
		printf("\n ||2 - Modificacion.");
		printf("\n ||3 - Baja.");
		printf("\n ||4 - Listado en orden alfabetico por sector y promedio de salarios.");
		printf("\n ||0 - SALIR.");
		printf("\n || = ");
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
					aux = getInt("Ingrese ID a eliminar.");
					if(aux != -1)
					{
						removeEmployee(employeeList, TAM, aux);
					}
					else
					{
						printf("\nERROR AL PURGAR EMPLEADO");
					}
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



