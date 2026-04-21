#include <stdio.h>
#include <stdlib.h>
#include <string.h>






struct Student {
    int roll;
    char name[50];
    char dept[50];
    int room;
    char feeStatus[20];
    struct Student *next;
};






struct Student *head = NULL;





int totalRooms = 0;
int roomCapacity[100];







void saveToFile() {
    FILE *fp = fopen("students.txt", "w");
    if(fp == NULL) return;
    struct Student *temp = head;
    while(temp != NULL) {
        fprintf(fp, "%d %s %s %d %s\n",
                temp->roll, temp->name, temp->dept, temp->room, temp->feeStatus);
        temp = temp->next;
    }
    fclose(fp);
}








void loadFromFile() {
    FILE *fp = fopen("students.txt", "r");
    if(fp == NULL) return;
    struct Student *newStudent;
    while(1) {
        newStudent = (struct Student*)malloc(sizeof(struct Student));
        if(fscanf(fp, "%d %s %s %d %s",
                  &newStudent->roll, newStudent->name, newStudent->dept,
                  &newStudent->room, newStudent->feeStatus) == EOF) {
            free(newStudent);
            break;
        }
        newStudent->next = head;
        head = newStudent;
    }
    fclose(fp);
}





void addStudent() {
    if(totalRooms == 0) {
        printf("Please setup hostel info first!\n");
        return;
    }
    struct Student *newStudent = (struct Student*)malloc(sizeof(struct Student));
    printf("Enter Roll: ");
    scanf("%d", &newStudent->roll);
    printf("Enter Name: ");
    scanf("%s", newStudent->name);
    printf("Enter Department: ");
    scanf("%s", newStudent->dept);
    printf("Enter Room No (1-%d): ", totalRooms);
    scanf("%d", &newStudent->room);
    printf("Enter Fee Status (Paid/Unpaid): ");
    scanf("%s", newStudent->feeStatus);

    newStudent->next = head;
    head = newStudent;
    printf("Student added successfully!\n");
    saveToFile();
}






void viewStudents() {
    struct Student *temp = head;
    if(temp == NULL) {
        printf("No student records found!\n");
        return;
    }
    printf("\n--- Student List ---\n");
    while(temp != NULL) {
        printf("Roll: %d | Name: %s | Dept: %s | Room: %d | Fee: %s\n",
               temp->roll, temp->name, temp->dept, temp->room, temp->feeStatus);
        temp = temp->next;
    }
}






void searchStudent() {
    int roll;
    printf("Enter Roll to search: ");
    scanf("%d", &roll);
    struct Student *temp = head;
    while(temp != NULL) {
        if(temp->roll == roll) {
            printf("Found: %s (Dept: %s, Room: %d, Fee: %s)\n",
                   temp->name, temp->dept, temp->room, temp->feeStatus);
            return;
        }
        temp = temp->next;
    }
    printf("Student not found!\n");
}







void deleteStudent() {
    int roll;
    printf("Enter Roll to delete: ");
    scanf("%d", &roll);
    struct Student *temp = head, *prev = NULL;

    while(temp != NULL && temp->roll != roll) {
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL) {
        printf("Student not found!\n");
        return;
    }
    if(prev == NULL) {
        head = temp->next;
    } else {
        prev->next = temp->next;
    }
    free(temp);
    printf("Student deleted successfully!\n");
    saveToFile();
}






void roomInfo() {
    if(totalRooms == 0) {
        printf("Please setup hostel info first!\n");
        return;
    }
    int r, count = 0;
    printf("Enter Room No: ");
    scanf("%d", &r);
    struct Student *temp = head;
    while(temp != NULL) {
        if(temp->room == r)
        {printf("student on this room:\n");
          printf("ID:%d\n",temp->roll);
            count++;}
        temp = temp->next;
    }
    if(r <= 0 || r > totalRooms) {
        printf("Invalid room number!\n");
        return;
    }
    printf("Room %d: Occupied = %d, Free = %d (Capacity = %d)\n",
           r, count, roomCapacity[r] - count, roomCapacity[r]);
}







void sethinfofile()
{
    FILE *fp=fopen("hos.txt","w");
    fprintf(fp,"%d\n",totalRooms);
    for(int i=1;i<=totalRooms; i++)
    {
        fprintf(fp,"%d\n", roomCapacity[i]);
    }

}





void setupHostel() {
    printf("Enter total number of rooms: ");
    scanf("%d", &totalRooms);
    for(int i=1; i<=totalRooms; i++) {
        printf("Enter capacity of Room %d: ", i);
        scanf("%d", &roomCapacity[i]);
    }
    sethinfofile();
    printf("Hostel info setup completed!\n");
}







void loadHostelInfoFromFile() {
    FILE *fp = fopen("hos.txt", "r");
    if(fp == NULL) {
        printf("Hostel info file not found!\n");
        return;
    }

    fscanf(fp, "%d", &totalRooms);
    for(int i = 1; i <= totalRooms; i++) {
        fscanf(fp, "%d", &roomCapacity[i]);
    }

    fclose(fp);
    printf("Hostel info loaded successfully!\n");
}







void updateStudent() {
    int roll;
    printf("Enter Roll of student to update: ");
    scanf("%d", &roll);

    struct Student *temp = head;
    while(temp != NULL) {
        if(temp->roll == roll) {
            printf("\n--- Current Info ---\n");
            printf("Name: %s\nDept: %s\nRoom: %d\nFee: %s\n",
                   temp->name, temp->dept, temp->room, temp->feeStatus);


            printf("Enter new Room No (1-%d): ", totalRooms);
            scanf("%d", &temp->room);
            printf("Enter new Fee Status (Paid/Unpaid): ");
            scanf("%s", temp->feeStatus);
            printf("Student info updated successfully!\n");
            saveToFile();
            return;
        }
        temp = temp->next;
    }
    printf("Student not found!\n");
}




void managerPanel() {
    int choice;
    do {
        printf("\n--- Manager Panel ---\n");
        printf("1. Setup Hostel Info\n2. Add Student\n3. View Students\n4. Search Student\n5. Delete Student\n6. Room Info\n7. update student info\n 8: Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: setupHostel(); break;
            case 2: addStudent(); break;
            case 3: viewStudents(); break;
            case 4: searchStudent(); break;
            case 5: deleteStudent(); break;
            case 6: roomInfo(); break;
            case 7: updateStudent(); break;
        }
    } while(choice != 8);
}




void myinfo()
{
    int roll;
    printf("Enter your Roll: ");
    scanf("%d", &roll);
    struct Student *temp = head;
    while(temp != NULL) {
        if(temp->roll == roll) {
            printf("\n--- Student Info ---\n");
            printf("Name: %s\nDept: %s\nRoom: %d\nFee: %s\n",
                   temp->name, temp->dept, temp->room, temp->feeStatus);
            return;
        }
        temp = temp->next;
    }
    printf("No record found for this roll!\n");
}


void findsit()
{

   if(totalRooms == 0) {
        printf("Please setup hostel info first!\n");
        return;
    }
    int  i;
    for(i=1;i<=totalRooms;i++)

     {
         int  count = 0;
         struct Student *temp=head;
    while(temp != NULL) {
        if(temp->room == i)
        {
            count++;}
        temp = temp->next;
    }


    printf("Room %d: Occupied = %d, Free = %d (Capacity = %d)\n",
           i, count, roomCapacity[i] - count, roomCapacity[i]); }
}




void studentPanel() {
    int p;
    do{

    printf("\n\nAll option:\n1:MY INFO.\n2:Find room:(for new student)\n3:Exit\n");
    printf("enter your option:");
    scanf("%d",&p);
    switch(p)
    {


    case 1 :myinfo();break;
    case 2 :findsit();break;
    }

    }while(p!=3);

}


int main() {
    loadFromFile();
    loadHostelInfoFromFile();
    int choice;
    do {
        printf("\n=== Hostel Management System ===\n");
        printf("1. Manager Login\n2. Student Login\n3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: managerPanel(); break;
            case 2: studentPanel(); break;
        }
    } while(choice != 3);
    return 0;
}
