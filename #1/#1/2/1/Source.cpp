#include <stdio.h>

class myDad
{

};

int main(int argc, char* argv[])
{
	int x;
	int enought;
	printf("Write number ");
	x = scanf_s(" x= %d", &x);

	enought = (x % 10 + x % 100 / 10) == (x / 1000 + x / 100 % 10);
	if (enought) printf("true"); else printf("false");

	return 0;
}
