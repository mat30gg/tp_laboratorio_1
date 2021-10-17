#include "funciones.h"

#include <stdio.h>
#include <stdlib.h>

int IngresoDeValorA()
{
	int x;
	printf("\nIngrese valor de A: ");
	scanf("%d", &x);
	return x;
}

int IngresoDeValorB()
{
	int x;
	printf("\nIngrese valor de B: ");
	scanf("%d", &x);
	return x;
}

void InformarResultados(int x, int y, int resultados[], float resultadoDiv[])
{
	printf("\nEl resultado de %d + %d es: %d",x,y,resultados[0]);
	printf("\nEl resultado de %d - %d es: %d",x,y,resultados[1]);
	if(x != 0 && y != 0)
	{
		printf("\nEl resultado de %d / %d es: %.1f",x,y,resultadoDiv[0]);
	}
	else
	{
		printf("\nNo es posible dividir por 0.");
	}
	printf("\nEl resultado de %d * %d es: %d",x,y,resultados[2]);
	if(x > -1 && resultados[3] != 0)
	{
		printf("\nEl resultado de !%d es: %d",x,resultados[3]);
	}
	if(y > -1 && resultados[4] != 0)
	{
		printf("\nEl resultado de !%d es: %d\n",y,resultados[4]);
	}
}
void CalcularOperaciones(int x, int y, int resultados[], float resultadoDiv[])
{
	resultados[0] = Suma(x,y);
	resultados[1] = Resta(x,y);
	resultadoDiv[0] = Division(x,y);
	resultados[2] = Producto(x,y);
	resultados[3] = Factorial(x);
	resultados[4] = Factorial(y);
}
int Suma(int x, int y)
{
	int res;
	res = x + y;
	return res;
}
int Resta(int x, int y)
{
	int res;
	res = x - y;
	return res;
}
float Division(int x, int y)
{
	float res;
	res = (float)x / y;
	return res;
}
int Producto(int x, int y)
{
	int res;
	res = x * y;
	return res;
}
int Factorial(int x)
{
	int res;
	int i;
	res = 1;
	for(i = 1;i < x+1; i++)
	{
		res = res * i;
	}
	return res;
}
