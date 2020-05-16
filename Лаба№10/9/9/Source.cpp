#include <stdio.h>
#include <malloc.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

struct T
{
	char** str;
	int* number;
} x;

int main(int argc, char* argv)
{
	setlocale(LC_ALL, "Rus");

	struct T mas[4];

	char* str;

	for (int i = 0; i < 4; i++)
	{
		int* size = (int*)malloc(sizeof(int));

		printf("Введите количество символов в строке ");
		scanf_s("%d", size);
		getchar();
		mas[i].number = size;

		mas[i].str = (char**)malloc(1 * sizeof(char*));
		*(mas[i].str) = (char*)malloc(*(size) * sizeof(char));
		printf("Введите строку ");
		fgets( *(mas[i].str), *(size) + 1, stdin);
	}

	printf("\n\n");

	for (int i = 0; i < 4; i++)
	{
		printf(" Структура типа T элемент №%d, %s, %d \n", i, *(mas[i].str), *(mas[i].number));
	}

	return 0;
}

