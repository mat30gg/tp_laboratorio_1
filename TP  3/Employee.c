#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"

Employee *employee_new()
{
	Employee* pEmployee;

	pEmployee = (Employee*) malloc(sizeof(Employee));
	pEmployee->id = 0;
	strcpy(pEmployee->nombre,"");
	pEmployee->horasTrabajadas = 0;
	pEmployee->sueldo = 0;

	return pEmployee;
}

Employee *employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
	FILE* aUltimoId;
	Employee* pEmployee;

	int exito;
	int id;
	int ultimoId;
	char* nombre;
	int horasTrabajadas;
	int sueldo;
	exito = 0;
	id = atoi(idStr);
	nombre = (char*) malloc(128);
	strcpy(nombre, nombreStr);
	horasTrabajadas = atoi(horasTrabajadasStr);
	sueldo = atoi(sueldoStr);


	aUltimoId = fopen("ultimoId.bin", "rb");
	if(aUltimoId != NULL)
	{
		fread(&ultimoId, sizeof(int), 1, aUltimoId);
		if(ultimoId < id+1)
		{
			updateLastId(id);
		}
	}

	pEmployee = employee_new();
	if(pEmployee != NULL)
	{
		if(employee_setId(pEmployee, id))
		{
			if(employee_setNombre(pEmployee, nombreStr))
			{
				if(employee_setHorasTrabajadas(pEmployee, horasTrabajadas))
				{
					if(employee_setSueldo(pEmployee, sueldo))
					{
						exito = 1;
					}
				}
			}
		}
		if(exito == 0)
		{
			employee_delete(pEmployee);
			pEmployee = NULL;
		}
	}
	fclose(aUltimoId);
	return pEmployee;
}
void employee_delete(Employee* empleado)
{
	free(empleado);
}

int employee_setId(Employee* this,int id)
{
	int exito;
	exito = 0;
	if(this!=NULL && id > 0)
	{
		exito = 1;
		this->id = id;
	}
	return exito;
}

int employee_getId(Employee* this,int* id)
{
	int exito;
	exito = 0;
	if(this != NULL && id != NULL)
	{
		*id = this->id;
		exito = 1;
	}
	return exito;
}

int employee_setNombre(Employee* this,char* nombre)
{
	int exito;
	exito = 0;
	if(this != NULL && strcmp(nombre,"") != 0)
	{
		exito = 1;
		strcpy(this->nombre, nombre);
	}
	return exito;
}
int employee_getNombre(Employee* this,char* nombre)
{
	int exito;
	exito = 0;
	if(this != NULL)
	{
		exito = 1;
		strcpy(nombre, this->nombre);
	}
	return exito;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int exito;
	exito = 0;
	if(this != NULL && horasTrabajadas > 0)
	{
		exito = 1;
		this->horasTrabajadas = horasTrabajadas;
	}
	return exito;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int exito;
	exito = 0;
	if(this != NULL)
	{
		*horasTrabajadas = this->horasTrabajadas;
		exito = 1;
	}
	return exito;
}

int employee_setSueldo(Employee* this,int sueldo)
{
	int exito;
	exito = 0;
	if(this != NULL)
	{
		exito = 1;
		this->sueldo = sueldo;
	}
	return exito;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
	int exito;
	exito = 0;
	if(this != NULL)
	{
		exito = 1;
		*sueldo = this->sueldo;
	}
	return exito;
}

void startLastId(char* dir)
{
	char* ultimoId;
	char* aux;
	int id;
	FILE* idTxt;
	FILE* aUltimo;

	ultimoId = (char*) malloc(12);
	aux = (char*) malloc(24);
	aUltimo = fopen("ultimoId.bin", "wb");
	idTxt = fopen(dir, "r");
	if(idTxt != NULL)
	{
		while(!feof(idTxt))
		{
			fscanf(idTxt, "%[^,],%[^\n]\n", ultimoId, aux);
		}
		id = atoi(ultimoId);
		fwrite(&id, sizeof(int), 1, aUltimo);
	}
	fclose(idTxt);
	fclose(aUltimo);
}

void updateLastId(int id)
{
	FILE* aNewUltimo;
	aNewUltimo = fopen("ultimoId.bin", "wb");
	fwrite(&id, sizeof(int), 1, aNewUltimo);
	fclose(aNewUltimo);
}
