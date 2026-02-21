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
    if(head != NULL)
    {
       head->pre = nn;
    }

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
    temp->next=nn;
    if(nn->next!=NULL)
    {nn->next->pre=nn;}

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
    nn->pre=temp;

}

void delb()
{
    if(head==NULL) return;

    ss *temp=head;
    head=head->next;
    head->pre=NULL;
    free(temp);
}


void delm(int id)
{
    if(head==NULL) return;

    ss *temp=head;
    while(temp->next->id!=id)
    {
        temp=temp->next;
    }
    ss *temp2=temp->next;
    temp->next=temp->next->next;
    temp->next->pre=temp;
    free(temp2);
}

void dell()
{   if(head==NULL)return;
    ss *temp=head;
    while(temp->next->next!=NULL)
    {
        temp=temp->next;
    }
    ss *temp2=temp->next;
    temp->next=NULL;
    free(temp2);

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
    insl(40);
    insl(50);
    insl(60);
    delb();
    delm(40);
    dell();
    display();
}

