#include <stdio.h>
#include <locale.h>

void main()
{
	setlocale(LC_ALL, "Rus");

	int t;
	printf("Введите температуру\n");
	scanf_s("%d", &t);
	if (t < 5)
		printf("Холодно");
	if (t >= 5 && t <= 10)
		printf("Прохладно");
	if (t > 10 && t <= 20)
		printf("Тепло");
	if (t > 20)
		printf("Жарко");
}