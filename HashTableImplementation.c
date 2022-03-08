#include <stdio.h>
#include <stdlib.h>

#define TSIZE 19


enum typeOfRecord {EMPTY, DELETED, OCCUPIED};

struct student {

    int studentID;
    char studentName[20];

};

struct record {

    struct student studentInfo;
    enum typeOfRecord status;

};

int hash(int key){

    return key % TSIZE;

}

void insert(struct student rec, struct record table[]) {


    int key = rec.studentID;
    int location = hash(key);

    for(int i = 0; i <= TSIZE; i++) {

        if(table[location].status == EMPTY || table[location].status == DELETED) {

            table[location].studentInfo = rec;
            table[location].status = OCCUPIED;
            printf("Record inserted\n\n");
            return;

        }

        if(table[location].studentInfo.studentID == key) {

            printf("Duplicate key, must be unique\n\n");
            return;

        }

        location = hash(key + 1);

    }

    printf("Record cannot be inserted: table overflow \n\n");

}

int search(int key, struct record table[]) {

    int location = hash(key);
    int i = 0;

    for (i = 0; i < TSIZE; i++) {

        if(table[location].status == EMPTY)
            return -1;
        if(table[location].studentInfo.studentID == key)
            return location;
        location = hash(key + 1);

    }

    return -1;

}

void displayTable(struct record table[]) {

    for (int i = 0; i < TSIZE; i++) {

        printf("[%d]  : ", i);

        if(table[i].status == OCCUPIED)
            printf("Occupied : %d  %s\n", table[i].studentInfo.studentID, table[i].studentInfo.studentName);
        else if(table[i].status == DELETED)
            printf("Deleted\n");
        else
            printf("Empty\n");

    }

}

void del(int key, struct record table[]) {

    int location = search(key, table);
    if(location == -1)
        printf("Key not found\n");
    else
        table[location].status = DELETED;

}



int main()

{

    struct record table[TSIZE];
    struct student rec;

    int key = 0;
    int choice = 0;
    int location = 0;

    for(int i = 0; i < TSIZE; i++)
        table[i].status = EMPTY;

    while(1)
    {
        printf("1. Insert a record \n");
        printf("2. Search for a record \n");
        printf("3. Delete a record \n");
        printf("4. Display table \n");
        printf("5. Exit \n");

        printf("Enter your choice\n");
        scanf("%d", &choice);

        switch(choice) {

            case 1:
                printf("Enter studentID:\n");
                scanf("%d", &rec.studentID);
                printf("Enter student name:\n");
                scanf("%s", rec.studentName);
                insert(rec, table);
                break;
            case 2:
                printf("Enter a key (student ID) to be searched: \n");
                scanf("%d", &key);
                location = search(key, table);
                if (location == -1)
                    printf("Key not found");
                else {

                    printf("Key found at index %d\n", location);
                    printf("%d %s", table[location].studentInfo.studentID, table[location].studentInfo.studentName);

                }
                break;
            case 3:
                printf("Enter a key (student ID) to be deleted\n");
                scanf("%d", &key);
                del(key, table);
                break;
            case 4:
                displayTable(table);
                break;
            case 5:
                exit(1);

        }

    }

    return 0;

}
