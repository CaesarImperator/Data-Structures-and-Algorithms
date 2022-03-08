#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 255

char stack[MAX];
int top = -1;


int isEmpty (char x[]) {

    if (top == -1)
        return 1;
    else
        return 0;

}

void push(char x) {

    if (top == MAX - 1) {

        printf("Stack is full, you cannot push\n");
        exit(1);

    }

    else {

        top++;
        stack[top] = x;

    }

}

int pop() {

    if (top == -1) {

        printf("Stack is empty, you cannot pop\n");
        exit(1);

    }

    else {

        char x = stack[top];
        top--;
        return x;

    }

}

int isValid (char expr[]) {

    for (int i = 0; i < strlen(expr); i++) {
        if (expr[i] == '(' || expr[i] == '[' || expr[i] == '{')
            push(expr[i]);

        else if (expr[i] == ')' || expr[i] == ']' || expr[i] == '}') {

            if (isEmpty(stack) == 1) {

                printf("Right parenthesis without matching left parenthesis, so invalid\n");
                return 0;

            }

            else {

                char lastElem = pop();

                if ((lastElem == '(' && expr[i] == ')') || (lastElem == '[' && expr[i] == ']') || (lastElem == '{' && expr[i] == '}')) {

                    continue;

                }

                else {

                    printf("Mismatched parentheses are:\n ");
                    printf("%c and %c\n", lastElem, expr[i]);
                    return 0;

                return 1;

                }

            }

        }

    }

    if (!isEmpty(stack)) {

        printf("Left parenthesis without matching right parenthesis, so invalid\n");
        return 0;

    }

    else {

        printf("Correct parentheses or no parentheses, valid\n");
        return 1;

    }

}


int main() {

    char str[MAX];

    int goAgain = 1;

    while (goAgain == 1) {

        printf ("Enter an expression with parentheses:\n");
        gets(str);

        top = -1;

        if (isValid(str))
            printf("Valid expression\n");
        else
            printf("Invalid expression\n");

        printf("Wanna go again? '1' for yes, '0' for no\n");
        scanf("%d", &goAgain);
        fflush(stdin);

        }

    return 0;

}
