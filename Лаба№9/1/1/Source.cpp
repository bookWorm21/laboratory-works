#include <stdio.h>
#include <locale.h>

typedef int (*studyFinction)(int);

int f1(int x)
{
	return 2 * x;
}

int f2(int x)
{
	return 5 + 12 * x;
}

int f3(int x)
{
	return 7 - x;
}

int f4(int x)
{
	return 5 * x - 32;
}

int f5(int x)
{
	return 7 * (1 - x);
}

int f6(int x)
{
	return 15 - 4 * x;
}

int f7(int x)
{
	return (5 - x) / x;
}

int function(int (*first)(int), int (*second)(int), int x)
{
	return first(x) - second(x);
}

int TwoFunctionHundler(studyFinction first, studyFinction second, int x)
{
	return first(x) - second(x);
}

int main(int argc, char* argv)
{
	setlocale(LC_ALL, "Rus");

	int number;
	printf("Введите число\n");
	scanf_s("%d", &number);

	printf("Результат функции с пользовательским типом - %d\n", TwoFunctionHundler(f1, f2, number));
	printf("Результат обычной функции - %d", TwoFunctionHundler(f1, f2, number));
	
	return 0;
}