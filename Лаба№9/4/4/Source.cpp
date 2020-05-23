#include <stdio.h>
#include <locale.h>

typedef unsigned int natural;
typedef unsigned int(*twoNumberNunlder)(natural, natural);

natural Pow(natural base, natural index)
{
	natural sum = base;
	for (int i = 1; i < index; i++)
	{
		sum *= base;
	}
	return sum;
}

natural Multi(natural base, natural index)
{
	return base * index;
}

natural Modulo(natural base, natural index)
{
	return base % index;
}

natural IsAliquot(natural base, natural index)
{
	if (base % index == 0)
		return 1;
	else
		return 2;
}

int main(int argc, char* argv)
{
	setlocale(LC_ALL, "Rus");

	int firstNumber, secondNumber;
	int userInput = 1;
	twoNumberNunlder function[] = { Pow, Multi, Modulo, IsAliquot };
	printf("Выберите команду, нажав соответствующий номер\n");
	printf("Вводимые числа должны быть натуральными числами\n");

	while (userInput != 0)
	{
		printf("1 - возведение в степень\n");
		printf("2 - умножение двух чисел\n");
		printf("3 - вычисления остатка от деления\n");
		printf("4 - проверить на кратность\n");
		printf("5 - выход\n");
		scanf_s("%d", &userInput);

		if (userInput < 1 || userInput > 4)
		{
			if (userInput != 0)
				printf("Введите корректные данные");
		}
		else
		{
			printf("Введите 1 число\n");
			scanf_s("%d", &firstNumber);
			printf("Введите 2 число\n");
			scanf_s("%d", &secondNumber);
			
			if (secondNumber > 0 && firstNumber > 0)
			{
				printf("%d", (int)function[userInput - 1](firstNumber, secondNumber));
			}
			else
			{
				printf("Данные некорректны");
			}
		}
		printf("\n");
	}
	return 0;
}