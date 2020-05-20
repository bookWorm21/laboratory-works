#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void main()
{
	setlocale(LC_ALL, "Rus");

	const int n = 10;

	int array[n];
	int flags[n];

	int naydeno = 0;
	int count = 0;

	for (int i = 0; i < n; i++)
	{
		flags[i] = 0;
	}

	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &array[i]);
		printf("%d ", array[i]);
	}

	for (int i = 0; i < n; i++)
	{
		if (flags[i] == 0)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (array[i] == array[j])
				{
					flags[j] = 1;
					naydeno = 1;
				}
			}
			if (naydeno == 0)
			{
				count++;
			}
			naydeno = 0;
		}
	}

	printf("\n%d", count);
}