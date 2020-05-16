#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Rus");

	int arrayC[6][6], arrayB[6][6], arrayResult[6][6];

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			arrayC[i][j] = rand() % 100;
			arrayB[i][j] = rand() % 100;

			if (arrayC[i][j] > arrayB[i][j])
			{
				arrayResult[i][j] = arrayB[i][j];
			}
			else
			{
				arrayResult[i][j] = arrayC[i][j];
			}

			printf("%d\t", arrayResult[i][j]);
		}
		printf("\n");
	}

}