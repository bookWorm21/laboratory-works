#include <stdio.h>
#include <malloc.h>
struct els
{
    char data[8];
    els* next;
}*q, * p, * head, * temphead, * prevel;

void spisok(int n) // �������� �� ���� ������ �� ����������
{
    p = NULL;//��� ��� ������ ��� ���� // �������������� ������
    printf("Zapolnite spisok:\n");
    //������� ������ ��� ������� ��������
    q = (els*)malloc(sizeof(els));
    fgets(q->data, 8, stdin);
    //while (getchar() != '\n');
    q->next = NULL; //�������� ��� ����� ������ ������� ��� �� ���� ��������
    p = q;
    head = q;//������ ������� ������
    for (int i = 1; i < n; i++)
    {
        q = (els*)malloc(sizeof(els));
        fgets(q->data, 8, stdin);
        q->next = NULL; // ����� ��������, ��� ���� ������ ������ ���
        //while (getchar() != '\n');
        p->next = q; // ����� ���� �����, ��� � 17,����� � p ������� next, � ����� ��� ������ �������.
        p = q;
    }
}
void bringout() // � ������� ����� ������ �� ���������� � �������� ��������������� � p � head, ��� ��� ��� ����������
{
    p = head;
    printf("\n");
    while (p != NULL) //�� ����� � p 
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

int main()
{
    int n = 3;
    spisok(n);
    bringout();
    cut();
    bringout();//������� ������ ������ �������
    return 0;
}