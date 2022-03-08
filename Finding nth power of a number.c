#include <stdio.h>
#include <stdlib.h>


int nthPower (int x, int y) {

    if (y == 1)
        return x;
    return x * nthPower(x, y - 1);

}

int main()
{
    int n = 0;
    int m = 0;
    char choice = 'y';
    while(choice == 'y') {

        printf("Give me a number:\n");
        scanf("%d", &n);

        printf("Give me a power to raise the number to:\n");
        scanf("%d", &m);

        printf("The %dst/nd/rd/th power of thy number %d is equal to %d\n", m, n, nthPower(n, m));

        printf("Go again (press 'y' to continue)?\n");
        while(getchar() != '\n');
        scanf("%c", &choice);

    }

    return 0;

}
