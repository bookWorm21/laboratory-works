#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int main(int argc, char* argr[])
{
	setlocale(LC_ALL, "Rus");

	const int n = 20;
	float array[n];
	int NumberArray[n];
	int k = 0;

	for (int i = 0; i < n; i++)
	{
		NumberArray[i] = 1;
	}

	for (int i = 0; i < n; i++)
	{
		array[i] = (float)(rand() % 10) / (rand() % 20) ;
		printf("%f  \n", array[i]);
	}

	for (int i = 0; i < n; i++)
	{
		if (NumberArray[i])
		{
			for (int j = i + 1; j < n; j++)
			{
				if (array[i] == array[j])
				{
					k++;
					NumberArray[j] = 0;
				}
			}

			printf(" \nЭлемент %f встречается %d раз", array[i], k);
			k = 1;
		}
	}
		
	return 0;
}