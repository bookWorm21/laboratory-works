#include <string.h>
#include <locale.h>
#include <stdio.h>

char* Analog(char* str, int ch)
{
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == ch)
		{
			return &(str[i]);
		}
	}
	return NULL;
}

void main()
{
	setlocale(LC_ALL, "Rus");

	char str[20] = "kod is kood";

	if (strchr(str, 'g') == NULL)
		printf("null is base function\n");

	if (Analog(str, 'g') == NULL)
		printf("null is Analog");
	
	if (strchr(str, 'g') == Analog(str, 'g'))
	{
		printf("Функция реализована правильно");
	}
	else
	{
		printf("Функция реализована неправильно");
	}
}