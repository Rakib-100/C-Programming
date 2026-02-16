#include<stdio.h>
#include<stdlib.h>
typedef struct student
{
    int id;
    struct student *next;
}ss;
ss *front=NULL;
ss *rear=NULL;
void enqueue(int a)
{
    ss *nn=malloc(sizeof(ss));
    nn->id=a;
    nn->next=NULL;
    if(front==NULL&&rear==NULL)
    {
        front=nn;
        rear=nn;
    }
    else
    {
        rear->next=nn;
        rear=nn;
    }
}

void dequeqe()
{
    ss *temp=front;
    front=front->next;
    free(temp);
}

void display()
{
    ss *temp=front;
    while(temp!=NULL)
    {printf("%d\n",temp->id);
    temp=temp->next;
    }
}


int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    dequeqe();
    display();
}
