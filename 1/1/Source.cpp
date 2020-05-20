#include <stdio.h>

void main()
{
	int number = 1594;
	
	int a = number % 10;
	int b = number % 100 / 10;
	int c = number / 100 % 10;
	int d = number / 1000;

	printf("summa chisel - %d", a + b + c + d);
}