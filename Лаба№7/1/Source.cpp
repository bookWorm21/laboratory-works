#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <locale.h>
#include <math.h>

// в условии задания указан тип - вещественный, поэтому пришлось сделать так
// хотя скорее всего ошибка в условии и должен быть целочисленный
float CountEven(float array[][3], int n)
{
	float sum = 0;
	float a;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (modff(array[i][j], &a) == 0)
			{
				if ((int)array[i][j] % 2 == 0)
				{
					sum += array[i][j];
				}
			}
		}
	}
	return sum;
}

int main(int argc, char* agrv)
{
	setlocale(LC_ALL, "Rus");

	const int n = 5;
	
	float array[n][3];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			array[i][j] = rand() % 100;
			printf("%f  ", array[i][j]);
		}
		printf("\n");
	}

	printf("Сумма четных элементов - %f", CountEven(array, n));
}