#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
	setbuf(stdout, NULL);


	startLastId("data.csv");

    int option;
    LinkedList* pArrayListEmployee = ll_newLinkedList();
    do{
    	printf("\nMenu");
    	printf("\n	1. Carga de datos de empleados desde archivo data.csv (Texto).");
    	printf("\n	2. Carga de datos de empleados desde archivo data.bin (Binario).");
    	printf("\n	3. Alta empleado.");
    	printf("\n	5. Baja empleado.");
    	printf("\n	6. Listar empleados.");
    	scanf("\n%d", &option);
        switch(option)
        {
        	case 1:
        		controller_loadFromText("data.csv", pArrayListEmployee);
        		break;
        	case 2:
        		controller_loadFromBinary("data.bin", pArrayListEmployee);
        		break;
            case 3:
            	controller_addEmployee(pArrayListEmployee);
                break;
            case 5:
            	controller_removeEmployee(pArrayListEmployee);
            	break;
            case 6:
            	controller_ListEmployee(pArrayListEmployee);
            	break;
        }
    }while(option != 10);
    return 0;
}

