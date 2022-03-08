#include <stdio.h>
#include <stdlib.h>


void BinaryToDecimal (int x) {

    if (x == 0)
        return;
    BinaryToDecimal(x/2);
    printf("%d", x%2);

}

int main()
{
    int n = 0;
    char choice = 'y';
    while(choice == 'y') {

        printf("Give me a number:\n");
        scanf("%d", &n);

        BinaryToDecimal(n);
        printf("\n");

        printf("Go again (press 'y' to continue)?\n");
        while(getchar() != '\n');
        scanf("%c", &choice);

    }

    return 0;

}
