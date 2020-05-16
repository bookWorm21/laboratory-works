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
	int k = 2;

	for (int i = 0; i < n; i++)
	{
		*(array + i) = k;
		k *= 2;
	}

	for (int i = 0; i < n; i++)
	{
		printf("%d  ", *(array + i));
	}

	return 0;
}