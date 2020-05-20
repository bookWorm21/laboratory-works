#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

void main()
{
	int const num = 10;
	int A[num][num];
	int count = 0;
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
		{
			A[i][j] = rand() % 80 - 30;
			printf("\t%d", A[i][j]);
		}
		printf("\n");
	}
	for (int i = 0; i < num; i++)
	{
		for (int j = i; j < num - i; j++)
		{
			if (A[i][j] < 0)
				count++;
		}
	}
	printf("%d", count);

}