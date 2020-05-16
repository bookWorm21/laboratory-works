#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int GuessNumber(int number)
{
	int userInput = 1;
	int userNumber;
	
	printf("���������� ����� ����� � ���������� �� %d �� %d \n", number / 10 * 10 , (number / 10 + 1) * 10);

	while (userInput != 0)
	{
		printf("�������� ��������, ������ ��������������� ����� \n");
		printf("1 - ���������� ���� \n");
		printf("0 - ����� \n");
		
		scanf_s("%d", &userInput);

		if (userInput == 0)
		{
			return 0;
		}
		else if (userInput == 1)
		{
			printf("���������� ������� ����� \n");
			
			while (scanf_s("%d", &userNumber) != 1 )
			{
				printf("����� ������� �����������\n");
				printf("������� ���������� �����\n");
				while (getchar() != '\n');
			}
			
			if (userNumber > number)
			{
				printf("���������� ����� ������ \n");
			}
			else if( userNumber < number)
			{
				printf("���������� ����� ������ \n");
			}
			else
			{
				printf("�� ������� �����!!! \n");
				return 1;
			}
		}
		else
		{
			printf("������� ���������� ������� \n");
		}

	}
	return 0;
}

int main(int argc, char* argv)
{
	setlocale(LC_ALL, "Rus");

	int x = rand() % 100;

	GuessNumber(x);

	return 0;
}