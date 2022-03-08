#include <stdio.h>
#include <stdlib.h>


struct node {

    int data;
    struct node *next;
    struct node *prev;

};

void displayQueue(struct node *current) {

    if (current == NULL) {
        printf("Queue is empty\n");
    }

    else {
        while (current != NULL) {

            printf("%d <--> ", current -> data);
            current = current->next;

        }

    printf("NULL\n\n");

    }

}

int displaySize(struct node *current){

    int count = 0;

    while (current != NULL) {

        current = current->next;
        count++;

    }

    return count;

}

int peek (struct node *front) {

       if (front == NULL) {

            printf("Queue is empty, you cannot peek\n");
            exit(1);

    }

    return front->data;

}

void insertAtRear (struct node **front, struct node **rear, int value) {

    struct node *temp = NULL;

    temp = (struct node *) malloc(sizeof(struct node));
    temp->data = value;

    if (*front == NULL && *rear == NULL) {

        temp->next = NULL;
        temp->prev = NULL;
        *rear = temp;
        *front = temp;

    }

    else {

        temp->next = *rear;
        temp->prev = NULL;
        *rear = temp;

   }

}

void insertAtFront (struct node **front, struct node **rear, int value) {

    struct node *temp = NULL;

    temp = (struct node *) malloc(sizeof(struct node));
    temp->data = value;

    if (*front == NULL && *rear == NULL) {

        temp->next = NULL;
        temp->prev = NULL;
        *rear = temp;
        *front = temp;

    }

    else {

        temp->prev = *front;
        temp->next = NULL;
        (*front)->next = temp;
        *front = temp;

   }

}

int deleteAtFront (struct node **front, struct node **rear) {

    struct node *temp = NULL;

    if (*front == NULL && *rear == NULL) {

        printf("Queue is empty, you cannot dequeue\n");
        exit(1);

    }

    else if (*front == *rear) {

        temp = *front;
        *front = NULL;
        *rear = NULL;
        return temp->data;
        free(temp);

    }

    else {

        struct node *current = *rear;

        while(current->next->next != NULL)
            current = current->next;
        temp = *front;
        *front = current;
        current->next = NULL;
        return temp->data;
        free(temp);

    }

}

int deleteAtRear (struct node **front, struct node **rear) {

    struct node *temp = NULL;

    if (*front == NULL && *rear == NULL) {

        printf("Queue is empty, you cannot dequeue\n");
        exit(1);

    }

    else if (*front == *rear) {

        temp = *front;
        *front = NULL;
        *rear = NULL;
        return temp->data;
        free(temp);

    }

    else {

        temp = *rear;
        (*rear)->next->prev = NULL;
        *rear = (*rear)->next;
        return temp->data;
        free(temp);

    }

}


int main() {

    struct node *front = NULL;
    struct node *rear = NULL;
    int choice = 0;
    int value = 0;

    printf (
            "1. Display queue\n"
            "2. Display size of the queue\n"
            "3. Peek (display top of the queue)\n"
            "4. Insert at the rear of the queue\n"
            "5. Insert at the front of the queue\n"
            "6. Delete at rear and pop element\n"
            "7. Delete at front and pop element\n"
            "8. Display queue && exit.\n"
            );

    scanf("%d", &choice);

    while (choice != 8){

        switch(choice) {

        case 1:
            displayQueue(rear);
            break;
        case 2:
            value = displaySize(rear);
            printf("Size of the queue is %d element(s)\n", value);
            break;
        case 3:
            value = peek(rear);
            printf("Front of the queue has value %d\n", value);
            break;
        case 4:
            printf("Enter the value to be inserted at the rear: \n");
            scanf("%d", &value);
            insertAtRear(&front, &rear, value);
            printf("The queue is now: \n");
            displayQueue(rear);
            break;
        case 5:
            printf("Enter the value to be inserted at the front: \n");
            scanf("%d", &value);
            insertAtFront(&front, &rear, value);
            printf("The queue is now: \n");
            displayQueue(rear);
            break;
        case 6:
            value = deleteAtRear(&front, &rear);
            printf("Previous rear was %d\n", value);
            printf("The queue is now: \n");
            displayQueue(rear);
            break;
        case 7:
            value = deleteAtFront(&front, &rear);
            printf("Previous front was %d\n", value);
            printf("The queue is now: \n");
            displayQueue(rear);
            break;

        }

        printf("Enter your choice to go again: \n");
        scanf("%d", &choice);

    }

    if (choice == 8) {
        printf("Queue is: \n");
        displayQueue(rear);
    }

    return 0;
}
