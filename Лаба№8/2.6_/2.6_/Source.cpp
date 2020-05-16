#include <stdio.h>
#include <locale.h>
#include <malloc.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void StringHundler(char* str)
{
	int isNumber;
	
	char step = ' ';
	char* next = NULL;
	str = strtok_s(str, " ", &(next));

	while (str != NULL)
	{
		isNumber = 0;

		for (int i = 0; str[i] != '\0'; i++)
		{
			if (isdigit(str[i]))
			{
				isNumber = 1;
			}
		}

		if (isNumber)
		{
			puts(str);
		}

		str = strtok_s(NULL, " ", &(next));
	}
}

int main(int argc, char* argv)
{
	char str[100] = "1 2 3 4 12 user track5";

	StringHundler(str);

	return 0;
}