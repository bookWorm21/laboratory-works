#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <locale.h>

int main(int argc, char* argv)
{
	setlocale(LC_ALL, "Rus");
	int n;
	printf("¬ведите количество элементов массива  ");
	scanf_s("%d", &n);
	int* array = (int*)malloc(n * sizeof(int));

	for (int i = 0; i < n; i++)
	{
		array[i] = rand() % 100;
		printf("%d  ", array[i]);
		if (i % 2 != 0)
		{
			array[i] *= 2;
		}
		printf("%d  ", array[i]);
		printf("\n");
	}

	return 0;
}