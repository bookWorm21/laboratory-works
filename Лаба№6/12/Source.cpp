#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <locale.h>

void Calendared(int* day, int* month, int numberDay)
{
	int m, k;
	for (int i = 1; numberDay > 0; i++)
	{
		switch (i)
		{
		case 2: 
			if (numberDay - 28 < 0)
			{
				*(day) = numberDay;
				*(month) = i;
			}
			numberDay -= 28;
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			if (numberDay - 30 <  0)
			{
				*(month) = i;
				*(day) = numberDay;
			}
			numberDay -= 30;
			break;
		default:
			if (numberDay - 31 < 0)
			{
				*(month) = i;
				*(day) = numberDay;
			}
			numberDay -= 31;
			break;
		}
	}
}
int main(int argc, char* argv)
{
	setlocale(LC_ALL, "Rus");
	
	int days, day, month;
	printf("Введите номер дня ");
	scanf_s("%d", &days);

	Calendared( &day, &month, days);

	printf(" Номер месяца - %d", month);
	printf(" День - %d", day);

	return 0;
}