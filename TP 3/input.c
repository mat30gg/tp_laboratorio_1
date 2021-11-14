#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "input.h"

int getInt(char* msg)
{
	int returnAux;
	char stringAux[24];
	do{
		getString(msg, stringAux);
		if(esNumerica(stringAux))
		{
			returnAux = atoi(stringAux);
		}
		else
		{
			printf("Ingrese valor numerico valido.\n");
		}
	}while(esNumerica(stringAux) != 1);
	return returnAux;
}

float getFloat(char* msg)
{
	float returnAux;
	char stringAux[24];
	returnAux = 0;
	do{
		getString(msg, stringAux);
		if(esFlotante(stringAux))
		{
			returnAux = atof(stringAux);
		}
		else
		{
			printf("Ingrese valor numerico valido.\n");
		}
	}while(esFlotante(stringAux) != 1);
	return returnAux;
}

char getChar(char* msg)
{
	char returnAux;
	printf("%s", msg);
	scanf("%c", &returnAux);
	return returnAux;
}

int getString(char* msg, char* destino)
{
	int returnAux;
	returnAux = 0;
	printf("%s", msg);
	scanf("%s", destino);
	if(esNumerica(destino) || esEspaciado(destino))
	{
		returnAux = -1;
	}
	return returnAux;
}

int getStringSize(char* cadena)
{
	int i;
	int cont = 0;
	for(i = 0; cadena[i] != '\0'; i++)
	{
		cont++;
	}
	return cont;
}

int getStringAll(char* msg, char* destino)
{
	int returnAux;
	returnAux = 0;
	printf("%s", msg);
	scanf("%s", destino);
	if(esEspaciado(destino))
	{
		returnAux = -1;
	}
	return returnAux;
}

int getStringNum(char* msg, char* destino)
{
	int returnAux;
	returnAux = 0;
	printf("%s", msg);
	scanf("%s", destino);
	if(esNumerica(destino) == 0 || esEspaciado(destino))
	{
		returnAux = -1;
	}
	return returnAux;
}

/* Retorna 1 si hay valores numericos en la cadena y 0 si hay !numericos
 *
 *
 */
int esNumerica(char* cadena)
{
	int i=0;
	int returnAux = 1;
	if(strlen(cadena) > 0)
	{
		while(*(cadena+i) != '\0')
		{
			if((int)cadena[i] < 48 || (int)cadena[i] > 57)
			{
				returnAux = 0;
				break;
			}
			i++;
		}
	}
	return returnAux;
}

int esFlotante(char* cadena)
{
	int i=0;
	int returnAux = 1;
	if(strlen(cadena) > 0)
	{
		while(*(cadena+i) != '\0')
		{
			if((int)cadena[i] < 46 || (int)cadena[i] > 57 || (int)cadena[i] == 47)
			{
				returnAux = 0;
				break;
			}
			i++;
		}
	}
	return returnAux;
}
/*	Retorna 1 si solo hay valores alfanumericos en la cadena y 0 cuando hay !alfanumericos
 *
 */
int esAlfanumerica(char* cadena)
{
	int i = 0;
	int caracter;
	int returnAux = 1;
	if(strlen(cadena) > 0)
	{
		while(*(cadena+i) != '\0')
		{
			caracter = (int)cadena[i];
			if(!((caracter > 64 && caracter < 91) || (caracter > 96 && caracter < 123)))
			{
				returnAux = 0;
				break;
			}
			i++;
		}
	}
	return returnAux;
}
/*	Retorna 0 si no hay espacios y retorna 1 si se encuentran
 *
 */
int esEspaciado(char* cadena)
{
	int espacios = 0;
	int i = 0;
	if(strlen(cadena) > 0)
	{
		while(*(cadena+i) != '\0')
		{
			if((int)cadena[i] == 32)
			{
				espacios = 1;
				break;
			}
			i++;
		}
	}
	return espacios;
}

int getSON(char* msg)
{
	int value;
	char input;
	input = getChar(msg);
	input = toupper(input);
	if(input != 'N' && input != 'S')
	{
		printf("Respuesta invalida.");
		value = -1;
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
