#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <locale.h>

int HandlerArray(float* array, float leftBorder, float rightBorder, int n)
{
	int number = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (array[i * n + j] >= leftBorder && array[i * n + j] <= rightBorder)
			{
				number++;
			}
		}
	}
	return number;
}

int main(int argc, char* argv)
{
	setlocale(LC_ALL, "Rus");

	const int n = 10;
	int number;
	float left, right;

	printf("������� ����������  �����������");
	scanf_s("%d", &n);

	printf("������� ����� ������� ");
	scanf_s("%e", &left);
	printf("������� ������ ������� ");
	scanf_s("%e", &right);

	float array[n][n];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			array[i][j] = rand() % 100;
			printf("%f  ", array[i][j]);
		}
		printf("\n");
	}

	number = HandlerArray(&(array[0][0]), left, right, n);
	printf("\n���������� ����� � �������� ��������� - %d", number);

	return 0;
}