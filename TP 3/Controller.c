#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "input.h"



/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int exito;
	exito = 0;
	FILE* pArchivo;
	pArchivo = fopen(path, "r");
	if(pArchivo!=NULL)
	{
		exito = 1;
		if(parser_EmployeeFromText(pArchivo, pArrayListEmployee) == 0)
		{
			printf("ERROR al abrir archivo.");
		}
	}

	fclose(pArchivo);
    return exito;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int exito;
	exito = 0;
	FILE* pArchivo;
	pArchivo = fopen(path, "rb");
	if(pArchivo!=NULL)
	{
		exito = 1;
		if(parser_EmployeeFromBinary(pArchivo, pArrayListEmployee) == 0)
		{
			printf("ERROR al abrir archivo");
		}
	}
	fclose(pArchivo);
	return exito;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	FILE* aUltimo;
	Employee* aux;
	int ultimoId;
	int errorFlag;
	char* ultimoIdStr;

	int exito;
	char id[12];
	char nombre[128];
	char horasTrabajadas[4];
	char sueldo[5];

	exito = 0;
	aUltimo = fopen("ultimoId.bin", "rb");
	fread(&ultimoId, sizeof(int), 1, aUltimo);
	ultimoId += 1;
	itoa(ultimoId, id, 10);
	fclose(aUltimo);


	errorFlag = getString("\nIngrese nombre: ", nombre);
	if(errorFlag != -1)
	{
		nombre[0] = toupper(nombre[0]);
		errorFlag = getStringNum("\nIngrese horas de trabajo: ", horasTrabajadas);
		if(errorFlag != -1)
		{
			errorFlag = getStringNum("\nIngrese sueldo: ", sueldo);
			if(errorFlag != -1)
			{
				aux = employee_newParametros(id, nombre, horasTrabajadas, sueldo);
				errorFlag = ll_add(pArrayListEmployee, aux);
				if(errorFlag != 0)
				{
					printf("No se pudo agregar el empleado.");
				}
			}
			else
			{
				printf("\n\nSueldo contiene espacios o valores no validos\n\n");
			}
		}
		else
		{
			printf("\n\nHoras de trabajo contiene valores no valido o espacios.\n\n");
		}
	}
	else
	{
		printf("\n\nNombre ingresado contiene espacios o numeros.\n\n");
	}

	aUltimo = fopen("ultimoId.bin", "wb");
	if(aUltimo != NULL && errorFlag != -1)
	{
		updateLastId(ultimoId);
	}
	fclose(aUltimo);
    return exito;
}


int findIndexId(LinkedList* pArrayListEmployee, int id)
{
	Employee* aux;
	int returnAux;
	int len;
	returnAux = -1;
	len = ll_len(pArrayListEmployee);
	for(int x = 0;x != len; x++)
	{
		aux = ll_get(pArrayListEmployee, x);
		if(aux->id == id)
		{
			returnAux = x;
			break;
		}
	}
	employee_delete(aux);
	return returnAux;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	Employee* employeeEdit;
	Employee copia;
	int id;
	int index;
	int menu;
	if(pArrayListEmployee != NULL)
	{
		id = getInt("Ingrese ID del empleado a modificar: ");
		index = findIndexId(pArrayListEmployee, id);
		if(index != -1)
		{
			employeeEdit = ll_get(pArrayListEmployee, index);
			copyEmployee(&copia, *employeeEdit);
			printf("Modificando a empleado.\n");
			printOneEmployee(employeeEdit);
			do{
				printf("  |||Que se va a modificar: ");
				printf("\n||| 1 : Nombre.");
				printf("\n||| 2 : HorasTrabajadas.");
				printf("\n||| 3 : Sueldo.");
				printf("\n||| 4 : Cancelar modificacion.");
				printf("\n||| 0 : Salir.");
				printf("\n||| :=: ");
				scanf("%d", &menu);
				switch(menu)
				{
				case 1:
					employee_modifyNombre(employeeEdit);
				break;
				case 2:
					employee_modifyHorasTrabajadas(employeeEdit);
				break;
				case 3:
					employee_modifySueldo(employeeEdit);
				break;
				case 4:
					copyEmployee(employeeEdit, copia);
				break;
				}
			}while(menu != 0);
		}
		else
		{
			printf("ID no encontrado");
		}
	}
	return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int exito;
	int index;
	int id;
	exito = 0;
	if(pArrayListEmployee != NULL)
	{
		exito = 1;
		id = getInt("Ingrese numero ID para eliminar: ");
		index = findIndexId(pArrayListEmployee, id);
		ll_remove(pArrayListEmployee, index);

	}
    return exito;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    Employee* aux;
    int exito;
    int x;
    exito = 0;
    if(ll_len(pArrayListEmployee)>0)
    {
    	for(x=0; x<ll_len(pArrayListEmployee); x++)
    	{
    		aux = ll_get(pArrayListEmployee, x);
    		printOneEmployee(aux);
    	}
    }

    return exito;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int exito;
	int orden;
	int eleccion;
	exito = 0;
	if(pArrayListEmployee != NULL)
	{
		printf("Con que criterio se ordena la lista:");
		printf("\n|| 1. Por nombre.");
		printf("\n|| 2. Por sueldo.");
		printf("\n|| :=: ");
		scanf("%d", &eleccion);
		printf("De que forma: ");
		printf("\n|| 0. Ascendente.");
		printf("\n|| 1. Descendente.");
		printf("\n|| :=: ");
		scanf("%d", &orden);
		switch(eleccion)
		{
		case 1:
			ll_sort(pArrayListEmployee, ordenNombre, orden);
			break;
		case 2:
			ll_sort(pArrayListEmployee, ordenSueldo, orden);
			break;
		}
		//aux = ll_sort(pArrayListEmployee, ordenNombre, 0);
	}
    return exito;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	FILE* newT;
	Employee* aux;
	int exito;
	int len;
	exito = 0;
	newT = fopen(path, "w");
	aux = (Employee*) malloc(sizeof(Employee));
	len = ll_len(pArrayListEmployee);
	if(pArrayListEmployee != NULL && newT != NULL)
	{
		fprintf(newT, "id,nombre,horastrabajadas,sueldo");
		for(int x = 0;x != len; x++)
		{
			aux = ll_get(pArrayListEmployee, x);
			fprintf(newT, "%d, %s, %d, %d\n", aux->id, aux->nombre, aux->horasTrabajadas, aux->sueldo);
		}
	}
    return exito;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	FILE* newB;
	Employee* aux;
	int exito;
	int len;
	exito = 0;
	newB = fopen(path, "wb");
	aux = (Employee*) malloc(sizeof(Employee));
	len = ll_len(pArrayListEmployee);
	if(pArrayListEmployee != NULL && newB != NULL)
	{
		for(int x = 0;x != len; x++)
		{
			aux = ll_get(pArrayListEmployee, x);
			fwrite(aux, sizeof(Employee), 1, newB);
		}
	}
	return exito;
}
