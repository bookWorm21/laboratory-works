#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

void main()
{
	const int n = 5;
	int mas[n];
	int sum = 0;

	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &mas[i]);
		printf("%d ", mas[i]);
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			sum += abs(mas[i] - mas[j]);
		}
	}

	printf("\n%d", sum);
}