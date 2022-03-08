#include <stdio.h>
#include <stdlib.h>


int gcd (int x, int y) {

    if (y == 0)
        return x;
    return gcd(y, x % y);

}

int main()
{
    int n = 0;
    int m = 0;
    char choice = 'y';
    while(choice == 'y') {

        printf("Give me a number:\n");
        scanf("%d", &n);

        printf("Give me a second number (smaller than the first):\n");
        scanf("%d", &m);

        printf("The greatest common divisor of %d and %d is %d\n", n, m, gcd(n, m));

        printf("Go again (press 'y' to continue)?\n");
        while(getchar() != '\n');
        scanf("%c", &choice);

    }

    return 0;

}
