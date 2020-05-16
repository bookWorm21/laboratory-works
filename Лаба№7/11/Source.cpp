#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include <malloc.h>

int NumberOfNegative(float** array, int line, int column)
{
	int k = 0;
	for (int i = 0; i < line; i++)
	{
		for (int j = 0; j < column; j++)
		{
			if (array[i][j] < 0)
			{
				k++;
			}
		}
	}
	return k;
}

int main(int argc, char* argv)
{
	setlocale(LC_ALL, "Rus");

	int line, column;
	printf("Введите количество строчек ");
	scanf_s("%d", &line);
	printf("Введите количество столбцов ");
	scanf_s("%d", &column);

	float** array = (float**)malloc(line * sizeof(float*));

	for (int i = 0; i < line; i++)
	{
		array[i] = (float*)malloc(column * sizeof(float));
	}

	for (int i = 0; i < line; i++)
	{
		for (int j = 0; j < column; j++)
		{
			array[i][j] = (float)(rand() % 100 - 50);
			printf("%f  ", array[i][j]);
		}
		printf("\n");
	}

	printf("Количество отрицательных элементов в массиве - %d", NumberOfNegative(array, line, column));

	for (int i = 0; i < line; i++)
	{
		free(array[i]);
	}

	free(array);

	return 0;
}