#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <locale.h>

int main(int argc, char* argv)
{
	setlocale(LC_ALL, "Rus");
	int m, n, k;

	printf("¬ведите длину массива ");
	scanf_s("%d", &m);

	printf("¬ведите ширину массива ");
	scanf_s("%d", &n);

	printf("¬ведите 'высоту' массива ");
	scanf_s("%d", &k);

	int*** array = (int***)malloc(m * sizeof(int**));

	for (int i = 0; i < m; i++)
	{
		array[i] = (int**)malloc(n * sizeof(int*));
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			array[i][j] = (int*)malloc(k * sizeof(int));
		}
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int t = 0; t < k; t++)
			{
				array[i][j][t] = rand() % 100;
				printf("%d  ", array[i][j][t]);
			}
			printf("\n");
		}
		printf("\n\n\n");
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			free(array[i][j]);
		}
		free(array[i]);
	}

	free(array);

	return 0;
}