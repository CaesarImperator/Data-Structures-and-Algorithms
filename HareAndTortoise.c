#include <stdio.h>
#include <stdlib.h>

struct node {

    int data;
    struct node *next;

};

void displayList(struct node *current) {

    if (current == NULL) {
        printf("List is empty\n");
    }

    else {
        while (current != NULL) {

            printf("%d --> ", current -> data);
            current = current->next;

        }

    printf("NULL\n\n");

    }

}

void insertCycle(struct node *head, int value) {

    struct node *current = head;
    struct node *cyclePoint = NULL;

    while (current->next != NULL) {

        if (current->data == value)
            cyclePoint = current;
        current = current->next;
    }

    if(cyclePoint != NULL)
        current->next = cyclePoint;

};

struct node *findCycle(struct node *head){

    struct node *tortoise = NULL;
    struct node *hare = NULL;

    if(head == NULL || head->next == NULL)
        return NULL;

    tortoise = hare = head;

    while (hare != NULL && hare->next != NULL) {

        tortoise=tortoise->next;
        hare=hare->next->next;

        if (tortoise == hare){
            return tortoise;
        }
    }

    return NULL;

    }


void removeCycle(struct node *head, struct node *meetingPoint) {

    struct node *p = NULL;
    struct node *q = NULL;

    int lenCycle = 0;

    p = q = meetingPoint;

    do {
        lenCycle++;
        q = q->next;
    } while (p != q);

    printf("Length of the cycle is %d\n", lenCycle);

    int lenRemList = 0;

    p = head;

    while(p != q) {
        lenRemList++;
        p = p->next;
        q = q->next;
    }

    printf("Number of nodes not included in the cycle are %d\n", lenRemList);

    int lengthList = lenCycle + lenRemList;

    printf("Total length of the list is %d\n", lengthList);

    p = head;

    for(int i = 1; i <= lengthList - 1; i++)
        p = p->next;

    p->next = NULL;

};

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

int main() {

    struct node *head = NULL;
    int choice = 0;
    int value = 0;

    printf (
            "1. Display list 1\n"
            "2. Insert a new node in the list\n"
            "3. Insert a cycle\n"
            "4. Display list && exit.\n"
            );

    scanf("%d", &choice);

    while (choice != 4){

        switch(choice) {

        case 1:
            displayList(head);
            break;
        case 2:
            printf("Enter the value of the node to be inserted in the list: \n");
            scanf("%d", &value);
            insertElemInOrder(&head, value);
            printf("The list is now: \n");
            displayList(head);
            break;
        case 3:
            printf("Enter the value of the node where cycle begins: \n");
            scanf("%d", &value);
            insertCycle(head, value);
            printf("The cycle node has been inserted\n");
            break;

        }

        struct node *meetingPoint = findCycle(head);

        if (meetingPoint == NULL)
            printf("There is no cycle\n");
        else {
            printf("The node where cycle was detected (not necessarily where cycle begins) is %d \n", meetingPoint->data);
            removeCycle(head, meetingPoint);
            printf("The cycle has been removed\n");
        }

        printf("Enter your choice to go again: \n");
        scanf("%d", &choice);

    }

    if (choice == 4) {
        printf("The list is: \n");
        displayList(head);
    }


    return 0;
}

