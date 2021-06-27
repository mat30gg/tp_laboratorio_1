#include <stdio.h>
#include <string.h>
#include "input.h"

int getInt(char* msg)
{
	int returnAux;
	printf("%s", msg);
	scanf("%d", &returnAux);
	return returnAux;
}

float getFloat(char* msg)
{
	float returnAux;
	printf("%s", msg);
	scanf("%f", &returnAux);
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
	if(esNumerica(destino))
	{
		returnAux = -1;
	}

	return returnAux;
}

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
