#include <stdio.h>
#include <locale.h>
#include <math.h>

int main(int argc, char* argr[])
{
	setlocale(LC_ALL, "Rus");

	float a = 0;
	float x, y;

	for (y = -2; y <= 1; y += 0.5)
	{
		for (x = -3; x <= 4; x += 0.2)
		{
			a = x * sin(y) + y * cos(x);
			printf("значение функции при x = %f, y = %f равно = %f", x, y, a);
			printf("\n");
		}
		printf("\n");
	}
}