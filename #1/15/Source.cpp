#include <stdio.h>
#include <locale.h>

void main()
{
	setlocale(LC_ALL, "Rus");

	int a, b, c;
	printf("Введите 1 сторону треугольника\n");
	scanf_s("%d", &a);
	printf("Введите 2 сторону треугольника\n");
	scanf_s("%d", &b);
	printf("Введите 3 сторону треугольника\n");
	scanf_s("%d", &c);

	if (a + b > c && a + c > b && c + b > a)
	{
		if (a == b)
		{
			if (b == c)
			{
				printf("Равносторонний треугольник\n");
			}
			else
			{
				printf("Равнобедренный треугольник\n");
			}
		}
		else if( b == c || a == c)
		{
			printf("Равнобедренный треугольник");
		}
		else
		{
			printf("Разносторонний треугольник");
		}
	}
	else
	{
		printf("Невозможно построить треугольник\n");
	}
}