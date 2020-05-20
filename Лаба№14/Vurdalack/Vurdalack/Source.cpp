
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <wchar.h>

struct stock
{
    char name[30];
    char deals[30];
    char volume[30];
    struct stock* next;
    struct stock* prev;
};
struct stock* head;
struct stock* tail;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    if (FileReader() != 0)
        ConsoleMenu();
    return 0;
}

int FileReader()
{
    char name[30];
    char deals[30], volume[30];
    FILE* f_in;
    f_in = fopen("C:/Users/ramis/Labs_C/Laba_6/list.txt", "r");
    if (f_in == NULL)
    {
        printf("ОШИБКА! ФАЙЛ НЕ НАЙДЕН!");
        return 0;
    }
    else
    {
        rewind(f_in);
        while ((fscanf(f_in, "%s %s %s", &name, &deals, &volume) != EOF))
        {
            Creation(name, deals, volume);
        }
        fclose(f_in);
        return 1;
    }

}

void ConsoleMenu()
{
    char name[30];
    char deals[30], volume[30];
    int num;
    while (1)
    {
        printf("МЕНЮ: \n");
        printf("1. Вывод всех элементов на экран\n");
        printf("2. Сброс значений всех элементов\n");
        printf("3. Печать всех элементов в отсортированном виде\n");
        printf("4. Добавление элемента, заданной ссылочной переменной\n");
        printf("5. Выход\n");
        printf(":");
        scanf("%d", &num);
        if (num == 1)
        {
            ConsolePrinter();
        }
        if (num == 2)
        {
            Delete();
        }
        if (num == 3)
        {
            ListSort();
        }
        if (num == 4)
        {
            int pozition;
            head = NULL;
            scanf("%d", &pozition);
            fgets(name, 20, stdin);
            fgets(deals, 20, stdin);
            fgets(volume, 20, stdin);
            Adding(&head, pozition, name, deals, volume);
        }
        if (num == 5)
        {
            break;
        }
        printf("\n");
    }
}

void Creation(char* name, char* deals, char* volume)
{
    struct stock* tmp;
    struct stock* newELement = (struct stock*)malloc(sizeof(struct stock));
    tmp = head;
    strcpy(newELement->name, "Untitled");
    strcpy(newELement->deals, "Untitled");
    strcpy(newELement->volume, "Untitled");

    if (head != NULL)
    {
        do
        {
            tmp = tmp->next;
        } while (tmp->next != head);
        newELement->next = head;
        tmp->next = newELement;

    }
    else
    {
        head = newELement;
        newELement->next = head;
    }
}

void ConsolePrinter()
{
    struct stock* tmp;
    tmp = head;
    int poz = 0;
    printf("                   Название ценной бумаги            Количество сделок               Объем торгов\n");
    do {
        if ((strcmp(tmp->name, "") != 0) && (poz == 0))
        {
            printf("   %30s %30s %30s\n", tmp->name, tmp->deals, tmp->volume);
            poz++;
            tmp = tmp->next;
        }
        if ((strcmp(tmp->name, "") != 0) && (poz > 0))
        {
            printf("%d. %30s %30s %30s\n", poz, tmp->name, tmp->deals, tmp->volume);
            poz++;
        }
        tmp = tmp->next;

    } while (tmp != head);
}

void ListSort()
{
    struct stock* tmp, * tmp1;
    printf("Сортировка в алфавитном порядке:\n");
    for (tail = head; tail != head->next;)
    {
        for (tmp1 = head, tmp = head->next; tmp->next != tail; tmp1 = tmp1->next)
        {
            if (strcmp(tmp->next->name, tmp->name) != 1)
            {
                tmp1->next = tmp->next;
                tmp->next = tmp->next->next;
                tmp1->next->next = tmp;
            }
            else tmp = tmp->next;
        }
        tail = tmp;
    }
    tmp = head;
    ConsolePrinter();
    printf("\n");
}

void AddingFirstPozition(struct stock** head, char* name, char* deals, char* volume)
{
    struct stock* newNode = (struct stock*)malloc(sizeof(struct stock));
    strcpy(newNode->name, name);
    strcpy(newNode->deals, deals);
    strcpy(newNode->volume, volume);
    newNode->next = *head;
    *head = newNode;
    ConsolePrinter();
}

void Adding(struct stock** head, int index, char* name, char* deals, char* volume)
{
    if (index == 0)
        AddingFirstPozition(head, name, deals, volume);
    else
    {
        struct stock* current = *head;
        for (int i = 0; i < index - 1; i++)
        {
            current = current->next;
        }
        AddingFirstPozition(&(current->next), name, deals, volume);
    }
}

void Delete()
{
    printf("Hello,World");
}