#include <stdio.h>
#include <ctype.h>
#include "input.h"

int getInt(char message[], char messageError[])
{
	char INT;
	do{
		printf(message);
		scanf("%c", &INT);
		if(isdigit(INT) == 0)
		{
			printf(messageError);
		}
	}while(isdigit(INT) == 0);
	INT = (int)INT;
	return INT;
}

int getIntPos(char message[], char messageError[])
{
	char INT;
	int VAL;
	do{
		printf(message);
		scanf("%c", &INT);
		VAL = (int)INT;
		if(isdigit(INT) == 0 || VAL < 0)
		{
			printf(messageError);
		}
	}while(isdigit(INT) == 0);
	return VAL;
}




int getMMInt(char message[], char messageError[], int min, int max)
{
	char INT;
	int VAL;
	do{
		printf(message);
		scanf("%c", &INT);
		VAL = (int)INT;
		if(isdigit(INT) == 0 || (VAL > min || VAL < max))
		{
			printf(messageError);
		}
	}while(isdigit(INT) == 0);
	return VAL;
}

float getFloat(char message[], char messageError[])
{
	char FLOAT;
	float VAL;
	do{
		printf(message);
		scanf("%c", &FLOAT);
		if(isdigit(FLOAT) == 0)
		{
			printf(messageError);
		}
	}while(isdigit(FLOAT) == 0);
	VAL = (float)FLOAT;
	return VAL;
}

float getFloatPos(char message[], char messageError[])
{
	char FLOAT;
	float VAL;
	do{
		printf(message);
		scanf("%c", &FLOAT);
		VAL = (float)FLOAT;
		if(isdigit(FLOAT) == 0 || VAL < 0)
		{
			printf(messageError);
		}
	}while(isdigit(FLOAT) == 0);
	return VAL;
}

float getMMFloat(char message[], char messageError[], float min, float max)
{
	char FLOAT;
	float VAL;
	do{
		printf("\n", message);
		scanf("%c", &FLOAT);
		VAL = (float)FLOAT;
		if(isdigit(FLOAT) == 0 || (VAL > min || VAL < max))
		{
			printf(messageError);
		}
	}while(isdigit(FLOAT) == 0);
	return VAL;
}




char getChar(char message[])
{
	char CHAR;
	printf("\n", message);
	fflush(stdin);
	scanf("%c", &CHAR);
	return CHAR;
}

char getCharDual(char message[], char messageError[], char option1, char option2)
{
	char CHAR;
	do{
		printf("\n", message);
		fflush(stdin);
		scanf("%c", &CHAR);
		if(CHAR != option1 && CHAR != option2)
		{
			printf(messageError);
		}
	}while(CHAR != option1 && CHAR != option2);
	return CHAR;
}

void getString(char message[], char string[])
{
	printf("\n", message);
	fflush(stdin);
	scanf("%[^\n]", string);
}
