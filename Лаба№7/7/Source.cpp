#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <locale.h>

int HandlerArray(float** array, float leftBorder, float rightBorder, int line, int column)
{
	int number = 0;

	for (int i = 0; i < line; i++)
	{
		for (int j = 0; j < column; j++)
		{
			if (array[i][j] >= leftBorder && array[i][j] <= rightBorder)
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
	int line, column;
	int number;
	float leftBorder, rightBorder;

	printf("������� ���������� ������� ");
	scanf_s("%d", &line);
	printf("������� ���������� �������� ");
	scanf_s("%d", &column);

	printf("������� ����� ������� ");
	scanf_s("%e", &leftBorder);
	printf("������� ������ ������� ");
	scanf_s("%e", &rightBorder);

	float** array = (float**)malloc(line * sizeof(float*));

	for (int i = 0; i < line; i++)
	{
		array[i] = (float*)malloc(column * sizeof(float));
	}

	for (int i = 0; i < line; i++)
	{
		for (int j = 0; j < column; j++)
		{
			array[i][j] = (float)(rand() % 10);
			printf("%f  ", array[i][j]);
		}
		printf("\n");
	}

	number = HandlerArray(array, leftBorder, rightBorder, line, column);
	printf("\n���������� ����� � �������� ��������� - %d", number);

	for (int i = 0; i < line; i++)
	{
		free(array[i]);
	}

	free(array);

	return 0;
}