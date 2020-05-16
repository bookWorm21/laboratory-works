#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <locale.h>

void HundlerArray(int** array, int n, int k, int* quantity, int* sum)
{
	(*quantity) = 0;
	(*sum) = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < k; j++)
		{
			if (array[i][j] < 0)
			{
				(*quantity)++;
				(*sum) += array[i][j];
			}
		}
	}
}

int main(int argc, char* agrv)
{
	setlocale(LC_ALL, "Rus");

	int n;
	int sum, quantity;
	printf("Введите количесто строк масссива ");
	scanf_s("%d", &n);

	int** array = (int**)malloc(n * sizeof(int*));

	for (int i = 0; i < n; i++)
	{
		array[i] = (int*)malloc(2 * sizeof(int));
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			array[i][j] = rand() % 10 - rand() % 15;
			printf("%d  ", array[i][j]);
		}
		printf("\n");
	}

	HundlerArray(array, n, 2, &quantity, &sum);
	printf("Сумма - %d\n", sum);
	printf("Количество - %d", quantity);

	
	return 0;
}