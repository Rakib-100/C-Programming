#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct student
{
    int id;
    struct student *pre;
    struct student *next;
}ss;

ss *head=NULL;

void insb(int a)
{
    ss *nn=malloc(sizeof(ss));
    nn->id=a;
    nn->pre=NULL;
    nn->next=head;
    head=nn;

}
void insm(int p,int id)
{
    ss *nn=malloc(sizeof(ss));
    nn->id=id;
    ss *temp=head;
    while(temp->id!=p)
    {
        temp=temp->next;
    }
    nn->next=temp->next;
    nn->pre=temp;
    nn->next->pre=nn;
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
    insb(5);
    insm(10,20);
    insl(30);
    display();
}

