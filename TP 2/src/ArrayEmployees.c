#include <stdio.h>
#include "ArrayEmployees.h"
#include "input.h"

int initEmployees(sEmployees employeeList[], int tam)
{
	int error;
	error = 1;
	int x;
	for(x=0;x!=tam;x++)
	{
		error = 0;
		employeeList[x].isEmpty = 1;
	}
	return error;
}

int employeeEntry(sEmployees employeeList[], int tam)
{
	int error = 1;
	int empty;
	empty = findOpen(employeeList, tam);
	if(empty != -1)
	{
		error = 0;
		loadData(employeeList, tam, empty);
	}
	return error;
}

void loadData(sEmployees employeeList[], int tam, int empty)
{
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	do{
		id = getInt("Ingrese ID del empleado: ", "ERROR");
		if(findUsedID(employeeList, tam, id)==1)
		{
			printf("\nID de empleado ya ingresado.");
		}
	}while(findUsedID(employeeList, tam, id)==1);
	getString("Ingrese nombre del empleado: ", name);
	getString("Ingrese apellido del empleado: ", lastName);
	salary = getFloatPos("Ingrese salario del empleado: ", "ERROR");
	sector = getIntPos("Ingrese sector de trabajo: ", "ERROR");
	if(addEmployee(employeeList[empty], tam ,id ,name ,lastName ,salary ,sector))
	{
		printf("\n\nERROR AL INGRESAR EMPLEADO\n\n");
	}
}

int addEmployee(sEmployees employeeList, int tam, int id, char name[],char lastName[],float salary,int sector)
{

	int error;
	error = 1;
	employeeList.id = id;
	employeeList.sector = sector;
	employeeList.salary = salary;
	if(strlen(name) < 51 && strlen(lastName) < 51)
	{
		error = 0;
		strcpy(employeeList.name, name);
		strcpy(employeeList.lastName, lastName);
	}
	return error;

}

int findOpen(sEmployees employeeList[], int tam)
{

	int empty;
	empty = -1;
	int x;
	for(x=0;x!=tam;x++)
	{
		if(employeeList[x].isEmpty == 1)
		{
			empty = x;
			break;
		}
	}
	return empty;

}

int findUsedID(sEmployees employeeList[], int tam, int id)
{
	int error;
	error = 0;
	int x;
	for(x=0;x!=tam;x++)
	{
		if(id == employeeList[x].id)
		{
			error = 1;
		}
	}
	return error;
}
