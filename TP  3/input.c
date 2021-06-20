#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"

int getString(char* msg, char* destino)
{
	int exito;
	exito = 0;
	printf("%s", msg);
	scanf("%s", destino);
	if(strcmp(destino, "") != 0)
	{
		exito = 1;
	}
	return exito;
}
