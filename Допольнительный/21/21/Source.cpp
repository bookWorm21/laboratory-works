#include <stdio.h>
#include <locale.h>

int main(int argc, char* argv[])
{
	float areaLeftX= -2;
	float areaRightX = 2;
	float areaDownY = -2;
	float areaUpY = 0;
	float x, y;
	int enought;
	
	char* locale = setlocale(LC_ALL, "");
	printf("������� ���������� ����� x ");
	scanf_s(" %f ", &x);

	printf("������� ���������� ����� x ");
	scanf_s(" %f ", &x);

	if ((x >= -2 && y >= x - 2) || (x < -2 && y >= x + 2) && (y <= 0)) printf("������");
	else printf("�� ������");

	return 0;
}