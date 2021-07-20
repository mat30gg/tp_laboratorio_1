#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"
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

void printOneEmployee(Employee* this)
{
	int id;
	char* nombre;
	int horasTrabajadas;
	int sueldo;
	nombre = (char*) malloc(128);
	employee_getId(this, &id);
	employee_getNombre(this, nombre);
	employee_getHorasTrabajadas(this, &horasTrabajadas);
	employee_getSueldo(this, &sueldo);
	printf("[%4d] <%-9s>  %-3d Hs | $%d\n", id, nombre, horasTrabajadas, sueldo);
}

int employee_modifyNombre(Employee* this)
{
	int exito;
	char* aux;
	exito = 0;
	aux = (char*) malloc(128);
	if(getString("Ingrese nuevo nombre: ", aux) != -1)
	{
		exito = 1;
		employee_setNombre(this, aux);
	}
	return exito;
}

int employee_modifyHorasTrabajadas(Employee* this)
{
	int exito;
	int aux;
	exito = 0;
	aux = getInt("Ingrese nuevas horas de trabajo: ");
	if(aux != -1)
	{
		exito = 1;
		employee_setHorasTrabajadas(this, aux);
	}
	return exito;
}

int employee_modifySueldo(Employee* this)
{
	int exito;
	int aux;
	exito = 0;
	aux = getInt("Ingrese nuevo sueldo: ");
	if(aux != -1)
	{
		exito = 1;
		employee_setSueldo(this, aux);
	}
	return exito;
}

int ordenNombre(void* e1, void* e2)
{
	Employee* x = e1;
	Employee* y = e2;
	int returnAux;
	if(strcmp(x->nombre, y->nombre) == 0)
	{
		returnAux = 0;
	}
	else
	{
		if(strcmp(x->nombre, y->nombre) > 0)
		{
			returnAux = 1;
		}
		else
		{
			returnAux = -1;
		}
	}
	return returnAux;
}



int ordenSueldo(void* e1, void* e2)
{
	Employee* x = e1;
	Employee* y = e2;
	int returnAux;
	if(x->sueldo == y->sueldo)
	{
		returnAux = 0;
	}
	else
	{
		if(x->sueldo > y->sueldo)
		{
			returnAux = 1;
		}
		else
		{
			returnAux = -1;
		}
	}
	return returnAux;
}
