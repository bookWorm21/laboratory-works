#include <stdio.h>
#include <locale.h>
#include <malloc.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int StringHundler(const char* str)
{
	int sum = 0;
	int k = 0;
	int isNumber = 1;

	for (int i = 0; str[i] != '\0'; i++)
	{
		if (isspace(str[i]))
		{
			if (k != 0 && isNumber)
			{
				char* tempStr = (char*)malloc(k * sizeof(char));
				strncpy_s(tempStr, (k + 1) * sizeof(char), str + i - k, k * sizeof(char));
				sum += atoi(tempStr);
			}
			k = 0;
		}
		else
		{
			k++;

			if (isdigit(str[i]) == false)
			{
				isNumber = 0;
			}
		}
		isNumber = 1;
	}

	return sum;
}

int main(int argc, char* argv)
{
	char str[100] = "1 2 3 4 12 user track5";

	printf("%d", StringHundler(str));

	return 0;
}