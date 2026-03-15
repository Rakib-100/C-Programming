#include<stdlib.h>
#include<stdio.h>
#include<string.h>

typedef struct hostel
{
    char name[55];
    int hid;
    int mob;
    int ts;
    int fs;
    int sf;
    int dfd;
    char gl[505];
    char otinfo[1005];
    struct hostel *next;



}H;
H *head=NULL;
H *last=NULL;
void addhostel()
{
    H *hos=malloc(sizeof(H));
    printf("Enter your Hostel Name:\n");
    fgets(hos->name,sizeof(hos->name),stdin);

    printf("Enter your hostel unic ID no:\n");
    scanf("%d",&hos->hid);


    printf("Enter contacts no:\n");
    scanf("%d",&hos->mob);


    printf("Enter total seat no of your hostel:\n");
    scanf("%d",&hos->ts);


    printf("Enter free seat no:\n");
    scanf("%d",&hos->fs);


    printf("Enter seat fee amount per month:\n");
    scanf("%d",&hos->sf);


    printf("Enter google map distance from daffodil(km):\n");
    scanf("%d",&hos->dfd);
    getchar();

    printf("Paste google map link of your hostel:\n");
    fgets(hos->gl,sizeof(hos->gl),stdin);

    printf("give extra info about your hostel:\n");
    fgets(hos->otinfo,sizeof(hos->otinfo),stdin);

    hos->next=NULL;

    if(head==NULL)
        {
            head=hos;
            last=hos;
    }

    else
        {
            last->next=hos;
            last=hos;
        }
}


void dishos()
{
    H *temp=head;
    if(temp!=NULL)
    {
        while(temp!=NULL)
        {
        printf("Hostel name:%s\n",temp->name);
        printf("Hostel ID:%d\n",temp->hid);
        printf("contract no:%d\n",temp->mob);
        printf("Total seat:%d\n",temp->ts);
        printf("free seat:%d\n",temp->fs);
        printf("seat fee per month(TK): %d\n",temp->sf);
        printf("google map distance from daffodil(KM): %d\n",temp->dfd);
        printf("google map link :\n %s \n",temp->gl);
        printf("other info:\n %s \n",temp->otinfo);
        printf("-----------------------------------\n");

        temp=temp->next;
        }
        printf("\nPress Enter to continue...");
        getchar();

    }
    else{printf("\n**no record found**\n\n");}
}

int main()
{
   int p;
    do{
    printf("########################################\n");
    printf("#                                      #\n");
    printf("#        WELCOME TO DIU-SAMS           #\n");
    printf("#                                      #\n");
    printf("########################################\n");



    printf("ALL OPTION:\n\n");
    printf("1:Add your Hostel.\n");
    printf("2:display all Hostel info.\n");



    printf("enter your Option no:\n");
    scanf("%d",&p);
    getchar();
    switch(p)
    {
        case 1:addhostel();break;
        case 2:dishos();break;

    }
    }while(p!=8);

}



