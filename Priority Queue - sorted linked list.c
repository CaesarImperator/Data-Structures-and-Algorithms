#include <stdio.h>
#include <stdlib.h>

struct node {

    int data;
    int priority;
    struct node *next;

};

void displayQueue(struct node *current) {

    if (current == NULL) {
        printf("Queue is empty\n");
    }

    else {
        while (current != NULL) {

            printf("%d(%d) --> ", current->data, current->priority);
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

void enqueue (struct node **front, struct node **rear, int value, int priority) {

    struct node *temp = NULL;
    struct node *current = *rear;

    temp = (struct node *) malloc(sizeof(struct node));
    temp->data = value;
    temp->priority = priority;

    if ((*front == NULL && *rear == NULL) || priority <= (*rear)->priority) {

        temp->next = *rear;
        *rear = temp;
        *front = temp;

    }


    else if (priority < (*front)->priority) {

        while (current->next != NULL && priority > current->next->priority)
            current = current->next;

        temp->next = current->next;
        current->next = temp;

   }

    else {

        while (current->next != NULL && priority > current->next->priority)
            current = current->next;

        temp->next = current->next;
        current->next = temp;
        *front = temp;

    }

}

int dequeue (struct node **front, struct node **rear) {

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


int main() {

    struct node *front = NULL;
    struct node *rear = NULL;
    int choice = 0;
    int value = 0;
    int priority = 0;

    printf (
            "1. Display queue\n"
            "2. Display size of the queue\n"
            "3. Peek (display top of the queue)\n"
            "4. Enqueue (add element at the rear of the queue)\n"
            "5. Dequeue (return last element of queue && eliminate it)\n"
            "6. Display queue && exit.\n"
            );

    scanf("%d", &choice);

    while (choice != 6){

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
            printf("Enter the value to be enqueued: \n");
            scanf("%d", &value);
            printf("Enter the priority of element to be enqueued: \n");
            scanf("%d", &priority);
            enqueue(&front, &rear, value, priority);
            printf("The queue is now: \n");
            displayQueue(rear);
            break;
        case 5:
            value = dequeue(&front, &rear);
            printf("Previous front was %d\n", value);
            printf("The queue is now: \n");
            displayQueue(rear);
            break;

        }

        printf("Enter your choice to go again: \n");
        scanf("%d", &choice);

    }

    if (choice == 6) {
        printf("Queue is: \n");
        displayQueue(rear);
    }

    return 0;
}

