#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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


	getString("\nIngrese nombre: ", nombre);
	getString("\nIngrese horas de trabajo: ", horasTrabajadas);
	getString("\nIngrese sueldo: ", sueldo);
	aux = employee_newParametros(id, nombre, horasTrabajadas, sueldo);
	ll_add(pArrayListEmployee, aux);
	fclose(aUltimo);
    return exito;
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
	Employee* aux;
	aux = (Employee*) malloc(sizeof(Employee));
	aux = (Employee*) ll_get(pArrayListEmployee, 4);
	printf("%d, %s, %d, %d", aux->id, aux->nombre, aux->horasTrabajadas, aux->sueldo);
    return 1;
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
	int exito;
	Employee* aux;
	int x;
	int id;
	char* nombre;
	int horasTrabajadas;
	int sueldo;
	exito = 0;
	if(ll_isEmpty(pArrayListEmployee) != 0)
	{

		nombre = (char*) malloc(128);
		if(ll_len(pArrayListEmployee)>0)
		{
			for(x=0; x<ll_len(pArrayListEmployee); x++)
			{
				aux = ll_get(pArrayListEmployee, x);
				employee_getId(aux, &id);
				employee_getNombre(aux, nombre);
				employee_getHorasTrabajadas(aux, &horasTrabajadas);
				employee_getSueldo(aux, &sueldo);
				printf("[%4d] <%-9s>  %-3d Hs | $%d\n", id, nombre, horasTrabajadas, sueldo);
			}
		}
	}
	else
	{
		printf("No se encuentran elementos dentro de la lista.");
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
    return 1;
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
    return 1;
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
    return 1;
}

