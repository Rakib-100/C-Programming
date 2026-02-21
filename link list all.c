#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct student
{
    int id;
    struct student *next;
} ss;

ss *head = NULL;

void insb(int a)
{
    ss *nn = malloc(sizeof(ss));
    nn->id = a;
    nn->next = head;
    head = nn;
}

void insm(int a, int p)
{
    ss *nn = malloc(sizeof(ss));
    nn->id = a;

    ss *temp = head;
    while(temp->id != p)
    {
        temp = temp->next;
    }

    nn->next = temp->next;
    temp->next = nn;
}

void insl(int a)
{
    ss *nn = malloc(sizeof(ss));
    nn->id = a;
    nn->next = NULL;

    ss *temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = nn;
}

void delb()
{
    ss *temp;
    temp = head;
    head = head->next;
    free(temp);
}

void delm(int a)
{
    ss *temp;
    temp = head;
    while(temp->next->id != a)
    {
        temp = temp->next;
    }
    if(temp != NULL)
    {
        ss *temp2;
        temp2 = temp->next;
        temp->next = temp->next->next;
        free(temp2);
    }
}

void dell()
{
    ss *temp;
    temp = head;
    while(temp->next->next != NULL)
    {
        temp = temp->next;
    }

    ss *temp2;
    temp2 = temp->next;
    temp->next = NULL;
    free(temp2);
}

void display()
{
    ss *temp = head;
    while(temp != NULL)
    {
        printf("%d\n", temp->id);
        temp = temp->next;
    }
}

int main()
{
    insb(10);
    insl(20);
    insl(40);
    insl(100);

    dell();
    //delm(100);

    display();
}
