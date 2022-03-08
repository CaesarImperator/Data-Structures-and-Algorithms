#include <stdio.h>
#include <stdlib.h>



int main()
{
    int a = 0;
    int b = 0;
    printf("Enter a number (called 'a'): ");
    scanf("%d", &a);
    printf("Enter another number (called 'b'): ");
    scanf("%d", &b);

    printf("~a is %d\n", ~a);
    printf("~b is %d\n", ~b);
    printf("a&b is %d\n", a&b);
    printf("a|b is %d\n", a|b);
    printf("a^b is %d\n", a^b);
    printf("a<<1 is %d\n", a<<1);
    printf("b<<1 is %d\n", b<<1);


    return 0;
}
