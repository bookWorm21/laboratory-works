#include <locale.h>
#include <stdio.h>

float function(float a, float b)
{
	return a * b;
}
void main()
{
	setlocale(LC_ALL, "Rus");

	float a = 10, b = 15;

	printf("Площадь прямоугольника - %f", function(a, b));
}