#include <stdio.h>
#include <locale.h>
#include <malloc.h>
#include <string.h>

int number(char* str)
{
	int count = 0;

	while (str[count] != '\0')
	{
		count++;
	}

	return count - 1;
}
char* StringFunction(char* str)
{
	char* last = strrchr(str, ' ') + 1;
	char* result = (char*)malloc(80 * sizeof(char));
	int count1 = number(last);//при использовании strlen копируетс€ символ переноса строки
	int count2 = number(str);
	memcpy(result, last, count1);
	memcpy(result + count1, " ", 1);
	memcpy(result  +count1 + 1, str, count2 - count1);
	result[count2] = '\0';
	return result;
}

void main()
{
	setlocale(LC_ALL, "Rus");

	char* str = (char*)malloc(80 * sizeof(char));
	printf("¬ведите строку\n");
	fgets(str, 80, stdin);
	str = StringFunction(str);
	printf("%s", str, 20);
}