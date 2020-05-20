#include <stdio.h>
#include <malloc.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

struct List
{
	char name[9];
	List* next;
} *current, * temp, * head;

void InputList(List* listStart)
{
	listStart = head;
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

void SortAlphabetical()
{
	struct List* first = NULL;
	struct List* second = NULL;
	struct List* previous = NULL;
	struct List* gradiationRate = NULL;
	struct List* temp = NULL;

	while (gradiationRate != head->next)
	{
		first = head;
		previous = first;
		second = first->next;

		while (first != gradiationRate)
		{
			if (strcmp(first->name, second->name) > 0)
			{
				if (first == head)
				{
					temp = second->next;
					second->next = first;
					first->next = temp;
					head = second;
					previous = second;
				}
				else
				{
					temp = second->next;
					second->next = first;
					first->next = temp;
					previous->next = second;
					previous = second;
				}
			}
			else
			{
				previous = first;
				first = first->next;
			}
			second = first->next;
			if (second == gradiationRate)
				gradiationRate = first;
		}
	}
}


int main(int argc, char* argv)
{
	setlocale(LC_ALL, "Rus");

	int count = 5;
	char userStr[9];
	List startElement;

	current = &(startElement);
	printf("¬ведите им€\n");
	scanf_s("%15s", current->name, 9);
	current->next = NULL;
	startElement = *(current);
	head = current;

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

	//printf("\n¬ведите строку c которой нужно удалить");
	//scanf_s("%9s", userStr, 8);
	//DeleteElementAtList(userStr, &startElement);

	//InputList(&startElement);

	//printf("\n¬ведите строку дл€ поиска");
	//scanf_s("%9s", userStr, 8);
	//AddElement(userStr, &startElement);

	//InputList(&startElement);

	printf("\n");
	SortAlphabetical();
	InputList(&startElement);

	return 0;
}