#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <Windows.h>

void Bubble(int* array, int n)
{
	int count = 0;
	int k = 0;
	int temp;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (array[i] > array[j])
			{
				k = 1;
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				count++;
			}
		}
		if (k == 0)
		{
			printf("Number of permutations - %d\n", count);
			return;
		}

		k = 0;
	}
	printf("Number of permutations - %d\n", count);
}

void Shaker(int* array, int n)
{
	int left = 0, right = n - 1;
	int isTrans = 1;
	int temp;
	int count = 0;

	while (left < right && isTrans > 0)
	{
		isTrans = 0;

		for (int i = 0; i < right; i++)
		{
			if (array[i] > array[i + 1])
			{
				isTrans = 1;
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				count++;
			}
		}
		right--;

		for (int i = right; i > left; i--)
		{
			if (array[i - 1] > array[i])
			{
				isTrans = 1;
				temp = array[i];
				array[i] = array[i - 1];
				array[i - 1] = temp;
				count++;
			}
		}
		left++;
	}

	printf("Number of permutations - %d\n", count);
}

void ChoiceSort(int* array, int n)
{
	int min;
	int count = 0;
	int number;

	for (int i = 0; i < n; i++)
	{
		min = array[i];
		number = i;
		for (int j = i + 1; j < n; j++)
		{
			if (array[j] < min)
			{
				min = array[j];
				number = j;
			}
		}
		array[number] = array[i];
		array[i] = min;
		count++;
	}
	printf("Number of permutations - %d\n", count);
}

void InsertionSort(int* array, int n)
{
	int temp;

	for (int i = 1; i < n; i++)
	{
		for (int j = i; j > 0 && array[j - 1] > array[j]; j--)
		{
			temp = array[j - 1];
			array[j - 1] = array[j];
			array[j] = temp;
		}
	}
}
void InputArray(int* array, int n)
{
	for (int i = 0; i < n; i++)
		printf("%d ", array[i]);
}

void FillArray(int* array, int n)
{
	srand(8);
	for (int i = 0; i < n; i++)
		array[i] = rand() % 101;
}
int main(int argc, char* argv)
{
	setlocale(LC_ALL, "Rus");
	printf("Sort array\n");
	long t;

	const int n = 10;
	int array[n];
	
	t = GetTickCount();
	FillArray(array, n);
	Bubble(array, n);
	t = t - GetTickCount();
	printf(" %ld \n", t);

	t = GetTickCount();
	FillArray(array, n);
	Shaker(array, n);
	t = t - GetTickCount();
	printf(" %ld \n", t);

	t = GetTickCount();
	FillArray(array, n);
	ChoiceSort(array, n);
	t = t - GetTickCount();
	printf(" %ld \n", t);

	t = GetTickCount();
	FillArray(array, n);
	InsertionSort(array, n);
	InputArray(array, n);
	t = t - GetTickCount();
	printf(" %ld \n", t);

	t = GetTickCount();
	FillArray(array, n);
	Bubble(array, n);
	t = t - GetTickCount();
	printf(" %ld \n", t);

	t = GetTickCount();
	FillArray(array, n);
	Bubble(array, n);
	t = t - GetTickCount();
	printf(" %ld \n", t);

	t = GetTickCount();
	FillArray(array, n);
	Bubble(array, n);
	t = t - GetTickCount();
	printf(" %ld \n", t);

	return 0;
}