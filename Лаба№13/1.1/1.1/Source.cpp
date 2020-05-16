#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <locale.h>

struct Book
{
	char authorName[20];
	char bookName[20];
	char officeHouse[20];
	int yearPublishing;
};

int WriteToFile(int* count)
{
	int n;

	printf("������� ���������� ��������� ");
	scanf_s("%d", &n);

	Book* books = (Book*)malloc(n * sizeof(Book));

	FILE* f;
	if (fopen_s(&f, "FB", "w"))
	{
		return -1;
	}

	for (int i = 0; i < n; i++)
	{
		while (getchar() != '\n');

		printf("������� ������� ������ ");
		fgets(books[i].authorName, 15, stdin);

		printf("������� �������� ����� ");
		fgets(books[i].bookName, 15, stdin);

		printf("������� �������� ������������ ");
		fgets(books[i].officeHouse, 15, stdin);

		printf("��� ������� ");
		scanf_s("%d", &books[i].yearPublishing);

		fwrite(&books[i], sizeof(Book), 1, f);
		*count = n;
	}

	fclose(f);
	return 0;
}

int WriteToScreen(int *k)
{
	FILE* f;
	Book tempTipeBook;
	if (fopen_s(&f, "FB", "r"))
	{
		return -1;
	}
	
	fread(&tempTipeBook, sizeof(Book), 1, f);

	while (!feof(f))
	{
		printf("%15s", tempTipeBook.authorName);
		printf("%15s", tempTipeBook.bookName);
		printf("%15s", tempTipeBook.officeHouse);
		printf("%d", tempTipeBook.yearPublishing);
		fread(&tempTipeBook, sizeof(Book), 1, f);
	}
	fclose(f);
	return 0;
}

int ReachCountBook(int year)
{
	int count = 0;

	FILE* f;
	Book tempTipeBook;
	if (fopen_s(&f, "FB", "r"))
	{
		return -1;
	}

	fread(&tempTipeBook, sizeof(Book), 1, f);
	while (!feof(f))
	{
		if (tempTipeBook.yearPublishing == year)
		{
			count++;
		}

		fread(&tempTipeBook, sizeof(Book), 1, f);
	}
	fclose(f);
	return count;
}

void ChangedAuthor(int number)
{
	FILE* f;
	Book tempBook;
	int k;;

	if(!(fopen_s(&f, "FB", "r+")))
	{
		k = fseek(f, (number - 1) * sizeof(Book), SEEK_SET);
		if (k == 0)
		{
			fread(&tempBook, sizeof(Book), 1, f);
			printf("\n������� ������������ ��� ������ ");
			while (getchar() != '\n');
			fgets(tempBook.authorName, 20, stdin);
	
			fseek(f, (number - 1) * sizeof(Book), SEEK_SET);
			fwrite(&tempBook, sizeof(Book), 1, f);
		}
		fclose(f);
	}
}

int main(int argc, char* argv)
{
	setlocale(LC_ALL, "Rus");

	int countSymbol;
	int year = 1922;
	int userInput = 1;
	int isPresenceData = 0;
	int countRecord = 0;

	while (userInput != 0)
	{
		printf("\n�������� �������, ������ �������������� �����\n");
		printf("0 - �����\n");
		printf("1 - ������ ������ � ������\n");
		printf("2 - ����� ���������� �� �����\n");
		printf("3 - ��������� ���������� ���� ������ ���� �������\n");
		printf("4 - �������� ���������� �� ������\n");

		if (scanf_s("%d", &userInput) > 0)
		{
			switch (userInput)
			{
			case 1:
				WriteToFile(&countRecord);
				break;
			case 2:
				WriteToScreen(&countSymbol);
				break;
			case 3:
				printf("������� ��� ");
				scanf_s("%d", &year);
				printf("���������� ���� - %d", ReachCountBook(year));
				break;
			case 4: 
			{
				printf("������� ���������� ����� ����� ");
				scanf_s("%d", &year);
				ChangedAuthor(year);
			}
				break;
			default:
				printf("������� ���������� ����� ��������\n");
			}
		}
		else
		{
			printf("������� ������ ���������\n");
		}
	}
		
	return 0;
}