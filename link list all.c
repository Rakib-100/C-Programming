#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct student
{
    int id;
    struct student *next;
}ss;

ss *head=NULL;

void insb(int a)
{
    ss *nn=malloc(sizeof(ss));
    nn->id=a;
    nn->next=head;
    head=nn;
}
void insm(int a,int p)
{
    ss *nn=malloc(sizeof(ss));
    nn->id=a;
    ss *temp=head;
    while(temp->id!=p)
    {
        temp=temp->next;
    }
    if(temp == NULL) {
        printf("Position not found!\n");
        free(nn);
        return;
    }

    nn->next=temp->next;
    temp->next=nn;
}

void insl(int a)
{
    ss *nn=malloc(sizeof(ss));
    nn->id=a;
    nn->next=NULL;
    ss *temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=nn;
}

void delb()
{
    ss *temp=malloc(sizeof(ss));
    temp=head;
    head=head->next;
    free(temp);
}

void

void display()
{
    ss *temp=head;
    while(temp!=NULL)
    {
        printf("%d\n",temp->id);
        temp=temp->next;
    }

}

int main()
{
    insb(10);
    insl(20);
    insl(40);
    insl(100);
    delb();
    display();
}
