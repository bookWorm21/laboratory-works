#include <stdio.h>
#include <malloc.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

struct List
{
	char name[9];
	List* next;
} *current, * temp;

void InputList(List* listStart)
{
	while (listStart != NULL)
	{
		printf("%9s", listStart->name);
		listStart = listStart->next;
	}
}

void DeleteElementAtList(char str[9], List* listStart)
{
	List* linkToDelete = NULL;

	while (listStart != NULL)
	{
		if (strcmp(listStart->name, str) == 0)
		{
			if (strstr(listStart->name, str) != 0)
			{
				if (linkToDelete != NULL)
				{
					linkToDelete->next = listStart->next;
					free(listStart);

					listStart = linkToDelete->next;
				}
				else
				{
					linkToDelete = listStart;
					*listStart = *listStart->next;
				}
			}
		}
		else
		{
			linkToDelete = listStart;
			listStart = listStart->next;
		}
	}
}

void AddElement(char str[9], List* listStart)
{
	while (listStart != NULL)
	{
		if (strcmp(listStart->name, str) == 0)
		{
			if (strstr(listStart->name, str) != 0)
			{
				while (getchar() != '\n');

				temp = (List*)malloc(sizeof(List));
				temp->next = listStart->next;
				listStart->next = temp;
				printf("¬ведите им€\n");
				scanf_s("%9s", temp->name, 8);
			}
		}
		listStart = listStart->next;
	}
}

int main(int argc, char* argv)
{
	setlocale(LC_ALL, "Rus");

	int count = 3;
	char userStr[9];
	List startElement;

	current = &(startElement);
	printf("¬ведите им€\n");
	scanf_s("%15s", current->name, 9);
	current->next = NULL;
	startElement = *(current);

	for (int i = 1; i < count; i++)
	{
		while (getchar() != '\n');

		temp = (List*)malloc(sizeof(List));
		temp->next = NULL;
		current->next = temp;
		current = temp;
		printf("\n¬ведите им€\n");
		scanf_s("%15s", current->name, 9);
	}

	InputList(&startElement);

	printf("\n¬ведите строку c которой нужно удалить");
	scanf_s("%9s", userStr, 8);
	DeleteElementAtList(userStr, &startElement);

	InputList(&startElement);

	printf("\n¬ведите строку дл€ поиска");
	scanf_s("%9s", userStr, 8);
	AddElement(userStr, &startElement);

	InputList(&startElement);

	return 0;
}