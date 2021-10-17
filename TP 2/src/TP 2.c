#include <stdio.h>
#include "ArrayEmployees.h"
#include "input.h"



int main(void)
{
	setbuf(stdout, NULL);
	int lastId = 6;
	int choice;
	int aux;
	sEmployees employeeList[TAM];
	if(initEmployees(employeeList, TAM))
	{
		printf("ERROR DE MEMORIA.");
	}
	HardcodearEmpleados(employeeList);
	do{
		choice = MainMenu();
		switch(choice)
		{
			case 1:
				if(employeeEntry(employeeList, TAM, &lastId))
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
					informMenu(employeeList, TAM);
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



