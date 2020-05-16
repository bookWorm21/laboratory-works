#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <locale.h>

void HundlerArray(int* array, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == (n - j - 1))
			{
				array[i * n + j] = 0;
			}
		}
	}
}

int main(int argc, char* agrv)
{
	setlocale(LC_ALL, "Rus");

	const int n = 10;
	
	int array[n][n];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			array[i][j] = rand() % 100;
			printf("%d  ", array[i][j]);
		}
		printf("\n");
	}

	HundlerArray(&(array[0][0]), n);

	printf("\n\n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d  ", array[i][j]);
		}
		printf("\n");
	}

	return 0;
}