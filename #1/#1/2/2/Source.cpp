#include <stdio.h>
#include <locale.h>


int main(int argc, char* argv[])
{
	char* locale = setlocale(LC_ALL, "");

	int x;
	printf(" ������� ��� ������� "); 
	scanf_s("%d", &x);

	if ((x >= 1) && (x <= 3)) printf("� ����");
	if ((x >= 4) && (x <= 6)) printf("� ������� ���");
	if ((x >= 7) && (x <= 16)) printf("� �����");
	if (x > 16) printf(" �������� �����");

	return 0;
}