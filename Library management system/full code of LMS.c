#include<stdio.h>
#include<string.h>
struct book
{
char title[50];
char author[50];
int ISBN;
int puby;
char av;

};
struct book p[350];
int c=0;

void addbook()
{
printf("Enter book name: ");
scanf(" %[^\n]",p[c].title);
printf("Enter Author name: ");
scanf(" %[^\n]",p[c].author);
printf("Enter ISBN no: ");
scanf("%d",&p[c].ISBN);
printf("Enter Publication year: ");
scanf("%d",&p[c].puby);
c++;
printf("Book Added Successfully!\n");
}

void displaybook()
{
if(c==0)
{
printf("No book found!");
return;
}
int i;
for(i=0;i<c;i++)
{
printf("\nBook no : %d\n",i+1);
printf("Name : %s\n",p[i].title);
printf("Author name : %s\n",p[i].author);
printf("ISBN No : %d\n",p[i].ISBN);
printf("Publication year : %d\n",p[i].puby);
printf("availability : Available!\n\n");

}
}

void srcbook()
{
int isbn;
int found = 0;
printf("Enter book ISBN no: ");

scanf("%d",&isbn);
for(int i=0;i<c;i++)
{
if(isbn == p[i].ISBN)
{
printf("\nBook no : %d\n",i+1);
printf("Name : %s\n",p[i].title);
printf("Author name : %s\n",p[i].author);
printf("ISBN No : %d\n",p[i].ISBN);
printf("Publication year : %d\n",p[i].puby);
printf("availability : Available!\n");
found = 1;
break;
}
}
if(found == 0)
{
printf("Book Not Found!\n");
}
}

void savefile()
{
FILE *fp;
fp =fopen("book.txt","w");
int i;
for(i=0;i<c;i++)
{
fprintf(fp,"%s|%s|%d|%d\n",p[i].title,p[i].author,p[i].ISBN,p[i].puby);
}
fclose(fp);
printf("Saved to file successfully!\n");
}

void updatebook()
{
int isbn;
int found = 0;
printf("Enter book ISBN no for update: ");
scanf("%d",&isbn);

for(int i=0;i<c;i++)
{
if(isbn == p[i].ISBN)
{
printf("Enter updated book name: ");
scanf(" %[^\n]",p[i].title);
printf("Enter updated Author name: ");
scanf(" %[^\n]",p[i].author);
printf("Enter updated Publication year: ");
scanf("%d",&p[i].puby);
printf("Book Updated Successfully!\n");
found = 1;
break;
}
}
if(found == 0)
{
printf("Book Not Found!\n");
}
}

void loadFromFile() {
FILE *fp=fopen("book.txt","r");
if (fp==NULL) {
printf("No file found!\n");
return;
}
c = 0;
while(fscanf(fp," %[^|]|%[^|]|%d|%d",
p[c].title,
p[c].author,
&p[c].ISBN,
&p[c].puby)!=EOF)
{
c++;
}
fclose(fp);
printf("Data Loaded Successfully!\n");
}

void deleteFile() {
if (remove("book.txt") == 0)
printf("Record deleate successfully!\n");
else
printf("Unable to delete file!\n");
}

int main(){
int ch;
do {
printf("\n\n---------Library Book Database Management System--------\n------Developed byRAKIB|ISMAIL|NASIM|FAHMIDA|OMI-------\n");
printf("1. Add Book\n");
printf("2. Display all Book\n");
printf("3. Search Book by ISBN No\n");
printf("4. Update Book\n");
printf("5. Save to permanent record\n");
printf("6. Load From permanent record\n");
printf("7. Delete permanent record\n");
printf("8. Exit\n");
printf("Enter choice: ");
scanf("%d",&ch);
switch(ch) {
case 1: addbook(); break;
case 2: displaybook(); break;
case 3: srcbook(); break;
case 4: updatebook(); break;
case 5: savefile(); break;
case 6: loadFromFile(); break;
case 7: deleteFile(); break;
case 8: printf("Thanks for use by record system\n"); break;
default: printf("Invalid Choice!\n");
}
} while (ch != 8);
return 0;
}
