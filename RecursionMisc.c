#include <stdio.h>
#include <stdlib.h>

int sum (int x, int y) {

    if (x == y)
        return x;
    return y + sum (x, y - 1);

}

void printNumbersAscending (int x, int y) {

    if (x == y) {
        printf("%d \n", x);
        return;
    }
    printf("%d ", y);
    printNumbersAscending(x, y - 1);

}

void printNumbersDescending (int x, int y) {

    if (x == y) {
        printf("%d ", x);
        return;
    }

    printNumbersDescending(x, y - 1);
    printf("%d ", y);

}

int factorialLoop (int x) {

    int f = 1;

    for (int i = 1; i<=x; i++)
        f = f*i;

    return f;
}

int factorialRecursive (int x) {

    if (x == 1 || x == 0)
        return x;
    return x * factorialRecursive(x - 1);

}

int main()
{
    int n = 0;
    int m = 0;
    char choice = 'y';
    while(choice == 'y') {

        printf("Give me a number:\n");
        scanf("%d", &n);
        printf("Give me a second number (relevant for sum calculation only, must be smaller than first):\n");
        scanf("%d", &m);

        printf("The factorial (recursively calculated) of this number is %d\n", factorialRecursive(n));
        printf("The factorial (calculated as a loop) of this number is %d\n", factorialLoop(n));
        printf("The sum of all numbers from second number to the first is %d\n\n", sum(m, n));
        printf("The numbers from second to first are: \n");
        printNumbersAscending(m, n);
        printf("The numbers from second to first are: \n");
        printNumbersDescending(m, n);
        printf("\n");

        printf("Go again (press 'y' to continue)?\n");
        while(getchar() != '\n');
        scanf("%c", &choice);

    }

    return 0;
}
