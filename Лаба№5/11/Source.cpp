#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <locale.h>

int main(int argc, char* argv)
{
	setlocale(LC_ALL, "Rus");
	int line, column;

	printf("Введите количество строк ");
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
			array[i][j] = rand() % 20 - rand() % 20;
			printf("%d  ", array[i][j]);
		}
		printf("\n");
	}

	int numberLine = line - 1;
	for (int j = 0; j < column; j++)
	{
		if (array[numberLine][j] > 0)
		{
			array[numberLine][j] *= 2;
		}
	}

	printf("\n\n");
	for (int i = 0; i < line; i++)
	{
		for (int j = 0; j < column; j++)
		{
			printf("%d  ", array[i][j]);
		}
		printf("\n");
	}
	return 0;
}