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
    	printf("\n|| Menu");
    	printf("\n|| 1. Carga de datos de empleados desde archivo data.csv (Texto).");
    	printf("\n|| 2. Carga de datos de empleados desde archivo data.bin (Binario).");
    	printf("\n|| 3. Alta empleado.");
    	printf("\n|| 4. Modificar empleado.");
    	printf("\n|| 5. Baja empleado.");
    	printf("\n|| 6. Listar empleados.");
    	printf("\n|| 7. Ordenar empleados.");
    	printf("\n|| 8. Guardar datos de empleados en archivo .csv (Texto).");
    	printf("\n|| 9. Guardar datos de empleados en archivo .bin (Binario).");
    	printf("\n|| 10. SALIR.");
    	printf("\n|| =:= ");
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
            case 4:
            	if(ll_len(pArrayListEmployee) != 0)
            	{
            		controller_editEmployee(pArrayListEmployee);
            	}
            	break;
            case 5:
            	if(ll_len(pArrayListEmployee) != 0)
            	{
            		controller_removeEmployee(pArrayListEmployee);
            	}
            	break;
            case 6:
            	if(ll_len(pArrayListEmployee) != 0)
            	{
            		controller_ListEmployee(pArrayListEmployee);
            	}
            	break;
            case 7:
            	if(ll_len(pArrayListEmployee) != 0)
            	{
            		controller_sortEmployee(pArrayListEmployee);
            	}
            	break;
            case 8:
            	if(ll_len(pArrayListEmployee) != 0)
            	{
            		controller_saveAsText("data.csv",pArrayListEmployee);
            	}
            	break;
            case 9:
            	if(ll_len(pArrayListEmployee) != 0)
            	{
            		controller_saveAsBinary("data.bin", pArrayListEmployee);
            	}
        }
    }while(option != 10);
    return 0;
}

