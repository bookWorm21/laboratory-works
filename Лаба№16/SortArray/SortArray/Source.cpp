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
	int countTrans = 0;

	for (int i = 1; i < n; i++)
	{
		for (int j = i; j > 0 && array[j - 1] > array[j]; j--)
		{
			temp = array[j - 1];
			array[j - 1] = array[j];
			array[j] = temp;
			countTrans++;
		}
	}

	printf("Number of permutations - %d\n", countTrans);
}

void InclusionSort(int* array, int n)
{
	int left, right, mean, current;
	int countTrans = 0;

	for (int i = 1; i < n; i++)
	{
		if (array[i - 1] > array[i])
		{
			current = array[i];
			left = 0;
			right = i - 1;

			while (left <= right)
			{
				mean = (left + right) / 2;

				if (array[mean] < current)
					left++;
				else
					right--;
			}

			for (int j = i - 1; j >= left; j--)
			{
				array[j + 1] = array[j];
				countTrans++;
			}

			array[left] = current;
		}
	}

	printf("Number of permutations - %d\n", countTrans);
}

int QuickSort(int* array, int left, int right, int isGeneral)
{
	int countTrans = 0;
	int pivot;
	int startLeft = left;
	int startRight = right;
	pivot = array[left];
	
	while (left < right)
	{
		while (array[right] >= pivot && (left < right))
			right--;
		
		if (left != right)
		{
			array[left] = array[right];
			left++;
			countTrans++;
		}

		while (array[left] <= pivot && (left < right))
			left++;

		if (left != right)
		{
			array[right] = array[left];
			right--;
			countTrans++;
		}
	}

	array[left] = pivot;
	pivot = left;
	left = startLeft;
	right = startRight;

	if (left < pivot)
		countTrans += QuickSort(array, left, pivot - 1, 0);

	if (pivot < right)
		countTrans += QuickSort(array, pivot + 1, right, 0);
	
	if(isGeneral)
		printf("Number of permutations - %d\n", countTrans);

	return countTrans;
}

void ShellSort(int* array, int n)
{
	int step = 31;
	int current;
	int index;
	int countTrans = 0;

	while (step > 0)
	{
		for (int i = 0; i < n; i++)
		{
			index = i;
			current = array[i];

			while ((index >= step) && (array[index - step] > current))
			{
				countTrans++;
				array[index] = array[index - step];
				index -= step;
			}
			array[index] = current;
		}

		if (step > 1)
			step = step / 2 - 1;
		else
			break;
	}

	printf("Number of permutations - %d\n", countTrans);
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

	const int n = 100000;
	int array[n];
	
	printf("\n");
	printf("Bubble:\n");
	t = GetTickCount();
	FillArray(array, n);
	Bubble(array, n);
	t = GetTickCount() - t;
	printf("time - %ld \n", t);

	printf("\n");
	printf("Shaker:\n");
	t = GetTickCount();
	FillArray(array, n);
	Shaker(array, n);
	t = GetTickCount() - t;
	printf("time - %ld \n", t);

	printf("\n");
	printf("Choice:\n");
	t = GetTickCount();
	FillArray(array, n);
	ChoiceSort(array, n);
	t = GetTickCount() - t;
	printf("time - %ld \n", t);

	printf("\n");
	printf("Insertion:\n");
	t = GetTickCount();
	FillArray(array, n);
	InsertionSort(array, n);
	t = GetTickCount() - t;
	printf("time - %ld \n", t);

	printf("\n");
	printf("Inclusion:\n");
	t = GetTickCount();
	FillArray(array, n);
	InclusionSort(array, n);
	t = GetTickCount() - t;
	printf("time - %ld \n", t);

	printf("\n");
	printf("Quick:\n");
	t = GetTickCount();
	FillArray(array, n);
	QuickSort(array, 0 , n - 1, 1);
	t = GetTickCount() - t;
	printf("time - %ld \n", t);
	
	printf("\n");
	printf("Shell: \n");
	t = GetTickCount();
	FillArray(array, n);
	ShellSort(array, n);
	t = GetTickCount() - t;
	printf("time - %ld \n", t);
	return 0;
}