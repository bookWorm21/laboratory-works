#include <stdio.h>
#include <math.h>
#include <locale.h>

int main(int argc, char* argr[])
{
	float x = 9.1f, y = 10.0f;
	float z;

	while ((y - x) >= 0.0001)
	{
		z = (x + y) / 2;

		if ((z * z * z + z - 1000) * (x * x * x + x - 1000) > 0)
		{
			x = z;
		}
		else
		{
			y = z;
		}
	}

	printf("%f", z);
	
	return 0;
}