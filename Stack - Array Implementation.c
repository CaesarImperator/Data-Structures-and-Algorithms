#include <stdio.h>
#include <stdlib.h>
#define MAX 50

int arr[MAX];
int top = -1;

void displayStack() {

    if (top == -1) {

        printf("Stack is empty, nothing to display\n");
        exit(1);

    }

    for (int i = top; i >= 0; i--)
        printf("%d --> ", arr[i]);

    printf("\n");

}

int displaySize() {

    return top + 1;

}

int peek() {

    if (top == -1) {

        printf("Stack is empty, you cannot peek\n");
        exit(1);

    }

    return arr[top];

}

void push(int x) {

    if (top == MAX - 1) {

        printf("Stack is full, you cannot push\n");
        exit(1);

    }

    else {

        top++;
        arr[top] = x;

    }

}

int pop() {

    if (top == -1) {

        printf("Stack is empty, you cannot pop\n");
        exit(1);

    }

    else {

        int x = arr[top];
        top--;
        return x;

    }


}

int main() {

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
            displayStack();
            break;
        case 2:
            value = displaySize();
            printf("Size of the stack is %d elements\n", value);
            break;
        case 3:
            value = peek();
            printf("Top is %d\n", value);
            break;
        case 4:
            printf("Enter the value to be pushed: \n");
            scanf("%d", &value);
            push(value);
            printf("The stack is now: \n");
            displayStack();
            break;
        case 5:
            value = pop();
            printf("Previous top was %d\n", value);
            printf("The stack is now: \n");
            displayStack();
            break;

        }

        printf("Enter your choice to go again: \n");
        scanf("%d", &choice);

    }

    if (choice == 6) {
        printf("Stack is: \n");
        displayStack();
    }

    return 0;
}
