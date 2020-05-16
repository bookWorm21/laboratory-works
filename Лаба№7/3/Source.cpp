#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <locale.h>

float FindMinInArray(float** array, int n, int k)
{
	float min = array[0][0];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < k; j++)
		{
			if (array[i][j] < min)
			{
				min = array[i][j];
			}
		}
	}
	return min;
}

int main(int argc, char* agrv)
{
	setlocale(LC_ALL, "Rus");

	int n;
	printf("¬ведите количество строк масссива ");
	scanf_s("%d", &n);

	float** array = (float**)malloc(n * sizeof(float*));

	for (int i = 0; i < n; i++)
	{
		array[i] = (float*)malloc(4 * sizeof(float));
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			array[i][j] = rand() % 100;
			printf("%f  ", array[i][j]);
		}
		printf("\n");
	}

	printf("%f", FindMinInArray(array, n, 4));
	
	return 0;
}