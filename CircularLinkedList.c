#include <stdio.h>
#include <stdlib.h>

struct node {

    int data;
    struct node *next;

};

void displayList(struct node *ptr) {

    struct node *current = NULL;

    if (current == NULL) {
        printf("List is empty boss\n");
    }



    else {
        current = ptr->next;
        do {

            printf("%d --> ", current -> data);
            current = current->next;

        } while (current != ptr->next);


    printf("\n");

    }

}

int countNodes (struct node *ptr){

    struct node *current = NULL;
    int count = 0;

    current = ptr->next;

    do {

        current = current->next;
        count++;

    } while (current != ptr->next);

    return count;

}

void insertAtBeginning (struct node **last, int value) {

    struct node *temp = NULL;

    temp = (struct node *) malloc(sizeof(struct node));
    temp->data = value;

    if(*last == NULL) {

        *last = temp;
        (*last)->next = last;

    }

    else {

        temp->next = (*last)->next;
        (*last)->next = temp;

    }


}

void insertAtEnd (struct node **last, int value) {

    struct node *temp = NULL;

    temp = (struct node *) malloc(sizeof(struct node));
    temp->data = value;

    if(*last == NULL) {

        *last = temp;
        (*last)->next = *last;

    }

    else {

        temp->next = (*last)->next;
        (*last)->next = temp;
        *last = temp;

    }


}

void insertAfterSpecifiedNode (struct node **last, int value, int refValue) {

    struct node *current = (*last)->next;
    struct node *temp = NULL;

    temp = (struct node *) malloc(sizeof(struct node));
    temp->data = value;

    if (*last == NULL) {

        *last = temp;
        (*last)->next = *last;

    }

    else {
        do {

            if(current->data == refValue)
                break;
            current = current->next;

            } while(current != (*last)->next);

        temp->next = current->next;
        current->next = temp;
        if(current == *last)
            *last = temp;

    }
}




int main() {

    struct node *last = NULL;
    int choice = 0;
    int value = 0;
    int refValue = 0;

    printf (
            "1. Display list\n"
            "2. Count the number of nodes\n"
            "3. Insert an element at the beginning of the list\n"
            "4. Insert an element at the end of the list\n"
            "5. Insert an element after a specified node\n"
            "6. Delete the node at a given position\n"
            "7. Display list && exit.\n"
            );

    scanf("%d", &choice);

    while (choice != 7){

        switch(choice) {

        case 1:
            displayList(last);
            break;
        case 2:
            printf("The number of nodes is %d \n", countNodes(last));
            break;
        case 3:
            printf("Enter the value of the node to be inserted: \n");
            scanf("%d", &value);
            insertAtBeginning(&last, value);
            printf("The list is now: \n");
            displayList(last);
            break;
        case 4:
            printf("Enter the value of the node to be inserted: \n");
            scanf("%d", &value);
            insertAtEnd(&last, value);
            printf("The list is now: \n");
            displayList(last);
            break;
        case 5:
            printf("Enter the value of the node to be inserted: \n");
            scanf("%d", &value);
            printf("Enter the value of the node after which you shall insert: \n");
            scanf("%d", &refValue);
            insertAfterSpecifiedNode(&last, value, refValue);
            printf("The list is now: \n");
            displayList(last);
            break;
        case 6:
            printf("Enter the value of the node you want to delete: \n");
            scanf("%d", &refValue);
            deleteNode(&last, refValue);
            printf("The list is now: \n");
            displayList(last);
            break;

        }
        printf("Enter your choice to go again: \n");
        scanf("%d", &choice);
    }

    if (choice == 7) {
        printf("The list is now: \n");
        displayList(head);
    }


    return 0;
}
