#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <locale.h>

void HundlerArray(float** array, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)
			{
				array[i][j] *= 2;
			}
		}
	}
}

int main(int argc, char* agrv)
{
	setlocale(LC_ALL, "Rus");

	int n;
	printf("¬ведите размерность масссива ");
	scanf_s("%d", &n);

	float** array = (float**)malloc(n * sizeof(float*));

	for (int i = 0; i < n; i++)
	{
		array[i] = (float*)malloc(n * sizeof(float));
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			array[i][j] = rand() % 100;
			printf("%f  ", array[i][j]);
		}
		printf("\n");
	}

	HundlerArray(array, n);

	printf("\n\n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%f  ", array[i][j]);
		}
		printf("\n");
	}

	return 0;
}