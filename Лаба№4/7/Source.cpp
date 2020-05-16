#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Rus");

	int arrayA[10][10], tempNumber;

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			arrayA[i][j] = rand() % 100;
			printf("%d \t", arrayA[i][j]);
		}
		printf("\n");
	}

	for (int i = 0; i < 10; i++)
	{
		for (int j = i; j < 10; j++)
		{
			tempNumber = arrayA[i][j];
			arrayA[i][j] = arrayA[j][i];
			arrayA[j][i] = tempNumber;
		}
	}

	printf("\n\n");

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			printf("%d \t", arrayA[i][j]);
		}
		printf("\n");
	}
}