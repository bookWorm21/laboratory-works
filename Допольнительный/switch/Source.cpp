#include <stdio.h>

int main(int argc, char* argv[])
{
	int number;
	printf("¬ведите номер мес€ца");
	scanf_s("%d", &number);

	switch (number)
	{
	case 4: 
	case 6:
	case 9:
	case 11:
		printf("¬ мес€це 30 дней"); 
		break;
	case 2: 
		printf("¬ мес€це 28 дней"); 
		break;
	default: 
		printf("¬ мес€це 31 дней"); 
		break;
	}
	return 0;
}