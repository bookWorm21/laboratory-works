#include <locale.h>
#include <stdio.h>

void function(float a, float* kvadrat, float* cube)
{
	*(kvadrat) = a * a;
	*(cube) = *(kvadrat)*a;
}
void main()
{
	setlocale(LC_ALL, "Rus");

	float a = 10.1f , kvadrat, cube;

	function(a, &kvadrat, &cube);
	printf("������� ����� - %f\n", kvadrat);
	printf("��� ����� - %f", cube);
}