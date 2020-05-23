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
	printf("�������� �������, ����� ��������������� �����\n");
	printf("�������� ����� ������ ���� ������������ �������\n");

	while (userInput != 0)
	{
		printf("1 - ���������� � �������\n");
		printf("2 - ��������� ���� �����\n");
		printf("3 - ���������� ������� �� �������\n");
		printf("4 - ��������� �� ���������\n");
		printf("5 - �����\n");
		scanf_s("%d", &userInput);

		if (userInput < 1 || userInput > 4)
		{
			if (userInput != 0)
				printf("������� ���������� ������");
		}
		else
		{
			printf("������� 1 �����\n");
			scanf_s("%d", &firstNumber);
			printf("������� 2 �����\n");
			scanf_s("%d", &secondNumber);
			
			if (secondNumber > 0 && firstNumber > 0)
			{
				printf("%d", (int)function[userInput - 1](firstNumber, secondNumber));
			}
			else
			{
				printf("������ �����������");
			}
		}
		printf("\n");
	}
	return 0;
}