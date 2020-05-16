#include <stdio.h>
#include <malloc.h>
#include <locale.h>
#include <string.h>

char* AnalogHundler(char* str1, char* str2)
{
	char* k = 0;
	char* tempK = 0;
	int flag = 0;
	int tempI;

	for (int i = 0; str1[i] != '\0', flag == 0; i++)
	{
		flag = 1;

		if (str1[i] == str2[0])
		{
			tempK = &(str1[i]);
			tempI = i;
			i++;
			
			for (int j = 1; str2[j] != '\0' && str1[i] != '\0'; j++, i++)
			{
				if (str1[i] != str2[j])
				{
					flag = 0;
				}
			}

			if (flag)
			{
				k = tempK;
			}
			i = tempI;
		}
		else
		{
			flag = 0;
		}
	}

	return k;
}

int main(int argc, char* argv)
{
	setlocale(LC_ALL, "Rus");

	char str1[20] = "little youyour dog";
	char str2[5] = "your";

	if (strstr(str1, str2) == AnalogHundler(str1, str2))
	{
		printf("Функция написана правильно");
	}
	else
	{
		printf("Функия написана неправильно");
	}

	return 0;
}