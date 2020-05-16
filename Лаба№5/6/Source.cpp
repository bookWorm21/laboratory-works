#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <locale.h>

int main(int argc, char* argv)
{
	setlocale(LC_ALL, "Rus");
	int n, m, k = 0;
	printf("¬ведите размер первого массива ");
	scanf_s("%d", &n);
	printf("¬ведите размер второго массива ");
	scanf_s("%d", &m);

	int* arrayA = (int*)malloc(n * sizeof(int));
	int* arrayB = (int*)malloc(m * sizeof(int));
	int* useElementB = (int*)malloc(m * sizeof(int));
	int* trueElementA = (int*)malloc(n * sizeof(int));

	for (int i = 0; i < n; i++)
	{
		*(arrayA + i) = rand() % 10;
		*(trueElementA + i) = 0;
		printf("%d  ", *(arrayA + i));
	}
	printf("\n");

	for (int i = 0; i < m; i++)
	{
		*(arrayB + i) = rand() % 10;
		*(useElementB + i) = 0;
		printf("%d  ", *(arrayB + i));
	}
	printf("\n");

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if ((*(arrayA + i) == *(arrayB + j)) && (*(useElementB + j) == 0))
			{
				k++; 
				*(useElementB + j) = 1;
				j = m;
			}
		}
	}

	int* arrayC = (int*)malloc(k * sizeof(int));
	
	k = 0;
	for (int i = 0; i < m; i++)
	{
		if (*(useElementB + i) != 0)
		{
			*(arrayC + k) = *(arrayB + i);
			k++;
		}
	}

	printf("\n");
	for (int i = 0; i < k; i++)
	{
		printf("%d  ", *(arrayC + i));
	}

	return 0;
}