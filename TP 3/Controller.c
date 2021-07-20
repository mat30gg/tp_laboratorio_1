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
	char* ultimoIdStr;

	int exito;
	char* id;
	char* nombre;
	char* horasTrabajadas;
	char* sueldo;

	aUltimo = fopen("ultimoId.bin", "rb");
	fread(&ultimoId, sizeof(int), 1, aUltimo);
	ultimoId += 1;

	exito = 0;
	ultimoIdStr = (char*) malloc(12);
	id = (char*) malloc(12);
	itoa(ultimoId, ultimoIdStr, 10);
	strcpy(id, ultimoIdStr);
	nombre = (char*) malloc(128);
	horasTrabajadas = (char*) malloc(4);
	sueldo = (char*) malloc(5);


	if(getString("\nIngrese nombre: ", nombre) != -1)
	{
		nombre[0] = toupper(nombre[0]);
		if(getStringNum("\nIngrese horas de trabajo: ", horasTrabajadas) != -1)
		{
			if(getStringNum("\nIngrese sueldo: ", sueldo) != -1)
			{
				aux = employee_newParametros(id, nombre, horasTrabajadas, sueldo);
				ll_add(pArrayListEmployee, aux);
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
	Employee* aux;
	int id;
	int index;
	int menu;
	if(pArrayListEmployee != NULL)
	{
		id = getInt("Ingrese ID del empleado a modificar: ");
		index = findIndexId(pArrayListEmployee, id);
		aux = ll_get(pArrayListEmployee, index);
		printf("Modificando a empleado.\n");
		printOneEmployee(aux);
		do{
			printf("  |||Que se va a modificar: ");
			printf("\n||| 1 : Nombre.");
			printf("\n||| 2 : HorasTrabajadas.");
			printf("\n||| 3 : Sueldo.");
			printf("\n||| 0 : Cancelar.");
			printf("\n||| :=: ");
			scanf("%d", &menu);
			switch(menu)
			{
			case 1:
				employee_modifyNombre(aux);
			break;
			case 2:
				employee_modifyHorasTrabajadas(aux);
			break;
			case 3:
				employee_modifySueldo(aux);
			break;
			}
		}while(menu != 0);
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
	FILE* newT;
	Employee* aux;
	int exito;
	int len;
	exito = 0;
	newT = fopen("test.bin", "wb");
	aux = (Employee*) malloc(sizeof(Employee));
	len = ll_len(pArrayListEmployee);
	if(pArrayListEmployee != NULL && newT != NULL)
	{
		for(int x = 0;x != len; x++)
		{
			aux = ll_get(pArrayListEmployee, x);
		}
	}
	return exito;
}
