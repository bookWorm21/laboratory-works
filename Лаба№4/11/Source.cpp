#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

void main()
{
	int const num = 5;
	int A[num][num];
	int summ = 0, multiple = 1;
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
		if (A[i][0] < 0)
		{
			for (int j = 0; j < num; j++)
			{
				if (A[i][j] > 0)
				{
					summ += A[i][j];
					multiple *= A[i][j];
				}
			}
		}
	}
	printf("%d\t%d", summ, multiple);

}