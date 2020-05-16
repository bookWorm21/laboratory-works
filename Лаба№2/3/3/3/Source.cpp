#include <stdio.h>
#include <math.h>
#include <locale.h>

int main(int argc, char* argr[])
{
	setlocale(LC_ALL, "Rus");

	int day, month, lastDays = 0;

	printf("¬ведите день ");
	scanf_s(" %d", &day);

	printf("¬ведите номер мес€ца ");
	scanf_s(" %d", &month);
	
	for (int i = 1; i < month; i++)
	{
		switch (i)
		{
		case 2: 
			lastDays += 29;
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			lastDays += 30;
			break;
		default:
			lastDays += 31;
			break;
		}
	}
	

	lastDays += day - 1;

	printf(" ѕрошло - %d", lastDays);

	return 0;
}