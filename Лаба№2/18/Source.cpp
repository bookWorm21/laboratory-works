#include <locale.h>
#include <stdio.h>

void main()
{
	setlocale(LC_ALL, "Rus");

	char a, b;
	int count = 0;

	printf("������� ������ ");
	scanf_s("%c", &a, 1);

	while (a != '.')
	{
		while (getchar() != '\n');
		b = a;
		printf("������� ������ ");
		scanf_s("%c", &a, 1);

		if (b == 'n' && a == 'o')
		{
			count++;
		}
	}
	printf("\nno ����������� %d ���", count);
}