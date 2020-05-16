#include <stdio.h>
#include <locale.h>
#include <math.h>

int main(int argc, char* argv[])
{
	float y;

	for ( float x = 9.1f; x <= 10; x += 0.0001f)
	{
		y = pow(x,3) + x - 1000;
		y *= 10000;
		y = rint(y);
		y = y/10000;
		
			printf(" %f \n", y);
	}
	return 0;
}