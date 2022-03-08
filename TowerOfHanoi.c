#include <stdio.h>
#include <stdlib.h>


void hanoi (int x, char source, char temp, char dest) {

    if (x == 1) {
        printf("Move disk %d from %c to %c\n", x, source, dest);
        return;
    }
    hanoi(x - 1, source, dest, temp);
    printf("Move disk %d from %c-->%c\n", x, source, dest);
    hanoi(x - 1, temp, source, dest);


}

int main()
{
    int n = 0;
    char choice = 'y';
    while(choice == 'y') {

        printf("Enter the number of disks to be moved:\n");
        scanf("%d", &n);

        hanoi (n, 'A', 'B', 'C');

        printf("Go again (press 'y' to continue)?\n");
        while(getchar() != '\n');
        scanf("%c", &choice);

    }

    return 0;

}
