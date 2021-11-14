#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int exito;
	Employee* aux;
	char* id;
	char* nombre;
	char* horasTrabajadas;
	char* sueldo;
	exito = 0;
	id = (char*) malloc(12);
	nombre = (char*) malloc(24);
	horasTrabajadas = (char*) malloc(4);
	sueldo = (char*) malloc(5);
	if(pFile!=NULL)
	{
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, horasTrabajadas, sueldo);
		exito = 1;
		while(!feof(pFile))
		{
			fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, horasTrabajadas, sueldo);
			aux = employee_newParametros(id, nombre, horasTrabajadas, sueldo);
			if(aux != NULL)
			{
				ll_add(pArrayListEmployee, aux);
			}
		}
	}
	else
	{
		exito = 0;
	}
    return exito;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int exito;
	Employee* aux;

	/*int id;
	char* nombre;
	int horasTrabajadas;
	int sueldo;
	nombre = (char*) malloc(128);*/
	exito = 0;
	aux = (Employee*) malloc(sizeof(Employee));
	if(pFile!=NULL)
	{
		exito = 1;
		while(!feof(pFile))
		{
			fread(aux, sizeof(Employee), 1, pFile);
			if(aux != NULL)
			{
				ll_add(pArrayListEmployee, aux);
			}
		}
	}
	else
	{
		exito = 0;
	}
	return exito;
}
