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

int countNodes (struct node *current){

    int count = 0;

    while (current != NULL) {

        current = current->next;
        count++;

    }

    return count;

}

int searchForPositionOfElement (struct node *current, int refValue) {

    int pos = 1;

    if (current == NULL) {
        printf("List is empty boss\n");
        return 0;
    }

    else {
        while(current != NULL) {

            if(current->data == refValue)
                break;
            pos++;
            current = current->next;
    }
        return pos;

    }

}

void insertAtBeginning (struct node **head, int value) {

    struct node *temp = NULL;

    temp = (struct node *) malloc(sizeof(struct node));
    temp->data = value;

    temp->next = *head;
    *head = temp;

}

void insertAtEnd (struct node **head, int value) {

    struct node *current = *head;
    struct node *temp = NULL;

    temp = (struct node *) malloc(sizeof(struct node));
    temp->data = value;

    if (*head == NULL) {

        temp->next = *head;
        *head = temp;

    }

    else {

        while (current->next != NULL)
            current = current->next;

        current->next = temp;
        temp->next = NULL;

    }

}

void insertAfterSpecifiedNode (struct node **head, int value, int refValue) {

    struct node *current = *head;
    struct node *temp = NULL;

    temp = (struct node *) malloc(sizeof(struct node));
    temp->data = value;

    if (*head == NULL) {

        temp->next = NULL;
        *head = temp;

    }

    else {
           while(current->next != NULL) {

                if(current->data == refValue)
                    break;
                current = current->next;

            }

            temp->next = current->next;
            current->next = temp;

    }
}


void insertBeforeSpecifiedNode (struct node **head, int value, int refValue) {

    struct node *current = *head;
    struct node *temp = NULL;

    temp = (struct node *) malloc(sizeof(struct node));
    temp->data = value;

    if (*head == NULL) {

        temp->next = NULL;
        *head = temp;

    }

    else if (countNodes (current) == 1){

        insertAtBeginning (head, value);

    }

    else {
           while(current->next != NULL) {

                if(current->next->data == refValue)
                    break;
                current = current->next;

            }

            temp->next = current->next;
            current->next = temp;

    }
}


void insertAtGivenPosition (struct node **head, int value, int position) {

    struct node *current = *head;
    struct node *temp = NULL;

    temp = (struct node *) malloc(sizeof(struct node));
    temp->data = value;

    if (*head == NULL) {

        temp->next = NULL;
        *head = temp;

    }

    else if (countNodes (current) == 1 && position == 1) {

        insertAtBeginning (head, value);


    }

    else if (countNodes (current) == 1 && position == 2) {

        insertAtEnd (head, value);


    }

    else {

        for (int i = 2; i < position; i++) {
            current = current->next;
            }

        temp->next = current->next;
        current->next = temp;

    }

}

void deleteNodeAtBeginning (struct node **head) {

    struct node *temp = NULL;

    temp = *head;
    *head = (*head)->next;
    free(temp);

}

void deleteNodeAtEnd (struct node **head) {

    struct node *current = *head;
    struct node *temp = NULL;

    if ((*head)->next == NULL) {

        deleteNodeAtBeginning(head);

    }

    else {

        while(current->next->next != NULL)
            current = current->next;

        temp = current->next;
        current->next = NULL;
        free(temp);

    }

}

void deleteNodeAtGivenPosition (struct node **head, int position) {

    struct node *current = *head;
    struct node *temp = NULL;

    for (int i = 2; i < position; i++) {
        current = current->next;
    }

    if (countNodes (current) == 1 && position == 1) {

        deleteNodeAtBeginning(head);

    }

    else {

        temp = current->next;
        current->next = current->next->next;
        free(temp);

    }


}

void reverseTheList (struct node **head) {

    struct node *current = *head;
    struct node *prev = NULL;
    struct node *next = NULL;

    while (current != NULL) {

        next = current->next;
        current->next = prev;
        prev = current;
        current = next;

    }

    *head = prev;

}


int main() {

    struct node *head = NULL;
    int choice = 0;
    int value = 0;
    int refValue = 0;
    int position = 0;

    printf (
            "1. Display list\n"
            "2. Count the number of nodes\n"
            "3. Search for a specific element\n"
            "4. Insert an element at the beginning of the list\n"
            "5. Insert an element at the end of the list\n"
            "6. Insert an element after a specified node\n"
            "7. Insert an element before a specified node\n"
            "8. Insert an element at a given position\n"
            "9. Delete the node at the beginning of the list\n"
            "10. Delete the node at the end of the list\n"
            "11. Delete the node at a given position\n"
            "12. Reverse the list\n"
            "13. Display list && exit.\n"
            );

    scanf("%d", &choice);

    while (choice != 13){

        switch(choice) {

        case 1:
            displayList(head);
            break;
        case 2:
            printf("The number of nodes is %d \n", countNodes(head));
            break;
        case 3:
            printf("Which value do you want to search for?\n");
            scanf("%d", &refValue);
            printf("The position of the element is %d\n", searchForPositionOfElement(head, refValue));
            break;
        case 4:
            printf("Enter the value of the node to be inserted: \n");
            scanf("%d", &value);
            insertAtBeginning(&head, value);
            printf("The list is now: \n");
            displayList(head);
            break;
        case 5:
            printf("Enter the value of the node to be inserted: \n");
            scanf("%d", &value);
            insertAtEnd(&head, value);
            printf("The list is now: \n");
            displayList(head);
            break;
        case 6:
            printf("Enter the value of the node to be inserted: \n");
            scanf("%d", &value);
            printf("Enter the value of the node after which you shall insert: \n");
            scanf("%d", &refValue);
            insertAfterSpecifiedNode(&head, value, refValue);
            printf("The list is now: \n");
            displayList(head);
            break;
        case 7:
            printf("Enter the value of the node to be inserted: \n");
            scanf("%d", &value);
            printf("Enter the value of the node before which you shall insert: \n");
            scanf("%d", &refValue);
            insertBeforeSpecifiedNode(&head, value, refValue);
            printf("The list is now: \n");
            displayList(head);
            break;
        case 8:
            printf("Enter the value of the node to be inserted: \n");
            scanf("%d", &value);
            printf("Enter the position of the node where you want to insert: \n");
            scanf("%d", &position);
            insertAtGivenPosition(&head, value, position);
            printf("The list is now: \n");
            displayList(head);
            break;
        case 9:
            deleteNodeAtBeginning(&head);
            printf("The list is now: \n");
            displayList(head);
            break;
        case 10:
            deleteNodeAtEnd(&head);
            printf("The list is now: \n");
            displayList(head);
            break;
        case 11:
            printf("Enter the position of the node you want to delete: \n");
            scanf("%d", &position);
            deleteNodeAtGivenPosition(&head, position);
            printf("The list is now: \n");
            displayList(head);
            break;
        case 12:
            reverseTheList(&head);
            printf("The list is now: \n");
            displayList(head);
            break;


        }
        printf("Enter your choice to go again: \n");
        scanf("%d", &choice);
    }

    if (choice == 13) {
        printf("The list is now: \n");
        displayList(head);
    }


    return 0;
}
