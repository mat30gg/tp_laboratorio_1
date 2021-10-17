#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "input.h"


void HardcodearEmpleados(sEmployees employeeList[])
{
	employeeList[3].id = 1;
	strcpy(employeeList[3].name, "Carlos");
	strcpy(employeeList[3].lastName, "Guiterrez");
	employeeList[3].salary = 20000;
	employeeList[3].sector = 200;
	employeeList[3].isEmpty = 0;
	employeeList[1].id = 2;
	strcpy(employeeList[1].name, "Miguel");
	strcpy(employeeList[1].lastName, "Angel");
	employeeList[1].salary = 30000;
	employeeList[1].sector = 200;
	employeeList[1].isEmpty = 0;
	employeeList[2].id = 3;
	strcpy(employeeList[2].name, "Manuel");
	strcpy(employeeList[2].lastName, "Jorge");
	employeeList[2].salary = 45000;
	employeeList[2].sector = 200;
	employeeList[2].isEmpty = 0;
	employeeList[0].id = 4;
	strcpy(employeeList[0].name, "Ana");
	strcpy(employeeList[0].lastName, "Banana");
	employeeList[0].salary = 10000;
	employeeList[0].sector = 201;
	employeeList[0].isEmpty = 0;
	employeeList[4].id = 5;
	strcpy(employeeList[4].name, "Alan");
	strcpy(employeeList[4].lastName, "Brito");
	employeeList[4].salary = 60000;
	employeeList[4].sector = 201;
	employeeList[4].isEmpty = 0;
}

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
int employeeEntry(sEmployees employeeList[], int tam, int* lastId)
{

	int error = 1;
	int empty;
	empty = findOpen(employeeList, tam);
	if(empty != -1)
	{
		error = 0;
		loadData(employeeList, tam, *lastId ,empty);
		(*lastId)++;
	}
	return error;

}


/** \brief Le pide al usuario cargar los datos de una estructura de tipo sEmployee
 *
 * \param employeeList
 * \param tam
 *
 */
void loadData(sEmployees employeeList[], int tam, int id, int empty)
{
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int auxError;
	do{
		getString("\nIngrese nombre del empleado: ", name);
		auxError = 1;
		if(esEspaciado(name) == 1 || esAlfanumerica(name) == 0)
		{
			auxError = 0;
			printf("Ingrese un nombre valido sin espacios y numeros.\n");
		}

	}while(auxError == 0);
	do{
		auxError = 1;
		getString("Ingrese el apellido del empleado: ", lastName);
		if(esEspaciado(lastName) == 1 || esAlfanumerica(lastName) == 0)
		{
			auxError = 0;
			printf("Ingrese un apellido valido sin espacios y numeros.\n");
		}

	}while(auxError == 0);
	do{

		salary = getFloat("Ingrese salario del empleado: ");
		auxError = 1;
		if(salary < 0)
		{
			auxError = 0;
			printf("Ingrese un salario valido.\n");
		}
	}while(auxError == 0);
	do{
		sector = getInt("Ingrese sector del empleado: ");
		auxError = 1;
		if(sector < 0)
		{
			auxError = 0;
			printf("Ingrese un numero de sector valido.\n");
		}
	}while(auxError == 0);
	employeeList[empty] = addEmployee(id, name, lastName, salary, sector);
	employeeList[empty].isEmpty = 0;
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
	name[0] = toupper(name[0]);
	lastName[0] = toupper(lastName[0]);
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
		printf("\n[%-3d] |%-6s, %-8s|   $%-9.2f   n°%-5d", employeeList.id, employeeList.name, employeeList.lastName, employeeList.salary, employeeList.sector);

	}

}

int printEmployees(sEmployees employeeList[], int tam)
{

	int x;
	printf("[ID]  (Nombre, Apellido)   :Sueldo:   {Sector}");
	for(x=0;x!=tam;x++)
	{
		printOneEmployee(employeeList[x]);
		if(employeeList[x].sector != employeeList[x+1].sector && employeeList[x+1].isEmpty == 0)
		{
			printf("\n----");
		}
	}
	return 0;

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
			case 4:
				employeeList.sector = modifySector(employeeList);
			break;
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

int informMenu(sEmployees employeeList[], int tam)
{
	int choice;
	do{
		printf("\n|||(1)Listado ordenado alfabeticamente por sector.");
		printf("\n|||(2)Total y promedio de salarios con empleados que superen el mismo.");
		printf("\n|||(0)Cancelar.");
		choice = getInt("\n|||Elija una opcion: ");
		switch(choice)
		{
		case 1:
			sortMenu(employeeList, tam);
			break;
		case 2:
			AverageSalary(employeeList, tam);
			break;
		case 0:
			printf("CANCELANDO\n");
			break;
		default:
			printf("VALOR INGRESADO NO VALIDO.\n");
		}
	}while(choice != 0);
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
	OrderBySector(employeeList, tam);
	int x;
	int y;
	int r;
	for(x=0;x!=tam-1;x++)
	{
		for(y=x+1; y!=tam; y++)
		{
			if(employeeList[x].sector == employeeList[y].sector)
			{
				r = strcmp(employeeList[x].name, employeeList[y].name);
				if(r != 0)
				{
					if(r > 0 && order == 1)
					{
						Swap(employeeList, x, y);
					}
					else
					{
						if(r < 0 && order == 0)
						{
							Swap(employeeList, x, y);
						}
					}
				}
			}
		}
	}
	printEmployees(employeeList, tam);
	return error;


}


/** \brief Ordena de forma ascendente un array auxiliar de tipo sEmployees
 *
 * \param employeeList
 * \param tam
 *
 */
void Swap(sEmployees employeeList[], int x, int y)
{

	sEmployees aux;
	aux = employeeList[x];
	employeeList[x] = employeeList[y];
	employeeList[y] = aux;
}


void OrderBySector(sEmployees employeeList[], int tam)
{
	int x;
	int y;
	for(x=0;x!=tam-1;x++)
	{
		for(y=x+1;y!=tam;y++)
		{
			if(employeeList[x].sector > employeeList[y].sector)
			{
				Swap(employeeList, x, y);
			}
		}
	}
}

int AverageSalary(sEmployees employeeList[], int tam)
{

	int error;
	float sum;
	int count;
	float average;
	error = 1;
	sum = SumSalaries(employeeList, tam);
	count = CountLoaded(employeeList, tam);
	if(sum != 0)
	{
		average = GetAverage(sum, count);
		printf("\n\nEl total de todos los salarios da: $%.2f", sum);
		printf("\nEl promedio total de los salarios es: $%.2f", average);
		if(count > 1)
		{
			printf("\nLos empleados que superan el promedio de salario son: ");
			printOverAverage(employeeList, tam, average);
		}
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

float GetAverage(float suma, int cantidad)
{
	float returnAux;
	returnAux = suma / cantidad;
	return returnAux;
}

float SumSalaries(sEmployees employeeList[], int tam)
{

	int x;
	float sum = 0;
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
	for(x=0;x!=tam;x++)
	{
		if(average < employeeList[x].salary)
		{
			printOneEmployee(employeeList[x]);
		}
	}

}

int MainMenu()
{
	int choice;
	printf("\n -------------------");
	printf("\n||Menu:");
	printf("\n||1 - Alta.");
	printf("\n||2 - Modificacion.");
	printf("\n||3 - Baja.");
	printf("\n||4 - Listado en orden alfabetico por sector y promedio de salarios.");
	printf("\n||0 - SALIR.");
	choice = getInt("\n|| Elija una opcion:  ");
	return choice;
}
