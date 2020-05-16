#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char* argr[])
{
	setlocale(LC_ALL, "Rus");

	const int n = 10;
	float x, sum, number1, number2;
	float array[10];
	int max = 32000;

	printf(" ¬ведите число X ");
	scanf_s(" %e", &x);

	for (int i = 0; i < n; i++)
	{
		array[i] = rand() % 100;
		printf("%f\n", array[i]);
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			sum = (array[i] + array[j]) / 2;
			if ( fabs( (sum - x) ) < max)
			{
				max = fabs(sum - x);
				number1 = array[i];
				number2 = array[j];
			}
		}
	}

	printf(" \nƒва числа максимально близких к x - %f and %f", number1, number2 );

	return 0;
}