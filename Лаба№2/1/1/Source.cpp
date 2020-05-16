#include <stdio.h>
#include <locale.h>

int main(int argc, char* argv[])
{
	int x = 1;
	float y;
	setlocale(LC_ALL, "Rus");

	for (; x < 9; x++)
	{
		printf("x=%d;  ", x);
		y = 3 * x * x + 2;
		printf("y=%f \n", y);
	}

	for (; x < 15; x++)
	{
		printf("x=%d;  ", x);
		y = x;
		printf("y=%f \n", y);
	}

	for (; x <= 20; x++)
	{
		printf("x=%d;  ", x);
		y = 5 / x - 8;
		printf("y=%f \n", y);
	}
	return 0;
}