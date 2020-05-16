#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(int argc, char* argv)
{
	setlocale(LC_ALL, "Rus");
	
	const int n = 5;
	int A[n][n];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			A[i][j] = rand() % 50;
			printf("%d  ", A[i][j]);
		}
		printf("\n");
	}

	printf("\n");
	for (int j = 0; j < n; j++)
	{
		A[3][j] *= 2;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d  ", A[i][j]);
		}
		printf("\n");
	}


	return 0;
}