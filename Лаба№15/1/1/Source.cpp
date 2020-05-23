#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include "summer.h"

int main(int argc, char* argv)
{
#define circleArea(r) (r * r * 3.14159265f)
#define n 10
#if(n > 0)
	int array[n];
#endif

	setlocale(LC_ALL, "Rus");

	for (int i = 0; i < n; i++)
	{
		array[i] = rand() % 100 + 1;
		printf("%d ", array[i]);
	}
	printf("\n");

	float first = 5.0f;
	float second = 6.1f;

	printf("Сумма чисел, полученная из другого файла - %f\n", sum(first, second));

	float area = circleArea(first);
	printf("Площадь круга радиусом %f равен - %f\n", first, area);

	return 0;
}