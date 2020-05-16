#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <malloc.h>
#include <locale.h>

void FindBorder(int* leftNumber, int* rightNumber, float number)
{
	*(leftNumber) = (int)number;
	*(rightNumber) = (int)number + 1;
}

int main(int argc, char* argv)
{
	setlocale(LC_ALL, "Rus");
	
	int leftNumber, rightNumber;
	float number;

	printf("Напишите ваше число  ");
	scanf_s("%e", &number);
	
	FindBorder(&leftNumber, &rightNumber, number);
	printf("Левая - %d, правая - %d", leftNumber, rightNumber);
	
	return 0;
}
