#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void main()
{
	const int n = 10;
	int mas[n];
	int count = 0;

	for (int i = 0; i < n; i++)
	{
		mas[i] = rand() % 10 - rand() % 15;
		printf("%d ", mas[i]);
		if (mas[i] > 0)
		{
			count++;
		}
	}
	printf("\n%d", count);
}