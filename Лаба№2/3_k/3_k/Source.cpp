#include <stdio.h>
#include <locale.h>

void main()
{
	setlocale(LC_ALL, "Rus");

	int count = 0, sum = 0, number;
	printf("Введите число\n ");
	scanf_s("%d", &number);

	while (number != 0)
	{
		count++;
		sum += number;
		printf("Введите число\n ");
		scanf_s("%d", &number);
	}
	printf("Среднее арифмитическое = %d", sum / count);
}