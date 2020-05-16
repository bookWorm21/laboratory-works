#include <stdio.h>
#include <locale.h>

int main(int argc, char* argv[])
{
	char* locale = setlocale(LC_ALL, "");
	int a, b, c, d, max;
	printf("Введите числа ");

	scanf_s("%d %d %d %d", &a, &b, &c, &d);

	if (a > b) max = a; else max = b;
	if (c > max) max = c; 
	if (d > max) max = d; 

	printf(" Максимальное число =  %d", max);

	return 0;
}