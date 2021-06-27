#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "input.h"

/** \brief Inicializa el parametro "isEmpty" del array tipo sEmployee en 1
 *
 * \param employeeList
 * \param tam
 * \return Retorna valor positivo si no se entro en el bucle
 *
 */
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

/** \brief Busca un lugar libre con findOpen y la posicion en el array lo carga en loadData
 *
 * \param employeeList
 * \param tam
 * \return Retorna valor positivo si no se encontro lugar libre
 *
 */
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


/** \brief Le pide al usuario cargar los datos de una estructura de tipo sEmployee
 *
 * \param employeeList
 * \param tam
 *
 */
void loadData(sEmployees employeeList[], int tam, int empty)
{
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	id = empty+1;
	do{
		fflush(stdin);
		printf("\nIngrese nombre del empleado: ");
		scanf("%[^\n]", name);
		if(esEspaciado(name) == 1 || esAlfanumerica(name) == 0)
		{
			printf("\nIngrese un nombre valido sin espacios y numeros.");
		}

	}while(esEspaciado(name) == 1 || esAlfanumerica(name) == 0);
	do{

		fflush(stdin);
		printf("\nIngrese el apellido del empleado: ");
		scanf("%[^\n]", lastName);
		if(esEspaciado(lastName) == 1 || esAlfanumerica(lastName) == 0)
		{
			printf("\nIngrese un apellido valido sin espacios y numeros.");
		}

	}while(esEspaciado(lastName) == 1|| esAlfanumerica(lastName) == 0);
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


/** \brief Carga los valores cargados en loadData en una estructura sEmployee auxiliar
 *
 * \param id
 * \param name
 * \param lastName
 * \param salary
 * \param sector
 * \return retorna la estructura auxiliar sobreescribiendo la posicion en el array
 *
 */
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


/** \brief Revisa el array employeeList
 *
 * \param employeeList
 * \param tam
 * \return Retorna una posicion en el array que tenga la variable isEmpty en 1
 *
 */
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



/** \brief Verifica que en la cadena de caracteres solo existan tipos char
 *
 * \param word
 * \return Retorna positivo si no se encontro valor alfanumerico
 *
 */
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

/** \brief Busca que alguna posicion del array tenga valores cargados
 *
 * \param employeeList
 * \param tam
 * \return Retorna positivo si no hay valores cargados
 *
 */
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

/** \brief Modifica valores de un elemento de employeeList
 *
 * \param employeeList
 * \param tam
 * \return retorna positivo si fallo en modificar
 *
 */
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


/** \brief Solicita el ingreso de un id
 *
 * \param employeeList
 * \param message
 * \param tam
 * \return Retorna la posicion en el array del id ingresado
 *
 */
int requestID(char message[], sEmployees employeeList[], int tam)
{

	int id;
	int pos;
	id = getInt(message);
	if(id == -1)
	{
		pos = id;
		printf("ID de empleado no encontrada.");
	}
	else
	{
		pos = findEmployeeById(employeeList, tam, id);
	}
	return pos;

}

/** \brief Busca la posicion en el array employeeList que contenga el id ingresado
 *
 * \param employeeList
 * \param tam
 * \param id
 * \return Retorna la posicion en el array del elemento con el id ingresado
 *
 */
int findEmployeeById(sEmployees employeeList[], int tam, int id)
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

/** \brief Imprime los datos de un elemento de tipo sEmployees
 *
 * \param employeeList
 *
 */
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

/** \brief Muestra en pantalla un menu de opciones para modificar valores
 *
 * \param employeeList
 * \return Retorna el elemento modificado
 *
 */
sEmployees modifyMenu(sEmployees employeeList)
{

	int choice;
	do{

		printf("\n\nQue dato desea modificar del empleado?");
		printf("\n (1) - Nombre.");
		printf("\n (2) - Apellido.");
		printf("\n (3) - Salario.");
		printf("\n (4) - Sector.");
		printf("\n °:");
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
			/*case 4:
				employeeList.sector = modifySector(employeeList);
			break;
			case 5:
				printOneEmployee(employeeList);
			break;*/
		}
	}while(choice != 0);
	return employeeList;
}

/** \brief Modifica los valores de la cadena name
 *
 * \param name
 * \param data
 * \param errorMessage
 *
 */
void modifyName(char name[], char data[], char errorMessage[])
{

	char auxiliar[51];
	printf("\n%s previo: %s", data, name);
	printf("\nNuevo %s: ", data);
	fflush(stdin);
	scanf("%[^\n]", auxiliar);
	if(esEspaciado(auxiliar) == 1|| esAlfanumerica(auxiliar) == 0)
	{
		printf("%s", errorMessage);
	}
	else
	{
		strcpy(name, auxiliar);
	}

}



/** \brief Modifica el valor de la variable salary de un sEmployee
 *
 * \param employeeList
 * \return Retorna el nuevo valor de la variable salary
 *
 */
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

/** \brief Modifica el valor de la variable sector de un sEmployee
 *
 * \param employeeList
 * \return Retorna el nuevo valor de la variable sector
 *
 */
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


/** \brief Elimina logicamente un elemento de tipo sEmployee cambiando el valor de la variable isEmpty
 *
 * \param employeeList
 * \return Retorna positivo si fallo en eliminar elemento
 *
 */
int removeEmployee(sEmployees employeeList[], int tam, int id)
{

	int error;
	int pos;
	error = 1;
	pos = findEmployeeById(employeeList, tam, id);
	if(pos != -1)
	{
		if(deleteEmployee(employeeList[pos]))
		{
			employeeList[pos].isEmpty = 1;
			error = 0;
		}
	}
	return error;

}

/** \brief Verifica que el usuario quiera eliminar un empleado
 *
 * \param employeeList
 * \return Retorna la validacion
 *
 */
int deleteEmployee(sEmployees employeeList)
{
	int choice;
	printf("Desea eliminar?");
	printOneEmployee(employeeList);
	do{
		setbuf(stdin, NULL);
		choice = getSON("\nIngrese S o N: ");
	}while(choice != 0 && choice != 1);
	return choice;

}



/** \brief Solicita el ingreso de un valor para definir como se mostrara el listado ordenado
 *
 * \param employeeList
 * \param tam
 * \return
 *
 */
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

/** \brief Llama a la funcion correspondiente segun el valor que se ingreso como metodo de ordenamiento
 *
 * \param employeeList
 * \param tam
 * \param order
 * \return Retorna positivo si fallo en ordenar
 *
 */
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


/** \brief Ordena de forma ascendente un array auxiliar de tipo sEmployees
 *
 * \param employeeList
 * \param tam
 *
 */
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


/** \brief Ordena de forma descendente un array auxiliar de tipo sEmployees
 *
 * \param employeeList
 * \param tam
 *
 */
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
