#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <locale.h>

int Calculate(int a, int b, int h)
{
	return a * b * h;
}
int main(int argc, char* argv)
{
	setlocale(LC_ALL, "Rus");
	int  a, b, h;
	printf("������� ����� ");
	scanf_s("%d", &a);
	printf("������� ������ ");
	scanf_s("%d", &b);
	printf("������� ������ ");
	scanf_s("%d", &h);

	printf("����� ������������� - %d", Calculate(a, b, h));
	return 0;
}