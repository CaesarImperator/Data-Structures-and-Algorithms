#include <stdio.h>
#include <stdlib.h>

struct node {

    int data;
    struct node *next;

};

void displayList(struct node *current) {

    if (current == NULL) {
        printf("List is empty boss\n");
    }

    else {
        while (current != NULL) {

            printf("%d --> ", current -> data);
            current = current->next;

        }

    printf("NULL\n\n");

    }

}

void insertElemInOrder (struct node **head, int value) {

    struct node *current = *head;
    struct node *temp = NULL;

    temp = (struct node *) malloc(sizeof(struct node));
    temp->data = value;

    if (*head == NULL || value < (*head)->data) {

        temp->next = *head;
        *head = temp;

    }

    else {

        while (current->next != NULL && value > current->next->data)
            current = current->next;

        temp->next = current->next;
        current->next = temp;

    }


}

void merge (struct node **head1, struct node **head2, struct node **headM) {

    struct node *temp = (struct node *) malloc(sizeof(struct node));
    temp->next = NULL;
    struct node *currentM = NULL;

    struct node *current1 = *head1;
    struct node *current2 = *head2;

    *headM = temp;

    if(current1->data < current2->data) {

        temp->data = current1->data;
        current1 = current1->next;

    }

    else {

        temp->data = current2->data;
        current2 = current2->next;

    }

    currentM = *headM;


    while (current1 != NULL && current2 != NULL) {

        temp = (struct node *) malloc(sizeof(struct node));
        temp->next = NULL;

        if(current1->data < current2->data) {

        temp->data = current1->data;
        current1 = current1->next;

    }

        else {

        temp->data = current2->data;
        current2 = current2->next;

    }

        currentM->next = temp;
        currentM = temp;


    }

    while (current2 != NULL) {

        temp = (struct node *) malloc(sizeof(struct node));
        temp->next = NULL;
        temp->data = current2->data;
        current2 = current2->next;
        currentM->next = temp;
        currentM = temp;

    }

    while (current1 != NULL) {

        temp = (struct node *) malloc(sizeof(struct node));
        temp->next = NULL;
        temp->data = current1->data;
        current1 = current1->next;
        currentM->next = temp;
        currentM = temp;

    }

}


int main() {

    struct node *head1 = NULL;
    struct node *head2 = NULL;
    struct node *headM = NULL;
    int choice = 0;
    int value = 0;

    printf (
            "1. Display list 1\n"
            "2. Display list 2\n"
            "3. Display merged list\n"
            "4. Insert a new node in list 1\n"
            "5. Insert a new node in list 2\n"
            "6. Merge the two lists\n"
            "7. Display lists && exit.\n"
            );

    scanf("%d", &choice);

    while (choice != 7){

        switch(choice) {

        case 1:
            displayList(head1);
            break;
        case 2:
            displayList(head2);
            break;
        case 3:
            displayList(headM);
            break;
        case 4:
            printf("Enter the value of the node to be inserted in list 1: \n");
            scanf("%d", &value);
            insertElemInOrder(&head1, value);
            printf("The list is now: \n");
            displayList(head1);
            break;
        case 5:
            printf("Enter the value of the node to be inserted in list 2: \n");
            scanf("%d", &value);
            insertElemInOrder(&head2, value);
            printf("The list is now: \n");
            displayList(head2);
            break;
        case 6:
            merge(&head1, &head2, &headM);
            printf("The merged list is now: \n");
            displayList(headM);
            break;

        }

        printf("Enter your choice to go again: \n");
        scanf("%d", &choice);

    }

    if (choice == 7) {
        printf("List 1 is: \n");
        displayList(head1);
        printf("List 2 is: \n");
        displayList(head2);
        printf("Merged list is: \n");
        displayList(headM);
    }


    return 0;
}
