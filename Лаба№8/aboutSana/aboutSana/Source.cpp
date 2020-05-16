#include <iostream>
#include "stdio.h"
#include <windows.h>
#include <string.h>

int Counter(char* str)
{
	int l = 0;
	for (int i = 0; str[i] != '\0'; i++) l++;

	return l;
}

char* s(char* s1, const char* s2, size_t n)		
{
	size_t i;
	int l = 0;
	l = Counter(s1);

	for (i = 0; i < n && s1[i] != '\0'; i++)
		s1[l + i] = s2[i];
	s1[l + i] = '\0';
	return s1;
}

int main()
{
	setlocale(LC_ALL, "rus");
	char tempStr[30] = "Good";
	char s1[30] = "Good";
	char s2[30] = "job";
	printf("Первая строка - %s", s1);
	printf("\nВторая строка - %s", s2);

	int n;
	printf("\nВведите количество объединяемых символов - ");
	scanf_s("%d", &n);

	s(tempStr, s2, n);
	printf("\nПервая строка после объединения со второй -%s", tempStr);

	strncat_s(s1, s2, n);				
	printf("\nПри использовании функции - %s", s1);
	scanf_s("%d");
}