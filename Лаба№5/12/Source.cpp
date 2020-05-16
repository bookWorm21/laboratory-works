#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <malloc.h>

int main(int argc, char* argv)
{
	setlocale(LC_ALL, "Rus");

	int n, sum = 0;
	printf("¬ведите размерность квадратной матрица  ");
	scanf_s("%d", &n);
	int** array = (int**)malloc(n * sizeof(int*));

	for (int i = 0; i < n; i++)
	{
		array[i] = (int*)malloc(n * sizeof(int));
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			array[i][j] = rand() % 11 - rand() % 11;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (j >= i && (j >= (n - 1 - i)))
			{
				if (array[i][j] < 0 )
				{
					sum += array[i][j];
				}
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d   ", array[i][j]);
		}
		printf("\n");
	}

	printf("%d", sum);

	for (int i = 0; i < n; i++)
		free(array[i]);

	free(array);
}