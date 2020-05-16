#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <locale.h>

char* DeleteElementInArray(char* array,int size, int number)
{
	char* tempArray = (char*)malloc(size * sizeof(char));

	for (int i = 0; i < number; i++)
	{
		tempArray[i] = array[i];
	}

	for (int i = number; i < size; i++)
	{
		tempArray[i] = array[i + 1];
	}

	return tempArray;
}

void DeleteWords(char* str, int size, char symbol, int* flags)
{
	int k = 0;
	for (int i = 0; i < size; i++)
	{
		if (str[i] == ' ')
		{
			for (int j = k; j < i; j++)
			{
				if (str[j] == symbol)
				{
					for (int l = k; l <= i; l++)
					{
						flags[l] = 1;
					}
					j = i;
				}
			}
			k = i + 1;
		}
	}
}

int main(int argc, char* argv)
{
	setlocale(LC_ALL, "Rus");

	int n;
	char symbol;
	printf("Введите длину строки ");
	scanf_s("%d", &n);
	getchar();
	char* str = (char*)malloc(n * sizeof(char));
	int* flags = (int*)malloc(n * sizeof(int));

	for (int i = 0; i < n; i++)
	{
		flags[i] = 0;
	}
	printf("Введите строку ");
	
	fgets(str, n, stdin);

	//printf("\nВведите символ ");
	symbol = 'a';

	puts(str);
	DeleteWords(str, n, symbol, flags);

	int size = n;
	for (int i = n - 1; i >= 0; i--)
	{
		if (flags[i] == 1)
		{
			str = DeleteElementInArray(str, size, i);
			size--;
		}
	}
	puts(str);

	return 0;
}