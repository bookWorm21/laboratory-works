#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <locale.h>
#include <math.h>

int IsSimple(int number)
{
	int isSimple = 1;
	for (int i = 2; i < number; i++)
	{
		if (number % i == 0)
		{
			i = number;
			isSimple = 0;
		}
	}
	return isSimple;
}

void SearchNeighbors(int* leftNeighbor, int* rightNeighbor, int number)
{
	*(leftNeighbor) = number - 1;
	*(rightNeighbor) = number + 1;
	
	while (IsSimple(*(leftNeighbor)) != 1)
	{
		(*(leftNeighbor))--;
	}

	while (IsSimple(*(rightNeighbor)) != 1)
	{
		(*(rightNeighbor))++;
	}
}

int main(int argc, char* argv)
{
	setlocale(LC_ALL, "Rus");
	int leftNeighbor, rightNeighbor, number;
	printf("Введите число ");
	scanf_s("%d", &number);
	SearchNeighbors(&leftNeighbor, &rightNeighbor, number);

	printf("Левое простое число - %d", leftNeighbor);
	printf("  Правое простое число - %d", rightNeighbor);

	return 0;
}