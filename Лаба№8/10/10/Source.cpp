#include <string.h>
#include <locale.h>
#include <malloc.h>
#include <stdio.h>

char* AnalogStringHudler(char* str, int c)
{
	char* k = 0;
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == c)
		{
			k = str + i;
		}
	}
	
	return k;
}

int main(int argc, char* argv)
{
	setlocale(LC_ALL, "Rus");

	char str[10];
	printf("Введите строку ");
	fgets(str, 10, stdin);

	if (AnalogStringHudler(str, 'k') == strrchr(str, 'k'))
	{
		printf("Функция написана правильно ");
	}
	else
	{
		printf("Функция написана неправильно ");
	}
	return 0;
}