#include <stdio.h>
#include <malloc.h>
#include <string.h>

struct els
{
    char data[8];
    els* next;
}*q, * p, * head, * temphead, * prevel;

void spisok(int n) // фукнкци€ по сути ничего не возвращает
{
    p = NULL;//“ак как список был пуст // необ€зательна€ строка
    printf("Zapolnite spisok:\n");
    //ѕробный проход дл€ первого элемента
    q = (els*)malloc(sizeof(els));
    fgets(q->data, 8, stdin);
    //while (getchar() != '\n');
    q->next = NULL; //выходило так будто первый элемент сам на себ€ указывал
    p = q;
    head = q;//первый элемент списка
    for (int i = 1; i < n; i++)
    {
        q = (els*)malloc(sizeof(els));
        fgets(q->data, 8, stdin);
        q->next = NULL; // нужно показать, что пока дальше ничего нет
        //while (getchar() != '\n');
        p->next = q; // здесь тоже самое, что в 17,нужно у p ставить next, а потом уже мен€ть текущий.
        p = q;
    }
}
void bringout() // в функцию можно ничего не передавать а работать непосредственно с p и head, так как они глобальные
{
    p = head;
    printf("\n");
    while (p != NULL) //но можно и p 
    {
        printf("%s\n", p->data);
        p = p->next;
    }
}

void cut()
{
    printf("\nKakoy element udalyaem?\n");
    int k = 0, counter = 1;

    scanf_s("%d", &k);
    p = head;
    while (p != NULL)
    {
        if (counter == k - 1)
        {
            q = p->next;
            p->next = q->next;
            free(q);
        }
        counter++;
        p = p->next;
    }
}

void add()
{
    printf("\nVvedite identificator:");
    char identy[8];
    while (getchar() != '\n');
    fgets(identy, 8, stdin);
    fflush(stdin);
    p = head;
    while (p != NULL)
    {
        if (strcmp(identy, p->data) == 0)
        {
            q = (els*)malloc(sizeof(els));
            printf("\nZadayte znachenie novomu polu: ");
            scanf_s("%s", q->data, 8);
            while (getchar() != '\n');
            q->next = p->next;
            p->next = q;

            //fgets(q->data, 8, stdin);
            //fflush(stdin);
           // p = q;//эксперимент
        }
        p = p->next;
    }
}


int main()
{
    int n = 3;
    spisok(n);
    bringout();
    cut();
    bringout();//выводит только первый элемент
    add();
    bringout();
    return 0;
}