#include <stdio.h>
#include <locale.h>

void main()
{
	setlocale(LC_ALL, "Rus");

	int n;
	printf("������� ���������� �����\n");
	scanf_s("%d", &n);
	int number, count = 0;
	for (int i = 0; i < n; i++)
	{
		printf("������� �����\n");
		scanf_s("%d", &number);
		if (number < 0)
		{
			count++;
		}
	}
	printf("������������� - %d", count);
}