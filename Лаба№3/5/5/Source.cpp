#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, char* argr[])
{
	const int n = 10;
	int k = 0;
	int array[n];

	for (int i = 0; i < n; i++)
	{
		array[i] = rand()% 100;
		printf(" %d", array[i]);
		if (array[i] >= 25 && array[i] <= 50)
		{
			k++;
		}
	}

	printf(" %d", k);

	return 0;
}