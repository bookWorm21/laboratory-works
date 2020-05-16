#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <locale.h>

float SearchMaxInArray(float** array, int line, int column)
{
	float max = array[0][0];

	for (int i = 0; i < line; i++)
	{
		for (int j = 0; j < column; j++)
		{
			if (array[i][j] > max)
			{
				max = array[i][j];
			}
		}
	}

	return max;
}

int main(int argc, char* argv)
{
	setlocale(LC_ALL, "Rus");
	int line, column;
	float max;

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

	max = SearchMaxInArray(array, line, column);
	printf("\nМаксимальное число в массиве - %f", max);

	for (int i = 0; i < line; i++)
	{
		free(array[i]);
	}

	free(array);

	return 0;
}