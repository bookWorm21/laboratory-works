#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <math.h>

int main(int argc, char* argr[])
{
	setlocale(LC_ALL, "Rus");

	float element, p;
	float x;
	int k = 1;
	int z = -1;

	scanf_s("%e", &x);
	float sum = x / 2;

	p = x * x;
	element = x * p / 3;

	for (int i = 2; element > 0.0001; i++)
	{
		
		element = x * p / (i - 1) / (i + k);
		sum += element * z;
		p = p * x * x;
		k += 1;
		z *= -1;
	}

	printf(" %f ", sum);

	return 0;
}