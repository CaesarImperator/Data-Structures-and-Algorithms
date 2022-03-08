#include <stdio.h>
#include <stdlib.h>


struct node {

    int data;
    struct node *next;

};

void displayStack(struct node *current) {

    if (current == NULL) {
        printf("Stack is empty\n");
    }

    else {
        while (current != NULL) {

            printf("%d --> ", current -> data);
            current = current->next;

        }

    printf("NULL\n\n");

    }

}

int displaySize (struct node *current){

    int count = 0;

    while (current != NULL) {

        current = current->next;
        count++;

    }

    return count;

}

int peek (struct node *top) {

       if (top == NULL) {

            printf("Stack is empty, you cannot peek\n");
            exit(1);

    }

    return top->data;

}

void push (struct node **top, int value) {

    struct node *temp = NULL;

    temp = (struct node *) malloc(sizeof(struct node));
    temp->data = value;

    temp->next = *top;
    *top = temp;

}

int pop (struct node **top) {

    struct node *temp = NULL;

    if (*top == NULL) {

        printf("Stack is empty, you cannot pop\n");
        exit(1);

    }

    else {

        temp = *top;
        *top = (*top)->next;
        return temp->data;
        free(temp);

    }

}


int main() {

    struct node *top = NULL;
    int choice = 0;
    int value = 0;

    printf (
            "1. Display stack\n"
            "2. Display size of stack\n"
            "3. Peek (display top of stack)\n"
            "4. Push (add element on top of stack)\n"
            "5. Pop (return last element and decrement top)\n"
            "6. Display stack && exit.\n"
            );

    scanf("%d", &choice);

    while (choice != 6){

        switch(choice) {

        case 1:
            displayStack(top);
            break;
        case 2:
            value = displaySize(top);
            printf("Size of the stack is %d elements\n", value);
            break;
        case 3:
            value = peek(top);
            printf("Top has value %d\n", value);
            break;
        case 4:
            printf("Enter the value to be pushed: \n");
            scanf("%d", &value);
            push(&top, value);
            printf("The stack is now: \n");
            displayStack(top);
            break;
        case 5:
            value = pop(&top);
            printf("Previous top was %d\n", value);
            printf("The stack is now: \n");
            displayStack(top);
            break;

        }

        printf("Enter your choice to go again: \n");
        scanf("%d", &choice);

    }

    if (choice == 6) {
        printf("Stack is: \n");
        displayStack(top);
    }

    return 0;
}
