#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Rus");
	const int N = 5;
	int arrayA[N][N], arrayC[ N * N];
	int i = 0, j = 0, k = 0;
	int  count = N - 1;
	int operations;

	for ( i = 0; i < N; i++)
	{
		for ( j = 0; j < N; j++)
		{
			arrayA[i][j] = rand() % 10;
			printf("%d\t", arrayA[i][j]);
		}
		printf("\n");
	}

	j = 0;
	i = 0;

	while (count > 0)
	{
		for (operations = 0; operations < count; j++,operations++)
			arrayC[k++] = arrayA[i][j];
	
		for ( operations = 0; operations < count; i++,operations++)
			arrayC[k++] = arrayA[i][j];


		for (operations = 0; operations < count; j--,operations++)
			arrayC[k++] = arrayA[i][j];


		for (operations = 0; operations < count; i--,operations++)
			arrayC[k++] = arrayA[i][j];

		count -= 2;
		j++;
		i++;
	}

	if (N / 2 != 0)
	{
		arrayC[N*N - 1] = arrayA[ N / 2][ N / 2];
	}
	
	printf("\n\n");
	for (i = 0; i < N * N; i++)
	{
		printf("%d   ", arrayC[i]);
	}
}
