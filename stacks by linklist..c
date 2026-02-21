#include<stdio.h>
#include<stdlib.h>

typedef struct student
{
    int id;
    struct student *next;
}ss;

ss *top= NULL;

void push(int a)
{
    ss *nn=malloc(sizeof(ss));
    nn->id=a;
    nn->next=top;
    top=nn;
}

void  pop()
{
    ss *temp=top;
    top=top->next;
    free(temp);
}
void display()
{
    ss *temp=top;
    while(temp!=NULL)
    {
        printf("%d\n",temp->id);

        temp=temp->next;

    }
}

int main()
{
    push(10);
    push(20);
    push(40);
    push(30);
    pop();
    display();
}
