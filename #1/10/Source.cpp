#include <stdio.h>
#include <locale.h>

void main()
{
	setlocale(LC_ALL, "Rus");

	int t;
	printf("������� �����������\n");
	scanf_s("%d", &t);
	if (t < 5)
		printf("�������");
	if (t >= 5 && t <= 10)
		printf("���������");
	if (t > 10 && t <= 20)
		printf("�����");
	if (t > 20)
		printf("�����");
}