#include <locale.h>
#include <stdio.h>

void function(int a, int b, int c, int* max, int* min)
{
	if (b > c)
	{
		if (a > b)
			*(max) = a;
		
		else
			*(max) = b;
	}
	else
	{
		if (a > c)
			*(max) = a;
		else
			*(max) = c;
	}

	if (b < c)
	{
		if (a < b)
			*(min) = a;
		else
			*(min) = b;
	}
	else
	{
		if (a < c)
			*(min) = a;
		else
			*(min) = c;
	}
}
void main()
{
	setlocale(LC_ALL, "Rus");

	int a, b, c;
	int max, min;

	printf("������ 1 �����\n");
	scanf_s("%d", &a);

	printf("������ 2 �����\n");
	scanf_s("%d", &b);

	printf("������ 3 �����\n");
	scanf_s("%d", &c);

	function(a, b, c, &max, &min);
	printf("Max = %d \n", max);
	printf("Min = %d", min);
}