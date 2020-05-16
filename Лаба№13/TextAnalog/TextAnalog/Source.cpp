#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

struct Book
{
	char authorName[20];
	char bookName[20];
	char officeHouse[20];
	int yearPublishing;
};

int WriteToTextFile(int* count)
{
	int n;
	int tempInt;
	char tempChar[15];

	printf("Введите количество элементов ");
	scanf_s("%d", &n);

	Book* books = (Book*)malloc(n * sizeof(Book));

	FILE* f;
	if (fopen_s(&f, "FT", "w"))
	{
		return -1;
	}

	for (int i = 0; i < n; i++)
	{
		while (getchar() != '\n');

		printf("Введите фамилию автора ");
		scanf_s("%15s", tempChar, 15);
		fprintf(f, "%15s", tempChar);

		while (getchar() != '\n');
		printf("Введите название книги ");
		scanf_s("%15s", tempChar, 15);
		fprintf(f, "%15s", tempChar);

		while (getchar() != '\n');
		printf("Введите название издательства ");
		scanf_s("%15s", tempChar, 15);
		fprintf(f, "%15s", tempChar);

		while (getchar() != '\n');
		printf("Год издания ");
		scanf_s("%d", &tempInt);
		fprintf(f, "%d", tempInt);

		*count = n;
	}

	fclose(f);
	return 0;
}

int WriteToScreen(int* k)
{
	FILE* f;
	Book tempTipeBook;
	char tempChar[15];

	if (fopen_s(&f, "FT", "r"))
	{
		return -1;
	}

	while (!feof(f))
	{
		fscanf_s(f, "%15s", tempChar, 15);
		printf("%15s", tempChar);
	}
	fclose(f);
	return 0;
}

int main(int argc, char* argv)
{
	setlocale(LC_ALL, "Rus");
	int count;

	int userInput = 1;
	while (userInput != 0)
	{
		printf("\nВыберите действие указав соответствующий номер команды");
		printf("\n1 - Запись в текстовый файл структур");
		printf("\n2 - Чтение из текстового файла структуры");
		printf("\n0 - Выход");
		scanf_s("%d", &userInput);
		
		switch (userInput)
		{
		case 1:
			WriteToTextFile(&count);
			break;
		case 2:
			WriteToScreen(&count);
			break;
		case 0:
			break;
		default:
			printf("Некорректный ввод");
			break;
		}
		while( getchar() != '\n')
		{ }
	}
	return 0;
}