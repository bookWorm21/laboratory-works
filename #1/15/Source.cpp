#include <stdio.h>
#include <locale.h>

void main()
{
	setlocale(LC_ALL, "Rus");

	int a, b, c;
	printf("������� 1 ������� ������������\n");
	scanf_s("%d", &a);
	printf("������� 2 ������� ������������\n");
	scanf_s("%d", &b);
	printf("������� 3 ������� ������������\n");
	scanf_s("%d", &c);

	if (a + b > c && a + c > b && c + b > a)
	{
		if (a == b)
		{
			if (b == c)
			{
				printf("�������������� �����������\n");
			}
			else
			{
				printf("�������������� �����������\n");
			}
		}
		else if( b == c || a == c)
		{
			printf("�������������� �����������");
		}
		else
		{
			printf("�������������� �����������");
		}
	}
	else
	{
		printf("���������� ��������� �����������\n");
	}
}