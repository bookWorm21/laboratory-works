#include <stdio.h>

int main(int argc, char* argv[])
{
	int number;
	printf("������� ����� ������");
	scanf_s("%d", &number);

	switch (number)
	{
	case 4: 
	case 6:
	case 9:
	case 11:
		printf("� ������ 30 ����"); 
		break;
	case 2: 
		printf("� ������ 28 ����"); 
		break;
	default: 
		printf("� ������ 31 ����"); 
		break;
	}
	return 0;
}