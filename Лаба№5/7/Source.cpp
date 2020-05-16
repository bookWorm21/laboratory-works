#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <locale.h>

int main(int argc, char* argv)
{
	setlocale(LC_ALL, "Rus");
	int n, temp;
	printf("¬ведите количество элементов массива  ");
	scanf_s("%d", &n);
	int* array = (int*)malloc(n * sizeof(int));

	for (int i = 0; i < n; i++)
	{
		array[i] = rand() % 100;
		printf("%d  ", array[i]);
	}
	printf("\n");

	for (int i = 0; i < n - 1; i += 2)
	{
		temp = array[i + 1];
		array[i + 1] = array[i];
		array[i] = temp;
	}

	for (int i = 0; i < n; i++)
	{
		printf("%d  ", array[i]);
	}
	printf("\n");

	return 0;
}