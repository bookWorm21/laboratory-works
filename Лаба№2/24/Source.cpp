#include <stdio.h>
#include <locale.h>

void main()
{
	setlocale(LC_ALL, "Rus");

	int a, b;
	printf("\n������� ����� ����� ");
	scanf_s("%d", &a);
	printf("\n������� ������ ����� ");
	scanf_s("%d", &b);

	for (int i = a + 1; i < b; i++)
	{
		printf(" ��� %d ", i);
		for (int j = 1; j < i / 2; j++)
		{
			if (i % j == 0)
			{
				printf(" %d", j);
			}
		}
		printf("\n");
	}
}