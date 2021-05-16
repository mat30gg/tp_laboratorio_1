#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "ArrayEmployees.h"


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
		employeeList[empty].isEmpty = 0;
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

		printf("\nIngrese ID del empleado: ");
		scanf("%d", &id);
		if(findUsedID(employeeList, tam, id)==0)
		{
			printf("\nID de empleado ya ingresado.");
		}

	}while(findUsedID(employeeList, tam, id)==0);
	do{

		fflush(stdin);
		printf("\nIngrese nombre del empleado: ");
		scanf("%[^\n]", name);
		if(verifySpaces(name) == 1 || verifyNumbers(name) == 1)
		{
			printf("\nIngrese un nombre valido sin espacios y numeros.");
		}

	}while(verifySpaces(name) == 1 || verifyNumbers(name) == 1);
	do{

		fflush(stdin);
		printf("\nIngrese el apellido del empleado: ");
		scanf("%[^\n]", lastName);
		if(verifySpaces(lastName) == 1 || verifyNumbers(lastName) == 1)
		{
			printf("\nIngrese un apellido valido sin espacios y numeros.");
		}

	}while(verifySpaces(lastName) == 1 || verifyNumbers(lastName) == 1);
	do{

		printf("\nIngrese el salario del empleado: ");
		scanf("%f", &salary);

	}while(salary < 0);
	do{

		printf("\nIngrese el numero de sector al que pertenece el empleado: ");
		scanf("%d", &sector);
		if(sector < 0)
		{
			printf("Ingrese un numero valido.");
		}

	}while(sector < 0);
	employeeList[empty] = addEmployee(id, name, lastName, salary, sector);

}

sEmployees addEmployee(int id, char name[],char lastName[],float salary,int sector)
{

	sEmployees aux;
	aux.id = id;
	aux.sector = sector;
	aux.salary = salary;
	strcpy(aux.name, name);
	strcpy(aux.lastName, lastName);
	return aux;

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
	error = 1;
	int x;
	for(x=0;x!=tam;x++)
	{
		if(id == employeeList[x].id && employeeList[x].isEmpty == 0)
		{
			error = 0;
		}
	}
	return error;

}

int VerifyChar(char word[])
{

	int valid;
	int x;
	int size;
	valid = 1;
	size = strlen(word);
	for(x=0;x!=size;x++)
	{
		if(isalpha(word[x]) == 0)
		{
			valid = 0;
		}
	}
	return valid;

}

int findLoaded(sEmployees employeeList[], int tam)
{

	int empty;
	empty = 1;
	int x;
	for(x=0;x!=tam;x++)
	{
		if(employeeList[x].isEmpty == 0)
		{
			empty = 0;
			break;
		}
	}
	return empty;

}

int modifyEmployee(sEmployees employeeList[], int tam)
{

	int pos;
	int verify;
	verify = 1;
	pos = requestID("\n\nIngrese id del empleado a modificar: ", employeeList, tam);
	if(pos != -1)
	{
		printOneEmployee(employeeList[pos]);
		employeeList[pos] = modifyMenu(employeeList[pos]);
		verify = 0;
	}
	return verify;

}

int requestID(char message[], sEmployees employeeList[], int tam)
{

	int id;
	int pos;
	printf("\n%s", message);
	scanf("%d", &id);
	pos = findIDPos(employeeList, tam, id);
	if(pos == -1)
	{
		printf("ID de empleado no encontrada.");
	}
	return pos;

}

int findIDPos(sEmployees employeeList[], int tam, int id)
{

	int x;
	int pos;
	pos = -1;
	for(x=0;x!=tam;x++)
	{
		if(employeeList[x].id == id && employeeList[x].isEmpty == 0)
		{
			pos = x;
			break;
		}
	}
	return pos;

}

void printOneEmployee(sEmployees employeeList)
{

	if(employeeList.isEmpty == 0)
	{
		printf("\n|ID: %d", employeeList.id);
		printf("\n|Nombre: %s", employeeList.name);
		printf("\n|Apellido: %s", employeeList.lastName);
		printf("\n|Salario: %.2f", employeeList.salary);
		printf("\n|Sector: %d", employeeList.sector);
	}

}

sEmployees modifyMenu(sEmployees employeeList)
{

	int choice;
	do{

		printf("\n\nQue dato desea modificar del empleado?");
		printf("\n (1) - Nombre.");
		printf("\n (2) - Apellido.");
		printf("\n (3) - Salario.");
		printf("\n (4) - Sector.");
		printf("\n (5) - Imprimir datos.");
		printf("\n (0) - Cancelar modificacion.");
		printf("\n �:");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				modifyName(employeeList.name, "nombre", "El nombre no puede contener espacios o numeros");
			break;
			case 2:
				modifyName(employeeList.lastName, "apellido", "El apellido no puede contener espacios o numeros");
			break;
			case 3:
				employeeList.salary = modifySalary(employeeList);
			break;
			case 4:
				employeeList.sector = modifySector(employeeList);
			break;
			case 5:
				printOneEmployee(employeeList);
			break;
		}
	}while(choice != 0);
	return employeeList;
}

void modifyName(char name[], char data[], char errorMessage[])
{

	char auxiliar[51];
	printf("\n%s previo: %s", data, name);
	printf("\nNuevo %s: ", data);
	fflush(stdin);
	scanf("%[^\n]", auxiliar);
	if(verifySpaces(auxiliar) == 1 || verifyNumbers(auxiliar) == 1)
	{
		printf("%s", errorMessage);
	}
	else
	{
		strcpy(name, auxiliar);
	}

}


int verifySpaces(char word[])
{

	int spaces;
	int x;
	int size;
	size = strlen(word);
	spaces = 0;
	for(x=0;x!=size;x++)
	{
		if(isspace(word[x]) != 0)
		{
			spaces = 1;
		}
	}
	return spaces;

}

int verifyNumbers(char word[])
{

	int numbers;
	int x;
	int size;
	size = strlen(word);
	numbers = 0;
	for(x=0;x!=size;x++)
	{
		if(isdigit(word[x]) != 0)
		{
			numbers = 1;
		}
	}
	return numbers;

}


float modifySalary(sEmployees employeeList)
{

	float newSalary;
	printf("\nSalario previo: %.2f", employeeList.salary);
	do{
		printf("\nNuevo salario: ");
		scanf("%f", &newSalary);
		if(newSalary < 0)
		{
			printf("Se deben ingresar valores positivos.");
		}
	}while(newSalary < 0);
	return newSalary;

}

int modifySector(sEmployees employeeList)
{

	int newSector;
	printf("\nSector previo: %d", employeeList.sector);
	do{
		printf("\nNuevo sector: ");
		scanf("%d", &newSector);
		if(newSector < 0)
		{
			printf("Se deben ingresar valores positivos.");
		}
	}while(newSector < 0);
	return newSector;

}



int removeEmployee(sEmployees employeeList[], int tam)
{

	int error;
	int pos;
	error = 1;
	pos = requestID("\n\nIngrese ID del empleado a dar de baja: ", employeeList, tam);
	if(pos != -1)
	{
		if(deleteEmployee(employeeList[pos]))
		{
			employeeList[pos].isEmpty = 1;
		}
	}
	return error;

}

int deleteEmployee(sEmployees employeeList)
{
	int choice;
	char verify;
	printf("Desea eliminar?");
	printOneEmployee(employeeList);
	do{
		printf("\nIngrese S o N: ");
		fflush(stdin);
		scanf("%c", &verify);
		verify = toupper(verify);
		choice = yesOrNo(verify);
	}while(verify != 'N' && verify != 'S');
	return choice;

}

int yesOrNo(int input)
{

	int value;
	if(input != 'N' && input != 'S')
	{
		printf("Respuesta invalida.");
		value = 0;
	}
	else
	{
		if(input == 'S')
		{
			value = 1;
		}
		else
		{
			value = 0;
		}
	}
	return value;

}

int sortMenu(sEmployees employeeList[], int tam)
{

	int error;
	int order;
	do{

		printf("\nDe que forma quiere ordenar la lista? (1 = ascendente / 0 = descendente): ");
		scanf("%d", &order);

	}while(order != 1 && order != 0);
	error = sortEmployees(employeeList, tam, order);
	return error;

}


int sortEmployees(sEmployees employeeList[], int tam, int order)
{

	int error;
	error = 0;
	sEmployees auxList[tam];
	initEmployees(auxList, tam);
	CopyList(employeeList, auxList, tam);
	OrderBySector(auxList, tam);
	if(order == 1)
	{
		AscendingOrder(auxList, tam);
	}
	else
	{
		DescendingOrder(auxList, tam);
	}
	PrintEmployeesBySector(auxList, tam);
	return error;


}

void AscendingOrder(sEmployees auxList[], int tam)
{

	sEmployees aux;
	int x;
	int y;
	for(x=0;x!=tam-1;x++)
	{
		for(y=x+1;y!=tam;y++)
		{
			if(auxList[x].sector == auxList[y].sector)
			{
				if(strcmp(auxList[y].name, auxList[x].name) > 0)
				{
					aux = auxList[y];
					auxList[y] = auxList[x];
					auxList[x] = aux;
				}
			}
		}
	}


}

void DescendingOrder(sEmployees auxList[], int tam)
{

	sEmployees aux;
	int x;
	int y;
	for(x=0;x!=tam-1;x++)
	{
		for(y=x+1;y!=tam;y++)
		{
			if(auxList[x].sector == auxList[y].sector)
			{
				if(strcmp(auxList[x].name, auxList[y].name) > 0)
				{
					aux = auxList[y];
					auxList[y] = auxList[x];
					auxList[x] = aux;
				}
			}
		}
	}

}

void OrderBySector(sEmployees auxList[], int tam)
{
	int x;
	int y;
	sEmployees aux;
	for(x=0;x!=tam-1;x++)
	{
		for(y=x+1;y!=tam;y++)
		{
			if(auxList[x].sector > auxList[y].sector)
			{
				aux = auxList[y];
				auxList[y] = auxList[x];
				auxList[x] = aux;
			}
		}
	}
}

void CopyList(sEmployees employeeList[], sEmployees auxList[], int tam)
{

	int x;
	int y;
	y = 0;
	for(x=0;x!=tam;x++)
	{
		if(employeeList[x].isEmpty == 0)
		{
			auxList[y] = employeeList[x];
			y++;
		}
	}

}

void PrintEmployeesBySector(sEmployees auxList[], int tam)
{

	int place;
	place = -1;
	int x;
	for(x=0;x!=tam;x++)
	{
		if(auxList[x].isEmpty == 0)
		{
			if(place != auxList[x].sector)
			{
				printf("\n\n\n\nSector: %d", auxList[x].sector);
				place = auxList[x].sector;
			}
			printOneEmployee(auxList[x]);
			printf("\n---------------------");
		}
	}

}


int printEmployees(sEmployees employeeList[], int tam)
{

	int x;
	for(x=0;x!=tam;x++)
	{
		printOneEmployee(employeeList[x]);
	}
	return 0;

}

int AverageSalary(sEmployees employeeList[], int tam)
{

	int error;
	int sum;
	int count;
	float average;
	error = 1;
	sum = SumSalaries(employeeList, tam);
	count = CountLoaded(employeeList, tam);
	if(sum != 0)
	{
		average = (float)sum / count;
		printf("\nEl total de todos los salarios da: $%d", sum);
		printf("\nEl promedio total de los salarios es: $%.2f", average);
		printf("\nLos empleados que superan el promedio de salario son: ");
		printOverAverage(employeeList, tam, average);
		error = 0;
	}
	return error;

}

int CountLoaded(sEmployees employeeList[], int tam)
{
	int x;
	int count;
	count = 0;
	for(x=0;x!=tam;x++)
	{
		if(employeeList[x].isEmpty == 0)
		{
			count++;
		}
	}
	return count;
}

int SumSalaries(sEmployees employeeList[], int tam)
{

	int x;
	int sum = 0;
	for(x=0;x!=tam;x++)
	{
		if(employeeList[x].isEmpty == 0)
		{
			sum += employeeList[x].salary;
		}
	}
	return sum;

}

void printOverAverage(sEmployees employeeList[], int tam, float average)
{
	int x;
	int y;
	y = 0;
	sEmployees overAverageList[tam];
	initEmployees(overAverageList, tam);
	for(x=0;x!=tam;x++)
	{
		if(average < employeeList[x].salary)
		{
			overAverageList[y] = employeeList[x];
			y++;
		}
	}
	printEmployees(overAverageList, tam);

}
