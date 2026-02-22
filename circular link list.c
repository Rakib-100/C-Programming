#include<stdio.h>
#include<stdlib.h>

typedef struct student
{
    int id;
    struct student *next;
}ss;

 ss *head=NULL;

void insb(int a){
    ss *nn=malloc(sizeof(ss));
    nn->id=a;
    if(head==NULL)
    {
       head=nn;
       head->next=nn;
    }
    else
    {
       nn->next=head;
       ss *temp=head;
       while(temp->next!=head){temp=temp->next;}
       temp->next=nn;
       head=nn;

    }
}

void delb()
{
    ss *f=head;
    head=head->next;
    ss *temp=head;
    while(temp->next!=f)
    {
        temp=temp->next;
    }
    temp->next=head;
    free(f);
}

    void display()
    {
        ss *temp=head;
        do
        {
            printf("%d ",temp->id);
            temp=temp->next;
        }while(temp!=head);
    }



int main()
{
    insb(50);
    insb(40);
    insb(30);
    insb(20);
    insb(10);
    delb();
    display();


}
