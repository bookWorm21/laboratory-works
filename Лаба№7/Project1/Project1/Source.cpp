#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include <malloc.h>

void nullFunction(int** array, int line, int column)
{
	for (int i = 0; i < line; i++)
	{
		for (int j = 0; j < column; j++)
		{
			if (array[i][j] % 3 == 0)
			{
				array[i][j] = 0;
			}
		}
	}
}

int main(int argc, char* argv)
{
	setlocale(LC_ALL, "Rus");
	int line, column;

	printf("Введите количество строчек ");
	scanf_s("%d", &line);
	printf("Введите количество столбцов ");
	scanf_s("%d", &column);

	int** array = (int**)malloc(line * sizeof(int*));

	for (int i = 0; i < line; i++)
	{
		array[i] = (int*)malloc(column * sizeof(int));
	}

	for (int i = 0; i < line; i++)
	{
		for (int j = 0; j < column; j++)
		{
			array[i][j] = rand() % 100;
			printf("%d  ", array[i][j]);
		}
		printf("\n");
	}

	nullFunction(array, line, column);
	printf("\n\n");

	for (int i = 0; i < line; i++)
	{
		for (int j = 0; j < column; j++)
		{
			printf("%d  ", array[i][j]);
		}
		printf("\n");
	}

	for (int i = 0; i < line; i++)
	{
		free(array[i]);
	}

	free(array);

	return 0;
}