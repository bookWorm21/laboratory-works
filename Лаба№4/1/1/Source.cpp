#include <stdio.h>

void main()
{
	int const num = 10;
	int mass[num][num] = { 0 };
	for (int i = 0; i < num; i++)
		mass[i][i] = i;
	for (int i = 0; i < num; i++)
	{
		printf("\n");
		for (int j = 0; j < num; j++)
			printf(" %d", mass[i][j]);
	}
}
