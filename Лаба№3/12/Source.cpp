#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <stdlib.h>

int main(int argc, char* argr[])
{
	setlocale(LC_ALL, "Rus");

	const int n = 5;
	int arrayA[n];
	int arrayB[n];
	int arrayC[n];

	int arrayD[n * 3];

	for (int i = 0; i < n; i++)
	{
		arrayA[i] = rand() % 100;
		arrayB[i] = rand() % 100;
		arrayC[i] = rand() % 100;
	}
	
	int k = 0; 

	for (int i = 0; i < n; i++)
	{
		arrayD[k++] = arrayA[i];
		arrayD[k++] = arrayB[i];
		arrayD[k++] = arrayC[i];
	}

	printf("Массив A  ");
	for (int i = 0; i < n; i++)
	{
		printf(" %d", arrayA[i]);
	}

	printf("\nМассив B  ");
	for (int i = 0; i < n; i++)
	{
		printf(" %d", arrayB[i]);
	}

	printf("\nМассив C  ");
	for (int i = 0; i < n; i++)
	{
		printf(" %d", arrayC[i]);
	}

	printf("\nМассив D  ");
	for (int i = 0; i < n * 3; i++)
	{
		printf(" %d", arrayD[i]);
	}

	

	return 0;
}