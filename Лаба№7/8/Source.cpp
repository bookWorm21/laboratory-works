#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <locale.h>

void HandlerArray(float** array, int line, int column)
{
	for (int i = 0; i < line; i++)
	{
		for (int j = 0; j < column; j++)
		{
			if (i > j)
			{
				array[i][j] *= 3;
			}
		}
	}
}

int main(int argc, char* argv)
{
	setlocale(LC_ALL, "Rus");
	int line, column;
	int sum = 0, numberPositive = 0;

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
			array[i][j] = (float)(rand() % 100);
			printf("%f  ", array[i][j]);
		}
		printf("\n");
	}

	HandlerArray(array, line, column);

	printf("\n\n");
	for (int i = 0; i < line; i++)
	{
		for (int j = 0; j < column; j++)
		{
			printf("%f  ", array[i][j]);
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