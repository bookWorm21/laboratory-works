#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char* argv[])
{
	printf("Hello world\n");
	setlocale(LC_ALL, "RUS");
	
	int arrayA[2][3], arrayB[3][4], arrayResult[2][4] = {};

	printf("\nМатрица 1:");
	printf("\n");
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			arrayA[i][j] = rand() % 4;
			printf("%d \t", arrayA[i][j]);
		}
		printf("\n");
	}

	printf("\nМатрица 2:");
	printf("\n");
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			arrayB[i][j] = rand() % 3;
			printf("%d \t", arrayB[i][j]);
		}
		printf("\n");
	}

	printf("\nИтоговый матрица:");
	printf("\n");
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			for (int k = 0; k < 3; k++)
			{			
					arrayResult[i][j] += arrayA[i][k] * arrayB[k][j];
			}
			printf("%d \t", arrayResult[i][j]);
		}
		printf("\n");
	}
	return 0;
}