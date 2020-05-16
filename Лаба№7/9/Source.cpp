#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <locale.h>

void HandlerArray(int** array, int* sum, int* numberPositive, int line, int column)
{
	for (int i = 0; i < line; i++)
	{
		for (int j = 0; j < column; j++)
		{
			if (array[i][j] > 0)
			{
				*(sum) += array[i][j];
				(*(numberPositive))++;
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

	int** array = (int**)malloc(line * sizeof(int*));

	for (int i = 0; i < line; i++)
	{
		array[i] = (int*)malloc(column * sizeof(int));
	}

	for (int i = 0; i < line; i++)
	{
		for (int j = 0; j < column; j++)
		{
			array[i][j] = (float)(rand() % 100 - 50);
			printf("%d  ", array[i][j]);
		}
		printf("\n");
	}

	HandlerArray(array, &sum, &numberPositive, line, column);

	printf("Количество положительных элементов - %d\n", numberPositive);
	printf("Сумма положительных элементов - %d", sum);

	for (int i = 0; i < line; i++)
	{
		free(array[i]);
	}

	free(array);

	return 0;
}