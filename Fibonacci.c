#include <stdio.h>
#include <stdlib.h>


int fibonacci (int x) {

    if (x == 1)
        return 0;
    else if (x == 2)
        return 1;
    return fibonacci(x - 1) + fibonacci(x - 2);

}

int main()
{
    int n = 0;
    char choice = 'y';
    while(choice == 'y') {

        printf("Which element of the Fibonacci series do you want?:\n");
        scanf("%d", &n);

        printf("The %d st/nd/rd/th Fibonacci number is %d\n", n, fibonacci(n));

        printf("Go again (press 'y' to continue)?\n");
        while(getchar() != '\n');
        scanf("%c", &choice);

    }

    return 0;

}
