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


    printf("Enter fillup seat no:\n");
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

    if(head==NULL){head=hos;}
    if(last==NULL){last=hos;}
    else
        {
            last->next=hos;
            last=hos;
        }
}

int main()
{
    printf("########################################\n");
    printf("#                                      #\n");
    printf("#        WELCOME TO DIU-SAMS           #\n");
    printf("#                                      #\n");
    printf("########################################\n");


    int p;
    printf("ALL OPTION:\n\n");
    printf("1:Add your Hostel.\n\n");

    printf("enter your Option no:\n");
    scanf("%d",&p);
    getchar();
    if(p==1){addhostel();}

}



