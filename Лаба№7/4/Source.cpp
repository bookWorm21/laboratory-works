#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <locale.h>

int HundlerArray(int** array, int n, int k)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < k; j++)
		{
			if ( array[i][j] > 0)
			{
				sum += array[i][j];
			}
		}
	}
	return sum;
}

int main(int argc, char* agrv)
{
	setlocale(LC_ALL, "Rus");

	int line;
	printf("¬ведите количество строк масссива ");
	scanf_s("%d", &line);

	int** array = (int**)malloc(line * sizeof(int*));

	for (int i = 0; i < line; i++)
	{
		array[i] = (int*)malloc(3 * sizeof(int));
	}

	for (int i = 0; i < line; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			array[i][j] = rand() % 10 - rand() % 11;
			printf("%d  ", array[i][j]);
		}
		printf("\n");
	}

	printf("%d", HundlerArray(array, line, 3));

	return 0;
}