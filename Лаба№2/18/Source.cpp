#include <locale.h>
#include <stdio.h>

void main()
{
	setlocale(LC_ALL, "Rus");

	char a, b;
	int count = 0;

	printf("Введите символ ");
	scanf_s("%c", &a, 1);

	while (a != '.')
	{
		while (getchar() != '\n');
		b = a;
		printf("Введите символ ");
		scanf_s("%c", &a, 1);

		if (b == 'n' && a == 'o')
		{
			count++;
		}
	}
	printf("\nno встречается %d раз", count);
}