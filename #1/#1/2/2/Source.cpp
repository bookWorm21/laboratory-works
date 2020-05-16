#include <stdio.h>
#include <locale.h>


int main(int argc, char* argv[])
{
	char* locale = setlocale(LC_ALL, "");

	int x;
	printf(" Введите ваш возраст "); 
	scanf_s("%d", &x);

	if ((x >= 1) && (x <= 3)) printf("в ясли");
	if ((x >= 4) && (x <= 6)) printf("в детский сад");
	if ((x >= 7) && (x <= 16)) printf("в школу");
	if (x > 16) printf(" закончил школу");

	return 0;
}